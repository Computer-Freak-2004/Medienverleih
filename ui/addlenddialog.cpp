#include "addlenddialog.h"
#include "ui_addlenddialog.h"
#include <QList>
#include <QMessageBox>
#include "../classes/Person.h"
#include "../classes/ManagePerson.h"
#include "../classes/Book.h"
#include "../classes/ManageBook.h"
#include "../classes/CD.h"
#include "../classes/ManageCD.h"

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

    // Person Widget konfig. + Liste laden
    QStringList PersonCols({"Person-Nr", "Name", "Adresse", "Alter", "Telefonr."});
    ui->PersonTableWidget->setColumnCount(PersonCols.length());
    ui->PersonTableWidget->setHorizontalHeaderLabels(PersonCols);
    ui->PersonTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ManagePerson::LoadPersonTable(ui);

    // Bücher Widget konfig. + Liste laden
    QStringList BookCols({"Buch-Nr", "Titel", "Autor", "Jahr", "Seiten", "Verlag"});
    ui->BookTableWidget->setColumnCount(BookCols.length());
    ui->BookTableWidget->setHorizontalHeaderLabels(BookCols);
    ui->BookTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ManageBook::LoadBookTable(ui);

    // CD Widget konfig. + Liste laden
    QStringList CDCols({"CD-Nr", "Titel", "Autor", "Jahr", "Dauer (min)", "Genre", "Verlag"});
    ui->CDTableWidget->setColumnCount(CDCols.length());
    ui->CDTableWidget->setHorizontalHeaderLabels(CDCols);
    ui->CDTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ManageCD::LoadCDTable(ui);

    #ifdef Q_OS_WIN
    this->setWindowIcon(QIcon(":WindowsIcons/Add.png"));
    #endif
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
