/********************************************************************************
** Form generated from reading UI file 'aboutdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTDIALOG_H
#define UI_ABOUTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AboutDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *MainLabelSpacer2;
    QGraphicsView *IconView;
    QSpacerItem *MainLabelSpacer1;
    QLabel *MainLabel;
    QLabel *DescriptionLabel;
    QFrame *Line;
    QLabel *BuldtimeLabel;
    QLabel *AuthorLabel;
    QLabel *VersionLabel;
    QLabel *DateLabel;
    QTextBrowser *VersionHistoryTextBrowser;
    QPushButton *AboutCloseButton;

    void setupUi(QDialog *AboutDialog)
    {
        if (AboutDialog->objectName().isEmpty())
            AboutDialog->setObjectName(QString::fromUtf8("AboutDialog"));
        AboutDialog->resize(410, 390);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AboutDialog->sizePolicy().hasHeightForWidth());
        AboutDialog->setSizePolicy(sizePolicy);
        AboutDialog->setMinimumSize(QSize(410, 390));
        AboutDialog->setMaximumSize(QSize(410, 390));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        AboutDialog->setWindowIcon(icon);
        AboutDialog->setModal(true);
        verticalLayout = new QVBoxLayout(AboutDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        MainLabelSpacer2 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(MainLabelSpacer2);

        IconView = new QGraphicsView(AboutDialog);
        IconView->setObjectName(QString::fromUtf8("IconView"));
        IconView->setEnabled(true);
        IconView->setMaximumSize(QSize(64, 64));
        IconView->setFrameShape(QFrame::NoFrame);
        IconView->setFrameShadow(QFrame::Sunken);
        IconView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        IconView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        QBrush brush(QColor(72, 72, 214, 192));
        brush.setStyle(Qt::SolidPattern);
        IconView->setBackgroundBrush(brush);
        IconView->setInteractive(false);
        IconView->setRenderHints(QPainter::LosslessImageRendering|QPainter::SmoothPixmapTransform);

        horizontalLayout_2->addWidget(IconView);

        MainLabelSpacer1 = new QSpacerItem(20, 2, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(MainLabelSpacer1);

        MainLabel = new QLabel(AboutDialog);
        MainLabel->setObjectName(QString::fromUtf8("MainLabel"));
        MainLabel->setMinimumSize(QSize(160, 0));
        MainLabel->setMaximumSize(QSize(250, 90));
        MainLabel->setTextFormat(Qt::RichText);

        horizontalLayout_2->addWidget(MainLabel);


        verticalLayout->addLayout(horizontalLayout_2);

        DescriptionLabel = new QLabel(AboutDialog);
        DescriptionLabel->setObjectName(QString::fromUtf8("DescriptionLabel"));
        DescriptionLabel->setMaximumSize(QSize(400, 40));
        DescriptionLabel->setTextFormat(Qt::RichText);
        DescriptionLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(DescriptionLabel);

        Line = new QFrame(AboutDialog);
        Line->setObjectName(QString::fromUtf8("Line"));
        Line->setWindowModality(Qt::WindowModal);
        Line->setMinimumSize(QSize(380, 3));
        Line->setMaximumSize(QSize(1000, 10));
        Line->setFrameShape(QFrame::HLine);
        Line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(Line);

        BuldtimeLabel = new QLabel(AboutDialog);
        BuldtimeLabel->setObjectName(QString::fromUtf8("BuldtimeLabel"));
        BuldtimeLabel->setMinimumSize(QSize(390, 0));
        BuldtimeLabel->setMouseTracking(true);
        BuldtimeLabel->setToolTipDuration(10);
        BuldtimeLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout->addWidget(BuldtimeLabel);

        AuthorLabel = new QLabel(AboutDialog);
        AuthorLabel->setObjectName(QString::fromUtf8("AuthorLabel"));

        verticalLayout->addWidget(AuthorLabel);

        VersionLabel = new QLabel(AboutDialog);
        VersionLabel->setObjectName(QString::fromUtf8("VersionLabel"));

        verticalLayout->addWidget(VersionLabel);

        DateLabel = new QLabel(AboutDialog);
        DateLabel->setObjectName(QString::fromUtf8("DateLabel"));

        verticalLayout->addWidget(DateLabel);

        VersionHistoryTextBrowser = new QTextBrowser(AboutDialog);
        VersionHistoryTextBrowser->setObjectName(QString::fromUtf8("VersionHistoryTextBrowser"));
        VersionHistoryTextBrowser->setMinimumSize(QSize(390, 100));
        VersionHistoryTextBrowser->setMaximumSize(QSize(400, 16777215));
        VersionHistoryTextBrowser->setAutoFormatting(QTextEdit::AutoBulletList);
        VersionHistoryTextBrowser->setAcceptRichText(false);
        VersionHistoryTextBrowser->setOpenExternalLinks(true);

        verticalLayout->addWidget(VersionHistoryTextBrowser);

        AboutCloseButton = new QPushButton(AboutDialog);
        AboutCloseButton->setObjectName(QString::fromUtf8("AboutCloseButton"));
        AboutCloseButton->setMinimumSize(QSize(0, 30));

        verticalLayout->addWidget(AboutCloseButton);


        retranslateUi(AboutDialog);

        QMetaObject::connectSlotsByName(AboutDialog);
    } // setupUi

    void retranslateUi(QDialog *AboutDialog)
    {
        AboutDialog->setWindowTitle(QCoreApplication::translate("AboutDialog", "\303\234ber...", nullptr));
#if QT_CONFIG(tooltip)
        IconView->setToolTip(QCoreApplication::translate("AboutDialog", "https://www.flaticon.com/de/kostenloses-icon/bibliothek_225993", nullptr));
#endif // QT_CONFIG(tooltip)
        MainLabel->setText(QCoreApplication::translate("AboutDialog", "<html><head/><body><p><span style=\" font-size:20pt; font-weight:700;\">Medienverleihe</span></p></body></html>", nullptr));
        DescriptionLabel->setText(QCoreApplication::translate("AboutDialog", "<html><head/><body><p><span style=\" font-weight:700;\">Eine einfache Medienverleihe geschrieben in C++ und Qt5.</span></p></body></html>", nullptr));
#if QT_CONFIG(tooltip)
        BuldtimeLabel->setToolTip(QCoreApplication::translate("AboutDialog", "https://www.flaticon.com/de/kostenloses-icon/bibliothek_225993", nullptr));
#endif // QT_CONFIG(tooltip)
        BuldtimeLabel->setText(QCoreApplication::translate("AboutDialog", "Buildtime: __DATE__ TIME", nullptr));
        AuthorLabel->setText(QCoreApplication::translate("AboutDialog", "Erstellt von: Eric H\303\274bel", nullptr));
        VersionLabel->setText(QCoreApplication::translate("AboutDialog", "Version: Ver", nullptr));
        DateLabel->setText(QCoreApplication::translate("AboutDialog", "Datum: 15.06. - 18.06.", nullptr));
        VersionHistoryTextBrowser->setHtml(QCoreApplication::translate("AboutDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9.75pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt; font-weight:704;\">Versionsgeschichte:</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">- Ver 0.3 (15.06.): erste GUI, Klasse Person hinzugef\303\274gt (hinzuf\303\274gen, bearbeiten, l\303\266schen, itern laden/speichern)</span></p>\n"
"<p style=\""
                        " margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">- Ver 0.5 (16.06.): Fehlerkorrektur, Klasse Medium -&gt; Buch &amp; CD hinzugef\303\274gt, Symbole &amp; Statusbar-Tipps hinzugef\303\274gt, Dark Theme</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">- Ver 0.7 (17.06.): Fehlerkorrektur, Ausleihe programmiert mit Extra-Dialog, Klasse Lend hinzugef\303\274gt, simpler \303\234ber-Dialog</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">- Ver 0.8 (18.06.): sch\303\266neren \303\234ber-Dialog hinzugef\303\274gt, Verwaltungsklassen f\303\274r Klassen erstellt, Icons</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text"
                        "-indent:0px;\"><span style=\" font-size:9pt;\"><br /></span><a href=\"https://github.com/Computer-Freak-2004/Medienverleih\"><span style=\" font-family:'Sans Serif'; font-size:10pt; text-decoration: underline; color:#3daee9;\">GitHub Link</span></a></p></body></html>", nullptr));
        AboutCloseButton->setText(QCoreApplication::translate("AboutDialog", "Schlie\303\237en", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AboutDialog: public Ui_AboutDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTDIALOG_H
