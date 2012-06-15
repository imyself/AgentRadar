#include "myglwidget.h"
#include "Wedge.h"
#include "Rect.h"
#include "glm/gtc/matrix_transform.hpp"

MyGLWidget::MyGLWidget(QWidget* parent) : QGLWidget(parent) {
	setFocusPolicy(Qt::ClickFocus);
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
	}
}

void MyGLWidget::initializeGL(){
	glClearColor(0, 0, 0, 1);
	//glEnable(GL_DEPTH_TEST);
	glClearDepth(1.0);
	glDepthFunc(GL_LEQUAL);

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

	sectors.push_back(new Rect());

	//Update max distance
	max_distance = 0;
	UpdateMaxDistance();
}

void MyGLWidget::UpdateMaxDistance(){
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
}

void MyGLWidget::Render(Sector* s){
	//Wedge
	if(s->GetType() == 1){
		Wedge* w = dynamic_cast<Wedge*>(s);
		//Draw the body of the wedge
		glBegin(GL_POLYGON);
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
			//Far right bound
			glm::vec4 p(w->far_bound/max_distance, 0, 1, 1);
			p = glm::rotate(glm::mat4(1.0f), (float)w->right_bound, glm::vec3(0,0,1)) * p;
			glVertex2f(p.x, p.y);
			//Rotate FRB by 5 degrees until reach FLB
			int angle = w->right_bound;
			while(angle < w->left_bound){
				angle = min(angle + 5, w->left_bound);
				p = glm::vec4(w->far_bound/max_distance, 0, 1, 1);
				p = glm::rotate(glm::mat4(1.0f), (float)angle, glm::vec3(0,0,1)) * p;
				glVertex2f(p.x, p.y);
			}
			//Near left bound
			p = glm::vec4(w->near_bound/max_distance, 0, 1, 1);
			p = glm::rotate(glm::mat4(1.0f), (float)w->left_bound, glm::vec3(0,0,1)) * p;
			glVertex2f(p.x, p.y);
			//Rotate NLB by 5 degrees until reach NRB
			angle = w->left_bound;
			while(angle > w->right_bound){
				angle = max(angle - 5, w->right_bound);
				p = glm::vec4(w->near_bound/max_distance, 0, 1, 1);
				p = glm::rotate(glm::mat4(1.0f), (float)angle, glm::vec3(0,0,1)) * p;
				glVertex2f(p.x, p.y);
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
		//Draw the snapping points
		for(unsigned int i = 0; i < w->snapping_points.size(); i++){
			float s = w->snapping_points[i]->position / max_distance;
			p = glm::vec4(s, 0, 1, 1);
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
	}
}

//SLOTS

//SET UP
void MyGLWidget::SetTypeWedges(){
}
void MyGLWidget::SetTypeRectangles(){
}
void MyGLWidget::SetNumberSectors(int){
}

void MyGLWidget::MergeSelectedSectors(){
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
void MyGLWidget::SetCardinality(int){
}

//WEDGE SLOTS
//Shifting Radial Boundaries
void MyGLWidget::WedgeSelectLeft(bool){
}
void MyGLWidget::WedgeSelectRight(bool){
}
void MyGLWidget::WedgeClockwise(){
}
void MyGLWidget::WedgeCounterClockwise(){
}
void MyGLWidget::WedgeSetDegrees(int){
}

//Shifting Arc-Aligned Boundaries
void MyGLWidget::WedgeSelectNear(bool){
}
void MyGLWidget::WedgeSelectFar(bool){
}
void MyGLWidget::WedgeCloser(){
}
void MyGLWidget::WedgeFarther(){
}
void MyGLWidget::WedgeSetDistance(double){
}