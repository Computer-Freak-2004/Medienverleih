#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_ShowPersonTableButton_clicked();

    void on_AddPersonButton_clicked();

    void on_DeletePersonButton_clicked();

    void on_SavePersonTableButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
