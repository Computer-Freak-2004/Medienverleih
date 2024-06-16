// Person hat: Personnummer, Name, Adresse, Alter, Telefonnummer
#include <QString>
#include <QDebug>
using namespace std;

class Person{
public:
    Person();
    int getNumber(){return this->Number;}
    QString getName(){return this->Name;}
    QString getAddress(){return this->Address;}
    int getAge(){return this->Age;}
    QString getPhoneNumber(){return this->Phonenumber;}

    void setNumber(int NewNr){this->Number = NewNr;}
    void setName(QString NewName){this->Name = NewName;}
    void setAddress(QString NewAddress){this->Address = NewAddress;}
    void setAge(int NewAge){this->Age = NewAge;}
    void setPhoneNumber(QString NewPhoneNumber){this->Phonenumber = NewPhoneNumber;}

    void PrintPerson();

private:
    int Number;
    QString Name;
    QString Address;
    int Age;
    QString Phonenumber;
};
