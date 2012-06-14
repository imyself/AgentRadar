#pragma once

#include <QGLWidget>
#include <QMouseEvent>
#include <vector>
#include <glut.h>
#include "Sector.h"

using namespace std;

class MyGLWidget : public QGLWidget{
	Q_OBJECT
public:
	MyGLWidget(QWidget*);
	//Variables
	vector<Sector*> sectors;
	vector<Sector*> selected_sectors;//Hopefully removal != deletion
	//Functions
	void mousePressEvent(QMouseEvent* e);
	void ToggleSelected(Sector*);
	void Render(Sector*);

	void paintGL();
	void initializeGL();
};