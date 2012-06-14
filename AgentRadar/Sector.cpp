#include "Sector.h"


Sector::Sector()
{
	agents = obstacles = inspection = net_flow = density = true;
	cardinality = 1;
	selected = false;
}

Sector::Sector(bool a, bool o, bool i, bool nf, bool d, int c){
	agents = a;
	obstacles = o;
	inspection = i;
	net_flow = nf;
	density = d;
	cardinality = c;
	selected = false;
}


Sector::~Sector()
{
}

bool Sector::IntersectionTest(float x, float y){
	return false;
}

int Sector::GetType(){
	return -1;
}