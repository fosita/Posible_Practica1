#pragma once
#include "Ball.hpp"

class _2Pitcher {
private:
	Ball** BallArray;
	int n;
public:
	_2Pitcher(void);
	~_2Pitcher();

	int getN();
	void addBall(Ball* NewBall);
	//void eraseBall(Ball* NewBall);
	Ball* obtainBall(int i);
};

_2Pitcher::_2Pitcher(void) {
	BallArray = nullptr;
	n = 0;
}

_2Pitcher::~_2Pitcher() {}

int _2Pitcher::getN() {
	return n;
}

void _2Pitcher::addBall(Ball* NewBall) {
	Ball** ArrTemp = new Ball * [n + 1];
	for (int i = 0; i < n; i++) {
		ArrTemp[i] = BallArray[i];
	}
	ArrTemp[n] = NewBall;
	n += 1;

	if (BallArray != nullptr) {
		delete[] BallArray;
	}
	BallArray = ArrTemp;
}


Ball* _2Pitcher::obtainBall(int i) {
	return BallArray[i];
}