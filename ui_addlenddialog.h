/********************************************************************************
** Form generated from reading UI file 'addlenddialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.14
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDLENDDIALOG_H
#define UI_ADDLENDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddLendDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *InstructionLabel;
    QSpacerItem *verticalSpacer;
    QTabWidget *MainTabWidget;
    QWidget *PersonTab;
    QVBoxLayout *verticalLayout_5;
    QTableWidget *PersonTableWidget;
    QWidget *MediaTab;
    QVBoxLayout *verticalLayout_4;
    QTabWidget *MediaTabWidget;
    QWidget *BookTab;
    QVBoxLayout *verticalLayout_2;
    QTableWidget *BookTableWidget;
    QWidget *CDTab;
    QVBoxLayout *verticalLayout_3;
    QTableWidget *CDTableWidget;
    QDialogButtonBox *DialogOKAbortButtons;

    void setupUi(QDialog *AddLendDialog)
    {
        if (AddLendDialog->objectName().isEmpty())
            AddLendDialog->setObjectName(QString::fromUtf8("AddLendDialog"));
        AddLendDialog->resize(946, 586);
        AddLendDialog->setSizeGripEnabled(true);
        AddLendDialog->setModal(true);
        verticalLayout = new QVBoxLayout(AddLendDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        InstructionLabel = new QLabel(AddLendDialog);
        InstructionLabel->setObjectName(QString::fromUtf8("InstructionLabel"));
        InstructionLabel->setFrameShape(QFrame::NoFrame);
        InstructionLabel->setFrameShadow(QFrame::Raised);

        verticalLayout->addWidget(InstructionLabel);

        verticalSpacer = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        MainTabWidget = new QTabWidget(AddLendDialog);
        MainTabWidget->setObjectName(QString::fromUtf8("MainTabWidget"));
        PersonTab = new QWidget();
        PersonTab->setObjectName(QString::fromUtf8("PersonTab"));
        verticalLayout_5 = new QVBoxLayout(PersonTab);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        PersonTableWidget = new QTableWidget(PersonTab);
        PersonTableWidget->setObjectName(QString::fromUtf8("PersonTableWidget"));
        PersonTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        PersonTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout_5->addWidget(PersonTableWidget);

        MainTabWidget->addTab(PersonTab, QString());
        MediaTab = new QWidget();
        MediaTab->setObjectName(QString::fromUtf8("MediaTab"));
        verticalLayout_4 = new QVBoxLayout(MediaTab);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        MediaTabWidget = new QTabWidget(MediaTab);
        MediaTabWidget->setObjectName(QString::fromUtf8("MediaTabWidget"));
        BookTab = new QWidget();
        BookTab->setObjectName(QString::fromUtf8("BookTab"));
        verticalLayout_2 = new QVBoxLayout(BookTab);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        BookTableWidget = new QTableWidget(BookTab);
        BookTableWidget->setObjectName(QString::fromUtf8("BookTableWidget"));
        BookTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        BookTableWidget->setAlternatingRowColors(true);
        BookTableWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);
        BookTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout_2->addWidget(BookTableWidget);

        MediaTabWidget->addTab(BookTab, QString());
        CDTab = new QWidget();
        CDTab->setObjectName(QString::fromUtf8("CDTab"));
        verticalLayout_3 = new QVBoxLayout(CDTab);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        CDTableWidget = new QTableWidget(CDTab);
        CDTableWidget->setObjectName(QString::fromUtf8("CDTableWidget"));
        CDTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        CDTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout_3->addWidget(CDTableWidget);

        MediaTabWidget->addTab(CDTab, QString());

        verticalLayout_4->addWidget(MediaTabWidget);

        MainTabWidget->addTab(MediaTab, QString());

        verticalLayout->addWidget(MainTabWidget);

        DialogOKAbortButtons = new QDialogButtonBox(AddLendDialog);
        DialogOKAbortButtons->setObjectName(QString::fromUtf8("DialogOKAbortButtons"));
        DialogOKAbortButtons->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(DialogOKAbortButtons);


        retranslateUi(AddLendDialog);

        MainTabWidget->setCurrentIndex(0);
        MediaTabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(AddLendDialog);
    } // setupUi

    void retranslateUi(QDialog *AddLendDialog)
    {
        AddLendDialog->setWindowTitle(QCoreApplication::translate("AddLendDialog", "Neue Ausleihe", nullptr));
        InstructionLabel->setText(QCoreApplication::translate("AddLendDialog", "<html><head/><body><p align=\"center\"><span style=\" font-weight:600;\">Ausleihende Person und das auzuleihende Medium ausw\303\244hlen:</span></p></body></html>", nullptr));
        MainTabWidget->setTabText(MainTabWidget->indexOf(PersonTab), QCoreApplication::translate("AddLendDialog", "Personen", nullptr));
        MediaTabWidget->setTabText(MediaTabWidget->indexOf(BookTab), QCoreApplication::translate("AddLendDialog", "B\303\274cher", nullptr));
        MediaTabWidget->setTabText(MediaTabWidget->indexOf(CDTab), QCoreApplication::translate("AddLendDialog", "CDs", nullptr));
        MainTabWidget->setTabText(MainTabWidget->indexOf(MediaTab), QCoreApplication::translate("AddLendDialog", "Medien", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddLendDialog: public Ui_AddLendDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDLENDDIALOG_H
