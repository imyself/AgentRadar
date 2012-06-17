/********************************************************************************
** Form generated from reading UI file 'agentradar.ui'
**
** Created: Sat Jun 16 20:09:09 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AGENTRADAR_H
#define UI_AGENTRADAR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>
#include "myglwidget.h"
#include "qList.h"

QT_BEGIN_NAMESPACE

class Ui_AgentRadarClass
{
public:
    QWidget *centralWidget;
    MyGLWidget *widget;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_4;
    QCheckBox *checkBox_5;
    QSpinBox *spinBox;
    QLabel *label;
    QTabWidget *tabWidget;
    QWidget *tab;
    QCheckBox *LeftArcCheckbox;
    QCheckBox *RightArcCheckbox;
    QLabel *label_2;
    QSpinBox *spinBox_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_3;
    QFrame *line;
    QLabel *label_4;
    QCheckBox *checkBox_6;
    QCheckBox *checkBox_7;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QLabel *label_5;
    QDoubleSpinBox *doubleSpinBox;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QFrame *line_2;
    QFrame *line_3;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    qList *listWidget;
    QLabel *label_14;
    QSpinBox *spinBox_3;
    QLabel *label_15;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QWidget *tab_2;
    QLabel *label_17;
    QCheckBox *checkBox_8;
    QCheckBox *checkBox_9;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QDoubleSpinBox *doubleSpinBox_2;
    QLabel *label_18;
    QFrame *line_4;
    QLabel *label_19;
    QCheckBox *checkBox_10;
    QCheckBox *checkBox_11;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QDoubleSpinBox *doubleSpinBox_3;
    QLabel *label_20;
    QLabel *label_21;
    QFrame *line_5;
    QLabel *label_25;
    QFrame *line_6;
    QLabel *label_24;
    QLabel *label_23;
    QLabel *label_28;
    QLabel *label_22;
    QLabel *label_27;
    QLabel *label_26;
    QPushButton *pushButton_5;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QSpinBox *spinBox_4;
    QLabel *label_16;
    QPushButton *pushButton_12;
    QPushButton *pushButton_13;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *AgentRadarClass)
    {
        if (AgentRadarClass->objectName().isEmpty())
            AgentRadarClass->setObjectName(QString::fromUtf8("AgentRadarClass"));
        AgentRadarClass->resize(673, 819);
        centralWidget = new QWidget(AgentRadarClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        widget = new MyGLWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(260, 10, 400, 400));
        checkBox = new QCheckBox(centralWidget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(20, 40, 70, 17));
        checkBox_2 = new QCheckBox(centralWidget);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setGeometry(QRect(20, 60, 70, 17));
        checkBox_3 = new QCheckBox(centralWidget);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setGeometry(QRect(20, 80, 70, 17));
        checkBox_4 = new QCheckBox(centralWidget);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));
        checkBox_4->setGeometry(QRect(20, 100, 70, 17));
        checkBox_5 = new QCheckBox(centralWidget);
        checkBox_5->setObjectName(QString::fromUtf8("checkBox_5"));
        checkBox_5->setGeometry(QRect(20, 120, 70, 17));
        spinBox = new QSpinBox(centralWidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(20, 140, 42, 22));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 140, 61, 21));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 420, 661, 341));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        LeftArcCheckbox = new QCheckBox(tab);
        LeftArcCheckbox->setObjectName(QString::fromUtf8("LeftArcCheckbox"));
        LeftArcCheckbox->setGeometry(QRect(10, 30, 82, 17));
        RightArcCheckbox = new QCheckBox(tab);
        RightArcCheckbox->setObjectName(QString::fromUtf8("RightArcCheckbox"));
        RightArcCheckbox->setGeometry(QRect(80, 30, 82, 17));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 10, 111, 16));
        spinBox_2 = new QSpinBox(tab);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setGeometry(QRect(10, 80, 42, 22));
        spinBox_2->setMaximum(360);
        spinBox_2->setValue(5);
        pushButton = new QPushButton(tab);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(0, 50, 75, 23));
        pushButton_2 = new QPushButton(tab);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(80, 50, 91, 23));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(60, 80, 81, 21));
        line = new QFrame(tab);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(10, 100, 161, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        label_4 = new QLabel(tab);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 110, 141, 16));
        checkBox_6 = new QCheckBox(tab);
        checkBox_6->setObjectName(QString::fromUtf8("checkBox_6"));
        checkBox_6->setGeometry(QRect(10, 130, 82, 17));
        checkBox_7 = new QCheckBox(tab);
        checkBox_7->setObjectName(QString::fromUtf8("checkBox_7"));
        checkBox_7->setGeometry(QRect(90, 130, 82, 17));
        pushButton_3 = new QPushButton(tab);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(0, 150, 75, 23));
        pushButton_4 = new QPushButton(tab);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(80, 150, 75, 23));
        label_5 = new QLabel(tab);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(80, 180, 81, 21));
        doubleSpinBox = new QDoubleSpinBox(tab);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setGeometry(QRect(10, 180, 62, 22));
        doubleSpinBox->setValue(5);
        label_6 = new QLabel(tab);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(310, 10, 61, 16));
        label_7 = new QLabel(tab);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(310, 40, 61, 16));
        label_8 = new QLabel(tab);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(470, 10, 61, 16));
        label_9 = new QLabel(tab);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(470, 40, 61, 16));
        line_2 = new QFrame(tab);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(310, 20, 331, 21));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(tab);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(450, 10, 20, 41));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);
        label_10 = new QLabel(tab);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(370, 10, 46, 16));
        label_11 = new QLabel(tab);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(380, 40, 46, 16));
        label_12 = new QLabel(tab);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(540, 10, 46, 16));
        label_13 = new QLabel(tab);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(530, 40, 46, 16));
        listWidget = new qList(tab);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(310, 100, 61, 211));
        label_14 = new QLabel(tab);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(300, 80, 81, 20));
        label_14->setAlignment(Qt::AlignCenter);
        spinBox_3 = new QSpinBox(tab);
        spinBox_3->setObjectName(QString::fromUtf8("spinBox_3"));
        spinBox_3->setGeometry(QRect(390, 170, 42, 22));
        label_15 = new QLabel(tab);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(390, 150, 71, 16));
        pushButton_6 = new QPushButton(tab);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(390, 200, 75, 23));
        pushButton_7 = new QPushButton(tab);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(390, 230, 75, 23));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        label_17 = new QLabel(tab_2);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(10, 10, 101, 16));
        checkBox_8 = new QCheckBox(tab_2);
        checkBox_8->setObjectName(QString::fromUtf8("checkBox_8"));
        checkBox_8->setGeometry(QRect(10, 30, 71, 17));
        checkBox_9 = new QCheckBox(tab_2);
        checkBox_9->setObjectName(QString::fromUtf8("checkBox_9"));
        checkBox_9->setGeometry(QRect(80, 30, 81, 17));
        pushButton_8 = new QPushButton(tab_2);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(10, 50, 75, 23));
        pushButton_9 = new QPushButton(tab_2);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setGeometry(QRect(90, 50, 75, 23));
        doubleSpinBox_2 = new QDoubleSpinBox(tab_2);
        doubleSpinBox_2->setObjectName(QString::fromUtf8("doubleSpinBox_2"));
        doubleSpinBox_2->setGeometry(QRect(10, 80, 62, 22));
        doubleSpinBox_2->setValue(5);
        label_18 = new QLabel(tab_2);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(80, 80, 81, 21));
        line_4 = new QFrame(tab_2);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(10, 100, 151, 16));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        label_19 = new QLabel(tab_2);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(10, 110, 101, 16));
        checkBox_10 = new QCheckBox(tab_2);
        checkBox_10->setObjectName(QString::fromUtf8("checkBox_10"));
        checkBox_10->setGeometry(QRect(10, 130, 71, 17));
        checkBox_11 = new QCheckBox(tab_2);
        checkBox_11->setObjectName(QString::fromUtf8("checkBox_11"));
        checkBox_11->setGeometry(QRect(80, 130, 81, 17));
        pushButton_10 = new QPushButton(tab_2);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
        pushButton_10->setGeometry(QRect(10, 150, 75, 23));
        pushButton_11 = new QPushButton(tab_2);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));
        pushButton_11->setGeometry(QRect(90, 150, 75, 23));
        doubleSpinBox_3 = new QDoubleSpinBox(tab_2);
        doubleSpinBox_3->setObjectName(QString::fromUtf8("doubleSpinBox_3"));
        doubleSpinBox_3->setGeometry(QRect(10, 180, 62, 22));
        doubleSpinBox_3->setValue(5);
        label_20 = new QLabel(tab_2);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(80, 180, 81, 21));
        label_21 = new QLabel(tab_2);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(550, 40, 46, 16));
        line_5 = new QFrame(tab_2);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setGeometry(QRect(310, 20, 331, 21));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);
        label_25 = new QLabel(tab_2);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(310, 40, 61, 16));
        line_6 = new QFrame(tab_2);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setGeometry(QRect(450, 10, 20, 41));
        line_6->setFrameShape(QFrame::VLine);
        line_6->setFrameShadow(QFrame::Sunken);
        label_24 = new QLabel(tab_2);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(470, 40, 71, 16));
        label_23 = new QLabel(tab_2);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(540, 10, 46, 16));
        label_28 = new QLabel(tab_2);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setGeometry(QRect(470, 10, 61, 16));
        label_22 = new QLabel(tab_2);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(310, 10, 61, 16));
        label_27 = new QLabel(tab_2);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(380, 40, 46, 16));
        label_26 = new QLabel(tab_2);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(370, 10, 46, 16));
        tabWidget->addTab(tab_2, QString());
        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(20, 380, 131, 23));
        radioButton = new QRadioButton(centralWidget);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(140, 20, 82, 17));
        radioButton->setChecked(true);
        radioButton_2 = new QRadioButton(centralWidget);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(140, 40, 82, 17));
        spinBox_4 = new QSpinBox(centralWidget);
        spinBox_4->setObjectName(QString::fromUtf8("spinBox_4"));
        spinBox_4->setGeometry(QRect(130, 70, 42, 22));
        spinBox_4->setMinimum(1);
        spinBox_4->setValue(8);
        label_16 = new QLabel(centralWidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(130, 100, 91, 16));
        pushButton_12 = new QPushButton(centralWidget);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));
        pushButton_12->setGeometry(QRect(20, 350, 131, 23));
        pushButton_13 = new QPushButton(centralWidget);
        pushButton_13->setObjectName(QString::fromUtf8("pushButton_13"));
        pushButton_13->setGeometry(QRect(84, 210, 101, 23));
        AgentRadarClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(AgentRadarClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 673, 21));
        AgentRadarClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(AgentRadarClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        AgentRadarClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(AgentRadarClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        AgentRadarClass->setStatusBar(statusBar);

        retranslateUi(AgentRadarClass);
        QObject::connect(checkBox_6, SIGNAL(clicked(bool)), widget, SLOT(WedgeSelectNear(bool)));
        QObject::connect(checkBox_7, SIGNAL(clicked(bool)), widget, SLOT(WedgeSelectFar(bool)));
        QObject::connect(pushButton, SIGNAL(clicked()), widget, SLOT(WedgeClockwise()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), widget, SLOT(WedgeCounterClockwise()));
        QObject::connect(pushButton_3, SIGNAL(clicked()), widget, SLOT(WedgeCloser()));
        QObject::connect(pushButton_4, SIGNAL(clicked()), widget, SLOT(WedgeFarther()));
        QObject::connect(checkBox, SIGNAL(clicked(bool)), widget, SLOT(DisplayAgents(bool)));
        QObject::connect(checkBox_2, SIGNAL(clicked(bool)), widget, SLOT(DisplayObstacles(bool)));
        QObject::connect(checkBox_3, SIGNAL(clicked(bool)), widget, SLOT(DisplayInspection(bool)));
        QObject::connect(checkBox_4, SIGNAL(clicked(bool)), widget, SLOT(DisplayNetFlow(bool)));
        QObject::connect(checkBox_5, SIGNAL(clicked(bool)), widget, SLOT(DisplayDensity(bool)));
        QObject::connect(spinBox, SIGNAL(valueChanged(int)), widget, SLOT(SetCardinality(int)));
        QObject::connect(spinBox_2, SIGNAL(valueChanged(int)), widget, SLOT(WedgeSetDegrees(int)));
        QObject::connect(doubleSpinBox, SIGNAL(valueChanged(double)), widget, SLOT(WedgeSetDistance(double)));
        QObject::connect(radioButton, SIGNAL(clicked()), widget, SLOT(SetTypeWedges()));
        QObject::connect(radioButton_2, SIGNAL(clicked()), widget, SLOT(SetTypeRectangles()));
        QObject::connect(spinBox_4, SIGNAL(valueChanged(int)), widget, SLOT(SetNumberSectors(int)));
        QObject::connect(pushButton_5, SIGNAL(clicked()), widget, SLOT(MergeSelectedSectors()));
        QObject::connect(widget, SIGNAL(SendSnappingPoint(QListWidgetItem*)), listWidget, SLOT(AddToList(QListWidgetItem*)));
        QObject::connect(widget, SIGNAL(ClearSnappingPoint()), listWidget, SLOT(ClearList()));
        QObject::connect(widget, SIGNAL(SendWedgeLeftBound(double)), label_10, SLOT(setNum(double)));
        QObject::connect(widget, SIGNAL(SendWedgeLowerBound(double)), label_12, SLOT(setNum(double)));
        QObject::connect(widget, SIGNAL(SendWedgeUpperBound(double)), label_13, SLOT(setNum(double)));
        QObject::connect(widget, SIGNAL(SendWedgeRightBound(double)), label_11, SLOT(setNum(double)));
        QObject::connect(widget, SIGNAL(SendAgentStatus(bool)), checkBox, SLOT(setChecked(bool)));
        QObject::connect(widget, SIGNAL(SendObstaclesStatus(bool)), checkBox_2, SLOT(setChecked(bool)));
        QObject::connect(widget, SIGNAL(SendInspectionStatus(bool)), checkBox_3, SLOT(setChecked(bool)));
        QObject::connect(widget, SIGNAL(SendNetFlowStatus(bool)), checkBox_4, SLOT(setChecked(bool)));
        QObject::connect(widget, SIGNAL(SendDensityStatus(bool)), checkBox_5, SLOT(setChecked(bool)));
        QObject::connect(spinBox_3, SIGNAL(valueChanged(QString)), listWidget, SLOT(ArcValueChanged(QString)));
        QObject::connect(listWidget, SIGNAL(itemClicked(QListWidgetItem*)), listWidget, SLOT(AccessValue(QListWidgetItem*)));
        QObject::connect(listWidget, SIGNAL(SendValue(int)), spinBox_3, SLOT(setValue(int)));
        QObject::connect(spinBox_3, SIGNAL(valueChanged(int)), widget, SLOT(CallUpdateGL()));
        QObject::connect(pushButton_6, SIGNAL(clicked()), widget, SLOT(AddArc()));
        QObject::connect(pushButton_7, SIGNAL(clicked()), widget, SLOT(RemoveArc()));
        QObject::connect(listWidget, SIGNAL(itemClicked(QListWidgetItem*)), widget, SLOT(SetCurrentArc(QListWidgetItem*)));
        QObject::connect(pushButton_7, SIGNAL(clicked()), listWidget, SLOT(RemoveFromList()));
        QObject::connect(LeftArcCheckbox, SIGNAL(clicked(bool)), widget, SLOT(WedgeSelectLeft(bool)));
        QObject::connect(RightArcCheckbox, SIGNAL(clicked(bool)), widget, SLOT(WedgeSelectRight(bool)));
        QObject::connect(pushButton_12, SIGNAL(clicked()), widget, SLOT(DeleteSectors()));
        QObject::connect(checkBox_8, SIGNAL(clicked(bool)), widget, SLOT(RectSelectLeft(bool)));
        QObject::connect(checkBox_9, SIGNAL(clicked(bool)), widget, SLOT(RectSelectRight(bool)));
        QObject::connect(checkBox_10, SIGNAL(clicked(bool)), widget, SLOT(RectSelectTop(bool)));
        QObject::connect(checkBox_11, SIGNAL(clicked(bool)), widget, SLOT(RectSelectBottom(bool)));
        QObject::connect(pushButton_8, SIGNAL(clicked()), widget, SLOT(RectShiftLeft()));
        QObject::connect(pushButton_9, SIGNAL(clicked()), widget, SLOT(RectShiftRight()));
        QObject::connect(pushButton_10, SIGNAL(clicked()), widget, SLOT(RectShiftUp()));
        QObject::connect(pushButton_11, SIGNAL(clicked()), widget, SLOT(RectShiftDown()));
        QObject::connect(doubleSpinBox_2, SIGNAL(valueChanged(double)), widget, SLOT(RectSetHorizontal(double)));
        QObject::connect(doubleSpinBox_3, SIGNAL(valueChanged(double)), widget, SLOT(RectSetVertical(double)));
        QObject::connect(widget, SIGNAL(SendRectLeftBound(double)), label_26, SLOT(setNum(double)));
        QObject::connect(widget, SIGNAL(SendRectRightBound(double)), label_27, SLOT(setNum(double)));
        QObject::connect(widget, SIGNAL(SendRectTopBound(double)), label_23, SLOT(setNum(double)));
        QObject::connect(widget, SIGNAL(SendRectBottomBound(double)), label_21, SLOT(setNum(double)));
        QObject::connect(widget, SIGNAL(SendCardinality(int)), spinBox, SLOT(setValue(int)));
        QObject::connect(pushButton_13, SIGNAL(clicked()), AgentRadarClass, SLOT(CreateNewSector()));
        QObject::connect(radioButton, SIGNAL(toggled(bool)), AgentRadarClass, SLOT(SetWedgesBool(bool)));
        QObject::connect(widget, SIGNAL(SendMyself(MyGLWidget*)), AgentRadarClass, SLOT(GetGLWidget(MyGLWidget*)));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(AgentRadarClass);
    } // setupUi

    void retranslateUi(QMainWindow *AgentRadarClass)
    {
        AgentRadarClass->setWindowTitle(QApplication::translate("AgentRadarClass", "AgentRadar", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("AgentRadarClass", "Agents", 0, QApplication::UnicodeUTF8));
        checkBox_2->setText(QApplication::translate("AgentRadarClass", "Obstacles", 0, QApplication::UnicodeUTF8));
        checkBox_3->setText(QApplication::translate("AgentRadarClass", "Inspection", 0, QApplication::UnicodeUTF8));
        checkBox_4->setText(QApplication::translate("AgentRadarClass", "Net Flow", 0, QApplication::UnicodeUTF8));
        checkBox_5->setText(QApplication::translate("AgentRadarClass", "Density", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("AgentRadarClass", "Cardinality", 0, QApplication::UnicodeUTF8));
        LeftArcCheckbox->setText(QApplication::translate("AgentRadarClass", "Left Edge", 0, QApplication::UnicodeUTF8));
        RightArcCheckbox->setText(QApplication::translate("AgentRadarClass", "Right Edge", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("AgentRadarClass", "Shift Radial Boundaries", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("AgentRadarClass", "Clockwise", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("AgentRadarClass", "Counterclockwise", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("AgentRadarClass", "Degrees shifted", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("AgentRadarClass", "Shift Arc-Aligned Boundaries", 0, QApplication::UnicodeUTF8));
        checkBox_6->setText(QApplication::translate("AgentRadarClass", "Near Bound", 0, QApplication::UnicodeUTF8));
        checkBox_7->setText(QApplication::translate("AgentRadarClass", "Far Bound", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("AgentRadarClass", "Closer", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("AgentRadarClass", "Farther", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("AgentRadarClass", "Distance shifted", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("AgentRadarClass", "Left Bound:", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("AgentRadarClass", "Right Bound:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("AgentRadarClass", "Near Bound:", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("AgentRadarClass", "Far Bound:", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("AgentRadarClass", "0", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("AgentRadarClass", "0", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("AgentRadarClass", "0", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("AgentRadarClass", "0", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("AgentRadarClass", "Snapping Arcs", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("AgentRadarClass", "Arc Position", 0, QApplication::UnicodeUTF8));
        pushButton_6->setText(QApplication::translate("AgentRadarClass", "Add Arc", 0, QApplication::UnicodeUTF8));
        pushButton_7->setText(QApplication::translate("AgentRadarClass", "Remove Arc", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("AgentRadarClass", "Wedges", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("AgentRadarClass", "Shift L/R Boundaries", 0, QApplication::UnicodeUTF8));
        checkBox_8->setText(QApplication::translate("AgentRadarClass", "Left Edge", 0, QApplication::UnicodeUTF8));
        checkBox_9->setText(QApplication::translate("AgentRadarClass", "Right Edge", 0, QApplication::UnicodeUTF8));
        pushButton_8->setText(QApplication::translate("AgentRadarClass", "Left", 0, QApplication::UnicodeUTF8));
        pushButton_9->setText(QApplication::translate("AgentRadarClass", "Right", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("AgentRadarClass", "Distance shifted", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("AgentRadarClass", "Shift T/B Boundaries", 0, QApplication::UnicodeUTF8));
        checkBox_10->setText(QApplication::translate("AgentRadarClass", "Top Edge", 0, QApplication::UnicodeUTF8));
        checkBox_11->setText(QApplication::translate("AgentRadarClass", "Bottom Edge", 0, QApplication::UnicodeUTF8));
        pushButton_10->setText(QApplication::translate("AgentRadarClass", "Up", 0, QApplication::UnicodeUTF8));
        pushButton_11->setText(QApplication::translate("AgentRadarClass", "Down", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("AgentRadarClass", "Distance shifted", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("AgentRadarClass", "0", 0, QApplication::UnicodeUTF8));
        label_25->setText(QApplication::translate("AgentRadarClass", "Right Bound:", 0, QApplication::UnicodeUTF8));
        label_24->setText(QApplication::translate("AgentRadarClass", "Bottom Bound:", 0, QApplication::UnicodeUTF8));
        label_23->setText(QApplication::translate("AgentRadarClass", "0", 0, QApplication::UnicodeUTF8));
        label_28->setText(QApplication::translate("AgentRadarClass", "Top Bound:", 0, QApplication::UnicodeUTF8));
        label_22->setText(QApplication::translate("AgentRadarClass", "Left Bound:", 0, QApplication::UnicodeUTF8));
        label_27->setText(QApplication::translate("AgentRadarClass", "0", 0, QApplication::UnicodeUTF8));
        label_26->setText(QApplication::translate("AgentRadarClass", "0", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("AgentRadarClass", "Rectangles", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("AgentRadarClass", "Merge Selected Sectors", 0, QApplication::UnicodeUTF8));
        radioButton->setText(QApplication::translate("AgentRadarClass", "Wedges", 0, QApplication::UnicodeUTF8));
        radioButton_2->setText(QApplication::translate("AgentRadarClass", "Rectangles", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("AgentRadarClass", "Number of Sectors", 0, QApplication::UnicodeUTF8));
        pushButton_12->setText(QApplication::translate("AgentRadarClass", "Delete Selected Sectors", 0, QApplication::UnicodeUTF8));
        pushButton_13->setText(QApplication::translate("AgentRadarClass", "Create New Sector", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AgentRadarClass: public Ui_AgentRadarClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AGENTRADAR_H
