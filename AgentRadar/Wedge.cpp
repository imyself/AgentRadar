#include "Wedge.h"

using namespace glm;


Wedge::Wedge() : Sector()
{
	left_bound = 120;
	right_bound = 60;
	near_bound = 0.0f;
	far_bound = 5.0f;
	sweep = 60;
	//Add default snapping points later?
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
}

bool Wedge::IntersectionTest(float x, float y){
	//Inner circle test
	if(glm::distance(vec2(x,y), vec2(0,0)) < this->near_bound)
		return false;
	//Outer circle test
	if(glm::distance(vec2(x,y), vec2(0,0)) > this->far_bound)
		return false;
	//Arc test
	//Right vector
	mat2 rotate = mat2(cos((float)right_bound), sin((float)right_bound), -sin((float)right_bound), cos((float)right_bound));//Column major
	vec2 a = rotate * vec2(1,0);
	//Left vector
	rotate = mat2(cos((float)left_bound), sin((float)left_bound), -sin((float)left_bound), cos((float)left_bound));//Column major
	vec2 b = rotate * vec2(1,0);
	//Point clicked
	vec2 v = glm::normalize(vec2(x,y));
	//Angles
	float angle_a = acos(glm::dot(a,v));//WORRY ABOUT NEGATIVE ANGLES!!!!!!!!!111!!!!
	float angle_b = acos(glm::dot(v,b));
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