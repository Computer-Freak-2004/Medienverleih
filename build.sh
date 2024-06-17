#!/bin/bash

# Erstelle das Qt-Projekt
qmake -project

# Füge 'QT += widgets' zur .pro-Datei hinzu (an der 8. Zeile)
sed -i '8i\QT += widgets' Medienverleih_0-7.pro

# Konfiguriere qmake für den Debug-Modus
qmake Medienverleih_0-7.pro "CONFIG+=debug"

# Kompiliere das Projekt
make
