#include "allauthordialog.h"
#include "ui_allauthordialog.h"
#include <fstream>
#include <QHeaderView>
#include <QString>
#include <string>
#include <QProgressBar>
#include <stdlib.h>
#include <sstream>
using namespace std;

AllauthorDialog::AllauthorDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AllauthorDialog)
{
    ui->setupUi(this);
    Show_All();
    //添加构件到单元格，如按钮，进度条等
//       QProgressBar *pgbar = new QProgressBar(ui->tableWidget);
//       pgbar->setTextVisible(false);
//       ui->tableWidget->setCellWidget(row,column,pgbar);
}

AllauthorDialog::~AllauthorDialog()
{
    delete ui;
}

int str2int(string string_temp)
{
    int int_temp;
    stringstream stream(string_temp);
    stream>>int_temp;
    return int_temp;
}

string int2str(int int_temp)
{
    string string_temp;
    stringstream stream;
    stream<<int_temp;
    stream>>string_temp;
    return string_temp;
}

void AllauthorDialog::Show_All()
{
    int maximum;
    ui->tableWidget->clear();
    //QString tempInput=ui->lineEdit->text();
    string temp_name,temp_frequence;
    //ifstream infile("G:\\dblp\\src\\allauthor_result.txt", ios::in);
    ifstream infile(DBLP_URL2+"allauthor_result.txt", ios::in);
    QStringList header;
    header<<QString::fromLocal8Bit("作者名")<<QString::fromLocal8Bit("出版数")
    <<QString::fromLocal8Bit("比重");
    ui->tableWidget->setHorizontalHeaderLabels(header);
    ui->tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{'微软雅黑'}");
    ui->tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color:rgb(49, 54, 59)}");
    ui->tableWidget->verticalHeader()->setStyleSheet("QHeaderView::section{background-color:rgb(49, 54, 59)}");

    for(int i=0;i<100;i++)
    {getline(infile,temp_name);
     getline(infile,temp_frequence);
     //infile>>temp_name>>temp_frequence;
     if(i==0)maximum=str2int(temp_frequence);
     ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::fromStdString(temp_name)));
     ui->tableWidget->setItem(i,1,new QTableWidgetItem(QString::fromStdString(temp_frequence)));
     QProgressBar *pgbar = new QProgressBar(ui->tableWidget);
     pgbar->setTextVisible(false);
     ui->tableWidget->setCellWidget(i,2,pgbar);
     pgbar->setOrientation(Qt::Horizontal);  // 水平方向
     pgbar->setMinimum(0);  // 最小值
     pgbar->setMaximum(maximum);  // 最大值
     pgbar->setValue(str2int(temp_frequence));  // 当前进度
     double dProgress = (pgbar->value() - pgbar->minimum()) * 100.0
                     / (pgbar->maximum() - pgbar->minimum());
     pgbar->setFormat(QString::fromLocal8Bit("当前进度为：%1%").arg(QString::number(dProgress, 'f', 1)));
     pgbar->setAlignment(Qt::AlignRight | Qt::AlignVCenter);  // 对齐方式
     if(i==0)pgbar->setStyleSheet("QProgressBar::chunk{background-color: #ff0066}");
     if(i==1)pgbar->setStyleSheet("QProgressBar::chunk{background-color: #ff9900}");
     if(i==2)pgbar->setStyleSheet("QProgressBar::chunk{background-color: #ffff33}");
     if(i==3)pgbar->setStyleSheet("QProgressBar::chunk{background-color: #66ff33}");
     if(i==4)pgbar->setStyleSheet("QProgressBar::chunk{background-color: #66ffff}");
     }

}
