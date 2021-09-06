#pragma once
#include "Sphere.hpp"

class _1Pitcher {
private:
	Sphere** SphereArr;
	int n;
public:
	_1Pitcher(void);
	~_1Pitcher();

	int getN();
	void addSphere(Sphere* NewSphere);
	Sphere* obtainSphere(int i);
};

_1Pitcher::_1Pitcher(void) {
	SphereArr = nullptr;
	n = 0;
}

_1Pitcher::~_1Pitcher() {}

int _1Pitcher::getN() {
	return n;
}

void _1Pitcher::addSphere(Sphere* NewSphere) {
	Sphere** TempSphere = new Sphere * [n + 1];
	for (int i = 0; i < n; i++) {
		TempSphere[i] = SphereArr[i];
	}
	TempSphere[n] = NewSphere;
	n += 1;

	if (SphereArr != nullptr) {
		delete[] SphereArr;
	}
	SphereArr = TempSphere;
}

Sphere* _1Pitcher::obtainSphere(int i) {
	return SphereArr[i];
}