// Nama : Gregorius Jovan Kresnadi
// NIM  : 13518135
// Latihan UTS OOP

#include "Ball.hpp"
#include <iostream>

using namespace std;

Ball::Ball(int r) {
	radius = r;
}

Ball::Ball() : radius(1) {}

Ball::Ball(const Ball& b) {
	radius = b.radius;
}

Ball::~Ball() {
	// none
}

void Ball::bounce() {
	cout << "bo";
	for (int i=0;i<radius;i++) {
		cout << "i";
	}
	cout << "ng\n";
}