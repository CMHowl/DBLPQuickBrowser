#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include <set>
#include <QXmlStreamReader>
#include <QtGui>
#include <QDrag>
#include "QTextStream"
#include <QIcon>
#include <QWidget>
#include <QLabel>
#include <QListWidget>
#include <QHBoxLayout>
#include <QTime>
#include <sstream>
#include <vector>
#include <QFileDialog>
#include <QMessageBox>
using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    string tempstr;
    set<string> coauthor_tree;
    long long div_finder;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    /*
     ***************功能函数***********************
     *具体作用在mainwindow.cpp中都有说明，此处不作赘述。
     * *******************************************
     */
    void findAuthor_inDBLP();
    void Generate_AuthorList(set<string> MyJointworker);
    void Generate_PublicationList
    (vector<string> Publicationinfo, vector<string> Publicationnode);
    void show_Publication(string search_name);
    void Show_CoauthorReader_main(string search_name);
    void Show_CoauthorReader_author(string search_name);
    void Show_FuzzySearch();
    void Probe_RBTree();


private slots:
    void on_pushButton_clicked();//点击“搜索”按钮

    void on_listWidget_clicked(const QModelIndex &index);//点击列表框

    void on_pushButton_3_clicked();//选择路径按钮

    void on_pushButton_8_clicked();//关闭按钮

    void on_pushButton_5_clicked();//年份词频统计dialog弹出按钮

    void on_pushButton_4_clicked();//前一百名作者dialog弹出按钮

    void on_pushButton_6_clicked();//网页浏览器dialog弹出按钮

private:
    Ui::MainWindow *ui;
    // 为真表示文件没有保存过，为假表示文件已经被保存过了
    bool isUntitled;
    // 保存当前文件的路径
    QString curFile;
    QXmlStreamReader reader;
    int radioButton;
};

#endif // MAINWINDOW_H
