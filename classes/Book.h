// Abgeleitete Klasse Buch von Medium hat zusätzlich: Buchnummer, Seiten, Verlag
#ifndef BOOK_H
#define BOOK_H

#include <QString>
#include <QDebug>
using namespace std;
#include "Medium.h"

class Book : public Medium{
public:
    Book();
    int getNumber(){return this->Number;}
    int getPages(){return this->Pages;}

    void setNumber(int NewNumber){this->Number = NewNumber;}
    void setPages(int NewPages){this->Pages = NewPages;}


    void PrintBook();

private:
    int Number;
    int Pages;
};

#endif // BOOK_H
