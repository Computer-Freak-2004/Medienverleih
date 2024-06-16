#include "ui/mainwindow.h"

#include <QApplication>
#include <QStyle>
#include <QStatusBar>
#include "classes/Person.h"
#include "classes/Book.h"
#include "classes/CD.h"

QList<Person> PersonList;
QList<Book> BookList;
QList<CD> CDList;

QString Ver = "0.5";

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
