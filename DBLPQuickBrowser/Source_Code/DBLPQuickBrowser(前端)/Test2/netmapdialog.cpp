#include "netmapdialog.h"
#include "ui_netmapdialog.h"
#include <QVBoxLayout>
//浏览器DIALOG
NetMapDialog::NetMapDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NetMapDialog)
{
    ui->setupUi(this);
    lineUrl = new QLineEdit;
    lineUrl->setText("http://xueshu.baidu.com/s?wd=DBLP&rsv_bp=0&tn=SE_baiduxueshu_c1gjeupa&rsv_spt=3&ie=utf-8&f=8&rsv_sug2=0&sc_f_para=sc_tasktype%3D%7BfirstSimpleSearch%7D");
    connect(lineUrl,SIGNAL(returnPressed()),this,SLOT(loadNavigate()));
    webWidget = new QAxWidget;
    //设置ActiveX控件为IEMicrosoft Web Browser
    //设置ActiveX控件的id，最有效的方式就是使用UUID
    //此处的{8856F961-340A-11D0-A96B-00C04FD705A2}就是Microsoft Web Browser控件的UUID
    webWidget->setControl(QString::fromUtf8("{8856F961-340A-11D0-A96B-00C04FD705A2}"));
    webWidget->setObjectName(QString::fromUtf8("webWidget"));//设置控件的名称
    webWidget->setFocusPolicy(Qt::StrongFocus);//设置控件接收键盘焦点的方式：鼠标单击、Tab键
    webWidget->setProperty("DisplayAlerts",false); //不显示任何警告信息。
    webWidget->setProperty("DisplayScrollBars",true); // 显示滚动条

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(lineUrl);
    mainLayout->addWidget(webWidget);
    setLayout(mainLayout);
    loadNavigate();
    //setWindowState(Qt::WindowMaximized);//最大化
}

void NetMapDialog::loadNavigate()
{
  QString sUrl = lineUrl->text().trimmed();
  webWidget->dynamicCall("Navigate(const QString&)",sUrl);
}

NetMapDialog::~NetMapDialog()
{
    delete ui;
}

