#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "addlenddialog.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_AddNewLendButton_clicked();
    void LendacceptSlot();
    void LendrejectSlot();
    void on_DeleteLendButton_clicked();
    void on_SaveLendTableButton_clicked();

    void on_AddPersonButton_clicked();
    void on_DeletePersonButton_clicked();
    void on_SavePersonTableButton_clicked();

    void on_AddBookButton_clicked();
    void on_DeleteBookButton_clicked();
    void on_SaveBookTableButton_clicked();

    void on_AddCDButton_clicked();
    void on_DeleteCDButton_clicked();
    void on_SaveCDTableButton_clicked();

    void on_MainTabWidget_currentChanged(int index);

    void on_actionBeenden_triggered();

    void on_actionDefault_Theme_triggered();

    void on_actionDark_Theme_triggered();

    void on_action_ber_triggered();

    void AboutacceptSlot();

private:
    Ui::MainWindow *ui;
    QStyle *defaultStyle;
    QPalette defaultPalette;
};
#endif // MAINWINDOW_H
