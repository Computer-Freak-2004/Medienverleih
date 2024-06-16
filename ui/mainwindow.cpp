#include "mainwindow.h"
#include "../ui_mainwindow.h"
#include <QTableWidget>
#include <QMessageBox>
#include <QDebug>
#include <QList>
#include "classes/Person.h"

// Liste aller Personen
QList<Person> PersonList;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QStringList PersonCols({"Person-Nr", "Name", "Adresse", "Alter", "Telefonr."});
    ui->PersonTableWidget->setColumnCount(PersonCols.length());
    ui->PersonTableWidget->setHorizontalHeaderLabels(PersonCols);
    ui->PersonTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // Beispiel-Daten einfügen
    QList<QList<QVariant>> data = {
        {1, "Max Mustermann","Teststr. 1", 30, "123456789"},
        {2, "Anna Müller","Teststr. 2", 25, "69420"},
        {3, "Peter Schmidt","Teststr. 3", 40, "987654321"}
    };


    ui->PersonTableWidget->setRowCount(data.length());

    for (int i=0; i < data.length(); i++){ // Zeilen
        for (int j=0; j < 5; j++){ // Spalten
            qDebug() << "I: " << i << " J: " << j << " Data:" << data[i][j].toString();
            QTableWidgetItem *newItem = new QTableWidgetItem(data[i][j].toString());
            ui->PersonTableWidget->setItem(i, j, newItem);
        }
    }
}

MainWindow::~MainWindow(){
    delete ui;
}



void MainWindow::on_ShowPersonTableButton_clicked(){
    ui->PersonTableWidget->clearContents();

    qDebug() << "PersonList Length: " << PersonList.length();

    // PersonList lesen und auf TableWidget anzeigen
    for (int i=0; i < PersonList.length(); i++){
        ui->PersonTableWidget->removeRow(i);
        ui->PersonTableWidget->insertRow(i);

        // initialisieren
        for (int j=0; j < 5; j++){ // Spalten
        QTableWidgetItem *newItem = new QTableWidgetItem("");
        ui->PersonTableWidget->setItem(i, j, newItem);
    }

        Person NewPerson = PersonList[i];


        int number = NewPerson.getNumber();
        QString NumberString = QString::number(number);
        QTableWidgetItem *newItem = new QTableWidgetItem(NumberString);
        ui->PersonTableWidget->setItem(i, 0, newItem);


        newItem = new QTableWidgetItem(NewPerson.getName());
        ui->PersonTableWidget->setItem(i, 1, newItem);

        newItem = new QTableWidgetItem(NewPerson.getAddress());
        ui->PersonTableWidget->setItem(i, 2, newItem);

        int age = NewPerson.getAge();
        QString AgeString = QString::number(age);
        newItem = new QTableWidgetItem(AgeString);
        ui->PersonTableWidget->setItem(i, 3, newItem);

        newItem = new QTableWidgetItem(NewPerson.getPhoneNumber());
        ui->PersonTableWidget->setItem(i, 4, newItem);


    }
}


void MainWindow::on_AddPersonButton_clicked(){
    // Neue Zeile hinzufügen
    int newRow = ui->PersonTableWidget->rowCount();
    ui->PersonTableWidget->insertRow(newRow);

    // initialisieren
    for (int i=0; i < 5; i++){ // Spalten
        QTableWidgetItem *newItem = new QTableWidgetItem("");
        ui->PersonTableWidget->setItem(newRow, i, newItem);
    }
}


void MainWindow::on_DeletePersonButton_clicked(){
    // Aktuell ausgewählte Zeile löschen
    int currentRow = ui->PersonTableWidget->currentRow();

    if (currentRow == -1){
        QMessageBox::warning(nullptr, "Person löschen", "Keine Zeile zum Löschen ausgewählt!");
    }
    ui->PersonTableWidget->removeRow(currentRow);
}

void MainWindow::on_SavePersonTableButton_clicked(){
    // Liste löschen
    PersonList.clear();

    for (int i=0; i < ui->PersonTableWidget->rowCount(); i++){ // Zeilen
        // Zellen leer? (Segfault verhindern ;)!)
        if (ui->PersonTableWidget->item(i, 0)->text().isEmpty() ||
            ui->PersonTableWidget->item(i, 1)->text().isEmpty() ||
            ui->PersonTableWidget->item(i, 2)->text().isEmpty() ||
            ui->PersonTableWidget->item(i, 3)->text().isEmpty() ||
            ui->PersonTableWidget->item(i, 4)->text().isEmpty()) {
            qDebug() << "HELLO";
            QMessageBox::warning(nullptr, "Personen speichern", "Es gibt noch leere Zellen!");
            return;
        }

        // Strings bei Integern eingetragen?
        QString NumberText = ui->PersonTableWidget->item(i, 0)->text();
        QString AgeText = ui->PersonTableWidget->item(i, 3)->text();
        QString PhoneNumberText = ui->PersonTableWidget->item(i, 4)->text();

        bool ConversionOk = true; // flag wird auf false gesetzt, falls String zu Int konvertiert wird
        int Number = NumberText.toInt(&ConversionOk);
        if (ConversionOk != true){
            QMessageBox::warning(nullptr, "Personen speichern", "Bitte Spalte PersonenNr. überprüfen! Es dürfen dort nur Zahlen drinstehen.");
            return;
        }
        int Age = AgeText.toInt(&ConversionOk);
        if (ConversionOk != true){
            QMessageBox::warning(nullptr, "Personen speichern", "Bitte Spalte Alter überprüfen! Es dürfen dort nur Zahlen drinstehen.");
            return;
        }

        // Keine Fehler für die aktuelle Spalte gefunden -> fahre fort...
        Person NewPerson;

        // Daten aus TableWidget lesen und in Person schreiben
        NewPerson.setNumber(ui->PersonTableWidget->item(i, 0)->text().toInt());
        NewPerson.setName(ui->PersonTableWidget->item(i, 1)->text());
        NewPerson.setAddress(ui->PersonTableWidget->item(i, 2)->text());
        NewPerson.setAge(ui->PersonTableWidget->item(i, 3)->text().toInt());
        NewPerson.setPhoneNumber(ui->PersonTableWidget->item(i, 4)->text());

        NewPerson.PrintPerson();
        PersonList.append(NewPerson); //An Liste anhängen

        qDebug() << "Inhalt der PersonList:";
        for (auto &pers : PersonList) {
            pers.PrintPerson();
        }
    }
}

