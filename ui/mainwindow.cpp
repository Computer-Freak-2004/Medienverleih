#include "mainwindow.h"
#include "../ui_mainwindow.h"
#include "addlenddialog.h"
#include "aboutdialog.h"
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
#include "../classes/ManagePerson.h"
#include "../classes/Book.h"
#include "../classes/ManageBook.h"
#include "../classes/CD.h"
#include "../classes/ManageCD.h"
#include "../classes/Lend.h"
#include "../classes/ManageLend.h"

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

    // Icon setzen
    QString AppDir = QCoreApplication::applicationDirPath();
    QIcon icon(AppDir + "/ui/icon.png");
    setWindowIcon(icon);

    ui->MainStatusbar->showMessage("Bereit");
}

MainWindow::~MainWindow(){
    delete ui;
}

// ========= AUSLEIHE =========
void MainWindow::on_AddNewLendButton_clicked(){
    AddLendDialog *dialog = new AddLendDialog(this);
    // Funktionen verbinden, wenn OK, Abbrechen gedrückt
    connect(dialog, &QDialog::accepted, this, &MainWindow::LendacceptSlot);
    connect(dialog, &QDialog::rejected, this, &MainWindow::LendrejectSlot);
    dialog->show();
}

void MainWindow::LendacceptSlot(){ // Dialog: OK gedrückt
    ManageLend::Lendaccept(ui);
}

void MainWindow::LendrejectSlot(){ // Dialog: Abbrechen gedrückt
    // Do nothing
}

void MainWindow::on_DeleteLendButton_clicked(){
    ManageLend::DeleteLend(ui);
}

void MainWindow::on_SaveLendTableButton_clicked(){
    ManageLend::SaveLendTable(ui);

}

// ========= PERSON ==========
void MainWindow::on_AddPersonButton_clicked(){
    ManagePerson::AddPerson(ui);
}

void MainWindow::on_DeletePersonButton_clicked(){
    ManagePerson::DeletePerson(ui);
}

void MainWindow::on_SavePersonTableButton_clicked(){
    ManagePerson::SavePersonTable(ui);
}

// ======= MEDIEN-BUCH =========
void MainWindow::on_AddBookButton_clicked(){
    ManageBook::AddBook(ui);
}


void MainWindow::on_DeleteBookButton_clicked(){
    ManageBook::DeleteBook(ui);

}

void MainWindow::on_SaveBookTableButton_clicked(){
    ManageBook::SaveBookTable(ui);
}

// ======= MEDIEN-CD =========

void MainWindow::on_AddCDButton_clicked(){
    ManageCD::AddCD(ui);
}

void MainWindow::on_DeleteCDButton_clicked(){
    ManageCD::DeleteCD(ui);
}

void MainWindow::on_SaveCDTableButton_clicked(){
    ManageCD::SaveCDTable(ui);
}


void MainWindow::on_MainTabWidget_currentChanged(int index) // bei Tabwechsel richtige Liste laden
{
    if (index == 0){ // Ausleihe
        ManageLend::LoadLendTable(ui);

    }
    else if (index == 1){ // Medien
        qDebug() << "==Medien==";
        // Buch
        ManageBook::LoadBookTable(ui);


        // CD
        ManageCD::LoadCDTable(ui);
    }
    else if (index == 2){ // Personen
        ManagePerson::LoadPersonTable(ui);
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
    AboutDialog *dialog = new AboutDialog(this);
    // Funktionen verbinden, wenn OK, Abbrechen gedrückt
    connect(dialog, &QDialog::accepted, this, &MainWindow::AboutacceptSlot);
    dialog->show();
}

void MainWindow::AboutacceptSlot(){
    // do nothing
}
