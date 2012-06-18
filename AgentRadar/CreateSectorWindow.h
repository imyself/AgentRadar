#pragma once

#include <QtGui/QMainWindow>
#include "ui_createsectorwindow.h"

class AgentRadar;
class MyGLWidget;

class CreateSectorWindow:  public QMainWindow
{
	Q_OBJECT

public:
	CreateSectorWindow(QWidget *parent = 0, Qt::WFlags flags = 0);
	~CreateSectorWindow();

	AgentRadar* agent_radar;
	bool wedges;
	MyGLWidget* gl_widget;

	//Wedge vars
	int lw, rw;
	float nw, fw;

	//Rect vars
	float lr, rr, ur, br;

	void DisableSpinboxes();

private:
	Ui::CreateSectorWindow ui;

public slots:
	void SetWedgeLeft(int);
	void SetWedgeRight(int);
	void SetWedgeNear(double);
	void SetWedgeFar(double);

	void SetRectLeft(double);
	void SetRectRight(double);
	void SetRectTop(double);
	void SetRectBottom(double);

	void CreateSector();

signals:
	void SetRectWidgets(bool);
	void SetWedgeWidgets(bool);
	
};

#include "agentradar.h"
#include "myglwidget.h"