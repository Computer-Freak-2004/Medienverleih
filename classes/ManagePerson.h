#ifndef MANAGEPERSON_H
#define MANAGEPERSON_H

using namespace std;

namespace Ui {
    class MainWindow; // Forward declaration
    class AddLendDialog;
}

class ManagePerson{
public:
    // statische Memberfunk. benötigen keine Instanz
    static void AddPerson(Ui::MainWindow *ui);
    static void DeletePerson(Ui::MainWindow *ui);
    static void SavePersonTable(Ui::MainWindow *ui);
    static void LoadPersonTable(Ui::MainWindow *ui);
    static void LoadPersonTable(Ui::AddLendDialog *ui);

};

#endif //MANAGEPERSON_H
