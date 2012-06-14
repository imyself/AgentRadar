#pragma once

class Sector
{
public:
	Sector(void);
	Sector(bool a, bool o, bool i, bool nf, bool d, int c);
	~Sector(void);

	virtual bool IntersectionTest(float x, float y);
	virtual int GetType();

	bool agents, obstacles, inspection, net_flow, density;
	int cardinality;

	bool selected;
};

