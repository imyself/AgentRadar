#include "Rect.h"


Rect::Rect(void)
{
	left_edge = 0;
	right_edge = 10;
	top_edge = 10;
	bottom_edge = 0;
}


Rect::~Rect(void)
{
}

bool Rect::IntersectionTest(float x, float y, float max_distance){
	float dx = (x-200)/max_distance;
	float dy = (200-y)/max_distance;
	if(dx > left_edge/max_distance && dx < right_edge/max_distance && dy < top_edge/max_distance && dy > bottom_edge/max_distance){
		return true;
	}
	return false;
}


int Rect::GetType(){
	return 2;
}