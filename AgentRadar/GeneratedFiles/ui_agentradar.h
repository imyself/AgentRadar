/********************************************************************************
** Form generated from reading UI file 'agentradar.ui'
**
** Created: Thu Jun 14 10:32:39 2012
**      by: Qt User Interface Compiler version 4.8.2
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
#include <QtGui/QListWidget>
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
    QCheckBox *checkBox1;
    QCheckBox *checkBox_21;
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
    QListWidget *listWidget;
    QLabel *label_14;
    QSpinBox *spinBox_3;
    QLabel *label_15;
    QWidget *tab_2;
    QPushButton *pushButton_5;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QSpinBox *spinBox_4;
    QLabel *label_16;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *AgentRadarClass)
    {
        if (AgentRadarClass->objectName().isEmpty())
            AgentRadarClass->setObjectName(QString::fromUtf8("AgentRadarClass"));
        AgentRadarClass->resize(679, 819);
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
        checkBox1 = new QCheckBox(tab);
        checkBox1->setObjectName(QString::fromUtf8("checkBox1"));
        checkBox1->setGeometry(QRect(10, 30, 82, 17));
        checkBox_21 = new QCheckBox(tab);
        checkBox_21->setObjectName(QString::fromUtf8("checkBox_21"));
        checkBox_21->setGeometry(QRect(80, 30, 82, 17));
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
        listWidget = new QListWidget(tab);
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
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget->addTab(tab_2, QString());
        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(20, 380, 131, 23));
        radioButton = new QRadioButton(centralWidget);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(140, 20, 82, 17));
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
        AgentRadarClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(AgentRadarClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 679, 21));
        AgentRadarClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(AgentRadarClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        AgentRadarClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(AgentRadarClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        AgentRadarClass->setStatusBar(statusBar);

        retranslateUi(AgentRadarClass);

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
        checkBox1->setText(QApplication::translate("AgentRadarClass", "Left Edge", 0, QApplication::UnicodeUTF8));
        checkBox_21->setText(QApplication::translate("AgentRadarClass", "Right Edge", 0, QApplication::UnicodeUTF8));
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
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("AgentRadarClass", "Wedges", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("AgentRadarClass", "Rectangles", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("AgentRadarClass", "Merge Selected Sectors", 0, QApplication::UnicodeUTF8));
        radioButton->setText(QApplication::translate("AgentRadarClass", "Wedges", 0, QApplication::UnicodeUTF8));
        radioButton_2->setText(QApplication::translate("AgentRadarClass", "Rectangles", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("AgentRadarClass", "Number of Sectors", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AgentRadarClass: public Ui_AgentRadarClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AGENTRADAR_H
