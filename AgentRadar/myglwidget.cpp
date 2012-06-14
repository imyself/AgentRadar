#include "myglwidget.h"
#include "Wedge.h"
#include "glm/gtc/matrix_transform.hpp"

MyGLWidget::MyGLWidget(QWidget* parent) : QGLWidget(parent) {
	;
}

void MyGLWidget::mousePressEvent(QMouseEvent* e){
	if(e->buttons() == Qt::LeftButton){
		for(unsigned int i = 0; i < sectors.size(); i++){
			if(sectors[i]->IntersectionTest(e->x(), e->y())){
				ToggleSelected(sectors[i]);
			}
		}
	}
}

void MyGLWidget::ToggleSelected(Sector* s){
	for(unsigned int i = 0; i < selected_sectors.size(); i++){
		if(selected_sectors[i] == s){
			selected_sectors.erase(selected_sectors.begin() + i);
			return;
		}
	}
	selected_sectors.push_back(s);
}

void MyGLWidget::initializeGL(){
	glClearColor(0, 0, 0, 1);
	glEnable(GL_DEPTH_TEST);
	glClearDepth(1.0);
	glDepthFunc(GL_LEQUAL);

	glMatrixMode(GL_PROJECTION);
	glOrtho(-10, 10, -10, 10, -1, 1);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	sectors.push_back(new Wedge());
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
		//GLUquadric* q = gluNewQuadric();
		//gluPartialDisk(q, w->near_bound, w->far_bound, 10, 0, w->right_bound, w->left_bound);
		float pos = 0.0f;
		glBegin(GL_POLYGON);
			//Color
			glColor3f(1,0.3,0.3);
			//Far right bound
			glm::vec4 p(w->far_bound, 0, 1, 1);
			p = glm::rotate(glm::mat4(1.0f), (float)w->right_bound, glm::vec3(0,0,1)) * p;
			p = glm::translate(glm::mat4(1.0f), glm::vec3(pos,pos,0.0f)) * p;
			glVertex2f(p.x, p.y);
			//Rotate FRB by 5 degrees until reach FLB
			int angle = w->right_bound;
			while(angle < w->left_bound){
				angle = min(angle + 5, w->left_bound);
				p = glm::vec4(w->far_bound, 0, 1, 1);
				p = glm::rotate(glm::mat4(1.0f), (float)angle, glm::vec3(0,0,1)) * p;
				p = glm::translate(glm::mat4(1.0f), glm::vec3(pos,pos,0.0f)) * p;
				glVertex2f(p.x, p.y);
			}
			//Near left bound
			p = glm::vec4(w->near_bound, 0, 1, 1);
			p = glm::rotate(glm::mat4(1.0f), (float)w->left_bound, glm::vec3(0,0,1)) * p;
			p = glm::translate(glm::mat4(1.0f), glm::vec3(pos,pos,0.0f)) * p;
			glVertex2f(p.x, p.y);
			//Rotate NLB by 5 degrees until reach NRB
			angle = w->left_bound;
			while(angle > w->right_bound){
				angle = max(angle - 5, w->right_bound);
				p = glm::vec4(w->near_bound, 0, 1, 1);
				p = glm::rotate(glm::mat4(1.0f), (float)angle, glm::vec3(0,0,1)) * p;
				p = glm::translate(glm::mat4(1.0f), glm::vec3(pos,pos,0.0f)) * p;
				glVertex2f(p.x, p.y);
			}
		glEnd();
	}
	//Rectangle
	else if(s->GetType() == 2){
		;
	}
}