/********************************************************************************
** Form generated from reading UI file 'changelogform.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGELOGFORM_H
#define UI_CHANGELOGFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChangelogForm
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTextBrowser *tb_Log;

    void setupUi(QMainWindow *ChangelogForm)
    {
        if (ChangelogForm->objectName().isEmpty())
            ChangelogForm->setObjectName("ChangelogForm");
        ChangelogForm->resize(795, 571);
        ChangelogForm->setMinimumSize(QSize(200, 200));
        QFont font;
        font.setPointSize(10);
        ChangelogForm->setFont(font);
        centralwidget = new QWidget(ChangelogForm);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        tb_Log = new QTextBrowser(centralwidget);
        tb_Log->setObjectName("tb_Log");
        tb_Log->setOpenLinks(false);

        gridLayout->addWidget(tb_Log, 0, 0, 1, 1);

        ChangelogForm->setCentralWidget(centralwidget);

        retranslateUi(ChangelogForm);

        QMetaObject::connectSlotsByName(ChangelogForm);
    } // setupUi

    void retranslateUi(QMainWindow *ChangelogForm)
    {
        ChangelogForm->setWindowTitle(QCoreApplication::translate("ChangelogForm", "Changelog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChangelogForm: public Ui_ChangelogForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGELOGFORM_H
