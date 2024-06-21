// TODO: automatisches Speichern (bei Fehler wieder zum voherigen Tab zurückgehen),

#include "ui/mainwindow.h"

#include <QApplication>
#include <QStyle>
#include <QStatusBar>
#include <QTranslator>
#include <QLocale>
#include <QLibraryInfo>
#include "classes/Person.h"
#include "classes/Book.h"
#include "classes/CD.h"
#include "classes/Lend.h"

QList<Person> PersonList;
QList<Book> BookList;
QList<CD> CDList;
QList<Lend> LendList;

// Variablen werden für Auswahl im AddLendDialog genutzt
int PersonRow = -1;
int MediaType = 0; //0= Book, 1=CD
int BookRow =-1;
int CDRow = -1;

// für persistente Pfade im SaveLoadDialog
QString LendPath = "";
QString BookPath = "";
QString CDPath = "";
QString PersonPath = "";

QString Ver = "1.0";

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    MainWindow w;

    QLocale::setDefault(QLocale(QLocale::German, QLocale::Germany));

    #ifdef Q_OS_WIN
    qApp->setStyle("Fusion");
    #else
    qApp->setStyle("gtk2");
    #endif
    qApp->setPalette(qApp->style()->standardPalette());
    qApp->setStyleSheet(""); // Reset the style sheet
    
    w.statusBar()->showMessage("Wilkommen zum Medienverleih!");
    w.setWindowTitle("Medienverleih " + Ver + " (Buildtime: " + __DATE__ + " " + __TIME__ + ")");

    w.show();

    return a.exec();
}
