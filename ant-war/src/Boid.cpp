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
#include <Boid.hpp>




Boid::Boid(float x, float y, float vx, float vy) :
	pos(Vector(x, y)),
	dir(Vector(vx, vy).Normalized()),
	speed(3)
	
{}

Boid::Boid():
	pos(Vector(100, 100)),
	dir(Vector(10, 10)),
	speed(1) 
{}

void Boid::RenderBoid(SDL_Renderer* renderer) {
	float fx = this->pos.x;
	float fy = this->pos.y;
	float vx = this->dir.x*10;
	float vy = this->dir.y*10;

	int ax = static_cast<int>(fx + vx);
	int ay = static_cast<int>(fy + vy);
	int bx = static_cast<int>(fx + vy / 2);
	int by = static_cast<int>(fy - vx / 2);
	int cx = static_cast<int>(fx - vy / 2);
	int cy = static_cast<int>(fy + vx / 2);


	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
	SDL_RenderDrawLine(renderer, ax, ay, bx, by);
	SDL_RenderDrawLine(renderer, cx, cy, bx, by);
	SDL_RenderDrawLine(renderer, ax, ay, cx, cy);
	
}

void Boid::UpdateBoid(Boid Boids[], int j, int l) {
	

	this->Cohesion(Boids, j,  l);
	this->Separation(Boids, j, l);
	this->Alignment(Boids, j, l);
	this->dir.Normalize();

	this->pos.x += speed * this->dir.x;
	this->pos.y += speed * this->dir.y;
	this->pos.x = fmod(this->pos.x, 800);
	this->pos.y = fmod(this->pos.y, 600);
}

float Boid::Boiddist(Boid B) {
	return this->pos.dist(B.pos);

}



void Boid::Separation(Boid Boids[], int j, int l) {
	float x = 0;
	float y = 0;
	int n = -1;
	for (int i = 0; i < l; i++) {
		if (this->Boiddist(Boids[i]) < 20) {
			if (this->Boiddist(Boids[i]) < 10) {
				x += Boids[i].pos.x;
				y += Boids[i].pos.y;
			};
			x += Boids[i].pos.x;
			y += Boids[i].pos.y;
			n++;
		}

		
	}
	if (n != 0) {
		x -= Boids[j].pos.x;
		y -= Boids[j].pos.y;
		x /= n;
		y /= n;
		Vector avg = Vector(x, y);

		this->dir = this->dir - (avg - this->pos) * (0,06);
		//this->dir.Normalize();
	}
	
};

void Boid::Cohesion(Boid Boids[], int j, int l) {
	float x = 0;
	float y = 0;
	int n = -1;
	for (int i = 0; i < l; i++) {
		if (this->Boiddist(Boids[i]) < 100) {
			x += Boids[i].pos.x;
			y += Boids[i].pos.y;
			n++;
		}
	}
	if (n != 0) {
		x -= Boids[j].pos.x;
		y -= Boids[j].pos.y;
		x /= n;
		y /= n;
		Vector avg = Vector(x, y);

		this->dir = this->dir + (avg - this->pos) * (0,02);
		//this->dir.Normalize();
	}
	

};

void Boid::Alignment(Boid Boids[], int j, int l) {
	float x = 0;
	float y = 0;
	int n = -1;
	for (int i = 0; i < l; i++) {
		if (this->Boiddist(Boids[i]) < 30) {
			x += Boids[i].dir.x;
			y += Boids[i].dir.y;
			n++;
		}
	}
	if (n != 0) {
		x -= Boids[j].dir.x;
		y -= Boids[j].dir.y;
		x /= n;
		y /= n;
		Vector avg = Vector(x, y);

		this->dir = this->dir + avg*(0,1);
		//this->dir.Normalize();
	}
};

