/********************************************************************************
** Form generated from reading UI file 'netmapdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NETMAPDIALOG_H
#define UI_NETMAPDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_NetMapDialog
{
public:

    void setupUi(QDialog *NetMapDialog)
    {
        if (NetMapDialog->objectName().isEmpty())
            NetMapDialog->setObjectName(QStringLiteral("NetMapDialog"));
        NetMapDialog->resize(800, 800);

        retranslateUi(NetMapDialog);

        QMetaObject::connectSlotsByName(NetMapDialog);
    } // setupUi

    void retranslateUi(QDialog *NetMapDialog)
    {
        NetMapDialog->setWindowTitle(QApplication::translate("NetMapDialog", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class NetMapDialog: public Ui_NetMapDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NETMAPDIALOG_H
