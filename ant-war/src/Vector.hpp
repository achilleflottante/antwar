#ifdef _WIN32
#include <SDL.h>

#define not !

#else

#include <SDL2/SDL.h>

#endif

#include "it_s_work.h"

#include <iostream>
#include <random>
#include <vector>
#include <cmath>


struct Vector {
public:
	float x;
	float y;

	Vector(float x, float y);
	float len();
	float dist(Vector);
	float torusdist(Vector, int ,int);
	void Normalize();
	Vector Normalized();
	Vector operator + (Vector);
	Vector operator - (Vector);
	Vector operator * (float);
	
	

};