#include "CreateSectorWindow.h"
#include "Wedge.h"
#include "Rect.h"

CreateSectorWindow::CreateSectorWindow(QWidget *parent, Qt::WFlags flags) : QMainWindow(parent, flags)
{
	ui.setupUi(this);
	lw = 120;
	rw = 60;
	nw = 0;
	fw = 10;

	lr = 0;
	rr = 10;
	ur = 10;
	br = 0;
}


CreateSectorWindow::~CreateSectorWindow(void)
{
}

void CreateSectorWindow::SetWedgeLeft(int i){
	lw = i;
}
void CreateSectorWindow::SetWedgeRight(int i){
	rw = i;
}
void CreateSectorWindow::SetWedgeNear(double d){
	nw = d;
}
void CreateSectorWindow::SetWedgeFar(double d){
	fw = d;
}

void CreateSectorWindow::SetRectLeft(double d){
	lr = d;
}
void CreateSectorWindow::SetRectRight(double d){
	rr = d;
}
void CreateSectorWindow::SetRectTop(double d){
	ur = d;
}
void CreateSectorWindow::SetRectBottom(double d){
	br = d;
}

void CreateSectorWindow::CreateSector(){
	Sector* s;
	if(wedges){
		s = new Wedge(lw, rw, nw, fw);
	}
	else{
		s = new Rect(lr, rr, ur, br);
	}
	gl_widget->AddNewSector(s);//Tell gl_widget to add a new Sector to its sectors
	this->close();
}

void CreateSectorWindow::DisableSpinboxes(){
	emit SetWedgeWidgets(wedges);
}