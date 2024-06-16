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
#include <QtGui/QIcon>
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
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1280, 720);
        MainWindow->setCursor(QCursor(Qt::ArrowCursor));
        action_ffnen = new QAction(MainWindow);
        action_ffnen->setObjectName("action_ffnen");
        actionSpeichern = new QAction(MainWindow);
        actionSpeichern->setObjectName("actionSpeichern");
        actionBeenden = new QAction(MainWindow);
        actionBeenden->setObjectName("actionBeenden");
        QIcon icon;
        QString iconThemeName = QString::fromUtf8("application-exit");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionBeenden->setIcon(icon);
        action_ber = new QAction(MainWindow);
        action_ber->setObjectName("action_ber");
        actionDefault_Theme = new QAction(MainWindow);
        actionDefault_Theme->setObjectName("actionDefault_Theme");
        actionDefault_Theme->setCheckable(true);
        actionDefault_Theme->setChecked(true);
        actionDark_Theme = new QAction(MainWindow);
        actionDark_Theme->setObjectName("actionDark_Theme");
        actionDark_Theme->setCheckable(true);
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
        QIcon icon1;
        iconThemeName = QString::fromUtf8("document-save");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon1 = QIcon::fromTheme(iconThemeName);
        } else {
            icon1.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        SaveBookTableButton->setIcon(icon1);

        verticalLayout_5->addWidget(SaveBookTableButton);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        AddBookButton = new QPushButton(BookTab);
        AddBookButton->setObjectName("AddBookButton");
        QIcon icon2;
        iconThemeName = QString::fromUtf8("list-add");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon2 = QIcon::fromTheme(iconThemeName);
        } else {
            icon2.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        AddBookButton->setIcon(icon2);

        horizontalLayout_3->addWidget(AddBookButton);

        DeleteBookButton = new QPushButton(BookTab);
        DeleteBookButton->setObjectName("DeleteBookButton");
        QIcon icon3;
        iconThemeName = QString::fromUtf8("list-remove");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon3 = QIcon::fromTheme(iconThemeName);
        } else {
            icon3.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        DeleteBookButton->setIcon(icon3);

        horizontalLayout_3->addWidget(DeleteBookButton);


        verticalLayout_5->addLayout(horizontalLayout_3);

        MediaTypeTab->addTab(BookTab, QString());
        CDTab = new QWidget();
        CDTab->setObjectName("CDTab");
        verticalLayout_6 = new QVBoxLayout(CDTab);
        verticalLayout_6->setObjectName("verticalLayout_6");
        CDTableWidget = new QTableWidget(CDTab);
        CDTableWidget->setObjectName("CDTableWidget");

        verticalLayout_6->addWidget(CDTableWidget);

        SaveCDTableButton = new QPushButton(CDTab);
        SaveCDTableButton->setObjectName("SaveCDTableButton");
        SaveCDTableButton->setIcon(icon1);

        verticalLayout_6->addWidget(SaveCDTableButton);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        AddCDButton = new QPushButton(CDTab);
        AddCDButton->setObjectName("AddCDButton");
        AddCDButton->setIcon(icon2);
        AddCDButton->setCheckable(false);
        AddCDButton->setAutoRepeatDelay(299);

        horizontalLayout_4->addWidget(AddCDButton);

        DeleteCDButton = new QPushButton(CDTab);
        DeleteCDButton->setObjectName("DeleteCDButton");
        DeleteCDButton->setIcon(icon3);

        horizontalLayout_4->addWidget(DeleteCDButton);


        verticalLayout_6->addLayout(horizontalLayout_4);

        MediaTypeTab->addTab(CDTab, QString());

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
        SavePersonTableButton->setIcon(icon1);

        verticalLayout_3->addWidget(SavePersonTableButton);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        AddPersonButton = new QPushButton(PersonenTab);
        AddPersonButton->setObjectName("AddPersonButton");
        AddPersonButton->setIcon(icon2);

        horizontalLayout->addWidget(AddPersonButton);

        DeletePersonButton = new QPushButton(PersonenTab);
        DeletePersonButton->setObjectName("DeletePersonButton");
        DeletePersonButton->setIcon(icon3);

        horizontalLayout->addWidget(DeletePersonButton);


        verticalLayout_3->addLayout(horizontalLayout);

        MainTabWidget->addTab(PersonenTab, QString());

        verticalLayout_2->addWidget(MainTabWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1280, 30));
        menuMedienverleih = new QMenu(menubar);
        menuMedienverleih->setObjectName("menuMedienverleih");
        menuHilfe = new QMenu(menubar);
        menuHilfe->setObjectName("menuHilfe");
        menuAnsicht = new QMenu(menubar);
        menuAnsicht->setObjectName("menuAnsicht");
        MainWindow->setMenuBar(menubar);
        MainStatusbar = new QStatusBar(MainWindow);
        MainStatusbar->setObjectName("MainStatusbar");
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
        MainTabWidget->setTabText(MainTabWidget->indexOf(AusleiheTab), QCoreApplication::translate("MainWindow", "Ausleihe", nullptr));
#if QT_CONFIG(statustip)
        MediaTypeTab->setStatusTip(QCoreApplication::translate("MainWindow", "Hier k\303\266nnen die B\303\274cher bearbeitet werden. Doppelklick auf eine Zelle zum Bearbeiten.", nullptr));
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(statustip)
        SaveBookTableButton->setStatusTip(QCoreApplication::translate("MainWindow", "Speichert die aktuelle B\303\274cherliste. \303\204nderungen gehen verloren ohne Speichern!", nullptr));
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
        MediaTypeTab->setTabText(MediaTypeTab->indexOf(BookTab), QCoreApplication::translate("MainWindow", "Buch", nullptr));
#if QT_CONFIG(statustip)
        CDTableWidget->setStatusTip(QCoreApplication::translate("MainWindow", "Hier k\303\266nnen die CDs bearbeitet werden. Doppelklick auf eine Zelle zum Bearbeiten.", nullptr));
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(statustip)
        SaveCDTableButton->setStatusTip(QCoreApplication::translate("MainWindow", "Speichert die aktuelle CD-Liste. \303\204nderungen gehen verloren ohne Speichern!", nullptr));
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
        MediaTypeTab->setTabText(MediaTypeTab->indexOf(CDTab), QCoreApplication::translate("MainWindow", "CD", nullptr));
        MainTabWidget->setTabText(MainTabWidget->indexOf(MedienTab), QCoreApplication::translate("MainWindow", "Medien", nullptr));
#if QT_CONFIG(statustip)
        PersonTableWidget->setStatusTip(QCoreApplication::translate("MainWindow", "Hier k\303\266nnen die Personen bearbeitet werden. Doppelklick auf eine Zelle zum Bearbeiten.", nullptr));
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(statustip)
        SavePersonTableButton->setStatusTip(QCoreApplication::translate("MainWindow", "Speichert die aktuelle Personenliste. \303\204nderungen gehen verloren ohne Speichern!", nullptr));
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
        menuMedienverleih->setTitle(QCoreApplication::translate("MainWindow", "Medien&verleih", nullptr));
        menuHilfe->setTitle(QCoreApplication::translate("MainWindow", "Hilfe", nullptr));
        menuAnsicht->setTitle(QCoreApplication::translate("MainWindow", "Ansicht", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
