using namespace std;

namespace Ui {
    class MainWindow; // Forward declaration
    class AddLendDialog;
}

class ManageBook{
public:
    // statische Memberfunk. benötigen keine Instanz
    static void AddBook(Ui::MainWindow *ui);
    static void DeleteBook(Ui::MainWindow *ui);
    static void SaveBookTable(Ui::MainWindow *ui);
    static void LoadBookTable(Ui::MainWindow *ui);
    static void LoadBookTable(Ui::AddLendDialog *ui);

};
