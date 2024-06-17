#include "ui/mainwindow.h"

#include <QApplication>
#include <QStyle>
#include <QStatusBar>
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

QString Ver = "0.7";

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    MainWindow w;

    #ifdef Q_OS_WIN
    qApp->setStyle("Fusion");
    #else
    qApp->setStyle("gtk2");
    #endif
    w.statusBar()->showMessage("Wilkommen zum Medienverleih!");
    w.setWindowTitle("Medienverleih " + Ver + " (Buildtime: " + __DATE__ + " " + __TIME__ + ")");

    w.show();

    return a.exec();
}
