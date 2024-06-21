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
    ui->IconView->setScene(scene);

    QString AppDir = QCoreApplication::applicationDirPath();
    QPixmap Pixmap(":/ProgIcons/icon.png");
    Pixmap = Pixmap.scaled(64, 64, Qt::KeepAspectRatio, Qt::SmoothTransformation);

    if (!Pixmap.isNull()) {
        QGraphicsPixmapItem * PixmapItem = new QGraphicsPixmapItem(Pixmap);
        scene->addItem(PixmapItem);
        qDebug() << "Image loaded!";
    }

    QPalette palette = ui->AuthorLabel->palette();
    QColor TextColor = palette.color(QPalette::WindowText);
    qDebug() << "Text color:" << TextColor;
    if (TextColor.redF() > 0.7 && TextColor.greenF() > 0.7 && TextColor.blueF() > 0.7){ // bei DarkMode Farben invertieren, wenn Text (fast) weiß
        QImage image = Pixmap.toImage();
        image.invertPixels();

        QPixmap invertedPixmap = QPixmap::fromImage(image);

        if (!Pixmap.isNull()) {
            QGraphicsPixmapItem * pixmapItem = new QGraphicsPixmapItem(invertedPixmap);
            scene->addItem(pixmapItem);
            qDebug() << "Inverted Image loaded!";
        }
    }

    #ifdef Q_OS_WIN
    ui->AboutCloseButton->setIcon(QIcon(":WindowsIcons/OK.png"));
    this->setWindowIcon(QIcon(":WindowsIcons/Info.png"));
    #endif
}

AboutDialog::~AboutDialog(){
    delete ui;
}

void AboutDialog::on_AboutCloseButton_clicked(){
    accept();
}

