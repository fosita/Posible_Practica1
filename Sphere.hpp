#pragma once
#include <iostream>

using namespace std;
using namespace System;

class Sphere {
private:
	int x, y, dx, dy;
	char form;
	bool limiter;
public:
	Sphere(void);
	Sphere(int x, int y);
	~Sphere();

	void erase();
	void move();
	void draw();
};

Sphere::Sphere(void) {
	int x = 0;
	int y = 0;
	int dx = 1;
	int dy = 0;
	char form = 79;
	bool limiter = true;
}

Sphere::Sphere(int _x, int _y) {
	x = _x;
	y = _y;
	dx = 1;
	dy = 0;
	form = 79;
}

Sphere::~Sphere() {}

void Sphere::erase() {
	Console::SetCursorPosition(x, y);
	cout << " ";
}

void Sphere::move() {
	if (x == 0 && y == 1) {
		dx = 0;
		dy = 0;
		limiter = false;
	}
	if (x == 79 && y == 0) {
		dx = 0;
		dy = 1;
	}
	if (x == 79 && y == 39) {
		dx = -1;
		dy = 0;
	}
	if (x == 0 && y == 39) {
		dx = 0;
		dy = -1;
	}

	x += dx;
	y += dy;
}

void Sphere::draw() {
	if (limiter != false) {
		Console::SetCursorPosition(x, y);
		cout << (char)form;
	}
}