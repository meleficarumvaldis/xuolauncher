/********************************************************************************
** Form generated from reading UI file 'launcherwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LAUNCHERWINDOW_H
#define UI_LAUNCHERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LauncherWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTabWidget *tw_Main;
    QWidget *tb_Server;
    QTabWidget *tw_Server;
    QWidget *tb_Config;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_15;
    QHBoxLayout *horizontalLayout_12;
    QVBoxLayout *verticalLayout_7;
    QLabel *lb_profileName;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *lb_clientPath;
    QVBoxLayout *verticalLayout_8;
    QLineEdit *le_ProfileName;
    QLineEdit *le_ServerAddress;
    QHBoxLayout *horizontalLayout_9;
    QLineEdit *le_ServerAccount;
    QCheckBox *cb_LaunchAutologin;
    QHBoxLayout *horizontalLayout_10;
    QLineEdit *le_ServerPassword;
    QCheckBox *cb_ServerShowPassword;
    QCheckBox *cb_LaunchSavePassword;
    QHBoxLayout *horizontalLayout_11;
    QLineEdit *le_ServerClientPath;
    QToolButton *tb_SetClientPath;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *pb_ServerAdd;
    QPushButton *pb_ServerSave;
    QPushButton *pb_ServerRemove;
    QWidget *tb_Launcher;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    QLabel *label_18;
    QLabel *label_21;
    QLabel *label_23;
    QLabel *label_13;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLineEdit *le_ServerCharacter;
    QCheckBox *cb_LaunchFastLogin;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *le_ServerClientVersion;
    QLabel *label_24;
    QLineEdit *le_ServerClientVersion_2;
    QCheckBox *cb_ServerUseCrypt;
    QComboBox *cb_ServerClientType;
    QHBoxLayout *horizontalLayout_3;
    QComboBox *cb_XuoPath;
    QToolButton *tb_SetXuoPath;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_5;
    QCheckBox *cb_LaunchSaveAero;
    QCheckBox *cb_LaunchRunUOAM;
    QVBoxLayout *verticalLayout_4;
    QSpacerItem *verticalSpacer;
    QLabel *label_12;
    QLineEdit *le_CommandLine;
    QHBoxLayout *horizontalLayout_6;
    QCheckBox *cb_ServerUseProxy;
    QComboBox *cb_ServerProxy;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_7;
    QCheckBox *cb_LaunchCloseAfterLaunch;
    QSpacerItem *horizontalSpacer;
    QCheckBox *cb_CheckUpdates;
    QCheckBox *cb_Beta;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout_6;
    QLabel *label;
    QListWidget *lw_ProfileList;
    QPushButton *pb_Launch;
    QWidget *tb_Update;
    QFrame *line;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout_13;
    QPushButton *pb_CheckUpdates;
    QPushButton *pb_ApplyUpdates;
    QPushButton *pb_ShowChangelog;
    QPushButton *pb_RestoreSelectedVersion;
    QWidget *layoutWidget5;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_16;
    QListWidget *lw_AvailableUpdates;
    QProgressBar *pb_UpdateProgress;
    QWidget *layoutWidget6;
    QVBoxLayout *verticalLayout_10;
    QLabel *label_17;
    QListWidget *lw_Packages;
    QWidget *tb_Proxy;
    QGroupBox *gb_ProxySocks5;
    QLabel *label_10;
    QLabel *label_11;
    QLineEdit *le_ProxyAccount;
    QLineEdit *le_ProxyPassword;
    QCheckBox *cb_ProxyShowPassword;
    QWidget *layoutWidget7;
    QVBoxLayout *verticalLayout_11;
    QLabel *label_6;
    QListWidget *lw_ProxyList;
    QWidget *layoutWidget8;
    QHBoxLayout *horizontalLayout_15;
    QVBoxLayout *verticalLayout_12;
    QLabel *label_7;
    QLabel *label_8;
    QVBoxLayout *verticalLayout_13;
    QLineEdit *le_ProxyName;
    QHBoxLayout *horizontalLayout_14;
    QLineEdit *le_ProxyAddress;
    QLabel *label_9;
    QLineEdit *le_ProxyPort;
    QWidget *layoutWidget9;
    QHBoxLayout *horizontalLayout_16;
    QPushButton *pb_ProxyAdd;
    QPushButton *pb_ProxySave;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pb_ProxyRemove;
    QWidget *tb_About;
    QWidget *layoutWidget10;
    QHBoxLayout *horizontalLayout_17;
    QVBoxLayout *verticalLayout_14;
    QLabel *label_14;
    QPushButton *pb_Github;
    QPushButton *pb_Website;
    QPushButton *pb_Discord;
    QPushButton *pb_TeamMember;
    QTextBrowser *textBrowser;

    void setupUi(QMainWindow *LauncherWindow)
    {
        if (LauncherWindow->objectName().isEmpty())
            LauncherWindow->setObjectName("LauncherWindow");
        LauncherWindow->resize(681, 434);
        QFont font;
        font.setPointSize(10);
        LauncherWindow->setFont(font);
        LauncherWindow->setStyleSheet(QString::fromUtf8("QTabWidget::tab-bar {\n"
"    left: 0;\n"
"}"));
        centralWidget = new QWidget(LauncherWindow);
        centralWidget->setObjectName("centralWidget");
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        tw_Main = new QTabWidget(centralWidget);
        tw_Main->setObjectName("tw_Main");
        tw_Main->setEnabled(true);
        tb_Server = new QWidget();
        tb_Server->setObjectName("tb_Server");
        tw_Server = new QTabWidget(tb_Server);
        tw_Server->setObjectName("tw_Server");
        tw_Server->setGeometry(QRect(200, 0, 476, 371));
        tb_Config = new QWidget();
        tb_Config->setObjectName("tb_Config");
        layoutWidget = new QWidget(tb_Config);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(0, 5, 466, 331));
        verticalLayout_15 = new QVBoxLayout(layoutWidget);
        verticalLayout_15->setSpacing(6);
        verticalLayout_15->setContentsMargins(11, 11, 11, 11);
        verticalLayout_15->setObjectName("verticalLayout_15");
        verticalLayout_15->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName("horizontalLayout_12");
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName("verticalLayout_7");
        lb_profileName = new QLabel(layoutWidget);
        lb_profileName->setObjectName("lb_profileName");
        lb_profileName->setLayoutDirection(Qt::LeftToRight);
        lb_profileName->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_7->addWidget(lb_profileName);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_7->addWidget(label_3);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName("label_4");
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_7->addWidget(label_4);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName("label_5");
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_7->addWidget(label_5);

        lb_clientPath = new QLabel(layoutWidget);
        lb_clientPath->setObjectName("lb_clientPath");
        lb_clientPath->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_7->addWidget(lb_clientPath);


        horizontalLayout_12->addLayout(verticalLayout_7);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName("verticalLayout_8");
        le_ProfileName = new QLineEdit(layoutWidget);
        le_ProfileName->setObjectName("le_ProfileName");
        le_ProfileName->setMaxLength(256);

        verticalLayout_8->addWidget(le_ProfileName);

        le_ServerAddress = new QLineEdit(layoutWidget);
        le_ServerAddress->setObjectName("le_ServerAddress");
        le_ServerAddress->setMaxLength(256);

        verticalLayout_8->addWidget(le_ServerAddress);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        le_ServerAccount = new QLineEdit(layoutWidget);
        le_ServerAccount->setObjectName("le_ServerAccount");
        le_ServerAccount->setMaxLength(30);

        horizontalLayout_9->addWidget(le_ServerAccount);

        cb_LaunchAutologin = new QCheckBox(layoutWidget);
        cb_LaunchAutologin->setObjectName("cb_LaunchAutologin");

        horizontalLayout_9->addWidget(cb_LaunchAutologin);


        verticalLayout_8->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        le_ServerPassword = new QLineEdit(layoutWidget);
        le_ServerPassword->setObjectName("le_ServerPassword");
        le_ServerPassword->setMaxLength(30);
        le_ServerPassword->setEchoMode(QLineEdit::Password);

        horizontalLayout_10->addWidget(le_ServerPassword);

        cb_ServerShowPassword = new QCheckBox(layoutWidget);
        cb_ServerShowPassword->setObjectName("cb_ServerShowPassword");

        horizontalLayout_10->addWidget(cb_ServerShowPassword);

        cb_LaunchSavePassword = new QCheckBox(layoutWidget);
        cb_LaunchSavePassword->setObjectName("cb_LaunchSavePassword");

        horizontalLayout_10->addWidget(cb_LaunchSavePassword);


        verticalLayout_8->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        le_ServerClientPath = new QLineEdit(layoutWidget);
        le_ServerClientPath->setObjectName("le_ServerClientPath");
        le_ServerClientPath->setMaxLength(256);

        horizontalLayout_11->addWidget(le_ServerClientPath);

        tb_SetClientPath = new QToolButton(layoutWidget);
        tb_SetClientPath->setObjectName("tb_SetClientPath");

        horizontalLayout_11->addWidget(tb_SetClientPath);


        verticalLayout_8->addLayout(horizontalLayout_11);


        horizontalLayout_12->addLayout(verticalLayout_8);


        verticalLayout_15->addLayout(horizontalLayout_12);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_15->addItem(verticalSpacer_2);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        pb_ServerAdd = new QPushButton(layoutWidget);
        pb_ServerAdd->setObjectName("pb_ServerAdd");

        horizontalLayout_8->addWidget(pb_ServerAdd);

        pb_ServerSave = new QPushButton(layoutWidget);
        pb_ServerSave->setObjectName("pb_ServerSave");

        horizontalLayout_8->addWidget(pb_ServerSave);

        pb_ServerRemove = new QPushButton(layoutWidget);
        pb_ServerRemove->setObjectName("pb_ServerRemove");

        horizontalLayout_8->addWidget(pb_ServerRemove);


        verticalLayout_15->addLayout(horizontalLayout_8);

        tw_Server->addTab(tb_Config, QString());
        tb_Launcher = new QWidget();
        tb_Launcher->setObjectName("tb_Launcher");
        layoutWidget1 = new QWidget(tb_Launcher);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(0, 5, 466, 331));
        verticalLayout_5 = new QVBoxLayout(layoutWidget1);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName("verticalLayout");
        label_18 = new QLabel(layoutWidget1);
        label_18->setObjectName("label_18");
        label_18->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(label_18);

        label_21 = new QLabel(layoutWidget1);
        label_21->setObjectName("label_21");
        label_21->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(label_21);

        label_23 = new QLabel(layoutWidget1);
        label_23->setObjectName("label_23");
        label_23->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(label_23);

        label_13 = new QLabel(layoutWidget1);
        label_13->setObjectName("label_13");
        label_13->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(label_13);


        horizontalLayout_4->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        le_ServerCharacter = new QLineEdit(layoutWidget1);
        le_ServerCharacter->setObjectName("le_ServerCharacter");
        le_ServerCharacter->setMaxLength(30);

        horizontalLayout->addWidget(le_ServerCharacter);

        cb_LaunchFastLogin = new QCheckBox(layoutWidget1);
        cb_LaunchFastLogin->setObjectName("cb_LaunchFastLogin");

        horizontalLayout->addWidget(cb_LaunchFastLogin);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        le_ServerClientVersion = new QLineEdit(layoutWidget1);
        le_ServerClientVersion->setObjectName("le_ServerClientVersion");
        le_ServerClientVersion->setMaxLength(30);

        horizontalLayout_2->addWidget(le_ServerClientVersion);

        label_24 = new QLabel(layoutWidget1);
        label_24->setObjectName("label_24");
        label_24->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_24);

        le_ServerClientVersion_2 = new QLineEdit(layoutWidget1);
        le_ServerClientVersion_2->setObjectName("le_ServerClientVersion_2");
        le_ServerClientVersion_2->setMaxLength(30);

        horizontalLayout_2->addWidget(le_ServerClientVersion_2);

        cb_ServerUseCrypt = new QCheckBox(layoutWidget1);
        cb_ServerUseCrypt->setObjectName("cb_ServerUseCrypt");

        horizontalLayout_2->addWidget(cb_ServerUseCrypt);


        verticalLayout_2->addLayout(horizontalLayout_2);

        cb_ServerClientType = new QComboBox(layoutWidget1);
        cb_ServerClientType->addItem(QString());
        cb_ServerClientType->addItem(QString());
        cb_ServerClientType->addItem(QString());
        cb_ServerClientType->addItem(QString());
        cb_ServerClientType->addItem(QString());
        cb_ServerClientType->addItem(QString());
        cb_ServerClientType->addItem(QString());
        cb_ServerClientType->addItem(QString());
        cb_ServerClientType->setObjectName("cb_ServerClientType");

        verticalLayout_2->addWidget(cb_ServerClientType);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        cb_XuoPath = new QComboBox(layoutWidget1);
        cb_XuoPath->setObjectName("cb_XuoPath");

        horizontalLayout_3->addWidget(cb_XuoPath);

        tb_SetXuoPath = new QToolButton(layoutWidget1);
        tb_SetXuoPath->setObjectName("tb_SetXuoPath");

        horizontalLayout_3->addWidget(tb_SetXuoPath);


        verticalLayout_2->addLayout(horizontalLayout_3);


        horizontalLayout_4->addLayout(verticalLayout_2);


        verticalLayout_5->addLayout(horizontalLayout_4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName("verticalLayout_3");
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        cb_LaunchSaveAero = new QCheckBox(layoutWidget1);
        cb_LaunchSaveAero->setObjectName("cb_LaunchSaveAero");

        horizontalLayout_5->addWidget(cb_LaunchSaveAero);


        verticalLayout_3->addLayout(horizontalLayout_5);

        cb_LaunchRunUOAM = new QCheckBox(layoutWidget1);
        cb_LaunchRunUOAM->setObjectName("cb_LaunchRunUOAM");

        verticalLayout_3->addWidget(cb_LaunchRunUOAM);


        verticalLayout_5->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);

        label_12 = new QLabel(layoutWidget1);
        label_12->setObjectName("label_12");

        verticalLayout_4->addWidget(label_12);

        le_CommandLine = new QLineEdit(layoutWidget1);
        le_CommandLine->setObjectName("le_CommandLine");

        verticalLayout_4->addWidget(le_CommandLine);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        cb_ServerUseProxy = new QCheckBox(layoutWidget1);
        cb_ServerUseProxy->setObjectName("cb_ServerUseProxy");

        horizontalLayout_6->addWidget(cb_ServerUseProxy);

        cb_ServerProxy = new QComboBox(layoutWidget1);
        cb_ServerProxy->setObjectName("cb_ServerProxy");

        horizontalLayout_6->addWidget(cb_ServerProxy);


        verticalLayout_4->addLayout(horizontalLayout_6);


        verticalLayout_5->addLayout(verticalLayout_4);

        tw_Server->addTab(tb_Launcher, QString());
        layoutWidget2 = new QWidget(tb_Server);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(10, 370, 661, 28));
        horizontalLayout_7 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        cb_LaunchCloseAfterLaunch = new QCheckBox(layoutWidget2);
        cb_LaunchCloseAfterLaunch->setObjectName("cb_LaunchCloseAfterLaunch");

        horizontalLayout_7->addWidget(cb_LaunchCloseAfterLaunch);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer);

        cb_CheckUpdates = new QCheckBox(layoutWidget2);
        cb_CheckUpdates->setObjectName("cb_CheckUpdates");
        cb_CheckUpdates->setChecked(true);

        horizontalLayout_7->addWidget(cb_CheckUpdates);

        cb_Beta = new QCheckBox(layoutWidget2);
        cb_Beta->setObjectName("cb_Beta");

        horizontalLayout_7->addWidget(cb_Beta);

        layoutWidget3 = new QWidget(tb_Server);
        layoutWidget3->setObjectName("layoutWidget3");
        layoutWidget3->setGeometry(QRect(10, 5, 186, 361));
        verticalLayout_6 = new QVBoxLayout(layoutWidget3);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget3);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(label);

        lw_ProfileList = new QListWidget(layoutWidget3);
        lw_ProfileList->setObjectName("lw_ProfileList");
        lw_ProfileList->setDragDropMode(QAbstractItemView::DragDrop);
        lw_ProfileList->setDefaultDropAction(Qt::MoveAction);

        verticalLayout_6->addWidget(lw_ProfileList);

        pb_Launch = new QPushButton(layoutWidget3);
        pb_Launch->setObjectName("pb_Launch");
        pb_Launch->setEnabled(true);

        verticalLayout_6->addWidget(pb_Launch);

        tw_Main->addTab(tb_Server, QString());
        tb_Update = new QWidget();
        tb_Update->setObjectName("tb_Update");
        line = new QFrame(tb_Update);
        line->setObjectName("line");
        line->setGeometry(QRect(310, 25, 20, 331));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        layoutWidget4 = new QWidget(tb_Update);
        layoutWidget4->setObjectName("layoutWidget4");
        layoutWidget4->setGeometry(QRect(10, 365, 661, 32));
        horizontalLayout_13 = new QHBoxLayout(layoutWidget4);
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_13->setObjectName("horizontalLayout_13");
        horizontalLayout_13->setContentsMargins(0, 0, 0, 0);
        pb_CheckUpdates = new QPushButton(layoutWidget4);
        pb_CheckUpdates->setObjectName("pb_CheckUpdates");

        horizontalLayout_13->addWidget(pb_CheckUpdates);

        pb_ApplyUpdates = new QPushButton(layoutWidget4);
        pb_ApplyUpdates->setObjectName("pb_ApplyUpdates");

        horizontalLayout_13->addWidget(pb_ApplyUpdates);

        pb_ShowChangelog = new QPushButton(layoutWidget4);
        pb_ShowChangelog->setObjectName("pb_ShowChangelog");

        horizontalLayout_13->addWidget(pb_ShowChangelog);

        pb_RestoreSelectedVersion = new QPushButton(layoutWidget4);
        pb_RestoreSelectedVersion->setObjectName("pb_RestoreSelectedVersion");

        horizontalLayout_13->addWidget(pb_RestoreSelectedVersion);

        layoutWidget5 = new QWidget(tb_Update);
        layoutWidget5->setObjectName("layoutWidget5");
        layoutWidget5->setGeometry(QRect(10, 10, 306, 351));
        verticalLayout_9 = new QVBoxLayout(layoutWidget5);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName("verticalLayout_9");
        verticalLayout_9->setContentsMargins(0, 0, 0, 0);
        label_16 = new QLabel(layoutWidget5);
        label_16->setObjectName("label_16");
        label_16->setAlignment(Qt::AlignCenter);

        verticalLayout_9->addWidget(label_16);

        lw_AvailableUpdates = new QListWidget(layoutWidget5);
        lw_AvailableUpdates->setObjectName("lw_AvailableUpdates");

        verticalLayout_9->addWidget(lw_AvailableUpdates);

        pb_UpdateProgress = new QProgressBar(layoutWidget5);
        pb_UpdateProgress->setObjectName("pb_UpdateProgress");
        pb_UpdateProgress->setValue(0);

        verticalLayout_9->addWidget(pb_UpdateProgress);

        layoutWidget6 = new QWidget(tb_Update);
        layoutWidget6->setObjectName("layoutWidget6");
        layoutWidget6->setGeometry(QRect(330, 10, 341, 351));
        verticalLayout_10 = new QVBoxLayout(layoutWidget6);
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setContentsMargins(11, 11, 11, 11);
        verticalLayout_10->setObjectName("verticalLayout_10");
        verticalLayout_10->setContentsMargins(0, 0, 0, 0);
        label_17 = new QLabel(layoutWidget6);
        label_17->setObjectName("label_17");
        label_17->setAlignment(Qt::AlignCenter);

        verticalLayout_10->addWidget(label_17);

        lw_Packages = new QListWidget(layoutWidget6);
        lw_Packages->setObjectName("lw_Packages");

        verticalLayout_10->addWidget(lw_Packages);

        tw_Main->addTab(tb_Update, QString());
        tb_Proxy = new QWidget();
        tb_Proxy->setObjectName("tb_Proxy");
        gb_ProxySocks5 = new QGroupBox(tb_Proxy);
        gb_ProxySocks5->setObjectName("gb_ProxySocks5");
        gb_ProxySocks5->setGeometry(QRect(285, 105, 386, 126));
        gb_ProxySocks5->setCheckable(true);
        gb_ProxySocks5->setChecked(false);
        label_10 = new QLabel(gb_ProxySocks5);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(10, 32, 61, 16));
        label_11 = new QLabel(gb_ProxySocks5);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(10, 62, 71, 16));
        le_ProxyAccount = new QLineEdit(gb_ProxySocks5);
        le_ProxyAccount->setObjectName("le_ProxyAccount");
        le_ProxyAccount->setGeometry(QRect(80, 30, 231, 20));
        le_ProxyAccount->setMaxLength(30);
        le_ProxyPassword = new QLineEdit(gb_ProxySocks5);
        le_ProxyPassword->setObjectName("le_ProxyPassword");
        le_ProxyPassword->setGeometry(QRect(80, 60, 231, 20));
        le_ProxyPassword->setMaxLength(30);
        le_ProxyPassword->setEchoMode(QLineEdit::Password);
        cb_ProxyShowPassword = new QCheckBox(gb_ProxySocks5);
        cb_ProxyShowPassword->setObjectName("cb_ProxyShowPassword");
        cb_ProxyShowPassword->setGeometry(QRect(80, 90, 130, 17));
        layoutWidget7 = new QWidget(tb_Proxy);
        layoutWidget7->setObjectName("layoutWidget7");
        layoutWidget7->setGeometry(QRect(10, 10, 266, 381));
        verticalLayout_11 = new QVBoxLayout(layoutWidget7);
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setContentsMargins(11, 11, 11, 11);
        verticalLayout_11->setObjectName("verticalLayout_11");
        verticalLayout_11->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(layoutWidget7);
        label_6->setObjectName("label_6");
        label_6->setAlignment(Qt::AlignCenter);

        verticalLayout_11->addWidget(label_6);

        lw_ProxyList = new QListWidget(layoutWidget7);
        lw_ProxyList->setObjectName("lw_ProxyList");
        lw_ProxyList->setDragDropMode(QAbstractItemView::DragDrop);
        lw_ProxyList->setDefaultDropAction(Qt::MoveAction);

        verticalLayout_11->addWidget(lw_ProxyList);

        layoutWidget8 = new QWidget(tb_Proxy);
        layoutWidget8->setObjectName("layoutWidget8");
        layoutWidget8->setGeometry(QRect(285, 28, 386, 68));
        horizontalLayout_15 = new QHBoxLayout(layoutWidget8);
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_15->setObjectName("horizontalLayout_15");
        horizontalLayout_15->setContentsMargins(0, 0, 0, 0);
        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setObjectName("verticalLayout_12");
        label_7 = new QLabel(layoutWidget8);
        label_7->setObjectName("label_7");
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_12->addWidget(label_7);

        label_8 = new QLabel(layoutWidget8);
        label_8->setObjectName("label_8");
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_12->addWidget(label_8);


        horizontalLayout_15->addLayout(verticalLayout_12);

        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setSpacing(6);
        verticalLayout_13->setObjectName("verticalLayout_13");
        le_ProxyName = new QLineEdit(layoutWidget8);
        le_ProxyName->setObjectName("le_ProxyName");

        verticalLayout_13->addWidget(le_ProxyName);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName("horizontalLayout_14");
        le_ProxyAddress = new QLineEdit(layoutWidget8);
        le_ProxyAddress->setObjectName("le_ProxyAddress");

        horizontalLayout_14->addWidget(le_ProxyAddress);

        label_9 = new QLabel(layoutWidget8);
        label_9->setObjectName("label_9");

        horizontalLayout_14->addWidget(label_9);

        le_ProxyPort = new QLineEdit(layoutWidget8);
        le_ProxyPort->setObjectName("le_ProxyPort");
        le_ProxyPort->setMaxLength(5);

        horizontalLayout_14->addWidget(le_ProxyPort);


        verticalLayout_13->addLayout(horizontalLayout_14);


        horizontalLayout_15->addLayout(verticalLayout_13);

        layoutWidget9 = new QWidget(tb_Proxy);
        layoutWidget9->setObjectName("layoutWidget9");
        layoutWidget9->setGeometry(QRect(285, 240, 386, 32));
        horizontalLayout_16 = new QHBoxLayout(layoutWidget9);
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_16->setObjectName("horizontalLayout_16");
        horizontalLayout_16->setContentsMargins(0, 0, 0, 0);
        pb_ProxyAdd = new QPushButton(layoutWidget9);
        pb_ProxyAdd->setObjectName("pb_ProxyAdd");

        horizontalLayout_16->addWidget(pb_ProxyAdd);

        pb_ProxySave = new QPushButton(layoutWidget9);
        pb_ProxySave->setObjectName("pb_ProxySave");

        horizontalLayout_16->addWidget(pb_ProxySave);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_16->addItem(horizontalSpacer_2);

        pb_ProxyRemove = new QPushButton(layoutWidget9);
        pb_ProxyRemove->setObjectName("pb_ProxyRemove");

        horizontalLayout_16->addWidget(pb_ProxyRemove);

        tw_Main->addTab(tb_Proxy, QString());
        tb_About = new QWidget();
        tb_About->setObjectName("tb_About");
        layoutWidget10 = new QWidget(tb_About);
        layoutWidget10->setObjectName("layoutWidget10");
        layoutWidget10->setGeometry(QRect(10, 5, 661, 391));
        horizontalLayout_17 = new QHBoxLayout(layoutWidget10);
        horizontalLayout_17->setSpacing(6);
        horizontalLayout_17->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_17->setObjectName("horizontalLayout_17");
        horizontalLayout_17->setContentsMargins(0, 0, 0, 0);
        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setSpacing(6);
        verticalLayout_14->setObjectName("verticalLayout_14");
        label_14 = new QLabel(layoutWidget10);
        label_14->setObjectName("label_14");
        label_14->setPixmap(QPixmap(QString::fromUtf8(":/qt/etc/XUO.png")));

        verticalLayout_14->addWidget(label_14);

        pb_Github = new QPushButton(layoutWidget10);
        pb_Github->setObjectName("pb_Github");

        verticalLayout_14->addWidget(pb_Github);

        pb_Website = new QPushButton(layoutWidget10);
        pb_Website->setObjectName("pb_Website");

        verticalLayout_14->addWidget(pb_Website);

        pb_Discord = new QPushButton(layoutWidget10);
        pb_Discord->setObjectName("pb_Discord");

        verticalLayout_14->addWidget(pb_Discord);

        pb_TeamMember = new QPushButton(layoutWidget10);
        pb_TeamMember->setObjectName("pb_TeamMember");

        verticalLayout_14->addWidget(pb_TeamMember);


        horizontalLayout_17->addLayout(verticalLayout_14);

        textBrowser = new QTextBrowser(layoutWidget10);
        textBrowser->setObjectName("textBrowser");

        horizontalLayout_17->addWidget(textBrowser);

        tw_Main->addTab(tb_About, QString());

        gridLayout->addWidget(tw_Main, 0, 0, 1, 1);

        LauncherWindow->setCentralWidget(centralWidget);
#if QT_CONFIG(shortcut)
        lb_profileName->setBuddy(le_ProfileName);
        label_3->setBuddy(le_ServerAddress);
        label_4->setBuddy(le_ServerAccount);
        label_5->setBuddy(le_ServerPassword);
        lb_clientPath->setBuddy(le_ServerClientPath);
        label_18->setBuddy(le_ServerCharacter);
        label_21->setBuddy(le_ServerClientVersion);
        label_23->setBuddy(cb_ServerClientType);
        label_13->setBuddy(cb_XuoPath);
        label_24->setBuddy(le_ServerClientVersion_2);
        label_12->setBuddy(le_CommandLine);
        label->setBuddy(lw_ProfileList);
        label_16->setBuddy(lw_AvailableUpdates);
        label_17->setBuddy(lw_Packages);
        label_10->setBuddy(le_ProxyAccount);
        label_11->setBuddy(le_ProxyPassword);
        label_6->setBuddy(lw_ProxyList);
        label_7->setBuddy(le_ProxyName);
        label_8->setBuddy(le_ProxyAddress);
        label_9->setBuddy(le_ProxyPort);
#endif // QT_CONFIG(shortcut)
        QWidget::setTabOrder(tw_Main, lw_ProfileList);
        QWidget::setTabOrder(lw_ProfileList, pb_Launch);
        QWidget::setTabOrder(pb_Launch, cb_LaunchCloseAfterLaunch);
        QWidget::setTabOrder(cb_LaunchCloseAfterLaunch, tw_Server);
        QWidget::setTabOrder(tw_Server, le_ProfileName);
        QWidget::setTabOrder(le_ProfileName, le_ServerAddress);
        QWidget::setTabOrder(le_ServerAddress, le_ServerAccount);
        QWidget::setTabOrder(le_ServerAccount, cb_LaunchAutologin);
        QWidget::setTabOrder(cb_LaunchAutologin, le_ServerPassword);
        QWidget::setTabOrder(le_ServerPassword, cb_ServerShowPassword);
        QWidget::setTabOrder(cb_ServerShowPassword, cb_LaunchSavePassword);
        QWidget::setTabOrder(cb_LaunchSavePassword, le_ServerClientPath);
        QWidget::setTabOrder(le_ServerClientPath, tb_SetClientPath);
        QWidget::setTabOrder(tb_SetClientPath, pb_ServerAdd);
        QWidget::setTabOrder(pb_ServerAdd, pb_ServerSave);
        QWidget::setTabOrder(pb_ServerSave, pb_ServerRemove);
        QWidget::setTabOrder(pb_ServerRemove, cb_CheckUpdates);
        QWidget::setTabOrder(cb_CheckUpdates, cb_Beta);
        QWidget::setTabOrder(cb_Beta, le_ServerCharacter);
        QWidget::setTabOrder(le_ServerCharacter, cb_LaunchFastLogin);
        QWidget::setTabOrder(cb_LaunchFastLogin, le_ServerClientVersion);
        QWidget::setTabOrder(le_ServerClientVersion, le_ServerClientVersion_2);
        QWidget::setTabOrder(le_ServerClientVersion_2, cb_ServerUseCrypt);
        QWidget::setTabOrder(cb_ServerUseCrypt, cb_ServerClientType);
        QWidget::setTabOrder(cb_ServerClientType, cb_XuoPath);
        QWidget::setTabOrder(cb_XuoPath, tb_SetXuoPath);
        QWidget::setTabOrder(tb_SetXuoPath, cb_LaunchSaveAero);
        QWidget::setTabOrder(cb_LaunchSaveAero, cb_LaunchRunUOAM);
        QWidget::setTabOrder(cb_LaunchRunUOAM, le_CommandLine);
        QWidget::setTabOrder(le_CommandLine, cb_ServerUseProxy);
        QWidget::setTabOrder(cb_ServerUseProxy, cb_ServerProxy);
        QWidget::setTabOrder(cb_ServerProxy, lw_AvailableUpdates);
        QWidget::setTabOrder(lw_AvailableUpdates, lw_Packages);
        QWidget::setTabOrder(lw_Packages, pb_CheckUpdates);
        QWidget::setTabOrder(pb_CheckUpdates, pb_ApplyUpdates);
        QWidget::setTabOrder(pb_ApplyUpdates, pb_ShowChangelog);
        QWidget::setTabOrder(pb_ShowChangelog, pb_RestoreSelectedVersion);
        QWidget::setTabOrder(pb_RestoreSelectedVersion, lw_ProxyList);
        QWidget::setTabOrder(lw_ProxyList, le_ProxyName);
        QWidget::setTabOrder(le_ProxyName, le_ProxyAddress);
        QWidget::setTabOrder(le_ProxyAddress, le_ProxyPort);
        QWidget::setTabOrder(le_ProxyPort, gb_ProxySocks5);
        QWidget::setTabOrder(gb_ProxySocks5, le_ProxyAccount);
        QWidget::setTabOrder(le_ProxyAccount, le_ProxyPassword);
        QWidget::setTabOrder(le_ProxyPassword, cb_ProxyShowPassword);
        QWidget::setTabOrder(cb_ProxyShowPassword, pb_ProxyAdd);
        QWidget::setTabOrder(pb_ProxyAdd, pb_ProxySave);
        QWidget::setTabOrder(pb_ProxySave, pb_ProxyRemove);
        QWidget::setTabOrder(pb_ProxyRemove, pb_Github);
        QWidget::setTabOrder(pb_Github, pb_Website);
        QWidget::setTabOrder(pb_Website, pb_Discord);
        QWidget::setTabOrder(pb_Discord, pb_TeamMember);
        QWidget::setTabOrder(pb_TeamMember, textBrowser);

        retranslateUi(LauncherWindow);

        tw_Main->setCurrentIndex(0);
        tw_Server->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(LauncherWindow);
    } // setupUi

    void retranslateUi(QMainWindow *LauncherWindow)
    {
        LauncherWindow->setWindowTitle(QCoreApplication::translate("LauncherWindow", "X:UO launcher", nullptr));
#if QT_CONFIG(tooltip)
        lb_profileName->setToolTip(QCoreApplication::translate("LauncherWindow", "Your profile name shown in the Accounts list", nullptr));
#endif // QT_CONFIG(tooltip)
        lb_profileName->setText(QCoreApplication::translate("LauncherWindow", "Profile Na&me:", nullptr));
#if QT_CONFIG(tooltip)
        label_3->setToolTip(QCoreApplication::translate("LauncherWindow", "LoginServer adress", nullptr));
#endif // QT_CONFIG(tooltip)
        label_3->setText(QCoreApplication::translate("LauncherWindow", "Server Address:", nullptr));
#if QT_CONFIG(tooltip)
        label_4->setToolTip(QCoreApplication::translate("LauncherWindow", "Your username", nullptr));
#endif // QT_CONFIG(tooltip)
        label_4->setText(QCoreApplication::translate("LauncherWindow", "&Login:", nullptr));
#if QT_CONFIG(tooltip)
        label_5->setToolTip(QCoreApplication::translate("LauncherWindow", "Password", nullptr));
#endif // QT_CONFIG(tooltip)
        label_5->setText(QCoreApplication::translate("LauncherWindow", "Password:", nullptr));
#if QT_CONFIG(tooltip)
        lb_clientPath->setToolTip(QCoreApplication::translate("LauncherWindow", "Path where your Ultima Online data files are located", nullptr));
#endif // QT_CONFIG(tooltip)
        lb_clientPath->setText(QCoreApplication::translate("LauncherWindow", "UO Data Pat&h:", nullptr));
        le_ProfileName->setText(QString());
#if QT_CONFIG(tooltip)
        le_ServerAddress->setToolTip(QCoreApplication::translate("LauncherWindow", "<html><head/><body><p>If empty, X:UO will use the address set in login.cfg found in the Client Path</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        le_ServerAddress->setText(QCoreApplication::translate("LauncherWindow", "127.0.0.1,2593", nullptr));
        le_ServerAccount->setText(QString());
        cb_LaunchAutologin->setText(QCoreApplication::translate("LauncherWindow", "Auto login", nullptr));
        cb_ServerShowPassword->setText(QCoreApplication::translate("LauncherWindow", "Show", nullptr));
        cb_LaunchSavePassword->setText(QCoreApplication::translate("LauncherWindow", "Save password", nullptr));
        le_ServerClientPath->setText(QString());
        tb_SetClientPath->setText(QCoreApplication::translate("LauncherWindow", "...", nullptr));
        pb_ServerAdd->setText(QCoreApplication::translate("LauncherWindow", "New", nullptr));
        pb_ServerSave->setText(QCoreApplication::translate("LauncherWindow", "Save", nullptr));
        pb_ServerRemove->setText(QCoreApplication::translate("LauncherWindow", "Remove", nullptr));
        tw_Server->setTabText(tw_Server->indexOf(tb_Config), QCoreApplication::translate("LauncherWindow", "Settings", nullptr));
#if QT_CONFIG(tooltip)
        label_18->setToolTip(QCoreApplication::translate("LauncherWindow", "Character Name to use with fast login", nullptr));
#endif // QT_CONFIG(tooltip)
        label_18->setText(QCoreApplication::translate("LauncherWindow", "Use C&haracter:", nullptr));
#if QT_CONFIG(tooltip)
        label_21->setToolTip(QCoreApplication::translate("LauncherWindow", "Client version for the server you want to reach", nullptr));
#endif // QT_CONFIG(tooltip)
        label_21->setText(QCoreApplication::translate("LauncherWindow", "Client Version:", nullptr));
#if QT_CONFIG(tooltip)
        label_23->setToolTip(QCoreApplication::translate("LauncherWindow", "Ultima Online client expansion (let auto if not sure)", nullptr));
#endif // QT_CONFIG(tooltip)
        label_23->setText(QCoreApplication::translate("LauncherWindow", "Client Type:", nullptr));
#if QT_CONFIG(tooltip)
        label_13->setToolTip(QCoreApplication::translate("LauncherWindow", "Path where to store the X:UO Suite (client, assistant, etc.)", nullptr));
#endif // QT_CONFIG(tooltip)
        label_13->setText(QCoreApplication::translate("LauncherWindow", "X:UO Folder:", nullptr));
        le_ServerCharacter->setText(QString());
        cb_LaunchFastLogin->setText(QCoreApplication::translate("LauncherWindow", "Fast login", nullptr));
#if QT_CONFIG(tooltip)
        le_ServerClientVersion->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        le_ServerClientVersion->setText(QCoreApplication::translate("LauncherWindow", "7.0.45.0", nullptr));
#if QT_CONFIG(tooltip)
        label_24->setToolTip(QCoreApplication::translate("LauncherWindow", "Some servers uses different protocol version. If unsure, let it empty)", nullptr));
#endif // QT_CONFIG(tooltip)
        label_24->setText(QCoreApplication::translate("LauncherWindow", "Protocol Version:", nullptr));
#if QT_CONFIG(tooltip)
        le_ServerClientVersion_2->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        le_ServerClientVersion_2->setText(QString());
#if QT_CONFIG(tooltip)
        cb_ServerUseCrypt->setToolTip(QCoreApplication::translate("LauncherWindow", " Use an encrypted client (ex. Sphere or OSI need this)", nullptr));
#endif // QT_CONFIG(tooltip)
        cb_ServerUseCrypt->setText(QCoreApplication::translate("LauncherWindow", "Use Crypt", nullptr));
        cb_ServerClientType->setItemText(0, QCoreApplication::translate("LauncherWindow", "Automatic", nullptr));
        cb_ServerClientType->setItemText(1, QCoreApplication::translate("LauncherWindow", "The Second Age (T2A)", nullptr));
        cb_ServerClientType->setItemText(2, QCoreApplication::translate("LauncherWindow", "Renaissance (RE)", nullptr));
        cb_ServerClientType->setItemText(3, QCoreApplication::translate("LauncherWindow", "Third Dawn (TD)", nullptr));
        cb_ServerClientType->setItemText(4, QCoreApplication::translate("LauncherWindow", "Lord Blackthorn's Revenge (LBR)", nullptr));
        cb_ServerClientType->setItemText(5, QCoreApplication::translate("LauncherWindow", "Age Of Shadows (AOS)", nullptr));
        cb_ServerClientType->setItemText(6, QCoreApplication::translate("LauncherWindow", "Samurai Empire (SE)", nullptr));
        cb_ServerClientType->setItemText(7, QCoreApplication::translate("LauncherWindow", "Stygian Abyss (SA)", nullptr));

        tb_SetXuoPath->setText(QCoreApplication::translate("LauncherWindow", "...", nullptr));
#if QT_CONFIG(tooltip)
        cb_LaunchSaveAero->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        cb_LaunchSaveAero->setText(QCoreApplication::translate("LauncherWindow", "Save aero (for assistant)", nullptr));
        cb_LaunchRunUOAM->setText(QCoreApplication::translate("LauncherWindow", "Run UOAM (UODir/Map/EnhancedMap.exe)", nullptr));
#if QT_CONFIG(tooltip)
        label_12->setToolTip(QCoreApplication::translate("LauncherWindow", "Arguments to pass to CrossUO client", nullptr));
#endif // QT_CONFIG(tooltip)
        label_12->setText(QCoreApplication::translate("LauncherWindow", "Command line:", nullptr));
#if QT_CONFIG(tooltip)
        le_CommandLine->setToolTip(QCoreApplication::translate("LauncherWindow", "Arguments to pass to Cross client", nullptr));
#endif // QT_CONFIG(tooltip)
        cb_ServerUseProxy->setText(QCoreApplication::translate("LauncherWindow", "Use proxy", nullptr));
        tw_Server->setTabText(tw_Server->indexOf(tb_Launcher), QCoreApplication::translate("LauncherWindow", "Advanced", nullptr));
#if QT_CONFIG(tooltip)
        cb_LaunchCloseAfterLaunch->setToolTip(QCoreApplication::translate("LauncherWindow", "Close X:UO Launcher after launching the game", nullptr));
#endif // QT_CONFIG(tooltip)
        cb_LaunchCloseAfterLaunch->setText(QCoreApplication::translate("LauncherWindow", "Close after launch", nullptr));
#if QT_CONFIG(tooltip)
        cb_CheckUpdates->setToolTip(QCoreApplication::translate("LauncherWindow", "Automatically check for updates on start", nullptr));
#endif // QT_CONFIG(tooltip)
        cb_CheckUpdates->setText(QCoreApplication::translate("LauncherWindow", "Check Updates", nullptr));
#if QT_CONFIG(tooltip)
        cb_Beta->setToolTip(QCoreApplication::translate("LauncherWindow", "Use Beta Channel for testing preview releases and help us", nullptr));
#endif // QT_CONFIG(tooltip)
        cb_Beta->setText(QCoreApplication::translate("LauncherWindow", "Beta Channel", nullptr));
        label->setText(QCoreApplication::translate("LauncherWindow", "Accounts", nullptr));
        pb_Launch->setText(QCoreApplication::translate("LauncherWindow", "Launch", nullptr));
        tw_Main->setTabText(tw_Main->indexOf(tb_Server), QCoreApplication::translate("LauncherWindow", "Accounts", nullptr));
        pb_CheckUpdates->setText(QCoreApplication::translate("LauncherWindow", "Check New Versions", nullptr));
        pb_ApplyUpdates->setText(QCoreApplication::translate("LauncherWindow", "Apply Updates", nullptr));
        pb_ShowChangelog->setText(QCoreApplication::translate("LauncherWindow", "Show Changelog", nullptr));
        pb_RestoreSelectedVersion->setText(QCoreApplication::translate("LauncherWindow", "Use Selected Version", nullptr));
        label_16->setText(QCoreApplication::translate("LauncherWindow", "Available Updates", nullptr));
        label_17->setText(QCoreApplication::translate("LauncherWindow", "Pac&kages / Versions", nullptr));
        tw_Main->setTabText(tw_Main->indexOf(tb_Update), QCoreApplication::translate("LauncherWindow", "Update", nullptr));
        gb_ProxySocks5->setTitle(QCoreApplication::translate("LauncherWindow", "SOC&KS5 (with authorization)", nullptr));
        label_10->setText(QCoreApplication::translate("LauncherWindow", "Account:", nullptr));
        label_11->setText(QCoreApplication::translate("LauncherWindow", "Password:", nullptr));
        cb_ProxyShowPassword->setText(QCoreApplication::translate("LauncherWindow", "Show password", nullptr));
        label_6->setText(QCoreApplication::translate("LauncherWindow", "Proxy Server List", nullptr));
        label_7->setText(QCoreApplication::translate("LauncherWindow", "Na&me:", nullptr));
        label_8->setText(QCoreApplication::translate("LauncherWindow", "Address:", nullptr));
        label_9->setText(QCoreApplication::translate("LauncherWindow", "Port:", nullptr));
        pb_ProxyAdd->setText(QCoreApplication::translate("LauncherWindow", "Add New", nullptr));
        pb_ProxySave->setText(QCoreApplication::translate("LauncherWindow", "Save", nullptr));
        pb_ProxyRemove->setText(QCoreApplication::translate("LauncherWindow", "Remove", nullptr));
        tw_Main->setTabText(tw_Main->indexOf(tb_Proxy), QCoreApplication::translate("LauncherWindow", "Proxy", nullptr));
        label_14->setText(QString());
        pb_Github->setText(QCoreApplication::translate("LauncherWindow", "GitHub", nullptr));
        pb_Website->setText(QCoreApplication::translate("LauncherWindow", "WebSite", nullptr));
        pb_Discord->setText(QCoreApplication::translate("LauncherWindow", "Discord", nullptr));
        pb_TeamMember->setText(QCoreApplication::translate("LauncherWindow", "Team Members", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("LauncherWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Noto Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'.SF NS Text'; font-size:13pt;\">      </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'.SF NS Text'; font-size:13pt;\">      </span></p>\n"
"<p align=\"center\" style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'.SF NS Text'; font-size:13pt; font-weight:600;\">CrossUO</span><span style=\" font-family:'.SF NS Text'; font-size"
                        ":13pt;\"> <br />Welcome to CrossUO, the very first Ultima Online client with </span><span style=\" font-family:'.SF NS Text'; font-size:13pt; font-weight:600;\">real native multiplatform support</span><span style=\" font-family:'.SF NS Text'; font-size:13pt;\">.   </span></p></body></html>", nullptr));
        tw_Main->setTabText(tw_Main->indexOf(tb_About), QCoreApplication::translate("LauncherWindow", "About", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LauncherWindow: public Ui_LauncherWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LAUNCHERWINDOW_H
