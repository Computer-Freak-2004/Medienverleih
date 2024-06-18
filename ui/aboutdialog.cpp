#include "aboutdialog.h"
#include "ui_aboutdialog.h"
#include <QDebug>
#include <QString>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QCoreApplication>

extern QString Ver;
extern QString AppDir;

AboutDialog::AboutDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AboutDialog)
{
    ui->setupUi(this);
    // Label setzen
    ui->VersionLabel->setText("Version: " + Ver);
    QString VersionString = QStringLiteral("Buildtime: ") + QString(__DATE__) + " " + QString(__TIME__);
    ui->BuldtimeLabel->setText(VersionString);

    // Icon setzen
    QGraphicsScene * scene = new QGraphicsScene(0,0,64,64, ui->IconView);
    scene->setBackgroundBrush(Qt::blue);
    ui->IconView->setScene(scene);

    QString AppDir = QCoreApplication::applicationDirPath();
    QPixmap pixmap(AppDir + "/ui/icon.png");
    pixmap = pixmap.scaled(64, 64, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    if (!pixmap.isNull()) {
        QGraphicsPixmapItem * pixmapItem = new QGraphicsPixmapItem(pixmap);
        scene->addItem(pixmapItem);
        qDebug() << "Image loaded!";
    }

    QIcon icon(AppDir + "/ui/icon.png");
    setWindowIcon(icon);
}

AboutDialog::~AboutDialog(){
    delete ui;
}

void AboutDialog::on_AboutCloseButton_clicked(){
    accept();
}

