#ifndef ANALYSEDIALOG_H
#define ANALYSEDIALOG_H

#include <QDialog>
#include <string>
using namespace std;
//分析年份词频dialog
namespace Ui {
class AnalyseDialog;
}

class AnalyseDialog : public QDialog
{
    Q_OBJECT

public:
    string DBLP_URL3="G:\\dblp\\src\\";
    explicit AnalyseDialog(QWidget *parent = 0);
    ~AnalyseDialog();

public slots:
    void on_pushButton_clicked();

private:
    Ui::AnalyseDialog *ui;
};

#endif // ANALYSEDIALOG_H
