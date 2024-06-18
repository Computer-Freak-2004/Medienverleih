using namespace std;

namespace Ui {
    class MainWindow; // Forward declaration
}

class ManageLend{
public:
    // statische Memberfunk. benötigen keine Instanz
    static void Lendaccept(Ui::MainWindow *ui);
    static void DeleteLend(Ui::MainWindow *ui);

    static void SaveLendTable(Ui::MainWindow *ui);
    static void LoadLendTable(Ui::MainWindow *ui);

};
