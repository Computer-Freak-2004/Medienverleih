#include "ManageLend.h"
#include "Lend.h"
#include "Book.h"
#include "CD.h"
#include "Person.h"
#include "../ui_mainwindow.h"
#include "../ui_addlenddialog.h"

#include <QTableWidget>
#include <QMessageBox>
#include <QStyleFactory>
#include <QApplication>
#include <QDebug>
#include <QList>
#include <QDate>

extern QList<Person> PersonList;
extern QList<Book> BookList;
extern QList<CD> CDList;
extern QList<Lend> LendList;

extern int PersonRow;
extern int MediaType; //0= Book, 1=CD
extern int BookRow;
extern int CDRow;

void ManageLend::Lendaccept(Ui::MainWindow *ui){
    // gewählte Daten in LendTableWidget eintragen + zusätzliche Daten

    int NewRow = ui->LendTableWidget->rowCount();
    ui->LendTableWidget->insertRow(NewRow);

    // Ausleihnummer
    QString LendNumberString = QString::number(NewRow + 1);
    QTableWidgetItem *newItem = new QTableWidgetItem(LendNumberString);
    ui->LendTableWidget->setItem(NewRow, 0, newItem);

    // gewählte Daten aus PersonList laden
    Person loadedPerson = PersonList[PersonRow];
    int Number = loadedPerson.getNumber();
    QString NumberString = QString::number(Number);
    newItem = new QTableWidgetItem(NumberString);

    ui->LendTableWidget->setItem(NewRow, 1, newItem);

    newItem = new QTableWidgetItem(loadedPerson.getName());
    ui->LendTableWidget->setItem(NewRow, 2, newItem);

    // gewählte Daten für Medien laden
    if (MediaType == 0){ // Buch
        Book loadedBook = BookList[BookRow];

        Number = loadedBook.getNumber();
        QString NumberString = QString::number(Number);
        newItem = new QTableWidgetItem(NumberString);

        ui->LendTableWidget->setItem(NewRow, 3, newItem);

        newItem = new QTableWidgetItem(loadedBook.getTitle());
        ui->LendTableWidget->setItem(NewRow, 4, newItem);

        // Medientyp setzen
        newItem = new QTableWidgetItem("Buch");
        ui->LendTableWidget->setItem(NewRow, 5, newItem);
    }
    else if (MediaType == 1){ // CD
        CD loadedCD = CDList[CDRow];

        Number = loadedCD.getNumber();
        NumberString = QString::number(Number);
        newItem = new QTableWidgetItem(NumberString);

        ui->LendTableWidget->setItem(NewRow, 3, newItem);

        newItem = new QTableWidgetItem(loadedCD.getTitle());
        ui->LendTableWidget->setItem(NewRow, 4, newItem);

        // Medientyp setzen
        newItem = new QTableWidgetItem("CD");
        ui->LendTableWidget->setItem(NewRow, 5, newItem);
    }

    // Aktuelles Datum hinzufügen
    QDate currentDate = QDate::currentDate();
    int day = currentDate.day();
    int year = currentDate.year();
    int month = currentDate.month();

    QString dayString = QString::number(day);
    QString monthString = QString::number(month);
    QString yearString = QString::number(year);

    // bei Bedarf führende Nullen hinzufügen
    if (month < 10){
        monthString = "0" + QString::number(month);
    }
    if (day < 10){
        dayString = "0" + QString::number(day);
    }

    QString currentDateString = dayString + "." + monthString + "." + yearString;
    qDebug() << "DateString: " << currentDateString;
    newItem = new QTableWidgetItem(currentDateString);
    ui->LendTableWidget->setItem(NewRow, 6, newItem);
    ui->LendTableWidget->selectRow(NewRow);

    // Variablen zurücksetzen
    MediaType = 0;
    PersonRow = -1;
    BookRow = -1;
    CDRow = -1;

}

void ManageLend::DeleteLend(Ui::MainWindow *ui){
    // Aktuell ausgewählte Zeile löschen
    int currentRow = ui->LendTableWidget->currentRow();

    if (currentRow == -1){
        QMessageBox::warning(nullptr, "Zurückgeben", "Keine Zeile zum Zurückgeben ausgewählt!");
    }
    ui->LendTableWidget->removeRow(currentRow);
    ui->LendTableWidget->selectRow(currentRow - 1);
}

void ManageLend::SaveLendTable(Ui::MainWindow *ui){
    int Rows = ui->LendTableWidget->rowCount();

    QList<Lend> TempLendList = LendList;
    // Liste löschen
    LendList.clear();

    for (int i=0; i < Rows; i++){ // Zeilen
        // hier sollte keine Fehlerbetrachtung nötig sein...
        Lend NewLend;

        // Daten aus TableWidget lesen und in NewLend schreiben
        NewLend.setNumber(ui->LendTableWidget->item(i, 0)->text().toInt());
        NewLend.setPersonNumber(ui->LendTableWidget->item(i, 1)->text().toInt());
        NewLend.setPersonName(ui->LendTableWidget->item(i, 2)->text());
        NewLend.setMediaNumber(ui->LendTableWidget->item(i, 3)->text().toInt());
        NewLend.setMediaTitle(ui->LendTableWidget->item(i, 4)->text());
        NewLend.setMediaType(ui->LendTableWidget->item(i, 5)->text());
        NewLend.setLendDate(ui->LendTableWidget->item(i, 6)->text());

        //NewLend.PrintLend();
        LendList.append(NewLend); //An Liste anhängen

        qDebug() << "Inhalt der LendList:";
        for (auto &pers : LendList) {
            pers.PrintLend();
        }
    }
}

void ManageLend::LoadLendTable(Ui::MainWindow *ui){
    qDebug() << "==Ausleihe==";
    // automatisches Laden aus der Liste (falls vorhanden)
    int Rows = LendList.length();

    ui->LendTableWidget->clearContents();
    ui->LendTableWidget->setRowCount(LendList.length());

    if (Rows < 1){
        qDebug() << "Liste leer!";
        return;
    }

    qDebug() << "LendList Length: " << LendList.length();

    // LendList lesen und auf TableWidget anzeigen
    for (int i=0; i < Rows; i++){
        // initialisieren
        for (int j=0; j < 7; j++){ // Spalten
            QTableWidgetItem *newItem = new QTableWidgetItem("");
            ui->LendTableWidget->setItem(i, j, newItem);
        }

        // Lend aus Liste laden
        Lend NewLend = LendList[i];

        // Variablen aus Lend in TableWidget eintragen
        int number = NewLend.getNumber();
        QString NumberString = QString::number(number);
        QTableWidgetItem *newItem = new QTableWidgetItem(NumberString);
        ui->LendTableWidget->setItem(i, 0, newItem);

        int PersonNumber = NewLend.getPersonNumber();
        QString PersonNumberString = QString::number(PersonNumber);
        newItem = new QTableWidgetItem(PersonNumberString);
        ui->LendTableWidget->setItem(i, 1, newItem);


        newItem = new QTableWidgetItem(NewLend.getPersonName());
        ui->LendTableWidget->setItem(i, 2, newItem);

        int MediaNumber = NewLend.getMediaNumber();
        QString MediaNumberString = QString::number(MediaNumber);
        newItem = new QTableWidgetItem(MediaNumberString);
        ui->LendTableWidget->setItem(i, 3, newItem);

        newItem = new QTableWidgetItem(NewLend.getMediaTitle());
        ui->LendTableWidget->setItem(i, 4, newItem);

        newItem = new QTableWidgetItem(NewLend.getMediaType());
        ui->LendTableWidget->setItem(i, 5, newItem);

        newItem = new QTableWidgetItem(NewLend.getLendDate());
        ui->LendTableWidget->setItem(i, 6, newItem);
    }
}
