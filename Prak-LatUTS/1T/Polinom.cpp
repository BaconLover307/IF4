// Nama : Gregorius Jovan Kresnadi
// NIM  : 13518135
// Latihan UTS OOP

#include "Polinom.hpp"
#include <iostream>

using namespace std;

Polinom::Polinom() {
    this->derajat = 0;
    for (int i=0; i<MAX_LENGTH; i++) {
        koef[i] = 0;
    }
}

Polinom::Polinom(int derajat) {
    this->derajat = derajat;
    for (int i=0; i<MAX_LENGTH; i++) {
        koef[i] = 0;
    }
}


Polinom::Polinom(const Polinom& p) {
    derajat = p.derajat;
    for (int i=0; i<MAX_LENGTH; i++) {
        koef[i] = p.koef[i];
    }
}

Polinom::~Polinom() {
    // tidak ada deklarasi pointer, maka kosong
}

Polinom& Polinom::operator=(const Polinom& p) {
    derajat = p.derajat;
    for (int i=0; i<MAX_LENGTH; i++) {
        koef[i] = p.koef[i];
    }
    return *this;
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

void Polinom::setDerajat(int idx) {
    derajat = idx;
}

Polinom operator+(const Polinom& a, const Polinom& b) {
    Polinom P;
    if (a.getDerajat() > b.getDerajat()) {
        P.setDerajat(a.getDerajat());
    } else {
        P.setDerajat(b.getDerajat());
    }
    for (int i=0; i<=P.getDerajat(); i++) {
        P.koef[i] = a.koef[i] + b.koef[i];
    }
    return P;
}

Polinom operator-(const Polinom& a, const Polinom& b) {
    Polinom P;
    if (a.getDerajat() > b.getDerajat()) {
        P.setDerajat(a.getDerajat());
    } else {
        P.setDerajat(b.getDerajat());
    }
    for (int i=0; i<=P.getDerajat(); i++) {
        P.koef[i] = a.koef[i] - b.koef[i];
    }
    return P;
}

Polinom operator*(const Polinom& a, const int x) {
    Polinom P;
    P.setDerajat(a.getDerajat());
    for (int i=0; i<=P.derajat; i++) {
        P.koef[i] = a.koef[i] * x;
    }
    return P;
}

Polinom operator*(const int x, const Polinom& a) {
    Polinom P;
    P.setDerajat(a.getDerajat());
    for (int i=0; i<=P.derajat; i++) {
        P.koef[i] = a.koef[i] * x;
    }
    return P;
}

Polinom operator/(const Polinom& a, const int x) {
    Polinom P;
    P.setDerajat(a.getDerajat());
    for (int i=0; i<=a.derajat; i++) {
        P.koef[i] = a.koef[i] / x;
    }
    return P;
}

void Polinom::input() {
    for (int i = 0; i<=derajat; i++) {
        cin >> koef[i];
    }
}

void Polinom::printKoef() {
    for (int i = 0; i<=derajat; i++) {
        cout << koef[i] << endl;
    }
}

int Polinom::substitute(int x) {
    int ret = 0, p = 1;
    for (int i = 0; i<=derajat; i++) {
        ret += p * koef[i];
        p *= x;
    }
    return ret;
}

Polinom Polinom::derive() {
    if (derajat <= 0) {
        Polinom Ph;
        return Ph;
    } else {
        Polinom Ph(derajat-1);
        for (int i=0; i<=Ph.derajat; i++) {
            Ph.koef[i] = koef[i+1] * (i+1);
        }
        return Ph;
    }
}

void Polinom::print() {
    cout << koef[0];
    for (int i=1; i<=derajat; i++) {
        if (koef[i] > 0) cout << "+" << koef[i] << "x^" << i;
        else if (koef[i] == 0) continue;
        else cout<< koef[i] << "x^" << i;
    }
    cout << endl;
}