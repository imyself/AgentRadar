#pragma once

#include "Sector.h"


class Rect : public Sector
{
public:
	Rect(void);
	~Rect(void);

	//Variables
	float left_edge, right_edge, top_edge, bottom_edge;

	//Functions
	bool IntersectionTest(float x, float y, float max_distance);
	int GetType();
};

