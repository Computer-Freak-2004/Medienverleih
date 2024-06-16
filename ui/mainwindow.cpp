#include "mainwindow.h"
#include "../ui_mainwindow.h"
#include <QTableWidget>
#include <QMessageBox>
#include <QStyleFactory>
#include <QActionGroup>
#include <QStyle>
#include <QApplication>
#include <QDebug>
#include <QList>
#include "../classes/Person.h"
#include "../classes/Book.h"
#include "../classes/CD.h"

extern QList<Person> PersonList;
extern QList<Book> BookList;
extern QList<CD> CDList;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Radiobuttons für Themes
    QActionGroup *radioGroup = new QActionGroup(this);
    radioGroup->addAction(ui->actionDark_Theme);
    radioGroup->addAction(ui->actionDefault_Theme);

    QStringList PersonCols({"Person-Nr", "Name", "Adresse", "Alter", "Telefonr."});
    ui->PersonTableWidget->setColumnCount(PersonCols.length());
    ui->PersonTableWidget->setHorizontalHeaderLabels(PersonCols);
    ui->PersonTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // Person Beispieldaten einfügen
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
    // =====================================================================================================================
    QStringList BookCols({"Buch-Nr", "Titel", "Autor", "Jahr", "Seiten", "Verlag"});
    ui->BookTableWidget->setColumnCount(BookCols.length());
    ui->BookTableWidget->setHorizontalHeaderLabels(BookCols);
    ui->BookTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // Beispieldaten für Bücher
    QList<QList<QVariant>> bookData = {
        {1, "Der kleine Prinz", "Antoine de Saint-Exupéry", 1943, 96, "Reynal & Hitchcock"},
        {2, "Harry Potter und der Stein der Weisen", "J.K. Rowling", 1997, 336, "Bloomsbury"},
        {3, "Clean Code: A Handbook of Agile Software Craftsmanship", "Robert C. Martin", 2008, 464, "Prentice Hall"}
    };

     ui->BookTableWidget->setRowCount(bookData.length());

    for (int i = 0; i < bookData.size(); ++i) { // Zeilen
        for (int j = 0; j < BookCols.size(); ++j) { // Spalten
            qDebug() << "I: " << i << " J: " << j << " Data:" << bookData[i][j].toString();
            QTableWidgetItem *newItem = new QTableWidgetItem(bookData[i][j].toString());
             ui->BookTableWidget->setItem(i, j, newItem);
        }
    }
    // =====================================================================================================================
    QStringList CDCols({"CD-Nr", "Titel", "Autor", "Jahr", "Dauer (min)", "Genre", "Verlag"});
    ui->CDTableWidget->setColumnCount(CDCols.length());
    ui->CDTableWidget->setHorizontalHeaderLabels(CDCols);
    ui->CDTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    QList<QList<QVariant>> cdData = {
    {1, "Back in Black", "AC/DC", 1980, 42, "Rock", "Albert Productions"},
    {2, "Thriller", "Michael Jackson", 1982, 42, "Pop", "Epic Records"},
    {3, "The Dark Side of the Moon", "Pink Floyd", 1973, 43, "Progressive Rock", "Harvest Records"}};

    ui->CDTableWidget->setRowCount(cdData.size());

    for (int i = 0; i < cdData.size(); ++i) { // Zeilen
        for (int j = 0; j < CDCols.size(); ++j) { // Spalten
            qDebug() << "I: " << i << " J: " << j << " Data:" << cdData[i][j].toString();
            QTableWidgetItem *newItem = new QTableWidgetItem(cdData[i][j].toString());
            ui->CDTableWidget->setItem(i, j, newItem);
        }
    }
    ui->MainStatusbar->showMessage("Bereit");


}

MainWindow::~MainWindow(){
    delete ui;
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

    }
    else if (index == 1){ // Medien
        // dann überprüfen, welche Untertabs ausgewählt
        qDebug() << "==Medien==";

        if (ui->MediaTypeTab->currentIndex() == 0){ // Buch
            qDebug() << "==Buch==";
            // automatisches Laden aus der Liste (falls vorhanden)
            int Rows = BookList.length();

            if (Rows < 1){
                qDebug() << "Liste leer!";
                return;
            }
            ui->BookTableWidget->clearContents();

            qDebug() << "BookList Length: " << BookList.length();
            ui->BookTableWidget->setRowCount(BookList.length());
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
        else if (ui->MediaTypeTab->currentIndex() == 1){ // CD
            qDebug() << "==CD==";
            // automatisches Laden aus der Liste (falls vorhanden)
            int Rows = CDList.length();

            if (Rows < 1){
                qDebug() << "Liste leer!";
                return;
            }
            ui->CDTableWidget->clearContents();

            qDebug() << "CDList Length: " << CDList.length();
            ui->CDTableWidget->setRowCount(CDList.length());
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
    }
    else if (index == 2){ // Personen
        qDebug() << "==Personen==";
        // automatisches Laden aus der Liste (falls vorhanden)
        int Rows = PersonList.length();

        if (Rows < 1){
            qDebug() << "Liste leer!";
            return;
        }
        ui->PersonTableWidget->clearContents();

        qDebug() << "PersonList Length: " << PersonList.length();
        ui->PersonTableWidget->setRowCount(PersonList.length());
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
