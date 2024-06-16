# Projekt erstellen
qmake -project
# Zeile in Makefile schreiben, damit es kompiliert
sed -i '8i\QT += widgets' Medienverleih_0-3.pro
# erstellen
qmake
make


