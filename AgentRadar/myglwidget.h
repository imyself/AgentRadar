#pragma once

#include <QGLWidget>
#include <QMouseEvent>
#include <QListWidget>
#include <vector>
//#include <glut.h>
#include "Sector.h"

using namespace std;

class MyGLWidget : public QGLWidget{
	Q_OBJECT
public:
	MyGLWidget(QWidget*);
	//Variables
	vector<Sector*> sectors;
	vector<Sector*> selected_sectors;//Hopefully removal != deletion

	float max_distance;//Keep track of the largest wedge/rectangle for sizing the shapes in the viewport


	//Functions
	void mousePressEvent(QMouseEvent* e);
	void ToggleSelected(Sector*);
	void Render(Sector*);
	void UpdateMaxDistance();

	void paintGL();
	void initializeGL();
	void resizeGL(int, int);

public slots:
	//SET UP
	void SetTypeWedges();
	void SetTypeRectangles();
	void SetNumberSectors(int);

	void MergeSelectedSectors();

	//FLAGS
	void DisplayAgents(bool);
	void DisplayObstacles(bool);
	void DisplayInspection(bool);
	void DisplayNetFlow(bool);
	void DisplayDensity(bool);
	void SetCardinality(int);

	//WEDGE SLOTS
	//Shifting Radial Boundaries
	void WedgeSelectLeft(bool);
	void WedgeSelectRight(bool);
	void WedgeClockwise();
	void WedgeCounterClockwise();
	void WedgeSetDegrees(int);

	//Shifting Arc-Aligned Boundaries
	void WedgeSelectNear(bool);
	void WedgeSelectFar(bool);
	void WedgeCloser();
	void WedgeFarther();
	void WedgeSetDistance(double);

signals:
	void SendSnappingPoint(QListWidgetItem*);


};