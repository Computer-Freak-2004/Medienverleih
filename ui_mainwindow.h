/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_ffnen;
    QAction *actionSpeichern;
    QAction *actionBeenden;
    QAction *action_ber;
    QAction *actionDefault_Theme;
    QAction *actionDark_Theme;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QTabWidget *MainTabWidget;
    QWidget *AusleiheTab;
    QVBoxLayout *verticalLayout_8;
    QTableWidget *LendTableWidget;
    QPushButton *SaveLendTableButton;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *AddNewLendButton;
    QPushButton *DeleteLendButton;
    QWidget *MedienTab;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout;
    QTabWidget *MediaTypeTab;
    QWidget *BookTab;
    QVBoxLayout *verticalLayout_5;
    QTableWidget *BookTableWidget;
    QPushButton *SaveBookTableButton;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *AddBookButton;
    QPushButton *DeleteBookButton;
    QWidget *CDTab;
    QVBoxLayout *verticalLayout_6;
    QTableWidget *CDTableWidget;
    QPushButton *SaveCDTableButton;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *AddCDButton;
    QPushButton *DeleteCDButton;
    QWidget *PersonenTab;
    QVBoxLayout *verticalLayout_3;
    QTableWidget *PersonTableWidget;
    QPushButton *SavePersonTableButton;
    QHBoxLayout *horizontalLayout;
    QPushButton *AddPersonButton;
    QPushButton *DeletePersonButton;
    QMenuBar *menubar;
    QMenu *menuMedienverleih;
    QMenu *menuHilfe;
    QMenu *menuAnsicht;
    QStatusBar *MainStatusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1280, 720);
        MainWindow->setCursor(QCursor(Qt::ArrowCursor));
        QIcon icon;
        icon.addFile(QString::fromUtf8("icon_32.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        action_ffnen = new QAction(MainWindow);
        action_ffnen->setObjectName(QString::fromUtf8("action_ffnen"));
        actionSpeichern = new QAction(MainWindow);
        actionSpeichern->setObjectName(QString::fromUtf8("actionSpeichern"));
        actionBeenden = new QAction(MainWindow);
        actionBeenden->setObjectName(QString::fromUtf8("actionBeenden"));
        QIcon icon1(QIcon::fromTheme(QString::fromUtf8("application-exit")));
        actionBeenden->setIcon(icon1);
        action_ber = new QAction(MainWindow);
        action_ber->setObjectName(QString::fromUtf8("action_ber"));
        actionDefault_Theme = new QAction(MainWindow);
        actionDefault_Theme->setObjectName(QString::fromUtf8("actionDefault_Theme"));
        actionDefault_Theme->setCheckable(true);
        actionDefault_Theme->setChecked(true);
        actionDark_Theme = new QAction(MainWindow);
        actionDark_Theme->setObjectName(QString::fromUtf8("actionDark_Theme"));
        actionDark_Theme->setCheckable(true);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        MainTabWidget = new QTabWidget(centralwidget);
        MainTabWidget->setObjectName(QString::fromUtf8("MainTabWidget"));
        AusleiheTab = new QWidget();
        AusleiheTab->setObjectName(QString::fromUtf8("AusleiheTab"));
        verticalLayout_8 = new QVBoxLayout(AusleiheTab);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        LendTableWidget = new QTableWidget(AusleiheTab);
        LendTableWidget->setObjectName(QString::fromUtf8("LendTableWidget"));
        LendTableWidget->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
        LendTableWidget->setAlternatingRowColors(true);
        LendTableWidget->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);

        verticalLayout_8->addWidget(LendTableWidget);

        SaveLendTableButton = new QPushButton(AusleiheTab);
        SaveLendTableButton->setObjectName(QString::fromUtf8("SaveLendTableButton"));
        QIcon icon2(QIcon::fromTheme(QString::fromUtf8("document-save")));
        SaveLendTableButton->setIcon(icon2);

        verticalLayout_8->addWidget(SaveLendTableButton);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        AddNewLendButton = new QPushButton(AusleiheTab);
        AddNewLendButton->setObjectName(QString::fromUtf8("AddNewLendButton"));
        QIcon icon3(QIcon::fromTheme(QString::fromUtf8("list-add")));
        AddNewLendButton->setIcon(icon3);

        horizontalLayout_2->addWidget(AddNewLendButton);

        DeleteLendButton = new QPushButton(AusleiheTab);
        DeleteLendButton->setObjectName(QString::fromUtf8("DeleteLendButton"));
        QIcon icon4(QIcon::fromTheme(QString::fromUtf8("list-remove")));
        DeleteLendButton->setIcon(icon4);

        horizontalLayout_2->addWidget(DeleteLendButton);


        verticalLayout_8->addLayout(horizontalLayout_2);

        MainTabWidget->addTab(AusleiheTab, QString());
        MedienTab = new QWidget();
        MedienTab->setObjectName(QString::fromUtf8("MedienTab"));
        verticalLayout_4 = new QVBoxLayout(MedienTab);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        MediaTypeTab = new QTabWidget(MedienTab);
        MediaTypeTab->setObjectName(QString::fromUtf8("MediaTypeTab"));
        BookTab = new QWidget();
        BookTab->setObjectName(QString::fromUtf8("BookTab"));
        verticalLayout_5 = new QVBoxLayout(BookTab);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        BookTableWidget = new QTableWidget(BookTab);
        BookTableWidget->setObjectName(QString::fromUtf8("BookTableWidget"));
        BookTableWidget->setAlternatingRowColors(true);

        verticalLayout_5->addWidget(BookTableWidget);

        SaveBookTableButton = new QPushButton(BookTab);
        SaveBookTableButton->setObjectName(QString::fromUtf8("SaveBookTableButton"));
        SaveBookTableButton->setIcon(icon2);

        verticalLayout_5->addWidget(SaveBookTableButton);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        AddBookButton = new QPushButton(BookTab);
        AddBookButton->setObjectName(QString::fromUtf8("AddBookButton"));
        AddBookButton->setIcon(icon3);

        horizontalLayout_3->addWidget(AddBookButton);

        DeleteBookButton = new QPushButton(BookTab);
        DeleteBookButton->setObjectName(QString::fromUtf8("DeleteBookButton"));
        DeleteBookButton->setIcon(icon4);

        horizontalLayout_3->addWidget(DeleteBookButton);


        verticalLayout_5->addLayout(horizontalLayout_3);

        MediaTypeTab->addTab(BookTab, QString());
        CDTab = new QWidget();
        CDTab->setObjectName(QString::fromUtf8("CDTab"));
        verticalLayout_6 = new QVBoxLayout(CDTab);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        CDTableWidget = new QTableWidget(CDTab);
        CDTableWidget->setObjectName(QString::fromUtf8("CDTableWidget"));
        CDTableWidget->setAlternatingRowColors(true);

        verticalLayout_6->addWidget(CDTableWidget);

        SaveCDTableButton = new QPushButton(CDTab);
        SaveCDTableButton->setObjectName(QString::fromUtf8("SaveCDTableButton"));
        SaveCDTableButton->setIcon(icon2);

        verticalLayout_6->addWidget(SaveCDTableButton);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        AddCDButton = new QPushButton(CDTab);
        AddCDButton->setObjectName(QString::fromUtf8("AddCDButton"));
        AddCDButton->setIcon(icon3);
        AddCDButton->setCheckable(false);
        AddCDButton->setAutoRepeatDelay(299);

        horizontalLayout_4->addWidget(AddCDButton);

        DeleteCDButton = new QPushButton(CDTab);
        DeleteCDButton->setObjectName(QString::fromUtf8("DeleteCDButton"));
        DeleteCDButton->setIcon(icon4);

        horizontalLayout_4->addWidget(DeleteCDButton);


        verticalLayout_6->addLayout(horizontalLayout_4);

        MediaTypeTab->addTab(CDTab, QString());

        verticalLayout->addWidget(MediaTypeTab);


        verticalLayout_4->addLayout(verticalLayout);

        MainTabWidget->addTab(MedienTab, QString());
        PersonenTab = new QWidget();
        PersonenTab->setObjectName(QString::fromUtf8("PersonenTab"));
        verticalLayout_3 = new QVBoxLayout(PersonenTab);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        PersonTableWidget = new QTableWidget(PersonenTab);
        PersonTableWidget->setObjectName(QString::fromUtf8("PersonTableWidget"));
        PersonTableWidget->setAlternatingRowColors(true);

        verticalLayout_3->addWidget(PersonTableWidget);

        SavePersonTableButton = new QPushButton(PersonenTab);
        SavePersonTableButton->setObjectName(QString::fromUtf8("SavePersonTableButton"));
        SavePersonTableButton->setIcon(icon2);

        verticalLayout_3->addWidget(SavePersonTableButton);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        AddPersonButton = new QPushButton(PersonenTab);
        AddPersonButton->setObjectName(QString::fromUtf8("AddPersonButton"));
        AddPersonButton->setIcon(icon3);

        horizontalLayout->addWidget(AddPersonButton);

        DeletePersonButton = new QPushButton(PersonenTab);
        DeletePersonButton->setObjectName(QString::fromUtf8("DeletePersonButton"));
        DeletePersonButton->setIcon(icon4);

        horizontalLayout->addWidget(DeletePersonButton);


        verticalLayout_3->addLayout(horizontalLayout);

        MainTabWidget->addTab(PersonenTab, QString());

        verticalLayout_2->addWidget(MainTabWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1280, 20));
        menuMedienverleih = new QMenu(menubar);
        menuMedienverleih->setObjectName(QString::fromUtf8("menuMedienverleih"));
        menuHilfe = new QMenu(menubar);
        menuHilfe->setObjectName(QString::fromUtf8("menuHilfe"));
        menuAnsicht = new QMenu(menubar);
        menuAnsicht->setObjectName(QString::fromUtf8("menuAnsicht"));
        MainWindow->setMenuBar(menubar);
        MainStatusbar = new QStatusBar(MainWindow);
        MainStatusbar->setObjectName(QString::fromUtf8("MainStatusbar"));
        MainWindow->setStatusBar(MainStatusbar);

        menubar->addAction(menuMedienverleih->menuAction());
        menubar->addAction(menuAnsicht->menuAction());
        menubar->addAction(menuHilfe->menuAction());
        menuMedienverleih->addAction(action_ffnen);
        menuMedienverleih->addAction(actionSpeichern);
        menuMedienverleih->addSeparator();
        menuMedienverleih->addAction(actionBeenden);
        menuHilfe->addAction(action_ber);
        menuAnsicht->addAction(actionDefault_Theme);
        menuAnsicht->addAction(actionDark_Theme);

        retranslateUi(MainWindow);

        MainTabWidget->setCurrentIndex(0);
        MediaTypeTab->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Medienverleih", nullptr));
        action_ffnen->setText(QCoreApplication::translate("MainWindow", "&\303\226ffnen", nullptr));
        actionSpeichern->setText(QCoreApplication::translate("MainWindow", "&Speichern", nullptr));
        actionBeenden->setText(QCoreApplication::translate("MainWindow", "&Beenden", nullptr));
#if QT_CONFIG(statustip)
        actionBeenden->setStatusTip(QCoreApplication::translate("MainWindow", "Beendet das Programm.", nullptr));
#endif // QT_CONFIG(statustip)
        action_ber->setText(QCoreApplication::translate("MainWindow", "&\303\234ber...", nullptr));
#if QT_CONFIG(statustip)
        action_ber->setStatusTip(QCoreApplication::translate("MainWindow", "Zeigt einen Dialog mit Information \303\274ber dieses Programm an.", nullptr));
#endif // QT_CONFIG(statustip)
        actionDefault_Theme->setText(QCoreApplication::translate("MainWindow", "&Default Theme", nullptr));
#if QT_CONFIG(statustip)
        actionDefault_Theme->setStatusTip(QCoreApplication::translate("MainWindow", "Setzt das GUI-Thema auf den Standard zur\303\274ck.", nullptr));
#endif // QT_CONFIG(statustip)
        actionDark_Theme->setText(QCoreApplication::translate("MainWindow", "D&ark Theme", nullptr));
#if QT_CONFIG(statustip)
        actionDark_Theme->setStatusTip(QCoreApplication::translate("MainWindow", "Setzt das GUI-Thema auf ein dunkles Thema.", nullptr));
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(statustip)
        SaveLendTableButton->setStatusTip(QCoreApplication::translate("MainWindow", "Speichert die aktuelle Ausleihliste. \303\204nderungen gehen verloren ohne Speichern beim Wechseln von Tabs!", nullptr));
#endif // QT_CONFIG(statustip)
        SaveLendTableButton->setText(QCoreApplication::translate("MainWindow", "Ausleihen speichern", nullptr));
#if QT_CONFIG(statustip)
        AddNewLendButton->setStatusTip(QCoreApplication::translate("MainWindow", "Erstellt eine neue Ausleihe.", nullptr));
#endif // QT_CONFIG(statustip)
        AddNewLendButton->setText(QCoreApplication::translate("MainWindow", "Neue Ausleihe", nullptr));
#if QT_CONFIG(statustip)
        DeleteLendButton->setStatusTip(QCoreApplication::translate("MainWindow", "Gibt ein ausgeliehenes Medium zur\303\274ck.", nullptr));
#endif // QT_CONFIG(statustip)
        DeleteLendButton->setText(QCoreApplication::translate("MainWindow", "Zur\303\274ckgeben", nullptr));
        MainTabWidget->setTabText(MainTabWidget->indexOf(AusleiheTab), QCoreApplication::translate("MainWindow", "Ausleihe", nullptr));
#if QT_CONFIG(statustip)
        MediaTypeTab->setStatusTip(QCoreApplication::translate("MainWindow", "Hier k\303\266nnen die B\303\274cher bearbeitet werden. Doppelklick auf eine Zelle zum Bearbeiten.", nullptr));
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(statustip)
        SaveBookTableButton->setStatusTip(QCoreApplication::translate("MainWindow", "Speichert die aktuelle B\303\274cherliste. \303\204nderungen gehen verloren ohne Speichern beim Wechseln von Tabs!", nullptr));
#endif // QT_CONFIG(statustip)
        SaveBookTableButton->setText(QCoreApplication::translate("MainWindow", "B\303\274cher speichern", nullptr));
#if QT_CONFIG(statustip)
        AddBookButton->setStatusTip(QCoreApplication::translate("MainWindow", "F\303\274gt ein Buch hinzu.", nullptr));
#endif // QT_CONFIG(statustip)
        AddBookButton->setText(QCoreApplication::translate("MainWindow", "Buch hinzuf\303\274gen", nullptr));
#if QT_CONFIG(statustip)
        DeleteBookButton->setStatusTip(QCoreApplication::translate("MainWindow", "L\303\266scht das aktuell ausgew\303\244hlte Buch.", nullptr));
#endif // QT_CONFIG(statustip)
        DeleteBookButton->setText(QCoreApplication::translate("MainWindow", "Buch l\303\266schen", nullptr));
        MediaTypeTab->setTabText(MediaTypeTab->indexOf(BookTab), QCoreApplication::translate("MainWindow", "B\303\274cher", nullptr));
#if QT_CONFIG(statustip)
        CDTableWidget->setStatusTip(QCoreApplication::translate("MainWindow", "Hier k\303\266nnen die CDs bearbeitet werden. Doppelklick auf eine Zelle zum Bearbeiten.", nullptr));
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(statustip)
        SaveCDTableButton->setStatusTip(QCoreApplication::translate("MainWindow", "Speichert die aktuelle CD-Liste. \303\204nderungen gehen verloren ohne Speichern beim Wechseln von Tabs!", nullptr));
#endif // QT_CONFIG(statustip)
        SaveCDTableButton->setText(QCoreApplication::translate("MainWindow", "CDs speichern", nullptr));
#if QT_CONFIG(statustip)
        AddCDButton->setStatusTip(QCoreApplication::translate("MainWindow", "F\303\274gt eine CD hinzu.", nullptr));
#endif // QT_CONFIG(statustip)
        AddCDButton->setText(QCoreApplication::translate("MainWindow", "CD hinzuf\303\274gen", nullptr));
#if QT_CONFIG(statustip)
        DeleteCDButton->setStatusTip(QCoreApplication::translate("MainWindow", "L\303\266scht die aktuell ausgew\303\244hlte CD.", nullptr));
#endif // QT_CONFIG(statustip)
        DeleteCDButton->setText(QCoreApplication::translate("MainWindow", "CD l\303\266schen", nullptr));
        MediaTypeTab->setTabText(MediaTypeTab->indexOf(CDTab), QCoreApplication::translate("MainWindow", "CDs", nullptr));
        MainTabWidget->setTabText(MainTabWidget->indexOf(MedienTab), QCoreApplication::translate("MainWindow", "Medien", nullptr));
#if QT_CONFIG(statustip)
        PersonTableWidget->setStatusTip(QCoreApplication::translate("MainWindow", "Hier k\303\266nnen die Personen bearbeitet werden. Doppelklick auf eine Zelle zum Bearbeiten.", nullptr));
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(statustip)
        SavePersonTableButton->setStatusTip(QCoreApplication::translate("MainWindow", "Speichert die aktuelle Personenliste. \303\204nderungen gehen verloren ohne Speichern beim Wechseln von Tabs!", nullptr));
#endif // QT_CONFIG(statustip)
        SavePersonTableButton->setText(QCoreApplication::translate("MainWindow", "Personen speichern", nullptr));
#if QT_CONFIG(statustip)
        AddPersonButton->setStatusTip(QCoreApplication::translate("MainWindow", "F\303\274gt eine Person hinzu.", nullptr));
#endif // QT_CONFIG(statustip)
        AddPersonButton->setText(QCoreApplication::translate("MainWindow", "Person hinzuf\303\274gen", nullptr));
#if QT_CONFIG(statustip)
        DeletePersonButton->setStatusTip(QCoreApplication::translate("MainWindow", "L\303\266scht die aktuell ausgew\303\244hlte Person.", nullptr));
#endif // QT_CONFIG(statustip)
        DeletePersonButton->setText(QCoreApplication::translate("MainWindow", "Person l\303\266schen", nullptr));
        MainTabWidget->setTabText(MainTabWidget->indexOf(PersonenTab), QCoreApplication::translate("MainWindow", "Personen", nullptr));
#if QT_CONFIG(statustip)
        menuMedienverleih->setStatusTip(QCoreApplication::translate("MainWindow", "Hauptmen\303\274", nullptr));
#endif // QT_CONFIG(statustip)
        menuMedienverleih->setTitle(QCoreApplication::translate("MainWindow", "Medien&verleih", nullptr));
#if QT_CONFIG(statustip)
        menuHilfe->setStatusTip(QCoreApplication::translate("MainWindow", "Hilfemen\303\274", nullptr));
#endif // QT_CONFIG(statustip)
        menuHilfe->setTitle(QCoreApplication::translate("MainWindow", "Hilfe", nullptr));
#if QT_CONFIG(statustip)
        menuAnsicht->setStatusTip(QCoreApplication::translate("MainWindow", "Ansichtsmen\303\274", nullptr));
#endif // QT_CONFIG(statustip)
        menuAnsicht->setTitle(QCoreApplication::translate("MainWindow", "Ansicht", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
