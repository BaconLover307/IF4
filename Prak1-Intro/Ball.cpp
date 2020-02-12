/* Nama         : Gregorius Jovan Kresnadi */
/* NIM          : 13518135 */
/* Tanggal      : 30-01-2020 */
/* Program      : Ball.cpp */
/* Deskripsi    : Implementasi ball */

#include "Ball.hpp"
#include <iostream>

using namespace std;

Ball::Ball() {
    this -> radius = 1;
}

Ball::Ball(int radius) {
	this -> radius = radius;
}
Ball::Ball(const Ball& b) {
	this -> radius = b.radius;
}
Ball::~Ball() {

}

void Ball::bounce() {
	cout << "bo";
	for (int i = 0; i < radius; i ++) {
		cout << "i";
	}
	cout << "ng" << endl;
}
