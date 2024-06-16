#include "Book.h"
#include <QDebug>

Book::Book(){
    this->Number = 0;
    this->Pages = 0;
}

void Book::PrintBook(){
    qDebug() << "Nummer:" << Number << "Titel:" << Title << ", Autor:" << Author << ", Jahr:" << Year << ", Seiten:" << Pages << ", Verlag:" << Publisher;
}
