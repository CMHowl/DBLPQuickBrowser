#ifndef ALLAUTHORDIALOG_H
#define ALLAUTHORDIALOG_H

#include <QDialog>
#include <string>
using namespace std;
//分析前一百名作者dialog
namespace Ui {
class AllauthorDialog;
}

class AllauthorDialog : public QDialog
{
    Q_OBJECT

public:
    string DBLP_URL2="G:\\dblp\\src\\";
    explicit AllauthorDialog(QWidget *parent = 0);
    ~AllauthorDialog();

private slots:
    void Show_All();

private:
    Ui::AllauthorDialog *ui;
};

#endif // ALLAUTHORDIALOG_H
