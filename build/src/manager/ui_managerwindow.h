/********************************************************************************
** Form generated from reading UI file 'managerwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGERWINDOW_H
#define UI_MANAGERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ManagerWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTabWidget *tw_Main;
    QWidget *tb_Update;
    QListWidget *lw_AvailableUpdates;
    QLabel *label_16;
    QLabel *label_17;
    QListWidget *lw_Packages;
    QFrame *line;
    QWidget *tb_XUOReleaseManager;
    QLineEdit *le_ReleasePath;
    QLabel *label_20;
    QToolButton *tb_SetReleasePath;
    QPushButton *pb_Process;
    QComboBox *cb_ReleaseProduct;
    QLabel *label_24;
    QLabel *label_25;
    QLineEdit *le_ReleaseVersion;
    QLabel *label_26;
    QComboBox *cb_ReleasePlatform;
    QWidget *tb_ReleaseManager;
    QLabel *lbl0;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pb_ShardProcess;
    QLineEdit *le_ShardReleasePath;
    QLineEdit *le_ShardName;
    QLineEdit *le_ShardVersion;
    QToolButton *tb_SetShardReleasePath;
    QWidget *tb_XuoFeatures;
    QPlainTextEdit *pte_XuoFeaturesCode;
    QLabel *label_19;
    QGroupBox *gb_XuoFeaturesEmulator;
    QRadioButton *rb_XuoFeaturesSphere;
    QRadioButton *rb_XuoFeaturesRunUO;
    QRadioButton *rb_XuoFeaturesPOL;
    QListWidget *lw_XuoFeaturesOptions;
    QWidget *tb_XUOAFeatures;
    QLabel *label_14;
    QListWidget *lw_XUOAFeaturesOptions;
    QLabel *label_15;
    QListWidget *lw_XUOAFeaturesScripts;
    QGroupBox *gb_XUOAFeaturesEmulator;
    QRadioButton *rb_XUOAFeaturesSphere;
    QRadioButton *rb_XUOAFeaturesRunUO;
    QRadioButton *rb_XUOAFeaturesPOL;
    QPlainTextEdit *pte_XUOAFeaturesCode;

    void setupUi(QMainWindow *ManagerWindow)
    {
        if (ManagerWindow->objectName().isEmpty())
            ManagerWindow->setObjectName("ManagerWindow");
        ManagerWindow->resize(681, 429);
        QFont font;
        font.setPointSize(10);
        ManagerWindow->setFont(font);
        ManagerWindow->setStyleSheet(QString::fromUtf8("QTabWidget::tab-bar {\n"
"    left: 0;\n"
"}"));
        centralWidget = new QWidget(ManagerWindow);
        centralWidget->setObjectName("centralWidget");
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        tw_Main = new QTabWidget(centralWidget);
        tw_Main->setObjectName("tw_Main");
        tw_Main->setEnabled(true);
        tb_Update = new QWidget();
        tb_Update->setObjectName("tb_Update");
        lw_AvailableUpdates = new QListWidget(tb_Update);
        lw_AvailableUpdates->setObjectName("lw_AvailableUpdates");
        lw_AvailableUpdates->setGeometry(QRect(10, 30, 311, 356));
        label_16 = new QLabel(tb_Update);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(10, 10, 311, 20));
        label_16->setAlignment(Qt::AlignCenter);
        label_17 = new QLabel(tb_Update);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(340, 10, 331, 20));
        label_17->setAlignment(Qt::AlignCenter);
        lw_Packages = new QListWidget(tb_Update);
        lw_Packages->setObjectName("lw_Packages");
        lw_Packages->setGeometry(QRect(340, 31, 331, 356));
        line = new QFrame(tb_Update);
        line->setObjectName("line");
        line->setGeometry(QRect(320, 30, 20, 356));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        tw_Main->addTab(tb_Update, QString());
        tb_XUOReleaseManager = new QWidget();
        tb_XUOReleaseManager->setObjectName("tb_XUOReleaseManager");
        le_ReleasePath = new QLineEdit(tb_XUOReleaseManager);
        le_ReleasePath->setObjectName("le_ReleasePath");
        le_ReleasePath->setEnabled(false);
        le_ReleasePath->setGeometry(QRect(80, 6, 566, 20));
        label_20 = new QLabel(tb_XUOReleaseManager);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(10, 8, 71, 16));
        tb_SetReleasePath = new QToolButton(tb_XUOReleaseManager);
        tb_SetReleasePath->setObjectName("tb_SetReleasePath");
        tb_SetReleasePath->setGeometry(QRect(650, 5, 22, 22));
        pb_Process = new QPushButton(tb_XUOReleaseManager);
        pb_Process->setObjectName("pb_Process");
        pb_Process->setEnabled(false);
        pb_Process->setGeometry(QRect(5, 339, 666, 51));
        cb_ReleaseProduct = new QComboBox(tb_XUOReleaseManager);
        cb_ReleaseProduct->addItem(QString());
        cb_ReleaseProduct->addItem(QString());
        cb_ReleaseProduct->addItem(QString());
        cb_ReleaseProduct->setObjectName("cb_ReleaseProduct");
        cb_ReleaseProduct->setGeometry(QRect(80, 30, 186, 20));
        label_24 = new QLabel(tb_XUOReleaseManager);
        label_24->setObjectName("label_24");
        label_24->setGeometry(QRect(10, 30, 71, 20));
        label_25 = new QLabel(tb_XUOReleaseManager);
        label_25->setObjectName("label_25");
        label_25->setGeometry(QRect(10, 82, 71, 16));
        le_ReleaseVersion = new QLineEdit(tb_XUOReleaseManager);
        le_ReleaseVersion->setObjectName("le_ReleaseVersion");
        le_ReleaseVersion->setEnabled(true);
        le_ReleaseVersion->setGeometry(QRect(80, 80, 186, 20));
        label_26 = new QLabel(tb_XUOReleaseManager);
        label_26->setObjectName("label_26");
        label_26->setGeometry(QRect(10, 55, 71, 20));
        cb_ReleasePlatform = new QComboBox(tb_XUOReleaseManager);
        cb_ReleasePlatform->addItem(QString());
        cb_ReleasePlatform->addItem(QString());
        cb_ReleasePlatform->addItem(QString());
        cb_ReleasePlatform->addItem(QString());
        cb_ReleasePlatform->addItem(QString());
        cb_ReleasePlatform->addItem(QString());
        cb_ReleasePlatform->addItem(QString());
        cb_ReleasePlatform->addItem(QString());
        cb_ReleasePlatform->setObjectName("cb_ReleasePlatform");
        cb_ReleasePlatform->setGeometry(QRect(80, 55, 186, 20));
        tw_Main->addTab(tb_XUOReleaseManager, QString());
        tb_ReleaseManager = new QWidget();
        tb_ReleaseManager->setObjectName("tb_ReleaseManager");
        lbl0 = new QLabel(tb_ReleaseManager);
        lbl0->setObjectName("lbl0");
        lbl0->setGeometry(QRect(10, 5, 59, 16));
        label_2 = new QLabel(tb_ReleaseManager);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 30, 86, 16));
        label_3 = new QLabel(tb_ReleaseManager);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 55, 59, 16));
        pb_ShardProcess = new QPushButton(tb_ReleaseManager);
        pb_ShardProcess->setObjectName("pb_ShardProcess");
        pb_ShardProcess->setEnabled(false);
        pb_ShardProcess->setGeometry(QRect(0, 355, 671, 41));
        le_ShardReleasePath = new QLineEdit(tb_ReleaseManager);
        le_ShardReleasePath->setObjectName("le_ShardReleasePath");
        le_ShardReleasePath->setEnabled(false);
        le_ShardReleasePath->setGeometry(QRect(100, 5, 546, 21));
        le_ShardName = new QLineEdit(tb_ReleaseManager);
        le_ShardName->setObjectName("le_ShardName");
        le_ShardName->setGeometry(QRect(100, 30, 136, 21));
        le_ShardVersion = new QLineEdit(tb_ReleaseManager);
        le_ShardVersion->setObjectName("le_ShardVersion");
        le_ShardVersion->setGeometry(QRect(100, 55, 136, 21));
        tb_SetShardReleasePath = new QToolButton(tb_ReleaseManager);
        tb_SetShardReleasePath->setObjectName("tb_SetShardReleasePath");
        tb_SetShardReleasePath->setGeometry(QRect(650, 5, 22, 22));
        tw_Main->addTab(tb_ReleaseManager, QString());
        tb_XuoFeatures = new QWidget();
        tb_XuoFeatures->setObjectName("tb_XuoFeatures");
        pte_XuoFeaturesCode = new QPlainTextEdit(tb_XuoFeatures);
        pte_XuoFeaturesCode->setObjectName("pte_XuoFeaturesCode");
        pte_XuoFeaturesCode->setGeometry(QRect(300, 85, 371, 306));
        pte_XuoFeaturesCode->setLineWrapMode(QPlainTextEdit::NoWrap);
        pte_XuoFeaturesCode->setReadOnly(true);
        label_19 = new QLabel(tb_XuoFeatures);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(10, 10, 271, 16));
        gb_XuoFeaturesEmulator = new QGroupBox(tb_XuoFeatures);
        gb_XuoFeaturesEmulator->setObjectName("gb_XuoFeaturesEmulator");
        gb_XuoFeaturesEmulator->setGeometry(QRect(300, 30, 371, 61));
        rb_XuoFeaturesSphere = new QRadioButton(gb_XuoFeaturesEmulator);
        rb_XuoFeaturesSphere->setObjectName("rb_XuoFeaturesSphere");
        rb_XuoFeaturesSphere->setGeometry(QRect(5, 30, 106, 17));
        rb_XuoFeaturesSphere->setChecked(true);
        rb_XuoFeaturesRunUO = new QRadioButton(gb_XuoFeaturesEmulator);
        rb_XuoFeaturesRunUO->setObjectName("rb_XuoFeaturesRunUO");
        rb_XuoFeaturesRunUO->setGeometry(QRect(120, 30, 111, 17));
        rb_XuoFeaturesPOL = new QRadioButton(gb_XuoFeaturesEmulator);
        rb_XuoFeaturesPOL->setObjectName("rb_XuoFeaturesPOL");
        rb_XuoFeaturesPOL->setGeometry(QRect(240, 30, 81, 17));
        lw_XuoFeaturesOptions = new QListWidget(tb_XuoFeatures);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(lw_XuoFeaturesOptions);
        __qlistwidgetitem->setCheckState(Qt::Checked);
        QListWidgetItem *__qlistwidgetitem1 = new QListWidgetItem(lw_XuoFeaturesOptions);
        __qlistwidgetitem1->setCheckState(Qt::Checked);
        QListWidgetItem *__qlistwidgetitem2 = new QListWidgetItem(lw_XuoFeaturesOptions);
        __qlistwidgetitem2->setCheckState(Qt::Checked);
        QListWidgetItem *__qlistwidgetitem3 = new QListWidgetItem(lw_XuoFeaturesOptions);
        __qlistwidgetitem3->setCheckState(Qt::Checked);
        QListWidgetItem *__qlistwidgetitem4 = new QListWidgetItem(lw_XuoFeaturesOptions);
        __qlistwidgetitem4->setCheckState(Qt::Checked);
        QListWidgetItem *__qlistwidgetitem5 = new QListWidgetItem(lw_XuoFeaturesOptions);
        __qlistwidgetitem5->setCheckState(Qt::Checked);
        QListWidgetItem *__qlistwidgetitem6 = new QListWidgetItem(lw_XuoFeaturesOptions);
        __qlistwidgetitem6->setCheckState(Qt::Checked);
        QListWidgetItem *__qlistwidgetitem7 = new QListWidgetItem(lw_XuoFeaturesOptions);
        __qlistwidgetitem7->setCheckState(Qt::Checked);
        QListWidgetItem *__qlistwidgetitem8 = new QListWidgetItem(lw_XuoFeaturesOptions);
        __qlistwidgetitem8->setCheckState(Qt::Checked);
        lw_XuoFeaturesOptions->setObjectName("lw_XuoFeaturesOptions");
        lw_XuoFeaturesOptions->setGeometry(QRect(10, 30, 281, 361));
        tw_Main->addTab(tb_XuoFeatures, QString());
        tb_XUOAFeatures = new QWidget();
        tb_XUOAFeatures->setObjectName("tb_XUOAFeatures");
        label_14 = new QLabel(tb_XUOAFeatures);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(10, 10, 181, 16));
        lw_XUOAFeaturesOptions = new QListWidget(tb_XUOAFeatures);
        QListWidgetItem *__qlistwidgetitem9 = new QListWidgetItem(lw_XUOAFeaturesOptions);
        __qlistwidgetitem9->setCheckState(Qt::Checked);
        QListWidgetItem *__qlistwidgetitem10 = new QListWidgetItem(lw_XUOAFeaturesOptions);
        __qlistwidgetitem10->setCheckState(Qt::Checked);
        QListWidgetItem *__qlistwidgetitem11 = new QListWidgetItem(lw_XUOAFeaturesOptions);
        __qlistwidgetitem11->setCheckState(Qt::Checked);
        QListWidgetItem *__qlistwidgetitem12 = new QListWidgetItem(lw_XUOAFeaturesOptions);
        __qlistwidgetitem12->setCheckState(Qt::Checked);
        QListWidgetItem *__qlistwidgetitem13 = new QListWidgetItem(lw_XUOAFeaturesOptions);
        __qlistwidgetitem13->setCheckState(Qt::Checked);
        QListWidgetItem *__qlistwidgetitem14 = new QListWidgetItem(lw_XUOAFeaturesOptions);
        __qlistwidgetitem14->setCheckState(Qt::Checked);
        QListWidgetItem *__qlistwidgetitem15 = new QListWidgetItem(lw_XUOAFeaturesOptions);
        __qlistwidgetitem15->setCheckState(Qt::Checked);
        QListWidgetItem *__qlistwidgetitem16 = new QListWidgetItem(lw_XUOAFeaturesOptions);
        __qlistwidgetitem16->setCheckState(Qt::Checked);
        QListWidgetItem *__qlistwidgetitem17 = new QListWidgetItem(lw_XUOAFeaturesOptions);
        __qlistwidgetitem17->setCheckState(Qt::Checked);
        QListWidgetItem *__qlistwidgetitem18 = new QListWidgetItem(lw_XUOAFeaturesOptions);
        __qlistwidgetitem18->setCheckState(Qt::Unchecked);
        QListWidgetItem *__qlistwidgetitem19 = new QListWidgetItem(lw_XUOAFeaturesOptions);
        __qlistwidgetitem19->setCheckState(Qt::Unchecked);
        QListWidgetItem *__qlistwidgetitem20 = new QListWidgetItem(lw_XUOAFeaturesOptions);
        __qlistwidgetitem20->setCheckState(Qt::Checked);
        QListWidgetItem *__qlistwidgetitem21 = new QListWidgetItem(lw_XUOAFeaturesOptions);
        __qlistwidgetitem21->setCheckState(Qt::Checked);
        QListWidgetItem *__qlistwidgetitem22 = new QListWidgetItem(lw_XUOAFeaturesOptions);
        __qlistwidgetitem22->setCheckState(Qt::Checked);
        QListWidgetItem *__qlistwidgetitem23 = new QListWidgetItem(lw_XUOAFeaturesOptions);
        __qlistwidgetitem23->setCheckState(Qt::Checked);
        QListWidgetItem *__qlistwidgetitem24 = new QListWidgetItem(lw_XUOAFeaturesOptions);
        __qlistwidgetitem24->setCheckState(Qt::Checked);
        QListWidgetItem *__qlistwidgetitem25 = new QListWidgetItem(lw_XUOAFeaturesOptions);
        __qlistwidgetitem25->setCheckState(Qt::Checked);
        QListWidgetItem *__qlistwidgetitem26 = new QListWidgetItem(lw_XUOAFeaturesOptions);
        __qlistwidgetitem26->setCheckState(Qt::Checked);
        QListWidgetItem *__qlistwidgetitem27 = new QListWidgetItem(lw_XUOAFeaturesOptions);
        __qlistwidgetitem27->setCheckState(Qt::Checked);
        QListWidgetItem *__qlistwidgetitem28 = new QListWidgetItem(lw_XUOAFeaturesOptions);
        __qlistwidgetitem28->setCheckState(Qt::Checked);
        QListWidgetItem *__qlistwidgetitem29 = new QListWidgetItem(lw_XUOAFeaturesOptions);
        __qlistwidgetitem29->setCheckState(Qt::Checked);
        QListWidgetItem *__qlistwidgetitem30 = new QListWidgetItem(lw_XUOAFeaturesOptions);
        __qlistwidgetitem30->setCheckState(Qt::Checked);
        QListWidgetItem *__qlistwidgetitem31 = new QListWidgetItem(lw_XUOAFeaturesOptions);
        __qlistwidgetitem31->setCheckState(Qt::Checked);
        QListWidgetItem *__qlistwidgetitem32 = new QListWidgetItem(lw_XUOAFeaturesOptions);
        __qlistwidgetitem32->setCheckState(Qt::Checked);
        QListWidgetItem *__qlistwidgetitem33 = new QListWidgetItem(lw_XUOAFeaturesOptions);
        __qlistwidgetitem33->setCheckState(Qt::Checked);
        lw_XUOAFeaturesOptions->setObjectName("lw_XUOAFeaturesOptions");
        lw_XUOAFeaturesOptions->setGeometry(QRect(10, 30, 181, 361));
        label_15 = new QLabel(tb_XUOAFeatures);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(200, 10, 191, 16));
        lw_XUOAFeaturesScripts = new QListWidget(tb_XUOAFeatures);
        QListWidgetItem *__qlistwidgetitem34 = new QListWidgetItem(lw_XUOAFeaturesScripts);
        __qlistwidgetitem34->setCheckState(Qt::Checked);
        QListWidgetItem *__qlistwidgetitem35 = new QListWidgetItem(lw_XUOAFeaturesScripts);
        __qlistwidgetitem35->setCheckState(Qt::Checked);
        QListWidgetItem *__qlistwidgetitem36 = new QListWidgetItem(lw_XUOAFeaturesScripts);
        __qlistwidgetitem36->setCheckState(Qt::Checked);
        QListWidgetItem *__qlistwidgetitem37 = new QListWidgetItem(lw_XUOAFeaturesScripts);
        __qlistwidgetitem37->setCheckState(Qt::Checked);
        QListWidgetItem *__qlistwidgetitem38 = new QListWidgetItem(lw_XUOAFeaturesScripts);
        __qlistwidgetitem38->setCheckState(Qt::Checked);
        QListWidgetItem *__qlistwidgetitem39 = new QListWidgetItem(lw_XUOAFeaturesScripts);
        __qlistwidgetitem39->setCheckState(Qt::Checked);
        QListWidgetItem *__qlistwidgetitem40 = new QListWidgetItem(lw_XUOAFeaturesScripts);
        __qlistwidgetitem40->setCheckState(Qt::Checked);
        QListWidgetItem *__qlistwidgetitem41 = new QListWidgetItem(lw_XUOAFeaturesScripts);
        __qlistwidgetitem41->setCheckState(Qt::Checked);
        QListWidgetItem *__qlistwidgetitem42 = new QListWidgetItem(lw_XUOAFeaturesScripts);
        __qlistwidgetitem42->setCheckState(Qt::Checked);
        QListWidgetItem *__qlistwidgetitem43 = new QListWidgetItem(lw_XUOAFeaturesScripts);
        __qlistwidgetitem43->setCheckState(Qt::Checked);
        QListWidgetItem *__qlistwidgetitem44 = new QListWidgetItem(lw_XUOAFeaturesScripts);
        __qlistwidgetitem44->setCheckState(Qt::Checked);
        QListWidgetItem *__qlistwidgetitem45 = new QListWidgetItem(lw_XUOAFeaturesScripts);
        __qlistwidgetitem45->setCheckState(Qt::Checked);
        QListWidgetItem *__qlistwidgetitem46 = new QListWidgetItem(lw_XUOAFeaturesScripts);
        __qlistwidgetitem46->setCheckState(Qt::Checked);
        QListWidgetItem *__qlistwidgetitem47 = new QListWidgetItem(lw_XUOAFeaturesScripts);
        __qlistwidgetitem47->setCheckState(Qt::Checked);
        QListWidgetItem *__qlistwidgetitem48 = new QListWidgetItem(lw_XUOAFeaturesScripts);
        __qlistwidgetitem48->setCheckState(Qt::Checked);
        QListWidgetItem *__qlistwidgetitem49 = new QListWidgetItem(lw_XUOAFeaturesScripts);
        __qlistwidgetitem49->setCheckState(Qt::Checked);
        QListWidgetItem *__qlistwidgetitem50 = new QListWidgetItem(lw_XUOAFeaturesScripts);
        __qlistwidgetitem50->setCheckState(Qt::Checked);
        QListWidgetItem *__qlistwidgetitem51 = new QListWidgetItem(lw_XUOAFeaturesScripts);
        __qlistwidgetitem51->setCheckState(Qt::Checked);
        QListWidgetItem *__qlistwidgetitem52 = new QListWidgetItem(lw_XUOAFeaturesScripts);
        __qlistwidgetitem52->setCheckState(Qt::Checked);
        QListWidgetItem *__qlistwidgetitem53 = new QListWidgetItem(lw_XUOAFeaturesScripts);
        __qlistwidgetitem53->setCheckState(Qt::Checked);
        QListWidgetItem *__qlistwidgetitem54 = new QListWidgetItem(lw_XUOAFeaturesScripts);
        __qlistwidgetitem54->setCheckState(Qt::Checked);
        QListWidgetItem *__qlistwidgetitem55 = new QListWidgetItem(lw_XUOAFeaturesScripts);
        __qlistwidgetitem55->setCheckState(Qt::Checked);
        QListWidgetItem *__qlistwidgetitem56 = new QListWidgetItem(lw_XUOAFeaturesScripts);
        __qlistwidgetitem56->setCheckState(Qt::Checked);
        QListWidgetItem *__qlistwidgetitem57 = new QListWidgetItem(lw_XUOAFeaturesScripts);
        __qlistwidgetitem57->setCheckState(Qt::Checked);
        QListWidgetItem *__qlistwidgetitem58 = new QListWidgetItem(lw_XUOAFeaturesScripts);
        __qlistwidgetitem58->setCheckState(Qt::Checked);
        QListWidgetItem *__qlistwidgetitem59 = new QListWidgetItem(lw_XUOAFeaturesScripts);
        __qlistwidgetitem59->setCheckState(Qt::Checked);
        QListWidgetItem *__qlistwidgetitem60 = new QListWidgetItem(lw_XUOAFeaturesScripts);
        __qlistwidgetitem60->setCheckState(Qt::Checked);
        QListWidgetItem *__qlistwidgetitem61 = new QListWidgetItem(lw_XUOAFeaturesScripts);
        __qlistwidgetitem61->setCheckState(Qt::Checked);
        QListWidgetItem *__qlistwidgetitem62 = new QListWidgetItem(lw_XUOAFeaturesScripts);
        __qlistwidgetitem62->setCheckState(Qt::Checked);
        QListWidgetItem *__qlistwidgetitem63 = new QListWidgetItem(lw_XUOAFeaturesScripts);
        __qlistwidgetitem63->setCheckState(Qt::Checked);
        QListWidgetItem *__qlistwidgetitem64 = new QListWidgetItem(lw_XUOAFeaturesScripts);
        __qlistwidgetitem64->setCheckState(Qt::Checked);
        QListWidgetItem *__qlistwidgetitem65 = new QListWidgetItem(lw_XUOAFeaturesScripts);
        __qlistwidgetitem65->setCheckState(Qt::Checked);
        QListWidgetItem *__qlistwidgetitem66 = new QListWidgetItem(lw_XUOAFeaturesScripts);
        __qlistwidgetitem66->setCheckState(Qt::Checked);
        QListWidgetItem *__qlistwidgetitem67 = new QListWidgetItem(lw_XUOAFeaturesScripts);
        __qlistwidgetitem67->setCheckState(Qt::Checked);
        lw_XUOAFeaturesScripts->setObjectName("lw_XUOAFeaturesScripts");
        lw_XUOAFeaturesScripts->setGeometry(QRect(200, 30, 191, 361));
        gb_XUOAFeaturesEmulator = new QGroupBox(tb_XUOAFeatures);
        gb_XUOAFeaturesEmulator->setObjectName("gb_XUOAFeaturesEmulator");
        gb_XUOAFeaturesEmulator->setGeometry(QRect(400, 30, 271, 61));
        rb_XUOAFeaturesSphere = new QRadioButton(gb_XUOAFeaturesEmulator);
        rb_XUOAFeaturesSphere->setObjectName("rb_XUOAFeaturesSphere");
        rb_XUOAFeaturesSphere->setGeometry(QRect(0, 30, 96, 17));
        rb_XUOAFeaturesSphere->setChecked(true);
        rb_XUOAFeaturesRunUO = new QRadioButton(gb_XUOAFeaturesEmulator);
        rb_XUOAFeaturesRunUO->setObjectName("rb_XUOAFeaturesRunUO");
        rb_XUOAFeaturesRunUO->setGeometry(QRect(100, 30, 91, 17));
        rb_XUOAFeaturesPOL = new QRadioButton(gb_XUOAFeaturesEmulator);
        rb_XUOAFeaturesPOL->setObjectName("rb_XUOAFeaturesPOL");
        rb_XUOAFeaturesPOL->setGeometry(QRect(200, 30, 66, 17));
        pte_XUOAFeaturesCode = new QPlainTextEdit(tb_XUOAFeatures);
        pte_XUOAFeaturesCode->setObjectName("pte_XUOAFeaturesCode");
        pte_XUOAFeaturesCode->setGeometry(QRect(400, 85, 271, 306));
        pte_XUOAFeaturesCode->setLineWrapMode(QPlainTextEdit::NoWrap);
        pte_XUOAFeaturesCode->setReadOnly(true);
        tw_Main->addTab(tb_XUOAFeatures, QString());

        gridLayout->addWidget(tw_Main, 0, 0, 1, 1);

        ManagerWindow->setCentralWidget(centralWidget);

        retranslateUi(ManagerWindow);

        tw_Main->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ManagerWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ManagerWindow)
    {
        ManagerWindow->setWindowTitle(QCoreApplication::translate("ManagerWindow", "X:UO launcher", nullptr));
#if QT_CONFIG(whatsthis)
        tw_Main->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        label_16->setText(QCoreApplication::translate("ManagerWindow", "Available Updates", nullptr));
        label_17->setText(QCoreApplication::translate("ManagerWindow", "Packages / Versions", nullptr));
        tw_Main->setTabText(tw_Main->indexOf(tb_Update), QCoreApplication::translate("ManagerWindow", "CrossUO Updates", nullptr));
        label_20->setText(QCoreApplication::translate("ManagerWindow", "Manifest:", nullptr));
        tb_SetReleasePath->setText(QCoreApplication::translate("ManagerWindow", "...", nullptr));
        pb_Process->setText(QCoreApplication::translate("ManagerWindow", "Process", nullptr));
        cb_ReleaseProduct->setItemText(0, QCoreApplication::translate("ManagerWindow", "CrossUO", nullptr));
        cb_ReleaseProduct->setItemText(1, QCoreApplication::translate("ManagerWindow", "X:UO Launcher", nullptr));
        cb_ReleaseProduct->setItemText(2, QCoreApplication::translate("ManagerWindow", "X:UO Assist", nullptr));

        label_24->setText(QCoreApplication::translate("ManagerWindow", "Product:", nullptr));
        label_25->setText(QCoreApplication::translate("ManagerWindow", "Version:", nullptr));
        label_26->setText(QCoreApplication::translate("ManagerWindow", "Platform:", nullptr));
        cb_ReleasePlatform->setItemText(0, QCoreApplication::translate("ManagerWindow", "win64", nullptr));
        cb_ReleasePlatform->setItemText(1, QCoreApplication::translate("ManagerWindow", "win64-beta", nullptr));
        cb_ReleasePlatform->setItemText(2, QCoreApplication::translate("ManagerWindow", "ubuntu", nullptr));
        cb_ReleasePlatform->setItemText(3, QCoreApplication::translate("ManagerWindow", "ubuntu-beta", nullptr));
        cb_ReleasePlatform->setItemText(4, QCoreApplication::translate("ManagerWindow", "manjarolinux", nullptr));
        cb_ReleasePlatform->setItemText(5, QCoreApplication::translate("ManagerWindow", "manjarolinux-beta", nullptr));
        cb_ReleasePlatform->setItemText(6, QCoreApplication::translate("ManagerWindow", "osx", nullptr));
        cb_ReleasePlatform->setItemText(7, QCoreApplication::translate("ManagerWindow", "osx-beta", nullptr));

        tw_Main->setTabText(tw_Main->indexOf(tb_XUOReleaseManager), QCoreApplication::translate("ManagerWindow", "CrossUO Releases", nullptr));
        lbl0->setText(QCoreApplication::translate("ManagerWindow", "Manifest:", nullptr));
        label_2->setText(QCoreApplication::translate("ManagerWindow", "Shard Name:", nullptr));
        label_3->setText(QCoreApplication::translate("ManagerWindow", "Version:", nullptr));
        pb_ShardProcess->setText(QCoreApplication::translate("ManagerWindow", "Process", nullptr));
        tb_SetShardReleasePath->setText(QCoreApplication::translate("ManagerWindow", "...", nullptr));
        tw_Main->setTabText(tw_Main->indexOf(tb_ReleaseManager), QCoreApplication::translate("ManagerWindow", "Shard Release", nullptr));
        label_19->setText(QCoreApplication::translate("ManagerWindow", "Enabled Options:", nullptr));
        gb_XuoFeaturesEmulator->setTitle(QCoreApplication::translate("ManagerWindow", "Output Code for Emulator", nullptr));
        rb_XuoFeaturesSphere->setText(QCoreApplication::translate("ManagerWindow", "Sp&here", nullptr));
        rb_XuoFeaturesRunUO->setText(QCoreApplication::translate("ManagerWindow", "RunUO", nullptr));
        rb_XuoFeaturesPOL->setText(QCoreApplication::translate("ManagerWindow", "POL", nullptr));

        const bool __sortingEnabled = lw_XuoFeaturesOptions->isSortingEnabled();
        lw_XuoFeaturesOptions->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = lw_XuoFeaturesOptions->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("ManagerWindow", "Draw characters status in the world", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = lw_XuoFeaturesOptions->item(1);
        ___qlistwidgetitem1->setText(QCoreApplication::translate("ManagerWindow", "Changing trees to stumps", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = lw_XuoFeaturesOptions->item(2);
        ___qlistwidgetitem2->setText(QCoreApplication::translate("ManagerWindow", "Marking cave tiles", nullptr));
        QListWidgetItem *___qlistwidgetitem3 = lw_XuoFeaturesOptions->item(3);
        ___qlistwidgetitem3->setText(QCoreApplication::translate("ManagerWindow", "No vegetation", nullptr));
        QListWidgetItem *___qlistwidgetitem4 = lw_XuoFeaturesOptions->item(4);
        ___qlistwidgetitem4->setText(QCoreApplication::translate("ManagerWindow", "No fields animation", nullptr));
        QListWidgetItem *___qlistwidgetitem5 = lw_XuoFeaturesOptions->item(5);
        ___qlistwidgetitem5->setText(QCoreApplication::translate("ManagerWindow", "Colored characters state", nullptr));
        QListWidgetItem *___qlistwidgetitem6 = lw_XuoFeaturesOptions->item(6);
        ___qlistwidgetitem6->setText(QCoreApplication::translate("ManagerWindow", "Change fields to tiles", nullptr));
        QListWidgetItem *___qlistwidgetitem7 = lw_XuoFeaturesOptions->item(7);
        ___qlistwidgetitem7->setText(QCoreApplication::translate("ManagerWindow", "Draw aura", nullptr));
        QListWidgetItem *___qlistwidgetitem8 = lw_XuoFeaturesOptions->item(8);
        ___qlistwidgetitem8->setText(QCoreApplication::translate("ManagerWindow", "No draw roofs", nullptr));
        lw_XuoFeaturesOptions->setSortingEnabled(__sortingEnabled);

        tw_Main->setTabText(tw_Main->indexOf(tb_XuoFeatures), QCoreApplication::translate("ManagerWindow", "X:UO Features", nullptr));
        label_14->setText(QCoreApplication::translate("ManagerWindow", "Enabled Options:", nullptr));

        const bool __sortingEnabled1 = lw_XUOAFeaturesOptions->isSortingEnabled();
        lw_XUOAFeaturesOptions->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem9 = lw_XUOAFeaturesOptions->item(0);
        ___qlistwidgetitem9->setText(QCoreApplication::translate("ManagerWindow", "Corpses autoopen", nullptr));
        QListWidgetItem *___qlistwidgetitem10 = lw_XUOAFeaturesOptions->item(1);
        ___qlistwidgetitem10->setText(QCoreApplication::translate("ManagerWindow", "Stealth steps counter", nullptr));
        QListWidgetItem *___qlistwidgetitem11 = lw_XUOAFeaturesOptions->item(2);
        ___qlistwidgetitem11->setText(QCoreApplication::translate("ManagerWindow", "Sound filter", nullptr));
        QListWidgetItem *___qlistwidgetitem12 = lw_XUOAFeaturesOptions->item(3);
        ___qlistwidgetitem12->setText(QCoreApplication::translate("ManagerWindow", "Light filter", nullptr));
        QListWidgetItem *___qlistwidgetitem13 = lw_XUOAFeaturesOptions->item(4);
        ___qlistwidgetitem13->setText(QCoreApplication::translate("ManagerWindow", "Weather filter", nullptr));
        QListWidgetItem *___qlistwidgetitem14 = lw_XUOAFeaturesOptions->item(5);
        ___qlistwidgetitem14->setText(QCoreApplication::translate("ManagerWindow", "Season filter", nullptr));
        QListWidgetItem *___qlistwidgetitem15 = lw_XUOAFeaturesOptions->item(6);
        ___qlistwidgetitem15->setText(QCoreApplication::translate("ManagerWindow", "No death screen", nullptr));
        QListWidgetItem *___qlistwidgetitem16 = lw_XUOAFeaturesOptions->item(7);
        ___qlistwidgetitem16->setText(QCoreApplication::translate("ManagerWindow", "Auto open doors", nullptr));
        QListWidgetItem *___qlistwidgetitem17 = lw_XUOAFeaturesOptions->item(8);
        ___qlistwidgetitem17->setText(QCoreApplication::translate("ManagerWindow", "Tracker", nullptr));
        QListWidgetItem *___qlistwidgetitem18 = lw_XUOAFeaturesOptions->item(9);
        ___qlistwidgetitem18->setText(QCoreApplication::translate("ManagerWindow", "Reserved", nullptr));
        QListWidgetItem *___qlistwidgetitem19 = lw_XUOAFeaturesOptions->item(10);
        ___qlistwidgetitem19->setText(QCoreApplication::translate("ManagerWindow", "Reserved", nullptr));
        QListWidgetItem *___qlistwidgetitem20 = lw_XUOAFeaturesOptions->item(11);
        ___qlistwidgetitem20->setText(QCoreApplication::translate("ManagerWindow", "Fast rotation", nullptr));
        QListWidgetItem *___qlistwidgetitem21 = lw_XUOAFeaturesOptions->item(12);
        ___qlistwidgetitem21->setText(QCoreApplication::translate("ManagerWindow", "Recurse search", nullptr));
        QListWidgetItem *___qlistwidgetitem22 = lw_XUOAFeaturesOptions->item(13);
        ___qlistwidgetitem22->setText(QCoreApplication::translate("ManagerWindow", "Autostart", nullptr));
        QListWidgetItem *___qlistwidgetitem23 = lw_XUOAFeaturesOptions->item(14);
        ___qlistwidgetitem23->setText(QCoreApplication::translate("ManagerWindow", "Ignore staminacheck", nullptr));
        QListWidgetItem *___qlistwidgetitem24 = lw_XUOAFeaturesOptions->item(15);
        ___qlistwidgetitem24->setText(QCoreApplication::translate("ManagerWindow", "Party agent", nullptr));
        QListWidgetItem *___qlistwidgetitem25 = lw_XUOAFeaturesOptions->item(16);
        ___qlistwidgetitem25->setText(QCoreApplication::translate("ManagerWindow", "Shop agent", nullptr));
        QListWidgetItem *___qlistwidgetitem26 = lw_XUOAFeaturesOptions->item(17);
        ___qlistwidgetitem26->setText(QCoreApplication::translate("ManagerWindow", "Tray icon", nullptr));
        QListWidgetItem *___qlistwidgetitem27 = lw_XUOAFeaturesOptions->item(18);
        ___qlistwidgetitem27->setText(QCoreApplication::translate("ManagerWindow", "Sound echo", nullptr));
        QListWidgetItem *___qlistwidgetitem28 = lw_XUOAFeaturesOptions->item(19);
        ___qlistwidgetitem28->setText(QCoreApplication::translate("ManagerWindow", "Animation echo", nullptr));
        QListWidgetItem *___qlistwidgetitem29 = lw_XUOAFeaturesOptions->item(20);
        ___qlistwidgetitem29->setText(QCoreApplication::translate("ManagerWindow", "Effect echo", nullptr));
        QListWidgetItem *___qlistwidgetitem30 = lw_XUOAFeaturesOptions->item(21);
        ___qlistwidgetitem30->setText(QCoreApplication::translate("ManagerWindow", "Map echo", nullptr));
        QListWidgetItem *___qlistwidgetitem31 = lw_XUOAFeaturesOptions->item(22);
        ___qlistwidgetitem31->setText(QCoreApplication::translate("ManagerWindow", "Speech filter", nullptr));
        QListWidgetItem *___qlistwidgetitem32 = lw_XUOAFeaturesOptions->item(23);
        ___qlistwidgetitem32->setText(QCoreApplication::translate("ManagerWindow", "Text replace", nullptr));
        QListWidgetItem *___qlistwidgetitem33 = lw_XUOAFeaturesOptions->item(24);
        ___qlistwidgetitem33->setText(QCoreApplication::translate("ManagerWindow", "Reconnector", nullptr));
        lw_XUOAFeaturesOptions->setSortingEnabled(__sortingEnabled1);

        label_15->setText(QCoreApplication::translate("ManagerWindow", "Enabled Script Groups:", nullptr));

        const bool __sortingEnabled2 = lw_XUOAFeaturesScripts->isSortingEnabled();
        lw_XUOAFeaturesScripts->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem34 = lw_XUOAFeaturesScripts->item(0);
        ___qlistwidgetitem34->setText(QCoreApplication::translate("ManagerWindow", "Information", nullptr));
        QListWidgetItem *___qlistwidgetitem35 = lw_XUOAFeaturesScripts->item(1);
        ___qlistwidgetitem35->setText(QCoreApplication::translate("ManagerWindow", "Text window", nullptr));
        QListWidgetItem *___qlistwidgetitem36 = lw_XUOAFeaturesScripts->item(2);
        ___qlistwidgetitem36->setText(QCoreApplication::translate("ManagerWindow", "Containers search", nullptr));
        QListWidgetItem *___qlistwidgetitem37 = lw_XUOAFeaturesScripts->item(3);
        ___qlistwidgetitem37->setText(QCoreApplication::translate("ManagerWindow", "Ground search", nullptr));
        QListWidgetItem *___qlistwidgetitem38 = lw_XUOAFeaturesScripts->item(4);
        ___qlistwidgetitem38->setText(QCoreApplication::translate("ManagerWindow", "Moving", nullptr));
        QListWidgetItem *___qlistwidgetitem39 = lw_XUOAFeaturesScripts->item(5);
        ___qlistwidgetitem39->setText(QCoreApplication::translate("ManagerWindow", "Resend", nullptr));
        QListWidgetItem *___qlistwidgetitem40 = lw_XUOAFeaturesScripts->item(6);
        ___qlistwidgetitem40->setText(QCoreApplication::translate("ManagerWindow", "Journal", nullptr));
        QListWidgetItem *___qlistwidgetitem41 = lw_XUOAFeaturesScripts->item(7);
        ___qlistwidgetitem41->setText(QCoreApplication::translate("ManagerWindow", "Rename mounts", nullptr));
        QListWidgetItem *___qlistwidgetitem42 = lw_XUOAFeaturesScripts->item(8);
        ___qlistwidgetitem42->setText(QCoreApplication::translate("ManagerWindow", "Buy", nullptr));
        QListWidgetItem *___qlistwidgetitem43 = lw_XUOAFeaturesScripts->item(9);
        ___qlistwidgetitem43->setText(QCoreApplication::translate("ManagerWindow", "Sell", nullptr));
        QListWidgetItem *___qlistwidgetitem44 = lw_XUOAFeaturesScripts->item(10);
        ___qlistwidgetitem44->setText(QCoreApplication::translate("ManagerWindow", "Hide", nullptr));
        QListWidgetItem *___qlistwidgetitem45 = lw_XUOAFeaturesScripts->item(11);
        ___qlistwidgetitem45->setText(QCoreApplication::translate("ManagerWindow", "Move items", nullptr));
        QListWidgetItem *___qlistwidgetitem46 = lw_XUOAFeaturesScripts->item(12);
        ___qlistwidgetitem46->setText(QCoreApplication::translate("ManagerWindow", "Morph", nullptr));
        QListWidgetItem *___qlistwidgetitem47 = lw_XUOAFeaturesScripts->item(13);
        ___qlistwidgetitem47->setText(QCoreApplication::translate("ManagerWindow", "Emote actions", nullptr));
        QListWidgetItem *___qlistwidgetitem48 = lw_XUOAFeaturesScripts->item(14);
        ___qlistwidgetitem48->setText(QCoreApplication::translate("ManagerWindow", "Find/Ignore types", nullptr));
        QListWidgetItem *___qlistwidgetitem49 = lw_XUOAFeaturesScripts->item(15);
        ___qlistwidgetitem49->setText(QCoreApplication::translate("ManagerWindow", "Find arrays", nullptr));
        QListWidgetItem *___qlistwidgetitem50 = lw_XUOAFeaturesScripts->item(16);
        ___qlistwidgetitem50->setText(QCoreApplication::translate("ManagerWindow", "Client options", nullptr));
        QListWidgetItem *___qlistwidgetitem51 = lw_XUOAFeaturesScripts->item(17);
        ___qlistwidgetitem51->setText(QCoreApplication::translate("ManagerWindow", "Corpse search", nullptr));
        QListWidgetItem *___qlistwidgetitem52 = lw_XUOAFeaturesScripts->item(18);
        ___qlistwidgetitem52->setText(QCoreApplication::translate("ManagerWindow", "Extended menu", nullptr));
        QListWidgetItem *___qlistwidgetitem53 = lw_XUOAFeaturesScripts->item(19);
        ___qlistwidgetitem53->setText(QCoreApplication::translate("ManagerWindow", "Buffs", nullptr));
        QListWidgetItem *___qlistwidgetitem54 = lw_XUOAFeaturesScripts->item(20);
        ___qlistwidgetitem54->setText(QCoreApplication::translate("ManagerWindow", "Trading", nullptr));
        QListWidgetItem *___qlistwidgetitem55 = lw_XUOAFeaturesScripts->item(21);
        ___qlistwidgetitem55->setText(QCoreApplication::translate("ManagerWindow", "Friend list", nullptr));
        QListWidgetItem *___qlistwidgetitem56 = lw_XUOAFeaturesScripts->item(22);
        ___qlistwidgetitem56->setText(QCoreApplication::translate("ManagerWindow", "Enemy list", nullptr));
        QListWidgetItem *___qlistwidgetitem57 = lw_XUOAFeaturesScripts->item(23);
        ___qlistwidgetitem57->setText(QCoreApplication::translate("ManagerWindow", "Font color", nullptr));
        QListWidgetItem *___qlistwidgetitem58 = lw_XUOAFeaturesScripts->item(24);
        ___qlistwidgetitem58->setText(QCoreApplication::translate("ManagerWindow", "Extended target tile", nullptr));
        QListWidgetItem *___qlistwidgetitem59 = lw_XUOAFeaturesScripts->item(25);
        ___qlistwidgetitem59->setText(QCoreApplication::translate("ManagerWindow", "Launch", nullptr));
        QListWidgetItem *___qlistwidgetitem60 = lw_XUOAFeaturesScripts->item(26);
        ___qlistwidgetitem60->setText(QCoreApplication::translate("ManagerWindow", "Removed objects position", nullptr));
        QListWidgetItem *___qlistwidgetitem61 = lw_XUOAFeaturesScripts->item(27);
        ___qlistwidgetitem61->setText(QCoreApplication::translate("ManagerWindow", "Extended gumps", nullptr));
        QListWidgetItem *___qlistwidgetitem62 = lw_XUOAFeaturesScripts->item(28);
        ___qlistwidgetitem62->setText(QCoreApplication::translate("ManagerWindow", "Objects property", nullptr));
        QListWidgetItem *___qlistwidgetitem63 = lw_XUOAFeaturesScripts->item(29);
        ___qlistwidgetitem63->setText(QCoreApplication::translate("ManagerWindow", "Character profile", nullptr));
        QListWidgetItem *___qlistwidgetitem64 = lw_XUOAFeaturesScripts->item(30);
        ___qlistwidgetitem64->setText(QCoreApplication::translate("ManagerWindow", "Prompts", nullptr));
        QListWidgetItem *___qlistwidgetitem65 = lw_XUOAFeaturesScripts->item(31);
        ___qlistwidgetitem65->setText(QCoreApplication::translate("ManagerWindow", "Statusbars control", nullptr));
        QListWidgetItem *___qlistwidgetitem66 = lw_XUOAFeaturesScripts->item(32);
        ___qlistwidgetitem66->setText(QCoreApplication::translate("ManagerWindow", "Log out", nullptr));
        QListWidgetItem *___qlistwidgetitem67 = lw_XUOAFeaturesScripts->item(33);
        ___qlistwidgetitem67->setText(QCoreApplication::translate("ManagerWindow", "Timers", nullptr));
        lw_XUOAFeaturesScripts->setSortingEnabled(__sortingEnabled2);

        gb_XUOAFeaturesEmulator->setTitle(QCoreApplication::translate("ManagerWindow", "Output Code for Emulator", nullptr));
        rb_XUOAFeaturesSphere->setText(QCoreApplication::translate("ManagerWindow", "Sp&here", nullptr));
        rb_XUOAFeaturesRunUO->setText(QCoreApplication::translate("ManagerWindow", "RunUO", nullptr));
        rb_XUOAFeaturesPOL->setText(QCoreApplication::translate("ManagerWindow", "POL", nullptr));
        tw_Main->setTabText(tw_Main->indexOf(tb_XUOAFeatures), QCoreApplication::translate("ManagerWindow", "X:UOA Features", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ManagerWindow: public Ui_ManagerWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGERWINDOW_H
