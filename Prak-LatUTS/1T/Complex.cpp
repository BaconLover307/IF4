// Nama : Gregorius Jovan Kresnadi
// NIM  : 13518135
// Latihan UTS OOP

#include "Complex.h"

using namespace std;

Complex::Complex(int re, int im) {
    real = re;
    imaginer = im;
}

Complex::Complex() : Complex(0,0) {}

Complex::Complex(const Complex &comp) {
    real = comp.real;
    imaginer = comp.imaginer;
} 

Complex::~Complex() {
    // dtor
}

int Complex::getReal() {
    return real;
}

int Complex::getImaginer() {
    return imaginer;
}

void Complex::setReal(int re) {
    real = re;
} 

void Complex::setImaginer(int im) {
    imaginer = im;
}

Complex Complex::operator+(Complex const &c) {
    Complex ret;
    ret.real = real + c.real;
    ret.imaginer = imaginer + c.imaginer;
    return ret;
}

Complex Complex::operator-(Complex const &c) {
    Complex ret;
    ret.real = real - c.real;
    ret.imaginer = imaginer - c.imaginer;
    return ret;
}

Complex Complex::operator*(Complex const &c) {
    Complex ret;
    ret.real = real*c.real - imaginer*c.imaginer;
    ret.imaginer = real*c.imaginer + imaginer*c.real;
    return ret; 
}