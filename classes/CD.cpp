#include "CD.h"

CD::CD(){
    this->Number = 0;
    this->Duration = 0;
    this->Genre = "";
}

void CD::PrintCD(){
    qDebug() << "Nummer:" << Number << "Titel:" << Title << ", Autor:" << Author << ", Jahr:" << Year << ", Dauer:" << Duration << ", Genre:" << Genre << ", Publisher:" << Publisher;
}
