// Abgeleitete Klasse CD von Medium hat zusätzlich: CD-nummer, Dauer (min), Genre
#ifndef CD_H
#define CD_H

#include <QString>
#include <QDebug>
using namespace std;
#include "Medium.h"

class CD : public Medium{
public:
    CD();
    int getNumber(){return this->Number;}
    int getDuration(){return this->Duration;}
    QString getGenre(){return this->Genre;}

    void setNumber(int NewNumber){this->Number = NewNumber;}
    void setDuration(int NewDuration){this->Duration = NewDuration;}
    void setGenre(QString NewGenre){this->Genre = NewGenre;}

    void PrintCD();

private:
    int Number;
    int Duration;
    QString Genre;
};

#endif // CD_H
