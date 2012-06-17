#include "agentradar.h"
#include "CreateSectorWindow.h"

AgentRadar::AgentRadar(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
	wedges = true;
}

AgentRadar::~AgentRadar()
{

}

void AgentRadar::CreateNewSector(){
	CreateSectorWindow* new_window = new CreateSectorWindow(0);
	new_window->agent_radar = this;
	new_window->wedges = this->wedges;
	new_window->gl_widget = this->gl_widget;
	new_window->DisableSpinboxes();
	new_window->show();
}

void AgentRadar::SetWedgesBool(bool b){
	wedges = b;
}

void AgentRadar::GetGLWidget(MyGLWidget* g){
	gl_widget = g;
}

void AgentRadar::keyPressEvent(QKeyEvent* e){
	gl_widget->keyPressEvent(e);
}