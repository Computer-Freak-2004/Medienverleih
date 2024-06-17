#include "addlenddialog.h"
#include "ui_addlenddialog.h"
#include <QList>
#include <QMessageBox>
#include "../classes/Person.h"
#include "../classes/Book.h"
#include "../classes/CD.h"

extern QList<Person> PersonList;
extern QList<Book> BookList;
extern QList<CD> CDList;

extern int PersonRow;
extern int MediaType; //0= Book, 1=CD
extern int BookRow;
extern int CDRow;

AddLendDialog::AddLendDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddLendDialog)
{
    ui->setupUi(this);

    // ========== Person Widget konfig. + Liste laden ==========
    QStringList PersonCols({"Person-Nr", "Name", "Adresse", "Alter", "Telefonr."});
    ui->PersonTableWidget->setColumnCount(PersonCols.length());
    ui->PersonTableWidget->setHorizontalHeaderLabels(PersonCols);
    ui->PersonTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    int Rows = PersonList.length();

    if (Rows < 1){
        qDebug() << "Liste leer!";
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

    // ========== Bücher Widget konfig. + Liste laden ==========
    QStringList BookCols({"Buch-Nr", "Titel", "Autor", "Jahr", "Seiten", "Verlag"});
    ui->BookTableWidget->setColumnCount(BookCols.length());
    ui->BookTableWidget->setHorizontalHeaderLabels(BookCols);
    ui->BookTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    Rows = BookList.length();

    if (Rows < 1){
        qDebug() << "Liste leer!";
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

    // ========== CD Widget konfig. + Liste laden ==========
    QStringList CDCols({"CD-Nr", "Titel", "Autor", "Jahr", "Dauer (min)", "Genre", "Verlag"});
    ui->CDTableWidget->setColumnCount(CDCols.length());
    ui->CDTableWidget->setHorizontalHeaderLabels(CDCols);
    ui->CDTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    Rows = CDList.length();

    if (Rows < 1){
        qDebug() << "Liste leer!";
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

AddLendDialog::~AddLendDialog(){
    delete ui;
}

void AddLendDialog::on_DialogOKAbortButtons_accepted(){
    // Ausgewählte Einträge lesen
    PersonRow = ui->PersonTableWidget->currentRow();
    BookRow = ui->BookTableWidget->currentRow();
    CDRow = ui->CDTableWidget->currentRow();
    MediaType = ui->MediaTabWidget->currentIndex();

    if ((PersonRow == -1) || ((BookRow == -1) & (CDRow == -1))){
        QMessageBox::warning(nullptr, "Neue Ausleihe", "Noch nicht alles ausgewählt! Es muss mind. 1 Person und 1 Medium ausgewählt werden.");
        return;
    }
    accept();
}


void AddLendDialog::on_DialogOKAbortButtons_rejected(){
    reject();
}
