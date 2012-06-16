#include "Wedge.h"

using namespace glm;


Wedge::Wedge() : Sector()
{
	left_bound = 120;
	right_bound = 60;
	near_bound = 10.0f;
	far_bound = 100.0f;
	sweep = 60;
	//Add default snapping points later?
	for(int i = 15; i < 100; i+=10){
		snapping_points.push_back(new SnappingPoint(i));
	}
}

Wedge::Wedge(int lb, int rb, float nb, float fb) : Sector(){
	left_bound = lb;
	right_bound = rb;
	near_bound = nb;
	far_bound = fb;
	sweep = ComputeSweep(lb, rb);
}

Wedge::Wedge(int lb, int rb, float nb, float fb, bool a, bool o, bool i, bool nf, bool d, int c) : Sector(a, o, i, nf, d, c){
	left_bound = lb;
	right_bound = rb;
	near_bound = nb;
	far_bound = fb;
	sweep = ComputeSweep(lb, rb);
}

Wedge::~Wedge()
{
	snapping_points.clear();
}

bool Wedge::IntersectionTest(float x, float y, float max_distance){
	//Inner circle test
	if(glm::distance(vec2(x-200,200-y)/200.0f, vec2(0,0)) < this->near_bound/max_distance)
		return false;
	//Outer circle test
	if(glm::distance(vec2(x-200,200-y)/200.0f, vec2(0,0)) > this->far_bound/max_distance)
		return false;
	//Arc test
	//Right vector
	float rb = glm::radians((float)right_bound);
	float lb = glm::radians((float)left_bound);
	mat2 rotate = mat2(cos(rb), sin(rb), -sin(rb), cos(rb));//Column major
	vec2 a = rotate * vec2(1,0);
	//Left vector
	rotate = mat2(cos(lb), sin(lb), -sin(lb), cos(lb));//Column major
	vec2 b = rotate * vec2(1,0);
	//Point clicked
	vec2 v = glm::normalize(vec2(x-200,200-y));
	//Angles
	float angle_a = glm::degrees(acos(glm::dot(a,v)));//WORRY ABOUT NEGATIVE ANGLES!!!!!!!!!111!!!!
	float angle_b = glm::degrees(acos(glm::dot(b,v)));
	if(abs(sweep - (angle_a + angle_b)) > 0.01f)
		return false;

	return true;
}

int Wedge::ComputeSweep(int lb, int rb){
	int s = lb - rb;
	if(s < 0)
		s = 360 + s;
	return s;
}

int Wedge::GetType(){
	return 1;//2 for rectangles
}