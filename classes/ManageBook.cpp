#ifndef MANAGEBOOK_H
#define MANAGEBOOK_H
#include "ManageBook.h"
#include "Book.h"
#include "../ui_mainwindow.h"
#include "../ui_addlenddialog.h"

#include <QTableWidget>
#include <QMessageBox>
#include <QStyleFactory>
#include <QApplication>
#include <QDebug>
#include <QList>
#include <QDate>

extern QList<Book> BookList;

void ManageBook::AddBook(Ui::MainWindow *ui){
    // Neue Zeile hinzufügen
    int newRow = ui->BookTableWidget->rowCount();
    ui->BookTableWidget->insertRow(newRow);

    // initialisieren
    for (int i=0; i < 5; i++){ // Spalten
        QTableWidgetItem *newItem = new QTableWidgetItem("");
        ui->BookTableWidget->setItem(newRow, i, newItem);
    }
}

void ManageBook::DeleteBook(Ui::MainWindow *ui){
    // Aktuell ausgewählte Zeile löschen
    int currentRow = ui->BookTableWidget->currentRow();

    if (currentRow == -1){
        QMessageBox::warning(nullptr, "Buch löschen", "Keine Zeile zum Löschen ausgewählt!");
    }
    ui->BookTableWidget->removeRow(currentRow);
}

void ManageBook::SaveBookTable(Ui::MainWindow *ui){
    int Rows = ui->BookTableWidget->rowCount();
    if (Rows < 1){
        QMessageBox::warning(nullptr, "Bücher speichern", "Tabelle leer!");
        return;
    }

    QList<Book> TempBookList = BookList;
    // Liste löschen
    BookList.clear();

    for (int i=0; i < ui->BookTableWidget->rowCount(); i++){ // Zeilen
        // Zellen leer? (Segfault verhindern ;)!)
        if (ui->BookTableWidget->item(i, 0)->text().isEmpty() ||
            ui->BookTableWidget->item(i, 1)->text().isEmpty() ||
            ui->BookTableWidget->item(i, 2)->text().isEmpty() ||
            ui->BookTableWidget->item(i, 3)->text().isEmpty() ||
            ui->BookTableWidget->item(i, 4)->text().isEmpty() ||
            ui->BookTableWidget->item(i, 5)->text().isEmpty()) {
            BookList = TempBookList;
            QMessageBox::warning(nullptr, "Bücher speichern", "Es gibt noch leere Zellen!");
            return;
        }

        // Strings bei Integern eingetragen?
        QString NumberText = ui->BookTableWidget->item(i, 0)->text();
        QString YearText = ui->BookTableWidget->item(i, 3)->text();
        QString PagesText = ui->BookTableWidget->item(i, 4)->text();

        bool ConversionOk = true; // flag wird auf false gesetzt, falls String zu Int konvertiert wird
        NumberText.toInt(&ConversionOk);
        if (ConversionOk != true){
            BookList = TempBookList;
            QMessageBox::warning(nullptr, "Bücher speichern", "Bitte Spalte Buch-Nr. überprüfen! Es dürfen dort nur Zahlen drinstehen.");
            return;
        }
        YearText.toInt(&ConversionOk);
        if (ConversionOk != true){
            BookList = TempBookList;
            QMessageBox::warning(nullptr, "Bücher speichern", "Bitte Spalte Jahr überprüfen! Es dürfen dort nur Zahlen drinstehen.");
            return;
        }
        PagesText.toInt(&ConversionOk);
        if (ConversionOk != true){
            BookList = TempBookList;
            QMessageBox::warning(nullptr, "Bücher speichern", "Bitte Spalte Seiten überprüfen! Es dürfen dort nur Zahlen drinstehen.");
            return;
        }

        // Keine Fehler für die aktuelle Spalte gefunden -> fahre fort...
        Book NewBook;

        // Daten aus TableWidget lesen und in NewBook schreiben
        NewBook.setNumber(ui->BookTableWidget->item(i, 0)->text().toInt());
        NewBook.setTitle(ui->BookTableWidget->item(i, 1)->text());
        NewBook.setAuthor(ui->BookTableWidget->item(i, 2)->text());
        NewBook.setYear(ui->BookTableWidget->item(i, 3)->text().toInt());
        NewBook.setPages(ui->BookTableWidget->item(i, 4)->text().toInt());
        NewBook.setPublisher(ui->BookTableWidget->item(i, 5)->text());

        //NewBook.PrintBook();
        BookList.append(NewBook); //An Liste anhängen

        qDebug() << "Inhalt der BookList:";
        for (auto &pers : BookList) {
            pers.PrintBook();
        }
    }
}

void ManageBook::LoadBookTable(Ui::MainWindow *ui){
    qDebug() << "==Buch==";
    // automatisches Laden aus der Liste (falls vorhanden)
    int Rows = BookList.length();

    ui->BookTableWidget->clearContents();
    ui->BookTableWidget->setRowCount(BookList.length());

    if (Rows < 1){
        qDebug() << "Liste leer!";
        return;
    }

    qDebug() << "BookList Length: " << BookList.length();

    // BookList lesen und auf TableWidget anzeigen
    for (int i=0; i < Rows; i++){
        // initialisieren
        for (int j=0; j < 6; j++){ // Spalten
            QTableWidgetItem *newItem = new QTableWidgetItem("");
            ui->BookTableWidget->setItem(i, j, newItem);
        }

        // Book aus Liste laden
        Book NewBook = BookList[i];

        // Variablen aus Person in TableWidget eintragen
        int number = NewBook.getNumber();
        QString NumberString = QString::number(number);
        QTableWidgetItem *newItem = new QTableWidgetItem(NumberString);
        ui->BookTableWidget->setItem(i, 0, newItem);

        newItem = new QTableWidgetItem(NewBook.getTitle());
        ui->BookTableWidget->setItem(i, 1, newItem);

        newItem = new QTableWidgetItem(NewBook.getAuthor());
        ui->BookTableWidget->setItem(i, 2, newItem);

        int year = NewBook.getYear();
        QString YearString = QString::number(year);
        newItem = new QTableWidgetItem(YearString);
        ui->BookTableWidget->setItem(i, 3, newItem);

        int pages = NewBook.getPages();
        QString PagesString = QString::number(pages);
        newItem = new QTableWidgetItem(PagesString);
        ui->BookTableWidget->setItem(i, 4, newItem);

        newItem = new QTableWidgetItem(NewBook.getPublisher());
        ui->BookTableWidget->setItem(i, 5, newItem);
    }
}

void ManageBook::LoadBookTable(Ui::AddLendDialog *ui){ // überladene Fkt.
    qDebug() << "==Buch==";
    // automatisches Laden aus der Liste (falls vorhanden)
    int Rows = BookList.length();

    ui->BookTableWidget->clearContents();
    ui->BookTableWidget->setRowCount(BookList.length());

    if (Rows < 1){
        qDebug() << "Liste leer!";
        return;
    }

    qDebug() << "BookList Length: " << BookList.length();

    // BookList lesen und auf TableWidget anzeigen
    for (int i=0; i < Rows; i++){
        // initialisieren
        for (int j=0; j < 6; j++){ // Spalten
            QTableWidgetItem *newItem = new QTableWidgetItem("");
            ui->BookTableWidget->setItem(i, j, newItem);
        }

        // Book aus Liste laden
        Book NewBook = BookList[i];

        // Variablen aus Person in TableWidget eintragen
        int number = NewBook.getNumber();
        QString NumberString = QString::number(number);
        QTableWidgetItem *newItem = new QTableWidgetItem(NumberString);
        ui->BookTableWidget->setItem(i, 0, newItem);

        newItem = new QTableWidgetItem(NewBook.getTitle());
        ui->BookTableWidget->setItem(i, 1, newItem);

        newItem = new QTableWidgetItem(NewBook.getAuthor());
        ui->BookTableWidget->setItem(i, 2, newItem);

        int year = NewBook.getYear();
        QString YearString = QString::number(year);
        newItem = new QTableWidgetItem(YearString);
        ui->BookTableWidget->setItem(i, 3, newItem);

        int pages = NewBook.getPages();
        QString PagesString = QString::number(pages);
        newItem = new QTableWidgetItem(PagesString);
        ui->BookTableWidget->setItem(i, 4, newItem);

        newItem = new QTableWidgetItem(NewBook.getPublisher());
        ui->BookTableWidget->setItem(i, 5, newItem);
    }
}

#endif //MANAGEBOOK_H
