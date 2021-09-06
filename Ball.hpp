#pragma once

#include <iostream>

using namespace std;
using namespace System;

int Direction[2] = { 1, -1 };

class Ball {
private:
	int x;
	int y;
	int dx;
	int dy;
	char form;
public:
	Ball(void);
	Ball(int x, int y);
	~Ball();

	void erase();
	void move();
	void draw();
};

Ball::Ball(void) {
	x = 40;
	y = 35;
	dx = Direction[rand() % 2];
	dy = -1;
	form = 79;
}

Ball::Ball(int _x, int _y) {
	x = _x;
	y = _y;
	dx = Direction[rand() % 2];
	dy = -1;
	form = 79;
}

Ball::~Ball() {}

void Ball::erase() {
	Console::SetCursorPosition(x, y);
	cout << " ";
}

void Ball::move() {
	if (x > 78 || x < 2) {
		dx *= -1;
	}
	if (y > 38 || y < 2) {
		dy *= -1;
	}

	x += dx;
	y += dy;
}

void Ball::draw() {
	Console::SetCursorPosition(x, y);
	cout << char(form);
}