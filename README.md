
# ![Icon](https://github.com/Computer-Freak-2004/Medienverleih/blob/main/rc/icon_32.png) Medienverleih
Eine simple Medienverleihe geschrieben in C++ und Qt5.

## Funktionen
- Anzeigen, bearbeiten, hinzufügen und löschen von Datenbeständen Ausleihe, Medien (Buch / CD) und Personen
- Speichern/Laden der Datenbestände in Dateien
- Dark Mode 🌙

## Verzeichnisse
- ``classes`` enthält die Klassen für Ausleihe, Person, Medium und daraus abgeleitete Klassen Buch & CD
-  ``rc`` enthält Ressourcen wie Icons und die Ressourcendatei
- ``samplelists`` enthält Beispiellisten
- ``ui`` enthält Klassen für die Benutzeroberfläche, sowohl die UI-Designer Dateien

## Building
Das Programm kann sowohl für Linux als auch für Windows unter [MSYS2](https://www.msys2.org/) kompiliert werden.
Folgendes muss installiert sein und in der PATH-Variable stehen:

 - Qt 5.15.13
 - qmake 3.1
 - g++ 14.1.0 
 - make 4.4.1

Etwas ältere Versionen könnten auch funktionieren, aber die oben genannten funktionieren garantiert.

Dananch das Buildskript ``build.sh`` im Hauptverzeichnis, wo die .pro-Projektdatei ist, ausführen.
Oder manuell folgende Befehle ausführen:

```bash
$ qmake Medienverleih_1-0.pro
$ make -j[No. of Jobs]
```
Eine höhere Anzahl von Jobs kann die Build-Geschwindigkeit stark erhöhen.
# Versionsgeschichte
- Ver 0.3: erste GUI, Klasse Person hinzugefügt (hinzufügen, bearbeiten, löschen, itern laden/speichern)

- Ver 0.5: Fehlerkorrektur, Klasse Medium -> Buch & CD hinzugefügt, Symbole & Statusbar-Tipps hinzugefügt, Dark Theme

- Ver 0.7: Fehlerkorrektur, Ausleihe programmiert mit Extra-Dialog, Klasse Lend hinzugefügt, simpler Über-Dialog

- Ver 0.8: schöneren Über-Dialog hinzugefügt, Verwaltungsklassen für Klassen erstellt, Icons

- Ver 1.0: Korrekturen, Speichern/Laden der Listen hinzugefügt, Fehler falls Ausgeliehen, Tastenkombinationen
