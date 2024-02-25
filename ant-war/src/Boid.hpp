#ifdef _WIN32
#include <SDL.h>

#define not !

#else

#include <SDL2/SDL.h>

#endif


#include <iostream>
#include <random>
#include <vector>
#include <cmath>
#include "Vector.hpp"

struct Boid {

	Vector pos;
	Vector dir;
	float speed;
	

	Boid();
	Boid(float x, float y, float vx, float vy);
	
	void RenderBoid(SDL_Renderer * renderer);
	void UpdateBoid(Boid[], int, int);
	float Boiddist(Boid);
	void Separation(Boid[], int, int);
	void Cohesion(Boid[], int, int);
	void Alignment(Boid[], int, int);
	

};