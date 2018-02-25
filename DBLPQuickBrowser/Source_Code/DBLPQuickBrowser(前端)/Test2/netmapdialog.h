#ifndef NETMAPDIALOG_H
#define NETMAPDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <ActiveQt/QAxWidget>
//浏览器dialog
namespace Ui {
class NetMapDialog;
}

class NetMapDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NetMapDialog(QWidget *parent = 0);
    ~NetMapDialog();

private slots:
  void loadNavigate();

private:
    Ui::NetMapDialog *ui;
    QLineEdit *lineUrl;
    QAxWidget *webWidget;
};

#endif // NETMAPDIALOG_H
