#pragma once

#include <QGLWidget>
#include <QMouseEvent>
#include <QListWidget>
#include <vector>
#include "qList.h"
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
	QListWidgetItem* current_arc;

	float max_distance;//Keep track of the largest wedge/rectangle for sizing the shapes in the viewport
	int num_sectors_in_ring;
	bool wedges;//Are we dealing with wedges or rectangles?

	//Wedge variables
	bool left_edge, right_edge;
	bool near_edge, far_edge;
	int degree_shift;
	float wedge_shift;

	//Rect variables
	bool left_side, right_side;
	bool top_side, bottom_side;
	float h_shift, v_shift;


	//Functions
	void mousePressEvent(QMouseEvent* e);
	void keyPressEvent(QKeyEvent* e);
	void ToggleSelected(Sector*);

	void DisplayPreviousSectorData(Sector* s);
	void DisplayCurrentSectorData(Sector* s);
	void Render(Sector*);
	void UpdateMaxDistance();


	void AddNewSector(Sector*);

	void paintGL();
	void initializeGL();
	void resizeGL(int, int);

public slots:
	//SET UP
	void SetTypeWedges();
	void SetTypeRectangles();
	void SetNumberSectors(int);
	void SetWedgesBool(bool);

	void MergeSelectedSectors();
	void DeleteSectors();
	void DeleteAllSectors();
	void CreateSectorRing();

	//FLAGS
	void DisplayAgents(bool);
	void DisplayObstacles(bool);
	void DisplayInspection(bool);
	void DisplayNetFlow(bool);
	void DisplayDensity(bool);
	void SetCardinality(int);

	void AllFlagsOn();
	void AllFlagsOff();

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

	void SetCurrentArc(QListWidgetItem*);
	void AddArc();
	void RemoveArc();

	//RECT SLOTS
	
	//Shifting Horizontal Boundaries
	void RectSetHorizontal(double);
	void RectSelectLeft(bool);
	void RectSelectRight(bool);
	void RectShiftLeft();
	void RectShiftRight();

	//Shifting Vertical Boundaries
	void RectSetVertical(double);
	void RectSelectTop(bool);
	void RectSelectBottom(bool);
	void RectShiftUp();
	void RectShiftDown();

	void CallUpdateGL();

signals:
	void SendSnappingPoint(QListWidgetItem*);
	void ClearSnappingPoint();
	void SendWedgeLeftBound(double);
	void SendWedgeRightBound(double);
	void SendWedgeUpperBound(double);
	void SendWedgeLowerBound(double);

	void SendAgentStatus(bool);
	void SendObstaclesStatus(bool);
	void SendInspectionStatus(bool);
	void SendNetFlowStatus(bool);
	void SendDensityStatus(bool);
	void SendCardinality(int);

	void SendRectLeftBound(double);
	void SendRectRightBound(double);
	void SendRectTopBound(double);
	void SendRectBottomBound(double);

	void SendMyself(MyGLWidget*);
};