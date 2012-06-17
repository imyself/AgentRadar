#include "Rect.h"


Rect::Rect(void) : Sector()
{
	left_edge = 0;
	right_edge = 10;
	top_edge = 10;
	bottom_edge = 0;
}

Rect::Rect(float lb, float rb, float ub, float bb){
	left_edge = lb;
	right_edge = rb;
	top_edge = ub;
	bottom_edge = bb;
}


Rect::~Rect(void)
{
}

bool Rect::IntersectionTest(float x, float y, float max_distance){
	float dx = (x-200)/200;
	float dy = (200-y)/200;
	float lt = left_edge/max_distance;
	float rt = right_edge/max_distance;
	float ut = top_edge/max_distance;
	float bt = bottom_edge/max_distance;

	if(dx > lt && dx < rt && dy < ut && dy > bt){
		return true;
	}
	return false;
}


int Rect::GetType(){
	return 2;
}