#include "saveloaddialog.h"
#include "ui_saveloaddialog.h"
#include <QFileDialog>
#include <QFileInfo>
#include <QDebug>
#include <QList>
#include <QMessageBox>
//#include <iostream>
#include <fstream>

//#include <cstdio>
//#include <string>

extern QList<Person> PersonList;
extern QList<Book> BookList;
extern QList<CD> CDList;
extern QList<Lend> LendList;

extern QString LendPath;
extern QString BookPath;
extern QString CDPath;
extern QString PersonPath;

SaveLoadDialog::SaveLoadDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SaveLoadDialog)
{
    ui->setupUi(this);
    ui->LendPathTextBox->setText(LendPath);
    ui->BookPathTextBox->setText(BookPath);
    ui->CDPathTextBox->setText(CDPath);
    ui->PersonPathTextBox->setText(PersonPath);
    //qDebug() << "Pfade: " << LendPath << BookPath << CDPath << PersonPath;

    #ifdef Q_OS_WIN
    this->setWindowIcon(QIcon(":WindowsIcons/Save.png"));
    #endif

}

SaveLoadDialog::~SaveLoadDialog()
{
    delete ui;
}

Lend SaveLoadDialog::ReadLendDataString(QString str){
    Lend lend;
    // Aufsplitten
    QStringList strParts = str.split("|");

    // Teile in Lend schreiben
    lend.setNumber(strParts[0].toInt());
    lend.setPersonNumber(strParts[1].toInt());
    lend.setPersonName(strParts[2]);
    lend.setMediaNumber(strParts[3].toInt());
    lend.setMediaTitle(strParts[4]);
    lend.setMediaType(strParts[5]);
    lend.setLendDate(strParts[6]);

    return lend;
}

Book SaveLoadDialog::ReadBookDataString(QString str){
    Book book;
    // Aufsplitten
    QStringList strParts = str.split("|");

    // Teile in Book schreiben
    book.setNumber(strParts[0].toInt());
    book.setTitle(strParts[1]);
    book.setAuthor(strParts[2]);
    book.setYear(strParts[3].toInt());
    book.setPages(strParts[4].toInt());
    book.setPublisher(strParts[5]);

    return book;
}

CD SaveLoadDialog::ReadCDDataString(QString str){
    CD cd;
    // Aufsplitten
    QStringList strParts = str.split("|");

    // Teile in Book schreiben
    cd.setNumber(strParts[0].toInt());
    cd.setTitle(strParts[1]);
    cd.setAuthor(strParts[2]);
    cd.setYear(strParts[3].toInt());
    cd.setDuration(strParts[4].toInt());
    cd.setGenre(strParts[5]);
    cd.setPublisher(strParts[6]);

    return cd;
}

Person SaveLoadDialog::ReadPersonDataString(QString str){
    Person person;
    // Aufsplitten
    QStringList strParts = str.split("|");

    // Teile in Book schreiben
    person.setNumber(strParts[0].toInt());
    person.setName(strParts[1]);
    person.setAddress(strParts[2]);
    person.setAge(strParts[3].toInt());
    person.setPhoneNumber(strParts[4]);

    return person;
}

QString SaveLoadDialog::MakeLendDataString(int Index){
    Lend lend;
    lend = LendList[Index];
    return QString::number(lend.getNumber()) + "|" + QString::number(lend.getPersonNumber()) + "|" + lend.getPersonName() + "|" + QString::number(lend.getMediaNumber()) + "|" + lend.getMediaTitle() + "|" + lend.getMediaType() + "|" + lend.getLendDate();

}

QString SaveLoadDialog::MakeBookDataString(int Index){
    Book book;
    book = BookList[Index];
    return QString::number(book.getNumber()) + "|" + book.getTitle() + "|" + book.getAuthor() + "|" + QString::number(book.getYear()) + "|" + QString::number(book.getPages()) + "|" + book.getPublisher();
}

QString SaveLoadDialog::MakeCDDataString(int Index){
    CD cd;
    cd = CDList[Index];
    return QString::number(cd.getNumber()) + "|" + cd.getTitle() + "|" + cd.getAuthor() + "|" + QString::number(cd.getYear()) + "|" + QString::number(cd.getDuration()) + "|" + cd.getGenre() + "|" + cd.getPublisher();
}

QString SaveLoadDialog::MakePersonDataString(int Index){
    Person person;
    person = PersonList[Index];
    return QString::number(person.getNumber()) + "|" + person.getName() + "|" + person.getAddress() + "|" + QString::number(person.getAge()) + "|" + person.getPhoneNumber();
}

void SaveLoadDialog::on_LendSelectPathButton_clicked(){
    QString fileName;
    if (this->windowTitle() == "Listen speichern"){
        fileName = QFileDialog::getSaveFileName(this, tr("Ausleihliste speichern"), "", tr("Listendateien (*.list);;Alle Dateien (*.*)"));
    }
    else if (this->windowTitle() == "Listen laden"){
        fileName = QFileDialog::getOpenFileName(this, tr("Ausleihliste öffnen"), "", tr("Listendateien (*.list);;Alle Dateien (*.*)"));
    }

    if (fileName == ""){ // Abgebrochen
        return;
    }

    if (!(fileName.endsWith(".list"))){ // gültige Dateiendung?
        QMessageBox::critical(nullptr, "Ausleihliste öffnen", "Ungültiger Dateityp!");
        return;
    }

    ui->LendPathTextBox->setText(fileName);
    LendPath = fileName;
}


void SaveLoadDialog::on_BookSelectPathButton_clicked(){
    QString fileName;
    if (this->windowTitle() == "Listen speichern"){
        fileName = QFileDialog::getSaveFileName(this, tr("Buchliste speichern"), "", tr("Listendateien (*.list);;Alle Dateien (*.*)"));
    }
    else if (this->windowTitle() == "Listen laden"){
        fileName = QFileDialog::getOpenFileName(this, tr("Buchliste öffnen"), "", tr("Listendateien (*.list);;Alle Dateien (*.*)"));
    }

    if (fileName == ""){ // Abgebrochen
        return;
    }

    if (!(fileName.endsWith(".list"))){ // gültige Dateiendung?
        QMessageBox::critical(nullptr, "Buchliste öffnen", "Ungültiger Dateityp!");
        return;
    }

    ui->BookPathTextBox->setText(fileName);
    BookPath = fileName;
}


void SaveLoadDialog::on_CDSelectPathButton_clicked(){
    QString fileName;
    if (this->windowTitle() == "Listen speichern"){
        fileName = QFileDialog::getSaveFileName(this, tr("CD-Liste speichern"), "", tr("Listendateien (*.list);;Alle Dateien (*.*)"));
    }
    else if (this->windowTitle() == "Listen laden"){
        fileName = QFileDialog::getOpenFileName(this, tr("CD-Liste öffnen"), "", tr("Listendateien (*.list);;Alle Dateien (*.*)"));
    }

    if (fileName == ""){ // Abgebrochen
        return;
    }

    if (!(fileName.endsWith(".list"))){ // gültige Dateiendung?
        QMessageBox::critical(nullptr, "CD-Liste öffnen", "Ungültiger Dateityp!");
        return;
    }

    ui->CDPathTextBox->setText(fileName);
    CDPath = fileName;

}


void SaveLoadDialog::on_PersonSelectPathButton_clicked(){
    QString fileName;
    if (this->windowTitle() == "Listen speichern"){
        fileName = QFileDialog::getSaveFileName(this, tr("Personenliste speichern"), "", tr("Listendateien (*.list);;Alle Dateien (*.*)"));
    }
    else if (this->windowTitle() == "Listen laden"){
        fileName = QFileDialog::getOpenFileName(this, tr("Personenliste öffnen"), "", tr("Listendateien (*.list);;Alle Dateien (*.*)"));
    }

    if (fileName == ""){ // Abgebrochen
        return;
    }

    if (!(fileName.endsWith(".list"))){ // gültige Dateiendung?
        QMessageBox::critical(nullptr, "Personenliste öffnen", "Ungültiger Dateityp!");
        return;
    }

    ui->PersonPathTextBox->setText(fileName);
    PersonPath = fileName;
}


void SaveLoadDialog::on_SaveLoadOKAbortButtons_accepted(){
    // Dateipfade lesen
    QString LendPath = ui->LendPathTextBox->text();
    QString BookPath = ui->BookPathTextBox->text();
    QString CDPath = ui->CDPathTextBox->text();
    QString PersonPath = ui->PersonPathTextBox->text();


    if (this->windowTitle() == "Listen speichern"){ // zu speichernde Dateien erstellen (versuchen), da sonst immer ungültiger Dateipfad Fehler
        std::ofstream OutFileStream;

        OutFileStream.open(LendPath.toStdString());
        OutFileStream.close();
        OutFileStream.open(BookPath.toStdString());
        OutFileStream.close();
        OutFileStream.open(CDPath.toStdString());
        OutFileStream.close();
        OutFileStream.open(PersonPath.toStdString());
        OutFileStream.close();

    }
    // Dateipfade überprüfen
    QFileInfo LendCheckFile(LendPath);
    QFileInfo BookCheckFile(BookPath);
    QFileInfo CDCheckFile(CDPath);
    QFileInfo PersonCheckFile(PersonPath);
    if ( (LendPath != "" && (!(LendCheckFile.exists() && LendCheckFile.isFile()))) ||
        (BookPath != "" && !(BookCheckFile.exists() && BookCheckFile.isFile())) ||
        (CDPath != "" && !(CDCheckFile.exists() && CDCheckFile.isFile())) ||
        (PersonPath != "" && !(PersonCheckFile.exists() && PersonCheckFile.isFile())) ) {
        QMessageBox::critical(nullptr, "Listen laden/speichern", "Ein oder mehrere Dateipfade sind ungültig!");
        return;
    }

    // Speichern oder laden?
    if (this->windowTitle() == "Listen speichern"){
        qDebug() << "==Liste Speichern==";


        QString Line;
        std::ofstream OutFileStream;

        // AUSLEIHE
        if (LendPath != ""){
            std::remove(LendPath.toStdString().c_str()); // Datei löschen

            OutFileStream.open(LendPath.toStdString(), std::ios_base::app); //anhängen

            // Ausleihe Zeile für Zeile in Datei speichern
            for (int i=0; i< LendList.length(); i++){
                Line = MakeLendDataString(i);
                OutFileStream << Line.toStdString() << std::endl;
            }
            OutFileStream.close();
        }

        // BUCH
        if (BookPath != ""){
            std::remove(BookPath.toStdString().c_str()); // Datei löschen

            OutFileStream.open(BookPath.toStdString(), std::ios_base::app); //anhängen

            // Ausleihe Zeile für Zeile in Datei speichern
            for (int i=0; i< BookList.length(); i++){
                Line = MakeBookDataString(i);
                OutFileStream << Line.toStdString() << std::endl;
            }
            OutFileStream.close();
        }

        // CD
        if (CDPath != ""){
            std::remove(CDPath.toStdString().c_str()); // Datei löschen

            OutFileStream.open(CDPath.toStdString(), std::ios_base::app); //anhängen

            // Ausleihe Zeile für Zeile in Datei speichern
            for (int i=0; i< CDList.length(); i++){
                Line = MakeCDDataString(i);
                OutFileStream << Line.toStdString() << std::endl;
            }
            OutFileStream.close();
        }

        // PERSON
        if (PersonPath != ""){
            std::remove(PersonPath.toStdString().c_str()); // Datei löschen

            OutFileStream.open(PersonPath.toStdString(), std::ios_base::app); //anhängen

            // Ausleihe Zeile für Zeile in Datei speichern
            for (int i=0; i< PersonList.length(); i++){
                Line = MakePersonDataString(i);
                OutFileStream << Line.toStdString() << std::endl;
            }
            OutFileStream.close();
        }


    }
    else if (this->windowTitle() == "Listen laden"){
        qDebug() << "==Liste laden==";
        std::string Line = "";
        QString QLine = "";

        std::ifstream InFileStream;
        qDebug() << "HELLO";

        // AUSLEIHE
        if (LendPath != ""){
            Lend lend;
            InFileStream.open(LendPath.toStdString().c_str()); // Lesemodus

            LendList.clear();
            while (std::getline(InFileStream, Line)){
                QLine = QString::fromStdString(Line);
                qDebug() << "ReadLine: " << QLine;
                lend = ReadLendDataString(QLine);
                qDebug() << "ReadLendObj: ";
                lend.PrintLend();
                LendList.append(lend);
            }
            InFileStream.close();
        }

        // BUCH
        if (BookPath != ""){
            Book book;
            InFileStream.open(BookPath.toStdString()); // Lesemodus

            BookList.clear();
            while (std::getline(InFileStream, Line)){
                QLine = QString::fromStdString(Line);
                qDebug() << "ReadLine: " << QLine;
                book = ReadBookDataString(QLine);
                qDebug() << "ReadLendObj: ";
                book.PrintBook();
                BookList.append(book);
            }
            InFileStream.close();
        }

        // CD
        if (CDPath != ""){
            CD cd;
            InFileStream.open(CDPath.toStdString()); // Lesemodus

            CDList.clear();
            while (std::getline(InFileStream, Line)){
                QLine = QString::fromStdString(Line);
                qDebug() << "ReadLine: " << QLine;
                cd = ReadCDDataString(QLine);
                qDebug() << "ReadLendObj: ";
                cd.PrintCD();
                CDList.append(cd);
            }
            InFileStream.close();
        }

        // PERSON
        if (PersonPath != ""){
            Person person;
            InFileStream.open(PersonPath.toStdString()); // Lesemodus

            PersonList.clear();
            while (std::getline(InFileStream, Line)){
                QLine = QString::fromStdString(Line);
                qDebug() << "ReadLine: " << QLine;
                person = ReadPersonDataString(QLine);
                qDebug() << "ReadLendObj: ";
                person.PrintPerson();
                PersonList.append(person);
            }
            InFileStream.close();
        }
    }
    accept();
}


void SaveLoadDialog::on_SaveLoadOKAbortButtons_rejected(){
    reject();
}

