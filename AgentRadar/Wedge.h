#pragma once

#include "Sector.h"
#include <vector>
#include "glm/glm.hpp"

using namespace std;

class Wedge : public Sector
{
public:
	Wedge(void);
	Wedge(int lb, int rb, float nb, float fb);
	Wedge(int lb, int rb, float nb, float fb, bool a, bool o, bool i, bool nf, bool d, int c);
	~Wedge(void);

	bool IntersectionTest(float x, float y);
	int ComputeSweep(int lb, int rb);
	int GetType();

	int left_bound, right_bound;
	float near_bound, far_bound;
	int sweep;

	vector<int> snapping_points;
};

