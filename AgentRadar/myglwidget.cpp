#include "myglwidget.h"
#include "Wedge.h"
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
	//Clear the QListWidget
	for(unsigned int i = 0; i < selected_sectors.size(); i++){
		if(selected_sectors[i] == s){
			s->selected = false;
			selected_sectors.erase(selected_sectors.begin() + i);
			//Get the last Sector* in sel_secs if we're dealing with Wedges and send all its snapping pts to the QListWidget
			return;
		}
	}
	selected_sectors.push_back(s);
	s->selected = true;
	if(s->GetType()==1){
		for(unsigned int i = 0; i < dynamic_cast<Wedge*>(s)->snapping_points.size(); i++){
			emit SendSnappingPoint(dynamic_cast<Wedge*>(s)->snapping_points[i]);
		}
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

	sectors.push_back(new Wedge());
	sectors.push_back(new Wedge(180, 120, 10, 100));
	sectors.push_back(new Wedge(240, 180, 10, 100));
	sectors.push_back(new Wedge(300, 240, 10, 100));
	sectors.push_back(new Wedge(360, 300, 10, 100));
	sectors.push_back(new Wedge(60, 0, 10, 100));
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
			//Max distance for rectangles
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
			if(w->selected)
				glColor3f(0.3,1,0.3);
			else
				glColor3f(1,0.3,0.3);
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
		;
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
void MyGLWidget::DisplayAgents(bool){
}
void MyGLWidget::DisplayObstacles(bool){
}
void MyGLWidget::DisplayInspection(bool){
}
void MyGLWidget::DisplayNetFlow(bool){
}
void MyGLWidget::DisplayDensity(bool){
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