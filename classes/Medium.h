// Basisklasse Medium hat: Titel, Autor, Jahr
#ifndef MEDIUM_H
#define MEDIUM_H

#include <QString>
#include <QDebug>
using namespace std;

class Medium{
public:
    Medium();
    QString getTitle(){return this->Title;}
    QString getAuthor(){return this->Author;}
    int getYear(){return this->Year;}
    QString getPublisher(){return this->Publisher;}

    void setTitle(QString NewTitle){this->Title = NewTitle;}
    void setAuthor(QString NewAuthor){this->Author = NewAuthor;}
    void setYear(int NewYear){this->Year = NewYear;}
    void setPublisher(QString NewPublisher){this->Publisher = NewPublisher;}

protected: // nicht private, damit abgeleitete Klassen drauf zugreifen können
    QString Title;
    QString Author;
    int Year;
    QString Publisher;

};
#endif // MEDIUM_H
