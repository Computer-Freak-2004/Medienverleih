/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
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
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QTabWidget *MainTabWidget;
    QWidget *AusleiheTab;
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
    QWidget *AudiobookTab;
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
    QStatusBar *MainStatusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        MainWindow->setCursor(QCursor(Qt::ArrowCursor));
        action_ffnen = new QAction(MainWindow);
        action_ffnen->setObjectName("action_ffnen");
        actionSpeichern = new QAction(MainWindow);
        actionSpeichern->setObjectName("actionSpeichern");
        actionBeenden = new QAction(MainWindow);
        actionBeenden->setObjectName("actionBeenden");
        action_ber = new QAction(MainWindow);
        action_ber->setObjectName("action_ber");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        MainTabWidget = new QTabWidget(centralwidget);
        MainTabWidget->setObjectName("MainTabWidget");
        AusleiheTab = new QWidget();
        AusleiheTab->setObjectName("AusleiheTab");
        MainTabWidget->addTab(AusleiheTab, QString());
        MedienTab = new QWidget();
        MedienTab->setObjectName("MedienTab");
        verticalLayout_4 = new QVBoxLayout(MedienTab);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        MediaTypeTab = new QTabWidget(MedienTab);
        MediaTypeTab->setObjectName("MediaTypeTab");
        BookTab = new QWidget();
        BookTab->setObjectName("BookTab");
        verticalLayout_5 = new QVBoxLayout(BookTab);
        verticalLayout_5->setObjectName("verticalLayout_5");
        BookTableWidget = new QTableWidget(BookTab);
        BookTableWidget->setObjectName("BookTableWidget");

        verticalLayout_5->addWidget(BookTableWidget);

        SaveBookTableButton = new QPushButton(BookTab);
        SaveBookTableButton->setObjectName("SaveBookTableButton");

        verticalLayout_5->addWidget(SaveBookTableButton);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        AddBookButton = new QPushButton(BookTab);
        AddBookButton->setObjectName("AddBookButton");

        horizontalLayout_3->addWidget(AddBookButton);

        DeleteBookButton = new QPushButton(BookTab);
        DeleteBookButton->setObjectName("DeleteBookButton");

        horizontalLayout_3->addWidget(DeleteBookButton);


        verticalLayout_5->addLayout(horizontalLayout_3);

        MediaTypeTab->addTab(BookTab, QString());
        AudiobookTab = new QWidget();
        AudiobookTab->setObjectName("AudiobookTab");
        MediaTypeTab->addTab(AudiobookTab, QString());

        verticalLayout->addWidget(MediaTypeTab);


        verticalLayout_4->addLayout(verticalLayout);

        MainTabWidget->addTab(MedienTab, QString());
        PersonenTab = new QWidget();
        PersonenTab->setObjectName("PersonenTab");
        verticalLayout_3 = new QVBoxLayout(PersonenTab);
        verticalLayout_3->setObjectName("verticalLayout_3");
        PersonTableWidget = new QTableWidget(PersonenTab);
        PersonTableWidget->setObjectName("PersonTableWidget");

        verticalLayout_3->addWidget(PersonTableWidget);

        SavePersonTableButton = new QPushButton(PersonenTab);
        SavePersonTableButton->setObjectName("SavePersonTableButton");

        verticalLayout_3->addWidget(SavePersonTableButton);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        AddPersonButton = new QPushButton(PersonenTab);
        AddPersonButton->setObjectName("AddPersonButton");

        horizontalLayout->addWidget(AddPersonButton);

        DeletePersonButton = new QPushButton(PersonenTab);
        DeletePersonButton->setObjectName("DeletePersonButton");

        horizontalLayout->addWidget(DeletePersonButton);


        verticalLayout_3->addLayout(horizontalLayout);

        MainTabWidget->addTab(PersonenTab, QString());

        verticalLayout_2->addWidget(MainTabWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 30));
        menuMedienverleih = new QMenu(menubar);
        menuMedienverleih->setObjectName("menuMedienverleih");
        menuHilfe = new QMenu(menubar);
        menuHilfe->setObjectName("menuHilfe");
        MainWindow->setMenuBar(menubar);
        MainStatusbar = new QStatusBar(MainWindow);
        MainStatusbar->setObjectName("MainStatusbar");
        MainWindow->setStatusBar(MainStatusbar);

        menubar->addAction(menuMedienverleih->menuAction());
        menubar->addAction(menuHilfe->menuAction());
        menuMedienverleih->addAction(action_ffnen);
        menuMedienverleih->addAction(actionSpeichern);
        menuMedienverleih->addSeparator();
        menuMedienverleih->addAction(actionBeenden);
        menuHilfe->addAction(action_ber);

        retranslateUi(MainWindow);

        MainTabWidget->setCurrentIndex(1);
        MediaTypeTab->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Medienverleih 0.5", nullptr));
        action_ffnen->setText(QCoreApplication::translate("MainWindow", "&\303\226ffnen", nullptr));
        actionSpeichern->setText(QCoreApplication::translate("MainWindow", "&Speichern", nullptr));
        actionBeenden->setText(QCoreApplication::translate("MainWindow", "&Beenden", nullptr));
        action_ber->setText(QCoreApplication::translate("MainWindow", "&\303\234ber...", nullptr));
        MainTabWidget->setTabText(MainTabWidget->indexOf(AusleiheTab), QCoreApplication::translate("MainWindow", "Ausleihe", nullptr));
        SaveBookTableButton->setText(QCoreApplication::translate("MainWindow", "B\303\274cher speichern", nullptr));
        AddBookButton->setText(QCoreApplication::translate("MainWindow", "Buch hinzuf\303\274gen", nullptr));
        DeleteBookButton->setText(QCoreApplication::translate("MainWindow", "Buch l\303\266schen", nullptr));
        MediaTypeTab->setTabText(MediaTypeTab->indexOf(BookTab), QCoreApplication::translate("MainWindow", "Buch", nullptr));
        MediaTypeTab->setTabText(MediaTypeTab->indexOf(AudiobookTab), QCoreApplication::translate("MainWindow", "H\303\266rbuch", nullptr));
        MainTabWidget->setTabText(MainTabWidget->indexOf(MedienTab), QCoreApplication::translate("MainWindow", "Medien", nullptr));
        SavePersonTableButton->setText(QCoreApplication::translate("MainWindow", "Personen speichern", nullptr));
        AddPersonButton->setText(QCoreApplication::translate("MainWindow", "Person hinzuf\303\274gen", nullptr));
        DeletePersonButton->setText(QCoreApplication::translate("MainWindow", "Person l\303\266schen", nullptr));
        MainTabWidget->setTabText(MainTabWidget->indexOf(PersonenTab), QCoreApplication::translate("MainWindow", "Personen", nullptr));
        menuMedienverleih->setTitle(QCoreApplication::translate("MainWindow", "Medien&verleih", nullptr));
        menuHilfe->setTitle(QCoreApplication::translate("MainWindow", "Hilfe", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
