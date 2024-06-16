/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.14
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
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
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QTabWidget *MainTabWidget;
    QWidget *AusleiheTab;
    QWidget *MedienTab;
    QWidget *PersonenTab;
    QVBoxLayout *verticalLayout_3;
    QTableWidget *PersonTableWidget;
    QPushButton *ShowPersonTableButton;
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
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        action_ffnen = new QAction(MainWindow);
        action_ffnen->setObjectName(QString::fromUtf8("action_ffnen"));
        actionSpeichern = new QAction(MainWindow);
        actionSpeichern->setObjectName(QString::fromUtf8("actionSpeichern"));
        actionBeenden = new QAction(MainWindow);
        actionBeenden->setObjectName(QString::fromUtf8("actionBeenden"));
        action_ber = new QAction(MainWindow);
        action_ber->setObjectName(QString::fromUtf8("action_ber"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        MainTabWidget = new QTabWidget(centralwidget);
        MainTabWidget->setObjectName(QString::fromUtf8("MainTabWidget"));
        AusleiheTab = new QWidget();
        AusleiheTab->setObjectName(QString::fromUtf8("AusleiheTab"));
        MainTabWidget->addTab(AusleiheTab, QString());
        MedienTab = new QWidget();
        MedienTab->setObjectName(QString::fromUtf8("MedienTab"));
        MainTabWidget->addTab(MedienTab, QString());
        PersonenTab = new QWidget();
        PersonenTab->setObjectName(QString::fromUtf8("PersonenTab"));
        verticalLayout_3 = new QVBoxLayout(PersonenTab);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        PersonTableWidget = new QTableWidget(PersonenTab);
        PersonTableWidget->setObjectName(QString::fromUtf8("PersonTableWidget"));

        verticalLayout_3->addWidget(PersonTableWidget);

        ShowPersonTableButton = new QPushButton(PersonenTab);
        ShowPersonTableButton->setObjectName(QString::fromUtf8("ShowPersonTableButton"));

        verticalLayout_3->addWidget(ShowPersonTableButton);

        SavePersonTableButton = new QPushButton(PersonenTab);
        SavePersonTableButton->setObjectName(QString::fromUtf8("SavePersonTableButton"));

        verticalLayout_3->addWidget(SavePersonTableButton);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        AddPersonButton = new QPushButton(PersonenTab);
        AddPersonButton->setObjectName(QString::fromUtf8("AddPersonButton"));

        horizontalLayout->addWidget(AddPersonButton);

        DeletePersonButton = new QPushButton(PersonenTab);
        DeletePersonButton->setObjectName(QString::fromUtf8("DeletePersonButton"));

        horizontalLayout->addWidget(DeletePersonButton);


        verticalLayout_3->addLayout(horizontalLayout);

        MainTabWidget->addTab(PersonenTab, QString());

        verticalLayout_2->addWidget(MainTabWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 20));
        menuMedienverleih = new QMenu(menubar);
        menuMedienverleih->setObjectName(QString::fromUtf8("menuMedienverleih"));
        menuHilfe = new QMenu(menubar);
        menuHilfe->setObjectName(QString::fromUtf8("menuHilfe"));
        MainWindow->setMenuBar(menubar);
        MainStatusbar = new QStatusBar(MainWindow);
        MainStatusbar->setObjectName(QString::fromUtf8("MainStatusbar"));
        MainWindow->setStatusBar(MainStatusbar);

        menubar->addAction(menuMedienverleih->menuAction());
        menubar->addAction(menuHilfe->menuAction());
        menuMedienverleih->addAction(action_ffnen);
        menuMedienverleih->addAction(actionSpeichern);
        menuMedienverleih->addSeparator();
        menuMedienverleih->addAction(actionBeenden);
        menuHilfe->addAction(action_ber);

        retranslateUi(MainWindow);

        MainTabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Medienverleih 0.3", nullptr));
        action_ffnen->setText(QCoreApplication::translate("MainWindow", "&\303\226ffnen", nullptr));
        actionSpeichern->setText(QCoreApplication::translate("MainWindow", "&Speichern", nullptr));
        actionBeenden->setText(QCoreApplication::translate("MainWindow", "&Beenden", nullptr));
        action_ber->setText(QCoreApplication::translate("MainWindow", "&\303\234ber...", nullptr));
        MainTabWidget->setTabText(MainTabWidget->indexOf(AusleiheTab), QCoreApplication::translate("MainWindow", "Ausleihe", nullptr));
        MainTabWidget->setTabText(MainTabWidget->indexOf(MedienTab), QCoreApplication::translate("MainWindow", "Medien", nullptr));
        ShowPersonTableButton->setText(QCoreApplication::translate("MainWindow", "Anzeigen", nullptr));
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
