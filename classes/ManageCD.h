using namespace std;

namespace Ui {
    class MainWindow; // Forward declaration
    class AddLendDialog;
}

class ManageCD{
public:
    // statische Memberfunk. benötigen keine Instanz
    static void AddCD(Ui::MainWindow *ui);
    static void DeleteCD(Ui::MainWindow *ui);
    static void SaveCDTable(Ui::MainWindow *ui);
    static void LoadCDTable(Ui::MainWindow *ui);
    static void LoadCDTable(Ui::AddLendDialog *ui);

};
