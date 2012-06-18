#include "myglwidget.h"
#include "Wedge.h"
#include "Rect.h"
#include "glm/gtc/matrix_transform.hpp"
#include <qfiledialog.h>
#include "XMLLoader.h"

MyGLWidget::MyGLWidget(QWidget* parent) : QGLWidget(parent) {
	setFocusPolicy(Qt::ClickFocus);
	near_edge = far_edge = left_edge = right_edge = false;
	degree_shift = 5;
	wedge_shift = 5.0f;

	left_side = right_side = top_side = bottom_side = false;
	h_shift = v_shift = 5.0f;

	num_sectors_in_ring = 8;
	wedges = true;
	arc_pos = 0;
}

void MyGLWidget::mousePressEvent(QMouseEvent* e){
	if(e->buttons() == Qt::LeftButton){
		for(unsigned int i = 0; i < sectors.size(); i++){
			if(sectors[i]->IntersectionTest(e->x(), e->y(), max_distance)){
				ToggleSelected(sectors[i]);
			}
		}
	}
	updateGL();
}

void MyGLWidget::keyPressEvent(QKeyEvent* e){
	if(e->key() == Qt::Key_Backspace || e->key() == Qt::Key_Delete){
		if(e->modifiers() & Qt::ShiftModifier){
			DeleteAllSectors();
		}
		else{
			DeleteSectors();
		}	
	}
	else if(e->key() == Qt::Key_Left){
		if(selected_sectors.size() > 0){
			if(selected_sectors[0]->GetType() == 1){
				WedgeCounterClockwise();
			}
			else if(selected_sectors[0]->GetType() == 2){
				RectShiftLeft();
			}
		}
	}
	else if(e->key() == Qt::Key_Right){
		if(selected_sectors.size() > 0){
			if(selected_sectors[0]->GetType() == 1){
				WedgeClockwise();
			}
			else if(selected_sectors[0]->GetType() == 2){
				RectShiftRight();
			}
		}
	}
	else if(e->key() == Qt::Key_Up){
		if(selected_sectors.size() > 0){
			if(selected_sectors[0]->GetType() == 1){
				WedgeFarther();
			}
			else if(selected_sectors[0]->GetType() == 2){
				RectShiftUp();
			}
		}
	}
	else if(e->key() == Qt::Key_Down){
		if(selected_sectors.size() > 0){
			if(selected_sectors[0]->GetType() == 1){
				WedgeCloser();
			}
			else if(selected_sectors[0]->GetType() == 2){
				RectShiftDown();
			}
		}
	}
	else if(e->key() == Qt::Key_A){
		if(e->modifiers() & Qt::ControlModifier){
			SelectAllSectors();
		}
		else{
			emit ClickWedgeLeft();
			emit ClickRectLeft();
		}
	}
	else if(e->key() == Qt::Key_D){
		if(e->modifiers() & Qt::ControlModifier){
			DeselectAll();
		}
		else{
			emit ClickWedgeRight();
			emit ClickRectRight();
		}
	}
	else if(e->key() == Qt::Key_W){
		emit ClickWedgeFar();
		emit ClickRectTop();
	}
	else if(e->key() == Qt::Key_S){
		if(e->modifiers() & Qt::ControlModifier){
			WriteXML();
		}
		else{
			emit ClickWedgeNear();
			emit ClickRectBottom();
		}
	}
	else if(e->key() == Qt::Key_O){
		if(e->modifiers() & Qt::ControlModifier){
			LoadXML();
		}
	}
}

void MyGLWidget::ToggleSelected(Sector* s){
	emit ClearSnappingPoint();
	for(unsigned int i = 0; i < selected_sectors.size(); i++){
		if(selected_sectors[i] == s){
			s->selected = false;
			selected_sectors.erase(selected_sectors.begin() + i);
			DisplayPreviousSectorData(s);
			return;
		}
	}
	selected_sectors.push_back(s);
	s->selected = true;
	DisplayCurrentSectorData(s);
}

void MyGLWidget::DisplayPreviousSectorData(Sector* s){
	if (s->GetType() == 1){
		if (selected_sectors.size() != 0){
			Wedge* w = dynamic_cast<Wedge*>(selected_sectors[selected_sectors.size()-1]);
			for(unsigned int j = 0; j < w->snapping_points.size(); j++){
				emit SendSnappingPoint(w->snapping_points[j]);
			}
			emit SendWedgeLeftBound(w->left_bound);
			emit SendWedgeRightBound(w->right_bound);
			emit SendWedgeUpperBound(w->far_bound);
			emit SendWedgeLowerBound(w->near_bound);
			emit SendAgentStatus(w->agents);
			emit SendObstaclesStatus(w->obstacles);
			emit SendInspectionStatus(w->inspection);
			emit SendNetFlowStatus(w->net_flow);
			emit SendDensityStatus(w->density);
			emit SendCardinality(w->cardinality);
		}
		else{
			emit SendWedgeLeftBound(0);
			emit SendWedgeRightBound(0);
			emit SendWedgeUpperBound(0);
			emit SendWedgeLowerBound(0);
			emit SendAgentStatus(false);
			emit SendObstaclesStatus(false);
			emit SendInspectionStatus(false);
			emit SendNetFlowStatus(false);
			emit SendDensityStatus(false);
			emit SendCardinality(0);
		}
	}

	else if (s->GetType() == 2){
		if (selected_sectors.size() != 0){
			Rect* w = dynamic_cast<Rect*>(selected_sectors[selected_sectors.size()-1]);
			emit SendRectLeftBound(w->left_edge);
			emit SendRectRightBound(w->right_edge);
			emit SendRectTopBound(w->top_edge);
			emit SendRectBottomBound(w->bottom_edge);
			emit SendAgentStatus(w->agents);
			emit SendObstaclesStatus(w->obstacles);
			emit SendInspectionStatus(w->inspection);
			emit SendNetFlowStatus(w->net_flow);
			emit SendDensityStatus(w->density);
			emit SendCardinality(w->cardinality);
		}
		else{
			emit SendRectLeftBound(0);
			emit SendRectRightBound(0);
			emit SendRectTopBound(0);
			emit SendRectBottomBound(0);
			emit SendAgentStatus(false);
			emit SendObstaclesStatus(false);
			emit SendInspectionStatus(false);
			emit SendNetFlowStatus(false);
			emit SendDensityStatus(false);
			emit SendCardinality(0);
		}
	}

}
void MyGLWidget::DisplayCurrentSectorData(Sector* s){
	if(s->GetType()==1){
		Wedge* w = dynamic_cast<Wedge*>(s);
		for(unsigned int i = 0; i < w->snapping_points.size(); i++){
			emit SendSnappingPoint(w->snapping_points[i]);
		}
		emit SendWedgeLeftBound(w->left_bound);
		emit SendWedgeRightBound(w->right_bound);
		emit SendWedgeUpperBound(w->far_bound);
		emit SendWedgeLowerBound(w->near_bound);
		emit SendAgentStatus(w->agents);
		emit SendObstaclesStatus(w->obstacles);
		emit SendInspectionStatus(w->inspection);
		emit SendNetFlowStatus(w->net_flow);
		emit SendDensityStatus(w->density);
		emit SendCardinality(w->cardinality);
	}

	else if (s->GetType() == 2){
		Rect* w = dynamic_cast<Rect*>(s);
		emit SendRectLeftBound(w->left_edge);
		emit SendRectRightBound(w->right_edge);
		emit SendRectTopBound(w->top_edge);
		emit SendRectBottomBound(w->bottom_edge);
		emit SendAgentStatus(w->agents);
		emit SendObstaclesStatus(w->obstacles);
		emit SendInspectionStatus(w->inspection);
		emit SendNetFlowStatus(w->net_flow);
		emit SendDensityStatus(w->density);
		emit SendCardinality(w->cardinality);
	}
}

void MyGLWidget::initializeGL(){
	glClearColor(0, 0, 0, 1);
	//glEnable(GL_DEPTH_TEST);
	glClearDepth(1.0);
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_POINT_SMOOTH);
	glPointSize(10.0f);

	//glMatrixMode(GL_PROJECTION);
	//glOrtho(-10, 10, -10, 10, -1, 1);

	//glMatrixMode(GL_MODELVIEW);
	//glPushMatrix();
	//glLoadIdentity();

	/*
	sectors.push_back(new Wedge());
	sectors.push_back(new Wedge(180, 120, 10, 100));
	sectors.push_back(new Wedge(240, 180, 10, 100));
	sectors.push_back(new Wedge(300, 240, 10, 100));
	sectors.push_back(new Wedge(360, 300, 10, 100));
	sectors.push_back(new Wedge(60, 0, 10, 100));
	*/

	//sectors.push_back(new Rect());

	//Update max distance
	max_distance = 0;
	UpdateMaxDistance();

	emit SendMyself(this);
}

void MyGLWidget::UpdateMaxDistance(){
	max_distance = 0;
	for(unsigned int i = 0; i < sectors.size(); i++){
		if(sectors[i]->GetType() == 1){
			if(max_distance < dynamic_cast<Wedge*>(sectors[i])->far_bound)
				max_distance = dynamic_cast<Wedge*>(sectors[i])->far_bound;
		}
		else if(sectors[i]->GetType() == 2){
			Rect* r = dynamic_cast<Rect*>(sectors[i]);
			float d = 0;
			//Get distance of each corner from origin and compare to max_distance
			//Lower left
			glm::vec2 p(r->left_edge, r->bottom_edge);
			if((d = glm::distance(p, glm::vec2(0,0))) > max_distance)
				max_distance = d;
			//Upper left
			p = glm::vec2(r->left_edge, r->top_edge);
			if((d = glm::distance(p, glm::vec2(0,0))) > max_distance)
				max_distance = d;
			//Upper right
			p = glm::vec2(r->right_edge, r->top_edge);
			if((d = glm::distance(p, glm::vec2(0,0))) > max_distance)
				max_distance = d;
			//Lower right
			p = glm::vec2(r->right_edge, r->bottom_edge);
			if((d = glm::distance(p, glm::vec2(0,0))) > max_distance)
				max_distance = d;
		}
	}
}

void MyGLWidget::resizeGL(int width, int height){
      int side = qMin(width, height);
      glViewport((width - side) / 2, (height - side) / 2, side, side);
 
      glMatrixMode(GL_PROJECTION);
      glLoadIdentity();
      glOrtho(-1,1,-1,1,-1,1);
      glMatrixMode(GL_MODELVIEW);
}

void MyGLWidget::paintGL(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	for(unsigned int i = 0; i < sectors.size(); i++){
		Render(sectors[i]);
	}
	glBegin(GL_POINTS);
		glColor3f(1,1,0);
		glVertex2f(0,0);
	glEnd();
}

void MyGLWidget::Render(Sector* s){
	//Wedge
	if(s->GetType() == 1){
		Wedge* w = dynamic_cast<Wedge*>(s);
		std::vector<glm::vec2> far_v; std::vector<glm::vec2> near_v;
		
		glm::vec4 p_f(w->far_bound/max_distance, 0, 1, 1);
		glm::vec4 p_n(w->near_bound/max_distance, 0, 1, 1);
		p_f = glm::rotate(glm::mat4(1.0f), (float)w->right_bound, glm::vec3(0,0,1)) * p_f;
		p_n = glm::rotate(glm::mat4(1.0f), (float)w->right_bound, glm::vec3(0,0,1)) * p_n;
		far_v.push_back(glm::vec2(p_f.x, p_f.y));
		near_v.push_back(glm::vec2(p_n.x, p_n.y));
		//Rotate FRB by 5 degrees until reach FLB
		int angle = w->right_bound;
		while(angle < w->left_bound){
			angle = min(angle + 5, w->left_bound);
			p_f = glm::vec4(w->far_bound/max_distance, 0, 1, 1);
			p_f = glm::rotate(glm::mat4(1.0f), (float)angle, glm::vec3(0,0,1)) * p_f;
			far_v.push_back(glm::vec2(p_f.x, p_f.y));
			p_n = glm::vec4(w->near_bound/max_distance, 0, 1, 1);
			p_n = glm::rotate(glm::mat4(1.0f), (float)angle, glm::vec3(0,0,1)) * p_n;
			near_v.push_back(glm::vec2(p_n.x, p_n.y));
		}

		glBegin(GL_TRIANGLE_STRIP);
			//Color
			if(w->agents || w->obstacles || w->inspection || w->net_flow || w->density){
				if(w->selected)
					glColor3f(0.3,1,0.3);
				else 
					glColor3f(1,0.3,0.3);
			}
			else{
				if(w->selected)
					glColor3f(0,0.3,0);
				else
					glColor3f(0.2,0.2,0.2);
			}
			for(unsigned int i = 0; i < far_v.size(); i++){
				glVertex2f(far_v[i].x, far_v[i].y);
				glVertex2f(near_v[i].x, near_v[i].y);
			}
		glEnd();
		//Draw the outline of the wedge
		glBegin(GL_LINES);
		//Right line
			glColor3f(1,1,1);
			glm::vec4 p1(w->near_bound/max_distance, 0, 1, 1);
			glm::vec4 p2(w->far_bound/max_distance, 0, 1, 1);
			p1 = glm::rotate(glm::mat4(1.0f), (float)w->right_bound, glm::vec3(0,0,1)) * p1;
			p2 = glm::rotate(glm::mat4(1.0f), (float)w->right_bound, glm::vec3(0,0,1)) * p2;
			glVertex2f(p1.x, p1.y);
			glVertex2f(p2.x, p2.y);
		//Left line
			glColor3f(1,1,1);
			p1 = glm::vec4(w->near_bound/max_distance, 0, 1, 1);
			p2 = glm::vec4(w->far_bound/max_distance, 0, 1, 1);
			p1 = glm::rotate(glm::mat4(1.0f), (float)w->left_bound, glm::vec3(0,0,1)) * p1;
			p2 = glm::rotate(glm::mat4(1.0f), (float)w->left_bound, glm::vec3(0,0,1)) * p2;
			glVertex2f(p1.x, p1.y);
			glVertex2f(p2.x, p2.y);
		glEnd();
		//Near edge
		glBegin(GL_LINE_STRIP);
			glColor3f(1,1,1);
			for(unsigned int i = 0; i < near_v.size(); i++){
				glVertex2f(near_v[i].x, near_v[i].y);
			}
		glEnd();
		//Far edge
		glBegin(GL_LINE_STRIP);
			glColor3f(1,1,1);
			for(unsigned int i = 0; i < far_v.size(); i++){
				glVertex2f(far_v[i].x, far_v[i].y);
			}
		glEnd();
		//Draw the snapping points
		for(unsigned int i = 0; i < w->snapping_points.size(); i++){
			float s = w->snapping_points[i]->position / max_distance;
			glm::vec4 p = glm::vec4(s, 0, 1, 1);
			glBegin(GL_LINE_STRIP);
				glColor3f(0,0,1);
				p = glm::rotate(glm::mat4(1.0f), (float)w->right_bound, glm::vec3(0,0,1)) * p;
				glVertex2f(p.x, p.y);
				angle = w->right_bound;
				while(angle < w->left_bound){
					angle = min(angle + 5, w->left_bound);
					p = glm::vec4(s, 0, 1, 1);
					p = glm::rotate(glm::mat4(1.0f), (float)angle, glm::vec3(0,0,1)) * p;
					glVertex2f(p.x, p.y);
				}
			glEnd();
		}
	}
	//Rectangle
	else if(s->GetType() == 2){
		Rect* r = dynamic_cast<Rect*>(s);
		//Draw the body of the rect
		glBegin(GL_POLYGON);
			//Color
			if(r->agents || r->obstacles || r->inspection || r->net_flow || r->density){
				if(r->selected)
					glColor3f(0.3,1,0.3);
				else 
					glColor3f(1,0.3,0.3);
			}
			else{
				if(r->selected)
					glColor3f(0,0.3,0);
				else
					glColor3f(0.2,0.2,0.2);
			}
			//Four corners
			//Lower Left
			glm::vec2 p(r->left_edge, r->bottom_edge); p/= max_distance;
			glVertex2f(p.x, p.y);
			//Upper left
			p = glm::vec2(r->left_edge, r->top_edge) / max_distance;
			glVertex2f(p.x, p.y);
			//Upper right
			p = glm::vec2(r->right_edge, r->top_edge) / max_distance;
			glVertex2f(p.x, p.y);
			//Lower right
			p = glm::vec2(r->right_edge, r->bottom_edge) / max_distance;
			glVertex2f(p.x, p.y);
		glEnd();
		//Edging
		glBegin(GL_LINE_STRIP);
			glColor3f(1,1,1);
			//Lower left
			p = glm::vec2(r->left_edge, r->bottom_edge); p/= max_distance;
			glVertex2f(p.x, p.y);
			//Upper left
			p = glm::vec2(r->left_edge, r->top_edge) / max_distance;
			glVertex2f(p.x, p.y);
			//Upper right
			p = glm::vec2(r->right_edge, r->top_edge) / max_distance;
			glVertex2f(p.x, p.y);
			//Lower right
			p = glm::vec2(r->right_edge, r->bottom_edge) / max_distance;
			glVertex2f(p.x, p.y);
			//Lower left again
			p = glm::vec2(r->left_edge, r->bottom_edge); p/= max_distance;
			glVertex2f(p.x, p.y);
		glEnd();
	}
}

//SLOTS

//SET UP
void MyGLWidget::SetTypeWedges(){
}
void MyGLWidget::SetTypeRectangles(){
}
void MyGLWidget::SetNumberSectors(int i){
	num_sectors_in_ring = i;
}

void MyGLWidget::MergeSelectedSectors(){
}

void MyGLWidget::DeleteSectors(){
	Sector* to_delete = new Sector[selected_sectors.size()];
	Sector* s = 0;
	if(selected_sectors.size() > 0){
		s = selected_sectors[0];
	}
	for(unsigned int i = 0; i < selected_sectors.size(); i++){
		for(unsigned int j = 0; j < sectors.size(); j++){
			if(selected_sectors[i] == sectors[j])
				sectors.erase(sectors.begin() + j);
		}
	}
	selected_sectors.clear();
	if(s != 0)
		DisplayPreviousSectorData(s);
	delete [] to_delete;
	updateGL();
}

void MyGLWidget::DeleteAllSectors(){
	//Select all
	for(unsigned int i = 0; i < sectors.size(); i++){
		if(sectors[i]->selected == false)
			ToggleSelected(sectors[i]);
	}
	DeleteSectors();
}

void MyGLWidget::SelectAllSectors(){
	//Select all
	for(unsigned int i = 0; i < sectors.size(); i++){
		if(sectors[i]->selected == false)
			ToggleSelected(sectors[i]);
	}
	updateGL();
}

void MyGLWidget::DeselectAll(){
	//Select all
	for(unsigned int i = 0; i < sectors.size(); i++){
		if(sectors[i]->selected)
			ToggleSelected(sectors[i]);
	}
	updateGL();
}

//FLAGS
void MyGLWidget::DisplayAgents(bool b){
	for(unsigned int i = 0; i < selected_sectors.size(); i++){
		selected_sectors[i]->agents = b;
	}
	updateGL();
}
void MyGLWidget::DisplayObstacles(bool b){
	for(unsigned int i = 0; i < selected_sectors.size(); i++){
		selected_sectors[i]->obstacles = b;
	}
	updateGL();
}
void MyGLWidget::DisplayInspection(bool b){
	for(unsigned int i = 0; i < selected_sectors.size(); i++){
		selected_sectors[i]->inspection = b;
	}
	updateGL();
}
void MyGLWidget::DisplayNetFlow(bool b){
	for(unsigned int i = 0; i < selected_sectors.size(); i++){
		selected_sectors[i]->net_flow = b;
	}
	updateGL();
}
void MyGLWidget::DisplayDensity(bool b){
	for(unsigned int i = 0; i < selected_sectors.size(); i++){
		selected_sectors[i]->density = b;
	}
	updateGL();
}
void MyGLWidget::SetCardinality(int c){
	for(unsigned int i = 0; i < selected_sectors.size(); i++){
		selected_sectors[i]->cardinality = c;
	}
	updateGL();
}

void MyGLWidget::AllFlagsOn(){
	DisplayAgents(true);
	DisplayObstacles(true);
	DisplayInspection(true);
	DisplayNetFlow(true);
	DisplayDensity(true);
	if(selected_sectors.size() > 0)
		DisplayCurrentSectorData(selected_sectors[selected_sectors.size() - 1]);
}

void MyGLWidget::AllFlagsOff(){
	DisplayAgents(false);
	DisplayObstacles(false);
	DisplayInspection(false);
	DisplayNetFlow(false);
	DisplayDensity(false);
	if(selected_sectors.size() > 0)
		DisplayCurrentSectorData(selected_sectors[selected_sectors.size() - 1]);
}

//WEDGE SLOTS
//Shifting Radial Boundaries
void MyGLWidget::WedgeSelectLeft(bool b){
	left_edge = b;
}
void MyGLWidget::WedgeSelectRight(bool b){
	right_edge = b;
}
void MyGLWidget::WedgeClockwise(){
	for(unsigned int i = 0; i < selected_sectors.size(); i++){
		//Make sure we're typesafe
		if(selected_sectors[i]->GetType() == 1){
			Wedge* w = dynamic_cast<Wedge*>(selected_sectors[i]);
			float diff = w->left_bound - w->right_bound;
			if(left_edge){
				/*Wedge* w_l = 0;//Initialize as null since it may never be initialized.
				for(unsigned int j = 0; j < sectors.size(); j++){
					if(dynamic_cast<Wedge*>(sectors[j])->right_bound == w->left_bound)
						w_l = dynamic_cast<Wedge*>(sectors[j]);
				}*/
				w->left_bound -= degree_shift;
				if((w->left_bound - w->right_bound) / diff <= 0)
					w->left_bound += degree_shift;
				SendWedgeLeftBound(w->left_bound);
				/*if(w_l != 0){
					w_l->right_bound -= degree_shift;
				}*/
			}
			if(right_edge){
				/*Wedge* w_r = 0;//Initialize as null since it may never be initialized.
				for(unsigned int j = 0; j < sectors.size(); j++){
					if(dynamic_cast<Wedge*>(sectors[j])->left_bound == w->right_bound)
						w_r = dynamic_cast<Wedge*>(sectors[j]);
				}*/
				w->right_bound -= degree_shift;
				if((w->left_bound - w->right_bound) / diff <= 0)
					w->right_bound += degree_shift;
				SendWedgeRightBound(w->right_bound);
				/*if(w_r != 0){
					w_r->left_bound -= degree_shift;
				}*/
			}
			w->sweep = w->ComputeSweep(w->left_bound, w->right_bound);
		}
	}
	updateGL();
}
void MyGLWidget::WedgeCounterClockwise(){
	for(unsigned int i = 0; i < selected_sectors.size(); i++){
		//Make sure we're typesafe
		if(selected_sectors[i]->GetType() == 1){
			Wedge* w = dynamic_cast<Wedge*>(selected_sectors[i]);
			float diff = w->left_bound - w->right_bound;
			if(left_edge){
				/*Wedge* w_l = 0;//Initialize as null since it may never be initialized.
				for(unsigned int j = 0; j < sectors.size(); j++){
					if(dynamic_cast<Wedge*>(sectors[j])->right_bound == w->left_bound)
						w_l = dynamic_cast<Wedge*>(sectors[j]);
				}*/
				w->left_bound += degree_shift;
				if((w->left_bound - w->right_bound) / diff <= 0)
					w->left_bound += degree_shift;
				SendWedgeLeftBound(w->left_bound);
				/*if(w_l != 0){
					int diff = w_l->right_bound - w_l->left_bound;
					w_l->right_bound += degree_shift;
					//Check if bounds overlapped or swapped sides
					if((w_l->right_bound - w_l->left_bound) / diff <= 0){
						//Delete w_l from sel_secs if there and from sectors. Remove its snappng points from the list if they're there.
						if(selected_sectors[selected_sectors.size() - 1] == w_l)
							//Display previous sector data
							;
						RemoveFromVectors(w_l);//Remove w_l from sectors and selected_sectors
					}
				}*/
			}
			if(right_edge){
				/*Wedge* w_r = 0;//Initialize as null since it may never be initialized.
				for(unsigned int j = 0; j < ectors.size(); j++){
					if(dynamic_cast<Wedge*>(sectors[j])->left_bound == w->right_bound)
						w_r = dynamic_cast<Wedge*>(sectors[j]);
				}*/
				w->right_bound += degree_shift;
				if((w->left_bound - w->right_bound) / diff <= 0)
					w->right_bound += degree_shift;
				SendWedgeRightBound(w->right_bound);
				/*if(w_r != 0){
					w_r->left_bound += degree_shift;
				}*/
			}
			w->sweep = w->ComputeSweep(w->left_bound, w->right_bound);
		}
	}
	updateGL();
}
void MyGLWidget::WedgeSetDegrees(int d){
	degree_shift = d;
}

//Shifting Arc-Aligned Boundaries
void MyGLWidget::WedgeSelectNear(bool b){
	near_edge = b;
}
void MyGLWidget::WedgeSelectFar(bool b){
	far_edge = b;
}
void MyGLWidget::WedgeCloser(){
	for(unsigned int i = 0; i < selected_sectors.size(); i++){
		//Make sure we're typesafe
		if(selected_sectors[i]->GetType() == 1){
			Wedge* w = dynamic_cast<Wedge*>(selected_sectors[i]);
			if(near_edge){
				w->near_bound = max(w->near_bound - wedge_shift, 0.0f);
				SendWedgeLowerBound(w->near_bound);
			}
			if(far_edge){
				w->far_bound = max(w->far_bound - wedge_shift, 0.0f);
				if(w->far_bound <= w->near_bound)
					w->far_bound = w->near_bound + 1;
				SendWedgeUpperBound(w->far_bound);
			}
		}
	}
	UpdateMaxDistance();
	updateGL();
}
void MyGLWidget::WedgeFarther(){
	for(unsigned int i = 0; i < selected_sectors.size(); i++){
		//Make sure we're typesafe
		if(selected_sectors[i]->GetType() == 1){
			Wedge* w = dynamic_cast<Wedge*>(selected_sectors[i]);
			if(near_edge){
				w->near_bound = w->near_bound + wedge_shift;
				if(w->far_bound <= w->near_bound)
					w->near_bound = w->far_bound - 1;
				SendWedgeLowerBound(w->near_bound);
			}
			if(far_edge){
				w->far_bound = w->far_bound + wedge_shift;
				SendWedgeUpperBound(w->far_bound);
			}
		}
	}
	UpdateMaxDistance();
	updateGL();
}
void MyGLWidget::WedgeSetDistance(double d){
	wedge_shift = d;
}

void MyGLWidget::AddArc(){
	if(selected_sectors.size() > 0){
		if(selected_sectors[0]->GetType() == 1){
			Wedge* w = dynamic_cast<Wedge*>(selected_sectors[selected_sectors.size()-1]);
			w->snapping_points.push_back(new SnappingPoint(arc_pos));
			for(unsigned int i = 0; i < w->snapping_points.size(); i++){
				emit SendSnappingPoint(w->snapping_points[i]);
			}
			updateGL();
		}
	}
}
void MyGLWidget::SetCurrentArc(QListWidgetItem* q){
	current_arc = q;
}
void MyGLWidget::RemoveArc(){
	if(selected_sectors.size() > 0){
		if(selected_sectors[0]->GetType() == 1){
			Wedge* w = dynamic_cast<Wedge*>(selected_sectors[selected_sectors.size()-1]);
			for (unsigned int i = 0; i < w->snapping_points.size(); i++){
				if (w->snapping_points[i] == dynamic_cast<SnappingPoint*>(current_arc)){
					w->snapping_points.erase(w->snapping_points.begin() + i);
				}
			}
			updateGL();
		}
	}
}

void MyGLWidget::UpdateStoredArcPos(int i){
	arc_pos = i;
}

void MyGLWidget::RectSetHorizontal(double d){
	h_shift = d;
}

void MyGLWidget::RectSelectLeft(bool b){
	left_side = b;
}
void MyGLWidget::RectSelectRight(bool b){
	right_side = b;
}
void MyGLWidget::RectShiftLeft(){
	for(unsigned int i = 0; i < selected_sectors.size(); i++){
		//Make sure we're typesafe
		if(selected_sectors[i]->GetType() == 2){
			Rect* r = dynamic_cast<Rect*>(selected_sectors[i]);
			if(left_side){
				r->left_edge -= h_shift;
				SendRectLeftBound(r->left_edge);
			}
			if(right_side){
				r->right_edge -= h_shift;
				if(r->right_edge <= r->left_edge)
					r->right_edge = r->left_edge + 1;
				SendRectRightBound(r->right_edge);
			}
		}
	}
	UpdateMaxDistance();
	updateGL();
}
void MyGLWidget::RectShiftRight(){
	for(unsigned int i = 0; i < selected_sectors.size(); i++){
		//Make sure we're typesafe
		if(selected_sectors[i]->GetType() == 2){
			Rect* r = dynamic_cast<Rect*>(selected_sectors[i]);
			if(left_side){
				r->left_edge += h_shift;
				if(r->right_edge <= r->left_edge)
					r->left_edge = r->right_edge - 1;
				SendRectLeftBound(r->left_edge);
			}
			if(right_side){
				r->right_edge += h_shift;
				SendRectRightBound(r->right_edge);
			}
		}
	}
	UpdateMaxDistance();
	updateGL();
}

void MyGLWidget::RectSetVertical(double d){
	v_shift = d;
}
void MyGLWidget::RectSelectTop(bool b){
	top_side = b;
}
void MyGLWidget::RectSelectBottom(bool b){
	bottom_side = b;
}
void MyGLWidget::RectShiftUp(){
	for(unsigned int i = 0; i < selected_sectors.size(); i++){
		//Make sure we're typesafe
		if(selected_sectors[i]->GetType() == 2){
			Rect* r = dynamic_cast<Rect*>(selected_sectors[i]);
			if(top_side){
				r->top_edge += v_shift;
				SendRectTopBound(r->top_edge);
			}
			if(bottom_side){
				r->bottom_edge += v_shift;
				if(r->bottom_edge >= r->top_edge)
					r->bottom_edge = r->top_edge - 1;
				SendRectBottomBound(r->bottom_edge);
			}
		}
	}
	UpdateMaxDistance();
	updateGL();
}
void MyGLWidget::RectShiftDown(){
	for(unsigned int i = 0; i < selected_sectors.size(); i++){
		//Make sure we're typesafe
		if(selected_sectors[i]->GetType() == 2){
			Rect* r = dynamic_cast<Rect*>(selected_sectors[i]);
			if(top_side){
				r->top_edge -= v_shift;
				if(r->bottom_edge >= r->top_edge)
					r->top_edge = r->bottom_edge + 1;
				SendRectTopBound(r->top_edge);
			}
			if(bottom_side){
				r->bottom_edge -= v_shift;
				if(r->bottom_edge >= r->top_edge)
					r->bottom_edge = r->top_edge - 1;
				SendRectBottomBound(r->bottom_edge);
			}
		}
	}
	UpdateMaxDistance();
	updateGL();
}

void MyGLWidget::CallUpdateGL(){
	updateGL();
}

void MyGLWidget::AddNewSector(Sector* s){
	sectors.push_back(s);
	UpdateMaxDistance();
	updateGL();
}

void MyGLWidget::CreateSectorRing(){
	Sector* s;
	float deg = 360.0f/num_sectors_in_ring;
	for(int i = 1; i <= num_sectors_in_ring; i++){
		if(wedges){
			s = new Wedge(deg/2 + i*deg + 90.0f, deg/2 + (i-1)*deg + 90.0f, 0, 10);
			sectors.push_back(s);
		}
		else{
			std::vector<glm::vec4> square;
			glm::vec4 ur(5,5,0,1); glm::vec4 ul(-5,5,0,1); glm::vec4 lr(5,-5,0,1); glm::vec4 ll(-5,-5,0,1);
			square.push_back(ur); square.push_back(ul); square.push_back(lr); square.push_back(ll);
			glm::vec4 p(0,1,0,1);
			p = glm::rotate(glm::mat4(1.0f), deg*i, glm::vec3(0,0,1)) * p;
			for(unsigned int j = 0; j < square.size(); j++){
				square[j] = glm::translate(glm::mat4(1.0f), 10.0f*glm::vec3(p)) * square[j];
			}
			s = new Rect(square[1].x, square[0].x, square[1].y, square[3].y);
			sectors.push_back(s);
		}
	}
	UpdateMaxDistance();
	updateGL();
}

void MyGLWidget::SetWedgesBool(bool b){
	wedges = b;
}

void MyGLWidget::LoadXML(){
	QString q_file_name = QFileDialog::getOpenFileName(this, tr("Open XML"), "../Output XML", tr("*.xml"));
	std::string filename = q_file_name.toLocal8Bit().constData();
	TiXmlDocument doc(filename);

	XMLLoader* loader = new XMLLoader();

	if(doc.LoadFile()){
		doc.Accept(loader);
		sectors.clear();
		sectors = loader->sectors;
	}
	delete loader;
	UpdateMaxDistance();
	updateGL();
}
void MyGLWidget::WriteXML(){
	QString q_file_name = QFileDialog::getSaveFileName(this, tr("Save XML"), "../Output XML", tr("*.xml"));
	std::string filename = q_file_name.toLocal8Bit().constData();

	TiXmlDocument doc;
	TiXmlElement* root = new TiXmlElement("sectors");
	doc.LinkEndChild(root);
	for(unsigned int i = 0; i < sectors.size(); i++){
		TiXmlElement* sector;
		if(sectors[i]->GetType() == 1){
			sector = new TiXmlElement("wedge");
			Wedge* w = dynamic_cast<Wedge*>(sectors[i]);
			//Bounds of wedge
			sector->SetAttribute("left", w->left_bound);
			sector->SetAttribute("right", w->right_bound);
			sector->SetAttribute("near", w->near_bound);
			sector->SetAttribute("far", w->far_bound);
			//Snapping points
			for(unsigned int j = 0; j < w->snapping_points.size(); j++){
				TiXmlElement* snap = new TiXmlElement("snaparc");
				snap->SetAttribute("pos", w->snapping_points[j]->position);
				sector->LinkEndChild(snap);
			}
		}
		else{
			sector = new TiXmlElement("rect");
			Rect* w = dynamic_cast<Rect*>(sectors[i]);
			//Bounds of rect
			sector->SetAttribute("left", w->left_edge);
			sector->SetAttribute("right", w->right_edge);
			sector->SetAttribute("up", w->top_edge);
			sector->SetAttribute("down", w->bottom_edge);
		}
		//Do stuff for flags
		//Agents
		TiXmlElement* agents = new TiXmlElement("agents");
		agents->SetAttribute("bool", (int)(sectors[i]->agents));
		sector->LinkEndChild(agents);
		//Obstacles
		TiXmlElement* obstacles = new TiXmlElement("obstacles");
		obstacles->SetAttribute("bool", (int)(sectors[i]->obstacles));
		sector->LinkEndChild(obstacles);
		//Inspection
		TiXmlElement* inspection = new TiXmlElement("inspection");
		inspection->SetAttribute("bool", (int)(sectors[i]->inspection));
		sector->LinkEndChild(inspection);
		//Net Flow
		TiXmlElement* net_flow = new TiXmlElement("netflow");
		net_flow->SetAttribute("bool", (int)(sectors[i]->net_flow));
		sector->LinkEndChild(net_flow);
		//Density
		TiXmlElement* density = new TiXmlElement("density");
		density->SetAttribute("bool", (int)(sectors[i]->density));
		sector->LinkEndChild(density);
		//Cardinality
		TiXmlElement* cardinality = new TiXmlElement("cardinality");
		cardinality->SetAttribute("num", (sectors[i]->cardinality));
		sector->LinkEndChild(cardinality);
		//Attach sector to root node
		root->LinkEndChild(sector);
	}
	doc.SaveFile(filename);
}