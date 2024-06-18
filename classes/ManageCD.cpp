#ifndef MANAGECD_H
#define MANAGECD_H
#include "ManageCD.h"
#include "CD.h"
#include "../ui_mainwindow.h"
#include "../ui_addlenddialog.h"

#include <QTableWidget>
#include <QMessageBox>
#include <QStyleFactory>
#include <QApplication>
#include <QDebug>
#include <QList>
#include <QDate>

extern QList<CD> CDList;

void ManageCD::AddCD(Ui::MainWindow *ui){
    // Neue Zeile hinzufügen
    int newRow = ui->CDTableWidget->rowCount();
    ui->CDTableWidget->insertRow(newRow);

    // initialisieren
    for (int i=0; i < 6; i++){ // Spalten
        QTableWidgetItem *newItem = new QTableWidgetItem("");
        ui->CDTableWidget->setItem(newRow, i, newItem);
    }
}

void ManageCD::DeleteCD(Ui::MainWindow *ui){
    // Aktuell ausgewählte Zeile löschen
    int currentRow = ui->CDTableWidget->currentRow();

    if (currentRow == -1){
        QMessageBox::warning(nullptr, "CD löschen", "Keine Zeile zum Löschen ausgewählt!");
    }
    ui->CDTableWidget->removeRow(currentRow);
}

void ManageCD::SaveCDTable(Ui::MainWindow *ui){
    int Rows = ui->CDTableWidget->rowCount();
    if (Rows < 1){
        QMessageBox::warning(nullptr, "CDs speichern", "Tabelle leer!");
        return;
    }

    QList<CD> TempCDList = CDList;
    // Liste löschen
    CDList.clear();

    for (int i=0; i < ui->CDTableWidget->rowCount(); i++){ // Zeilen
        // Zellen leer? (Segfault verhindern ;)!)
        if (ui->CDTableWidget->item(i, 0)->text().isEmpty() ||
            ui->CDTableWidget->item(i, 1)->text().isEmpty() ||
            ui->CDTableWidget->item(i, 2)->text().isEmpty() ||
            ui->CDTableWidget->item(i, 3)->text().isEmpty() ||
            ui->CDTableWidget->item(i, 4)->text().isEmpty() ||
            ui->CDTableWidget->item(i, 5)->text().isEmpty() ||
            ui->CDTableWidget->item(i, 6)->text().isEmpty()) {
            CDList = TempCDList;
            QMessageBox::warning(nullptr, "CDs speichern", "Es gibt noch leere Zellen!");
            return;
        }

        // Strings bei Integern eingetragen?
        QString NumberText = ui->CDTableWidget->item(i, 0)->text();
        QString YearText = ui->CDTableWidget->item(i, 3)->text();
        QString DurationText = ui->CDTableWidget->item(i, 4)->text();

        bool ConversionOk = true; // flag wird auf false gesetzt, falls String zu Int konvertiert wird
        NumberText.toInt(&ConversionOk);
        if (ConversionOk != true){
            CDList = TempCDList;
            QMessageBox::warning(nullptr, "CDs speichern", "Bitte Spalte CD-Nr. überprüfen! Es dürfen dort nur Zahlen drinstehen.");
            return;
        }
        YearText.toInt(&ConversionOk);
        if (ConversionOk != true){
            CDList = TempCDList;
            QMessageBox::warning(nullptr, "CDs speichern", "Bitte Spalte Jahr überprüfen! Es dürfen dort nur Zahlen drinstehen.");
            return;
        }
        DurationText.toInt(&ConversionOk);
        if (ConversionOk != true){
            CDList = TempCDList;
            QMessageBox::warning(nullptr, "CDs speichern", "Bitte Spalte Dauer (min) überprüfen! Es dürfen dort nur Zahlen drinstehen.");
            return;
        }

        // Keine Fehler für die aktuelle Spalte gefunden -> fahre fort...
        CD NewCD;

        // Daten aus TableWidget lesen und in NewCD schreiben
        NewCD.setNumber(ui->CDTableWidget->item(i, 0)->text().toInt());
        NewCD.setTitle(ui->CDTableWidget->item(i, 1)->text());
        NewCD.setAuthor(ui->CDTableWidget->item(i, 2)->text());
        NewCD.setYear(ui->CDTableWidget->item(i, 3)->text().toInt());
        NewCD.setDuration(ui->CDTableWidget->item(i, 4)->text().toInt());
        NewCD.setGenre(ui->CDTableWidget->item(i, 5)->text());
        NewCD.setPublisher(ui->CDTableWidget->item(i, 6)->text());

        //NewCD.PrintCD();
        CDList.append(NewCD); //An Liste anhängen

        qDebug() << "Inhalt der CDList:";
        for (auto &pers : CDList) {
            pers.PrintCD();
        }
    }
}

void ManageCD::LoadCDTable(Ui::MainWindow *ui){
    qDebug() << "==CD==";
    // automatisches Laden aus der Liste (falls vorhanden)
    int Rows = CDList.length();

    ui->CDTableWidget->clearContents();
    ui->CDTableWidget->setRowCount(CDList.length());

    if (Rows < 1){
        qDebug() << "Liste leer!";
        return;
    }

    qDebug() << "CDList Length: " << CDList.length();

    // CDList lesen und auf TableWidget anzeigen
    for (int i=0; i < Rows; i++){
        // initialisieren
        for (int j=0; j < 7; j++){ // Spalten
            QTableWidgetItem *newItem = new QTableWidgetItem("");
            ui->CDTableWidget->setItem(i, j, newItem);
        }

        // CD aus Liste laden
        CD NewCD = CDList[i];

        // Variablen aus Person in TableWidget eintragen
        int number = NewCD.getNumber();
        QString NumberString = QString::number(number);
        QTableWidgetItem *newItem = new QTableWidgetItem(NumberString);
        ui->CDTableWidget->setItem(i, 0, newItem);

        newItem = new QTableWidgetItem(NewCD.getTitle());
        ui->CDTableWidget->setItem(i, 1, newItem);

        newItem = new QTableWidgetItem(NewCD.getAuthor());
        ui->CDTableWidget->setItem(i, 2, newItem);

        int year = NewCD.getYear();
        QString YearString = QString::number(year);
        newItem = new QTableWidgetItem(YearString);
        ui->CDTableWidget->setItem(i, 3, newItem);

        int duration = NewCD.getDuration();
        QString DurationString = QString::number(duration);
        newItem = new QTableWidgetItem(DurationString);
        ui->CDTableWidget->setItem(i, 4, newItem);

        newItem = new QTableWidgetItem(NewCD.getGenre());
        ui->CDTableWidget->setItem(i, 5, newItem);

        newItem = new QTableWidgetItem(NewCD.getPublisher());
        ui->CDTableWidget->setItem(i, 6, newItem);
    }
}

void ManageCD::LoadCDTable(Ui::AddLendDialog *ui){
    qDebug() << "==CD==";
    // automatisches Laden aus der Liste (falls vorhanden)
    int Rows = CDList.length();

    ui->CDTableWidget->clearContents();
    ui->CDTableWidget->setRowCount(CDList.length());

    if (Rows < 1){
        qDebug() << "Liste leer!";
        return;
    }

    qDebug() << "CDList Length: " << CDList.length();

    // CDList lesen und auf TableWidget anzeigen
    for (int i=0; i < Rows; i++){
        // initialisieren
        for (int j=0; j < 7; j++){ // Spalten
            QTableWidgetItem *newItem = new QTableWidgetItem("");
            ui->CDTableWidget->setItem(i, j, newItem);
        }

        // CD aus Liste laden
        CD NewCD = CDList[i];

        // Variablen aus Person in TableWidget eintragen
        int number = NewCD.getNumber();
        QString NumberString = QString::number(number);
        QTableWidgetItem *newItem = new QTableWidgetItem(NumberString);
        ui->CDTableWidget->setItem(i, 0, newItem);

        newItem = new QTableWidgetItem(NewCD.getTitle());
        ui->CDTableWidget->setItem(i, 1, newItem);

        newItem = new QTableWidgetItem(NewCD.getAuthor());
        ui->CDTableWidget->setItem(i, 2, newItem);

        int year = NewCD.getYear();
        QString YearString = QString::number(year);
        newItem = new QTableWidgetItem(YearString);
        ui->CDTableWidget->setItem(i, 3, newItem);

        int duration = NewCD.getDuration();
        QString DurationString = QString::number(duration);
        newItem = new QTableWidgetItem(DurationString);
        ui->CDTableWidget->setItem(i, 4, newItem);

        newItem = new QTableWidgetItem(NewCD.getGenre());
        ui->CDTableWidget->setItem(i, 5, newItem);

        newItem = new QTableWidgetItem(NewCD.getPublisher());
        ui->CDTableWidget->setItem(i, 6, newItem);
    }
}

#endif //MANAGECD_H
