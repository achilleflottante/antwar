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
#include <Vector.hpp>



Vector::Vector(float x, float y):
	x(x),
	y(y)
	
{};

float Vector::len() {
	float a = this->x;
	float b = this->y;
	return sqrt(a * a + b * b);
};

float Vector::dist(Vector V) {
	float a = this->x - V.x;
	float b = this->y - V.y;
	return sqrt(a * a + b * b);

};

float Vector::torusdist(Vector V, int h, int w) {
	float a = this->x - V.x;
	float b = this->y - V.y;
	float u = fmin(abs(a), abs(w - a));
	float v = fmin(abs(b), abs(h - b));
	return sqrt(u * u + v * v);
};

void Vector::Normalize() {
	float l = this->len();
	this->x /= l;
	this->y /= l;
};

Vector Vector::Normalized() {
	this->Normalize();
	return *this;
};

Vector Vector::operator+(Vector b) {
	return Vector(this->x + b.x, this->y + b.y);
};

Vector Vector::operator-(Vector b) {
	return Vector(this->x - b.x, this->y - b.y);
};

Vector Vector::operator*(float a) {
	return Vector(this->x * a, this->y * a);
}







