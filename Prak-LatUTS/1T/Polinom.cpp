// Nama : Gregorius Jovan Kresnadi
// NIM  : 13518135
// Latihan UTS OOP

#include "Polinom.hpp"
#include <iostream>

using namespace std;

Polinom::Polinom() : Polinom(0) {}

Polinom::Polinom(int n) {
    derajat = n;
    for (int i=0;i<MAX_LENGTH;i++) {
        koef[i] = 0;
    }
}

Polinom::Polinom(const Polinom& p) {
    derajat = p.derajat;
    for (int i=0;i<=MAX_LENGTH;i++) {
        koef[i] = p.koef[i];
    }
}

Polinom::~Polinom() {
}

Polinom& Polinom::operator=(const Polinom& p) {
    derajat = p.derajat;
    for (int i=0;i<=derajat;i++) {
        koef[i] = p.koef[i];
    }
}

int Polinom::getKoefAt(int idx) const {
    return koef[idx];
}

int Polinom::getDerajat() const {
    return derajat;
}
void Polinom::setKoefAt(int idx, int val) {
    koef[idx] = val;
}

void Polinom::setDerajat(int val) {
    derajat = val;
}

Polinom operator+(const Polinom& a, const Polinom& b) {
    Polinom Ph;
    Ph.derajat = max(a.derajat, b.derajat);
    for (int i=0;i<=Ph.derajat; i++) {
        Ph.koef[i] = a.koef[i] + b.koef[i];
    }    
    return Ph;
}

Polinom operator-(const Polinom& a, const Polinom& b) {
    Polinom Ph;
    Ph.derajat = max(a.derajat, b.derajat);
    for (int i=0;i<=Ph.derajat; i++) {
        Ph.koef[i] = a.koef[i] - b.koef[i];
    }    
    return Ph;
}

Polinom operator*(const Polinom& a, const int x) {
    Polinom Ph;
    Ph.derajat = a.derajat;
    for (int i=0;i<=Ph.derajat; i++) {
        Ph.koef[i] = a.koef[i] * x;
    }    
    return Ph;
}

Polinom operator*(const int x, const Polinom& a) {
    return a*x;
}

Polinom operator/(const Polinom& a, const int x) {
    Polinom Ph;
    Ph.derajat = a.derajat;
    for (int i=0;i<=Ph.derajat; i++) {
        Ph.koef[i] = a.koef[i] / x;
    }    
    return Ph;
}

void Polinom::input() {
    for (int i=0; i<=derajat; i++) {
        cin >> koef[i];
    }
}
 
int Polinom::substitute(int x) {
    int hasil=0;
    int d=1;
    for (int i=0;i<derajat;i++) {
        hasil += koef[i] * d;
        d *= x;
    }
    return hasil;
} 
Polinom Polinom::derive() {
    if (derajat <= 0) {
        Polinom Ph;
        return Ph;
    } else {
        Polinom Ph;
        Ph.derajat = derajat-1;
        for (int i=0;i<derajat;i++) {
            Ph.koef[i] = koef[i+1] * (i+1);
        }
        return Ph;
    }
}

void Polinom::print() {
    cout<<koef[0];
    for (int i=1;i<=derajat;i++) {
        if (koef[i] == 0) continue;
        else if(koef[i] > 0) cout << "+" << koef[i] << "x^" << i;
        else cout << koef[i] << "x^" << i;
    }
    //memperindah
    cout <<endl;
}