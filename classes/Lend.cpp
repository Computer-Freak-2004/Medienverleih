#include "Lend.h"

using namespace std;

Lend::Lend(){
    this->Number = 0;
    this->PersonNumber = 0;
    this->PersonName = "";
    this->MediaNumber = 0;
    this->MediaTitle = "";
    this->MediaType = "";
    this->LendDate = "";
}

void Lend::PrintLend(){
    qDebug() << "Number:" << Number << ", PersonNumber:" << PersonNumber << ", PersonName:" << PersonName << ", MediaNumber:" << MediaNumber << ", MediaTitle:" << MediaTitle << ", MediaType:" << MediaType << ", LendDate: " << LendDate;
}
