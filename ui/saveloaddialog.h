#ifndef SAVELOADDIALOG_H
#define SAVELOADDIALOG_H

#include <QDialog>
#include <QList>
#include <QCloseEvent>
#include "../classes/Person.h"
#include "../classes/Book.h"
#include "../classes/CD.h"
#include "../classes/Lend.h"

namespace Ui {
class SaveLoadDialog;
}

class SaveLoadDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SaveLoadDialog(QWidget *parent = nullptr);
    ~SaveLoadDialog();

private slots:

    Lend ReadLendDataString(QString str);
    Book ReadBookDataString(QString str);
    CD ReadCDDataString(QString str);
    Person ReadPersonDataString(QString str);

    QString MakeLendDataString(int Index);
    QString MakeBookDataString(int Index);
    QString MakeCDDataString(int Index);
    QString MakePersonDataString(int Index);

    void on_LendSelectPathButton_clicked();

    void on_BookSelectPathButton_clicked();

    void on_CDSelectPathButton_clicked();

    void on_PersonSelectPathButton_clicked();

    void on_SaveLoadOKAbortButtons_accepted();

    void on_SaveLoadOKAbortButtons_rejected();

    void closeEvent(QCloseEvent* event);

private:
    Ui::SaveLoadDialog *ui;
};

#endif // SAVELOADDIALOG_H
