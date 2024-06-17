#ifndef ADDLENDDIALOG_H
#define ADDLENDDIALOG_H

#include <QDialog>
#include <QTableWidgetItem>

namespace Ui {
class AddLendDialog;
}

class AddLendDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddLendDialog(QWidget *parent = nullptr);
    ~AddLendDialog();

private slots:
    void on_DialogOKAbortButtons_accepted();
    void on_DialogOKAbortButtons_rejected();

private:
    Ui::AddLendDialog *ui;
};

#endif // ADDLENDDIALOG_H
