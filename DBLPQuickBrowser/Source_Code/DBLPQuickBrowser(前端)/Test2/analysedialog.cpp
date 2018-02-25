#include "analysedialog.h"
#include "ui_analysedialog.h"
#include <fstream>
#include <QHeaderView>
#include <QString>
using namespace std;

AnalyseDialog::AnalyseDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AnalyseDialog)
{
    ui->setupUi(this);
    setWhatsThis (QString::fromLocal8Bit("输入年份，即可显示相应的年份中排行前十的关键字。本程序带有词条筛选功能，可以打开文本文档replaced_text.txt，手动添加过滤词条"));
}

AnalyseDialog::~AnalyseDialog()
{
    delete ui;
}

void AnalyseDialog::on_pushButton_clicked()
{
    ui->tableWidget->clear();
    QString tempInput=ui->lineEdit->text();
    string temp_name,temp_frequence;
    ifstream infile(DBLP_URL3+"year_analysis\\" + tempInput.toStdString() + ".yea", ios::in);
    QStringList header;
    header<<QString::fromLocal8Bit("关键词")<<QString::fromLocal8Bit("频率");
    ui->tableWidget->setHorizontalHeaderLabels(header);
    ui->tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{'微软雅黑'}");
    for(int i=0;i<10;i++)
    {infile>>temp_name>>temp_frequence;
     ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::fromStdString(temp_name)));
     ui->tableWidget->setItem(i,1,new QTableWidgetItem(QString::fromStdString(temp_frequence)));
    }
}
