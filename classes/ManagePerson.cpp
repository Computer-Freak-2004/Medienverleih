#ifndef MANAGEPERSON_H
#define MANAGEPERSON_H
#include "ManagePerson.h"
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

void ManagePerson::AddPerson(Ui::MainWindow *ui){
    // Neue Zeile hinzufügen
    int newRow = ui->PersonTableWidget->rowCount();
    ui->PersonTableWidget->insertRow(newRow);

    // initialisieren
    for (int i=0; i < 5; i++){ // Spalten
        QTableWidgetItem *newItem = new QTableWidgetItem("");
        ui->PersonTableWidget->setItem(newRow, i, newItem);
    }
}

void ManagePerson::DeletePerson(Ui::MainWindow *ui){
    // Aktuell ausgewählte Zeile löschen
    int currentRow = ui->PersonTableWidget->currentRow();

    if (currentRow == -1){
        QMessageBox::warning(nullptr, "Person löschen", "Keine Zeile zum Löschen ausgewählt!");
    }
    ui->PersonTableWidget->removeRow(currentRow);
}

void ManagePerson::SavePersonTable(Ui::MainWindow *ui){
    int Rows = ui->PersonTableWidget->rowCount();
    if (Rows < 1){
        QMessageBox::warning(nullptr, "Personen speichern", "Tabelle leer!");
        return;
    }

    QList<Person> TempPersonList = PersonList;
    // Liste löschen
    PersonList.clear();

    for (int i=0; i < ui->PersonTableWidget->rowCount(); i++){ // Zeilen
        // Zellen leer? (Segfault verhindern ;)!)
        if (ui->PersonTableWidget->item(i, 0)->text().isEmpty() ||
            ui->PersonTableWidget->item(i, 1)->text().isEmpty() ||
            ui->PersonTableWidget->item(i, 2)->text().isEmpty() ||
            ui->PersonTableWidget->item(i, 3)->text().isEmpty() ||
            ui->PersonTableWidget->item(i, 4)->text().isEmpty()) {
            PersonList = TempPersonList;
            QMessageBox::warning(nullptr, "Personen speichern", "Es gibt noch leere Zellen!");
            return;
        }

        // Strings bei Integern eingetragen?
        QString NumberText = ui->PersonTableWidget->item(i, 0)->text();
        QString AgeText = ui->PersonTableWidget->item(i, 3)->text();

        bool ConversionOk = true; // flag wird auf false gesetzt, falls String zu Int konvertiert wird
        NumberText.toInt(&ConversionOk);
        if (ConversionOk != true){
            PersonList = TempPersonList;
            QMessageBox::warning(nullptr, "Personen speichern", "Bitte Spalte PersonenNr. überprüfen! Es dürfen dort nur Zahlen drinstehen.");
            return;
        }
        AgeText.toInt(&ConversionOk);
        if (ConversionOk != true){
            PersonList = TempPersonList;
            QMessageBox::warning(nullptr, "Personen speichern", "Bitte Spalte Alter überprüfen! Es dürfen dort nur Zahlen drinstehen.");
            return;
        }

        // Keine Fehler für die aktuelle Spalte gefunden -> fahre fort...
        Person NewPerson;

        // Daten aus TableWidget lesen und in NewPerson schreiben
        NewPerson.setNumber(ui->PersonTableWidget->item(i, 0)->text().toInt());
        NewPerson.setName(ui->PersonTableWidget->item(i, 1)->text());
        NewPerson.setAddress(ui->PersonTableWidget->item(i, 2)->text());
        NewPerson.setAge(ui->PersonTableWidget->item(i, 3)->text().toInt());
        NewPerson.setPhoneNumber(ui->PersonTableWidget->item(i, 4)->text());

        //NewPerson.PrintPerson();
        PersonList.append(NewPerson); //An Liste anhängen

        qDebug() << "Inhalt der PersonList:";
        for (auto &pers : PersonList) {
            pers.PrintPerson();
        }
    }
}

void ManagePerson::LoadPersonTable(Ui::MainWindow *ui){

    qDebug() << "==Personen==";
    // automatisches Laden aus der Liste (falls vorhanden)
    int Rows = PersonList.length();

    ui->PersonTableWidget->clearContents();
    ui->PersonTableWidget->setRowCount(PersonList.length());

    if (Rows < 1){
        qDebug() << "Liste leer!";
        return;
    }

    qDebug() << "PersonList Length: " << PersonList.length();

    // PersonList lesen und auf TableWidget anzeigen
    for (int i=0; i < Rows; i++){
        //ui->PersonTableWidget->removeRow(i);
        //ui->PersonTableWidget->insertRow(i);


        // initialisieren
        for (int j=0; j < 5; j++){ // Spalten
            QTableWidgetItem *newItem = new QTableWidgetItem("");
            ui->PersonTableWidget->setItem(i, j, newItem);
        }

        // Person aus Liste laden
        Person NewPerson = PersonList[i];

        // Variablen aus Person in TableWidget eintragen
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

void ManagePerson::LoadPersonTable(Ui::AddLendDialog *ui){ // überladene Fkt.

    qDebug() << "==Personen==";
    // automatisches Laden aus der Liste (falls vorhanden)
    int Rows = PersonList.length();

    ui->PersonTableWidget->clearContents();
    ui->PersonTableWidget->setRowCount(PersonList.length());

    if (Rows < 1){
        qDebug() << "Liste leer!";
        return;
    }

    qDebug() << "PersonList Length: " << PersonList.length();

    // PersonList lesen und auf TableWidget anzeigen
    for (int i=0; i < Rows; i++){
        //ui->PersonTableWidget->removeRow(i);
        //ui->PersonTableWidget->insertRow(i);


        // initialisieren
        for (int j=0; j < 5; j++){ // Spalten
            QTableWidgetItem *newItem = new QTableWidgetItem("");
            ui->PersonTableWidget->setItem(i, j, newItem);
        }

        // Person aus Liste laden
        Person NewPerson = PersonList[i];

        // Variablen aus Person in TableWidget eintragen
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
#endif //MANAGEPERSON_H
