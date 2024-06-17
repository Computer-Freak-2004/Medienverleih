/********************************************************************************
** Form generated from reading UI file 'addlenddialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDLENDDIALOG_H
#define UI_ADDLENDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
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
    QHBoxLayout *horizontalLayout_2;
    QLabel *PersonLabel;
    QLabel *MediaLabel;
    QHBoxLayout *horizontalLayout;
    QTableWidget *tableWidget_2;
    QTabWidget *tabWidget;
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
            AddLendDialog->setObjectName("AddLendDialog");
        AddLendDialog->resize(946, 548);
        verticalLayout = new QVBoxLayout(AddLendDialog);
        verticalLayout->setObjectName("verticalLayout");
        InstructionLabel = new QLabel(AddLendDialog);
        InstructionLabel->setObjectName("InstructionLabel");

        verticalLayout->addWidget(InstructionLabel);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        PersonLabel = new QLabel(AddLendDialog);
        PersonLabel->setObjectName("PersonLabel");
        PersonLabel->setFrameShape(QFrame::Box);
        PersonLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(PersonLabel);

        MediaLabel = new QLabel(AddLendDialog);
        MediaLabel->setObjectName("MediaLabel");
        MediaLabel->setFrameShape(QFrame::Panel);
        MediaLabel->setFrameShadow(QFrame::Plain);
        MediaLabel->setScaledContents(false);
        MediaLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(MediaLabel);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        tableWidget_2 = new QTableWidget(AddLendDialog);
        tableWidget_2->setObjectName("tableWidget_2");

        horizontalLayout->addWidget(tableWidget_2);

        tabWidget = new QTabWidget(AddLendDialog);
        tabWidget->setObjectName("tabWidget");
        BookTab = new QWidget();
        BookTab->setObjectName("BookTab");
        verticalLayout_2 = new QVBoxLayout(BookTab);
        verticalLayout_2->setObjectName("verticalLayout_2");
        BookTableWidget = new QTableWidget(BookTab);
        BookTableWidget->setObjectName("BookTableWidget");

        verticalLayout_2->addWidget(BookTableWidget);

        tabWidget->addTab(BookTab, QString());
        CDTab = new QWidget();
        CDTab->setObjectName("CDTab");
        verticalLayout_3 = new QVBoxLayout(CDTab);
        verticalLayout_3->setObjectName("verticalLayout_3");
        CDTableWidget = new QTableWidget(CDTab);
        CDTableWidget->setObjectName("CDTableWidget");

        verticalLayout_3->addWidget(CDTableWidget);

        tabWidget->addTab(CDTab, QString());

        horizontalLayout->addWidget(tabWidget);


        verticalLayout->addLayout(horizontalLayout);

        DialogOKAbortButtons = new QDialogButtonBox(AddLendDialog);
        DialogOKAbortButtons->setObjectName("DialogOKAbortButtons");
        DialogOKAbortButtons->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(DialogOKAbortButtons);


        retranslateUi(AddLendDialog);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(AddLendDialog);
    } // setupUi

    void retranslateUi(QDialog *AddLendDialog)
    {
        AddLendDialog->setWindowTitle(QCoreApplication::translate("AddLendDialog", "Dialog", nullptr));
        InstructionLabel->setText(QCoreApplication::translate("AddLendDialog", "Ausleihende Person und das auzuleihende Medium ausw\303\244hlen:", nullptr));
        PersonLabel->setText(QCoreApplication::translate("AddLendDialog", "Personen", nullptr));
        MediaLabel->setText(QCoreApplication::translate("AddLendDialog", "Medien", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(BookTab), QCoreApplication::translate("AddLendDialog", "B\303\274cher", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(CDTab), QCoreApplication::translate("AddLendDialog", "CDs", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddLendDialog: public Ui_AddLendDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDLENDDIALOG_H
