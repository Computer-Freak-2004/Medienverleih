#include "mainwindow.h"
#include "../ui_mainwindow.h"
#include "addlenddialog.h"
#include "../ui_addlenddialog.h"
#include <QTableWidget>
#include <QMessageBox>
#include <QStyleFactory>
#include <QActionGroup>
#include <QStyle>
#include <QApplication>
#include <QDebug>
#include <QList>
#include <QDate>
#include "../classes/Person.h"
#include "../classes/Book.h"
#include "../classes/CD.h"
#include "../classes/Lend.h"

extern QList<Person> PersonList;
extern QList<Book> BookList;
extern QList<CD> CDList;
extern QList<Lend> LendList;

extern QString Ver;
extern int PersonRow;
extern int MediaType; //0= Book, 1=CD
extern int BookRow;
extern int CDRow;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Radiobuttons für Themes
    QActionGroup *radioGroup = new QActionGroup(this);
    radioGroup->addAction(ui->actionDark_Theme);
    radioGroup->addAction(ui->actionDefault_Theme);


    QStringList PersonCols({"Person-Nr.", "Name", "Adresse", "Alter", "Telefonnr."});
    ui->PersonTableWidget->setColumnCount(PersonCols.length());
    ui->PersonTableWidget->setHorizontalHeaderLabels(PersonCols);
    ui->PersonTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    QStringList BookCols({"Buch-Nr.", "Titel", "Autor", "Jahr", "Seiten", "Verlag"});
    ui->BookTableWidget->setColumnCount(BookCols.length());
    ui->BookTableWidget->setHorizontalHeaderLabels(BookCols);
    ui->BookTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);


    QStringList CDCols({"CD-Nr.", "Titel", "Autor", "Jahr", "Dauer (min)", "Genre", "Verlag"});
    ui->CDTableWidget->setColumnCount(CDCols.length());
    ui->CDTableWidget->setHorizontalHeaderLabels(CDCols);
    ui->CDTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    QStringList lendCols({"Ausleih-Nr.", "Person-Nr.", "Person-Name", "Medien-Nr.", "Medien-Titel", "Medientyp", "Ausleihdatum"});
    ui->LendTableWidget->setColumnCount(lendCols.length());
    ui->LendTableWidget->setHorizontalHeaderLabels(lendCols);
    ui->LendTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // Beispieldaten einfügen

    // Daten für Personen
    QList<QList<QVariant>> personData = {
        {1, "John Doe", "123 Elm Street", 30, "555-1234"},
        {2, "Jane Smith", "456 Oak Avenue", 25, "555-5678"},
        {3, "Emily Davis", "789 Pine Road", 28, "555-8765"}
    };

    // Personen hinzufügen
    for (const QList<QVariant>& data : personData) {
        Person person;
        person.setNumber(data[0].toInt());
        person.setName(data[1].toString());
        person.setAddress(data[2].toString());
        person.setAge(data[3].toInt());
        person.setPhoneNumber(data[4].toString());
        PersonList.append(person);
    }

    // Daten für Bücher
    QList<QList<QVariant>> bookData = {
        {101, "C++ Programming", "Bjarne Stroustrup", 2013, 1366, "Addison-Wesley"},
        {102, "Effective Modern C++", "Scott Meyers", 2014, 334, "O'Reilly Media"},
        {103, "Clean Code", "Robert C. Martin", 2008, 464, "Prentice Hall"}
    };

    // Bücher hinzufügen
    for (const QList<QVariant>& data : bookData) {
        Book book;
        book.setNumber(data[0].toInt());
        book.setTitle(data[1].toString());
        book.setAuthor(data[2].toString());
        book.setYear(data[3].toInt());
        book.setPages(data[4].toInt());
        book.setPublisher(data[5].toString());
        BookList.append(book);
    }

    // Daten für CDs
    QList<QList<QVariant>> cdData = {
        {201, "The Dark Side of the Moon", "Pink Floyd", 1973, 42, "Progressive Rock", "Harvest Records"},
        {202, "Thriller", "Michael Jackson", 1982, 42, "Pop", "Epic Records"},
        {203, "Back in Black", "AC/DC", 1980, 41, "Hard Rock", "Albert/Atlantic"}
    };

    // CDs hinzufügen
    for (const QList<QVariant>& data : cdData) {
        CD cd;
        cd.setNumber(data[0].toInt());
        cd.setTitle(data[1].toString());
        cd.setAuthor(data[2].toString());
        cd.setYear(data[3].toInt());
        cd.setDuration(data[4].toInt());
        cd.setGenre(data[5].toString());
        cd.setPublisher(data[6].toString());
        CDList.append(cd);
    }
    ui->MainStatusbar->showMessage("Bereit");


}

MainWindow::~MainWindow(){
    delete ui;
}

// ========= AUSLEIHE =========
void MainWindow::on_AddNewLendButton_clicked(){
    AddLendDialog *dialog = new AddLendDialog(this);
    // Funktionen verbinden, wenn OK, Abbrechen gedrückt
    connect(dialog, &QDialog::accepted, this, &MainWindow::acceptSlot);
    connect(dialog, &QDialog::rejected, this, &MainWindow::rejectSlot);
    dialog->show();
}

void MainWindow::acceptSlot(){ // Dialog: OK gedrückt

    //QMessageBox::warning(nullptr, "Dialog", "Gewählt:\nPerson: " + QString::number(PersonRow) + "| Book: " + QString::number(BookRow) + "| CD: " + QString::number(CDRow) + "| MediaType: " + QString::number(MediaType));

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

    // Variablen zurücksetzen
    MediaType = 0;
    PersonRow = -1;
    BookRow = -1;
    CDRow = -1;

}

void MainWindow::rejectSlot(){ // Dialog: Abbrechen gedrückt
    // Do nothing
}

void MainWindow::on_DeleteLendButton_clicked(){
    // Aktuell ausgewählte Zeile löschen
    int currentRow = ui->LendTableWidget->currentRow();

    if (currentRow == -1){
        QMessageBox::warning(nullptr, "Zurückgeben", "Keine Zeile zum Zurückgeben ausgewählt!");
    }
    ui->LendTableWidget->removeRow(currentRow);
}

void MainWindow::on_SaveLendTableButton_clicked(){
    int Rows = ui->LendTableWidget->rowCount();
    if (Rows < 1){
        QMessageBox::warning(nullptr, "Ausleihe speichern", "Tabelle leer!");
        return;
    }

    QList<Lend> TempLendList = LendList;
    // Liste löschen
    LendList.clear();

    for (int i=0; i < ui->LendTableWidget->rowCount(); i++){ // Zeilen
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

// ========= PERSON ==========
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

// ======= MEDIEN-BUCH =========
void MainWindow::on_AddBookButton_clicked(){
    // Neue Zeile hinzufügen
    int newRow = ui->BookTableWidget->rowCount();
    ui->BookTableWidget->insertRow(newRow);

    // initialisieren
    for (int i=0; i < 5; i++){ // Spalten
        QTableWidgetItem *newItem = new QTableWidgetItem("");
        ui->BookTableWidget->setItem(newRow, i, newItem);
    }
}


void MainWindow::on_DeleteBookButton_clicked(){
    // Aktuell ausgewählte Zeile löschen
    int currentRow = ui->BookTableWidget->currentRow();

    if (currentRow == -1){
        QMessageBox::warning(nullptr, "Buch löschen", "Keine Zeile zum Löschen ausgewählt!");
    }
    ui->BookTableWidget->removeRow(currentRow);

}

void MainWindow::on_SaveBookTableButton_clicked(){
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

// ======= MEDIEN-CD =========

void MainWindow::on_AddCDButton_clicked(){
    // Neue Zeile hinzufügen
    int newRow = ui->CDTableWidget->rowCount();
    ui->CDTableWidget->insertRow(newRow);

    // initialisieren
    for (int i=0; i < 6; i++){ // Spalten
        QTableWidgetItem *newItem = new QTableWidgetItem("");
        ui->CDTableWidget->setItem(newRow, i, newItem);
    }

}

void MainWindow::on_DeleteCDButton_clicked(){
    // Aktuell ausgewählte Zeile löschen
    int currentRow = ui->CDTableWidget->currentRow();

    if (currentRow == -1){
        QMessageBox::warning(nullptr, "CD löschen", "Keine Zeile zum Löschen ausgewählt!");
    }
    ui->CDTableWidget->removeRow(currentRow);
}

void MainWindow::on_SaveCDTableButton_clicked(){
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


void MainWindow::on_MainTabWidget_currentChanged(int index) // bei Tabwechsel richtige Liste laden
{
    if (index == 0){ // Ausleihe
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

            // Variablen aus Person in TableWidget eintragen
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
    else if (index == 1){ // Medien
        qDebug() << "==Medien==";
        // Buch

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

        // CD
        qDebug() << "==CD==";
        // automatisches Laden aus der Liste (falls vorhanden)
        Rows = CDList.length();

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
    else if (index == 2){ // Personen
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
}

void MainWindow::on_actionBeenden_triggered(){
    exit(0);
}

// Themes eigentlich für Windows gedacht
// https://gist.github.com/QuantumCD/6245215
void MainWindow::on_actionDefault_Theme_triggered(){
    #ifdef Q_OS_WIN // Windows
        qApp->setStyle("Fusion");
    #else // Linux
        qApp->setStyle("gtk2");
    #endif

    qApp->setPalette(qApp->style()->standardPalette());
    qApp->setStyleSheet(""); // Reset the style sheet

}

void MainWindow::on_actionDark_Theme_triggered(){
    #ifdef Q_OS_WIN // Windows
    qApp->setStyle("Fusion");
    #else // Linux
    qApp->setStyle("gtk2");
    #endif
    qApp->setStyle(QStyleFactory::create("defaultStyle"));

    QPalette darkPalette;
    darkPalette.setColor(QPalette::Window, QColor(53,53,53));
    darkPalette.setColor(QPalette::WindowText, Qt::white);
    darkPalette.setColor(QPalette::Base, QColor(25,25,25));
    darkPalette.setColor(QPalette::AlternateBase, QColor(53,53,53));
    darkPalette.setColor(QPalette::ToolTipBase, Qt::white);
    darkPalette.setColor(QPalette::ToolTipText, Qt::white);
    darkPalette.setColor(QPalette::Text, Qt::white);
    darkPalette.setColor(QPalette::Button, QColor(53,53,53));
    darkPalette.setColor(QPalette::ButtonText, Qt::white);
    darkPalette.setColor(QPalette::BrightText, Qt::red);
    darkPalette.setColor(QPalette::Link, QColor(42, 130, 218));

    darkPalette.setColor(QPalette::Highlight, QColor(42, 130, 218));
    darkPalette.setColor(QPalette::HighlightedText, Qt::black);

    qApp->setPalette(darkPalette);

    qApp->setStyleSheet("QToolTip { color: #ffffff; background-color: #2a82da; border: 1px solid white; }");
}

void MainWindow::on_action_ber_triggered(){
    QMessageBox::information(nullptr, "Über...", ""
                                                 "Erstellt von: Eric H.\n"
                                                 "Datum: 15.08. - 17.06.2024\n"
                                                 "Version: " + Ver +
                                                 "\n\n"
                                                 "Versionsgeschichte:\n"
                                                 "Ver 0.3 (15.06.): erste GUI, Klasse Person hinzugefügt (hinzufügen, bearbeiten, löschen, itern laden/speichern)\n"
                                                 "Ver 0.5 (16.06.): Fehlerkorrektur, Klasse Medium -> Buch & CD hinzugefügt, Symbole & Statusbar-Tipps hinzugefügt, Dark Theme\n"
                                                 "Ver 0.7 (17.06.): Fehlerkorrektur, Ausleihe programmiert mit Extra-Dialog, Klasse Lend hinzugefügt");
}

