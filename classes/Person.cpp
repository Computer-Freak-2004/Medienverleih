#include "Person.h"

Person::Person(){
    this->Number = 0;
    this->Name = "";
    this->Address= "";
    this->Age = 0;
    this->Phonenumber = "";
}

void Person::PrintPerson(){
    qDebug() << "Number:" << Number << ", Name:" << Name << ", Address:" << Address << ", Age:" << Age << ", Phonenumber:" << Phonenumber;
}
