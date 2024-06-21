// Ausleihe hat: Ausleihnummer, Personennr, Pesonenname, Mediennummer, Medientitel, Medientyp, Ausleihdatum
#ifndef LEND_H
#define LEND_H

#include <QString>
#include <QDebug>
using namespace std;

class Lend{
public:
    Lend();
    int getNumber(){return this->Number;}
    int getPersonNumber(){return this->PersonNumber;}
    QString getPersonName(){return this->PersonName;}
    int getMediaNumber(){return this->MediaNumber;}
    QString getMediaTitle(){return this->MediaTitle;}
    QString getMediaType(){return this->MediaType;}
    QString getLendDate(){return this->LendDate;}

    void setNumber(int NewNr){this->Number = NewNr;}
    void setPersonNumber(int NewPersonNumber){this->PersonNumber = NewPersonNumber;}
    void setPersonName(QString NewPersonName){this->PersonName = NewPersonName;}
    void setMediaNumber(int NewMediaNumber){this->MediaNumber = NewMediaNumber;}
    void setMediaTitle(QString NewMediaTitle){this->MediaTitle = NewMediaTitle;}
    void setMediaType(QString NewMediaType){this->MediaType = NewMediaType;}
    void setLendDate(QString NewLendDate){this->LendDate = NewLendDate;}

    void PrintLend();

private:
    int Number;
    int PersonNumber;
    QString PersonName;
    int MediaNumber;
    QString MediaTitle;
    QString MediaType;
    QString LendDate;
};

#endif // LEND_H
