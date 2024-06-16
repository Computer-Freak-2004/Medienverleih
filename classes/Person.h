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

    void setNumber(int Nr){this->Number = Nr;}
    void setName(QString name){this->Name = name;}
    void setAddress(QString address){this->Address = address;}
    void setAge(int age){this->Age = age;}
    void setPhoneNumber(QString phonenr){this->Phonenumber = phonenr;}

    void PrintPerson(){qDebug() << "Number:" << Number << ", Name:" << Name << ", Address:" << Address
                 << ", Age:" << Age << ", Phonenumber:" << Phonenumber;}

private:
    int Number;
    QString Name;
    QString Address;
    int Age;
    QString Phonenumber;
};
