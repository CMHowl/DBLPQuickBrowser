/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QListWidget *listWidget;
    QTextBrowser *ShowText;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_3;
    QLineEdit *inputName;
    QPushButton *pushButton;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QFrame *line;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(510, 800);
        MainWindow->setSizeIncrement(QSize(0, 0));
        MainWindow->setBaseSize(QSize(500, 500));
        QIcon icon;
        icon.addFile(QStringLiteral("G:/dblp/certificate_256px_1185200_easyicon.net.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(100, 185, 380, 450));
        listWidget->setBaseSize(QSize(300, 100));
        listWidget->setDragEnabled(true);
        listWidget->setDragDropOverwriteMode(true);
        listWidget->setDragDropMode(QAbstractItemView::DragOnly);
        listWidget->setDefaultDropAction(Qt::CopyAction);
        listWidget->setViewMode(QListView::ListMode);
        listWidget->setSortingEnabled(false);
        ShowText = new QTextBrowser(centralWidget);
        ShowText->setObjectName(QStringLiteral("ShowText"));
        ShowText->setGeometry(QRect(100, 640, 380, 100));
        ShowText->setBaseSize(QSize(100, 100));
        ShowText->setAutoFillBackground(false);
        ShowText->setOpenExternalLinks(false);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(180, 10, 300, 60));
        label_2->setPixmap(QPixmap(QString::fromUtf8("G:/dblp/quickbro.png")));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(100, 10, 60, 60));
        label->setFrameShadow(QFrame::Plain);
        label->setPixmap(QPixmap(QString::fromUtf8("G:/dblp/certificate_256px_1185200_easyicon.net.png")));
        label->setScaledContents(true);
        label->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(110, 740, 350, 40));
        QFont font;
        font.setFamily(QStringLiteral("Fixedsys Excelsior 3.01"));
        label_3->setFont(font);
        inputName = new QLineEdit(centralWidget);
        inputName->setObjectName(QStringLiteral("inputName"));
        inputName->setGeometry(QRect(100, 80, 280, 30));
        inputName->setAcceptDrops(true);
        inputName->setDragEnabled(true);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(390, 80, 80, 30));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        pushButton->setFont(font1);
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));
        radioButton = new QRadioButton(centralWidget);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(100, 120, 180, 30));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(radioButton->sizePolicy().hasHeightForWidth());
        radioButton->setSizePolicy(sizePolicy);
        radioButton->setBaseSize(QSize(100, 50));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setBold(false);
        font2.setWeight(50);
        radioButton->setFont(font2);
        QIcon icon1;
        icon1.addFile(QStringLiteral("G:/dblp/1160274.gif"), QSize(), QIcon::Normal, QIcon::Off);
        radioButton->setIcon(icon1);
        radioButton_2 = new QRadioButton(centralWidget);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setGeometry(QRect(300, 120, 180, 30));
        radioButton_2->setBaseSize(QSize(100, 50));
        radioButton_2->setFont(font2);
        QIcon icon2;
        icon2.addFile(QStringLiteral("G:/dblp/people_online_256px_510507_easyicon.net.png"), QSize(), QIcon::Normal, QIcon::Off);
        radioButton_2->setIcon(icon2);
        radioButton_3 = new QRadioButton(centralWidget);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));
        radioButton_3->setGeometry(QRect(100, 150, 180, 30));
        radioButton_3->setBaseSize(QSize(100, 50));
        radioButton_3->setFont(font2);
        QIcon icon3;
        icon3.addFile(QStringLiteral("G:/dblp/beos_people_users_128px_3751_easyicon.net.png"), QSize(), QIcon::Normal, QIcon::Off);
        radioButton_3->setIcon(icon3);
        radioButton_4 = new QRadioButton(centralWidget);
        radioButton_4->setObjectName(QStringLiteral("radioButton_4"));
        radioButton_4->setGeometry(QRect(300, 150, 180, 30));
        radioButton_4->setBaseSize(QSize(100, 50));
        radioButton_4->setFont(font2);
        QIcon icon4;
        icon4.addFile(QStringLiteral("G:/dblp/Search_globe_512px_1176974_easyicon.net.png"), QSize(), QIcon::Normal, QIcon::Off);
        radioButton_4->setIcon(icon4);
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(69, 0, 1, 850));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(5, 20, 50, 50));
        pushButton_2->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon5;
        icon5.addFile(QStringLiteral("G:/dblp/search_1081px_1191635_easyicon.net.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon5);
        pushButton_2->setIconSize(QSize(50, 50));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(5, 120, 50, 50));
        pushButton_3->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon6;
        icon6.addFile(QStringLiteral("G:/dblp/gear_128px_1180534_easyicon.net.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon6);
        pushButton_3->setIconSize(QSize(50, 50));
        pushButton_3->setAutoDefault(false);
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(5, 220, 50, 50));
        pushButton_4->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon7;
        icon7.addFile(QStringLiteral("G:/dblp/Word_807px_1128330_easyicon.net.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon7);
        pushButton_4->setIconSize(QSize(50, 50));
        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(5, 320, 50, 50));
        pushButton_5->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon8;
        icon8.addFile(QStringLiteral("G:/dblp/circular_clock_1172px_1205924_easyicon.net.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_5->setIcon(icon8);
        pushButton_5->setIconSize(QSize(50, 50));
        pushButton_6 = new QPushButton(centralWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(5, 420, 50, 50));
        pushButton_6->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon9;
        icon9.addFile(QStringLiteral("G:/dblp/design_analysis_480px_1124009_easyicon.net.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_6->setIcon(icon9);
        pushButton_6->setIconSize(QSize(50, 50));
        pushButton_7 = new QPushButton(centralWidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(5, 520, 50, 50));
        pushButton_7->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon10;
        icon10.addFile(QStringLiteral("G:/dblp/help_question_mark_128px_11454_easyicon.net.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_7->setIcon(icon10);
        pushButton_7->setIconSize(QSize(50, 50));
        pushButton_8 = new QPushButton(centralWidget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(5, 720, 50, 50));
        pushButton_8->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon11;
        icon11.addFile(QStringLiteral("G:/dblp/system_shutdown_5_256px_541173_easyicon.net.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_8->setIcon(icon11);
        pushButton_8->setIconSize(QSize(50, 50));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        pushButton_3->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "DBLPQuickBrowser", 0));
        label_2->setText(QString());
        label->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "@Powered by 226-Studio(CMH,CJJ,CY&SJY)", 0));
        inputName->setText(QString());
        pushButton->setText(QApplication::translate("MainWindow", "\346\220\234\347\264\242", 0));
        radioButton->setText(QApplication::translate("MainWindow", "\346\214\211\346\240\207\351\242\230\345\220\215\346\237\245\350\257\242", 0));
        radioButton_2->setText(QApplication::translate("MainWindow", "\346\214\211\344\275\234\350\200\205\345\220\215\346\237\245\350\257\242", 0));
        radioButton_3->setText(QApplication::translate("MainWindow", "\345\220\210\344\275\234\344\275\234\350\200\205\346\237\245\350\257\242", 0));
        radioButton_4->setText(QApplication::translate("MainWindow", "\346\250\241\347\263\212\346\220\234\347\264\242", 0));
        pushButton_2->setText(QString());
        pushButton_3->setText(QString());
        pushButton_4->setText(QString());
        pushButton_5->setText(QString());
        pushButton_6->setText(QString());
        pushButton_7->setText(QString());
        pushButton_8->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
