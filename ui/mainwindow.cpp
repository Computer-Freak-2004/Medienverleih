#include "mainwindow.h"
#include "../ui_mainwindow.h"
#include "addlenddialog.h"
#include "saveloaddialog.h"
#include "aboutdialog.h"
#include <QTableWidget>
#include <QMessageBox>
#include <QStyleFactory>
#include <QActionGroup>
#include <QStyle>
#include <QCloseEvent>
#include <QThread>
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

    #ifdef Q_OS_WIN
    ui->AddNewLendButton->setIcon(QIcon(":WindowsIcons/Add.png"));
    ui->DeleteLendButton->setIcon(QIcon(":WindowsIcons/Remove.png"));
    ui->SaveLendTableButton->setIcon(QIcon(":WindowsIcons/Save.png"));

    ui->AddBookButton->setIcon(QIcon(":WindowsIcons/Add.png"));
    ui->DeleteBookButton->setIcon(QIcon(":WindowsIcons/Remove.png"));
    ui->SaveBookTableButton->setIcon(QIcon(":WindowsIcons/Save.png"));

    ui->AddCDButton->setIcon(QIcon(":WindowsIcons/Add.png"));
    ui->DeleteCDButton->setIcon(QIcon(":WindowsIcons/Remove.png"));
    ui->SaveCDTableButton->setIcon(QIcon(":WindowsIcons/Save.png"));

    ui->AddPersonButton->setIcon(QIcon(":WindowsIcons/Add.png"));
    ui->DeletePersonButton->setIcon(QIcon(":WindowsIcons/Remove.png"));
    ui->SavePersonTableButton->setIcon(QIcon(":WindowsIcons/Save.png"));

    ui->action_ffnen->setIcon(QIcon(":WindowsIcons/Open.png"));
    ui->actionSpeichern->setIcon(QIcon(":WindowsIcons/Save.png"));
    ui->actionBeenden->setIcon(QIcon(":WindowsIcons/Exit.png"));
    ui->action_ber->setIcon(QIcon(":WindowsIcons/Info.png"));


   #endif
}

MainWindow::~MainWindow(){
    delete ui;
}

int MainWindow::closeAsk(QCloseEvent *event){
    QMessageBox::StandardButton AskBox = QMessageBox::question( this, "Medienverleih",
                                                               tr("Listen vor dem Beenden speichern?\n"),
                                                               QMessageBox::Cancel | QMessageBox::No | QMessageBox::Yes, QMessageBox::Yes);
    if (AskBox == QMessageBox::Yes) {
        ManageLend::SaveLendTable(ui);
        ManageBook::SaveBookTable(ui);
        ManageCD::SaveCDTable(ui);
        ManagePerson::SavePersonTable(ui);
        SaveLoadDialog *dialog = new SaveLoadDialog(this);
        dialog->setAttribute(Qt::WA_DeleteOnClose);
        dialog->setWindowTitle("Listen speichern");

        int result = dialog->exec();

        if (result == QDialog::Accepted || result == QDialog::Rejected) {
            event->accept(); // Hauptfenster schließen akzeptieren
            return 1;
        }
    }
    else if (AskBox == QMessageBox::No) {
        event->accept();
        return 1;
    }
    else if (AskBox == QMessageBox::Cancel) {
        event->ignore();
        return 0;
    }
    return 0;
}

void MainWindow::closeEvent (QCloseEvent *event){
    closeAsk(event);
}

// ========= AUSLEIHE =========
void MainWindow::on_AddNewLendButton_clicked(){
    AddLendDialog *dialog = new AddLendDialog(this);
    dialog->setAttribute(Qt::WA_DeleteOnClose);
    // Funktionen verbinden, wenn OK gedrückt
    connect(dialog, &QDialog::accepted, this, &MainWindow::LendacceptSlot);
    dialog->show();
}

void MainWindow::LendacceptSlot(){ // Dialog: OK gedrückt
    ManageLend::Lendaccept(ui);

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

// ======= TABWECHSEL ==========
void MainWindow::on_MainTabWidget_currentChanged(int index){ // bei Tabwechsel richtige Liste laden
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

// ======= MENÜLEISTE ========
void MainWindow::on_action_ffnen_triggered(){
    ManageLend::SaveLendTable(ui);
    ManageBook::SaveBookTable(ui);
    ManageCD::SaveCDTable(ui);
    ManagePerson::SavePersonTable(ui);

    SaveLoadDialog *dialog = new SaveLoadDialog(this);
    dialog->setAttribute(Qt::WA_DeleteOnClose);
    dialog->setWindowTitle("Listen laden");
    // Funktionen verbinden, wenn OK gedrückt
    connect(dialog, &QDialog::accepted, this, &MainWindow::SaveacceptSlot);
    dialog->show();
}

void MainWindow::on_actionSpeichern_triggered(){
    ManageLend::SaveLendTable(ui);
    ManageBook::SaveBookTable(ui);
    ManageCD::SaveCDTable(ui);
    ManagePerson::SavePersonTable(ui);
    SaveLoadDialog *dialog = new SaveLoadDialog(this);
    dialog->setAttribute(Qt::WA_DeleteOnClose);
    dialog->setWindowTitle("Listen speichern");
    // Funktionen verbinden, wenn OK gedrückt
    connect(dialog, &QDialog::accepted, this, &MainWindow::SaveacceptSlot);
    dialog->show();
}

void MainWindow::SaveacceptSlot(){
    ManageLend::LoadLendTable(ui);
    ManageBook::LoadBookTable(ui);
    ManageCD::LoadCDTable(ui);
    ManagePerson::LoadPersonTable(ui);
}

void MainWindow::on_actionBeenden_triggered(){
    QCloseEvent *event = new QCloseEvent();
    int ret = closeAsk(event);
    if (ret == 1){
        exit(0);
    }
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
    //qApp->setStyle(QStyleFactory::create("defaultStyle"));

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
    dialog->setAttribute(Qt::WA_DeleteOnClose);
    dialog->show();
}


