#!/bin/bash

# Erstelle das Qt-Projekt
qmake -project "CONFIG+=debug"

# 'QT += widgets' hinzufügen
sed -i '8i\QT += widgets' Medienverleih_0-8.pro

# Konfiguriere qmake
qmake Medienverleih_0-8.pro "CONFIG+=debug"

# Kompiliere das Projekt
make
