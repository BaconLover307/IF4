/* Nama         : Gregorius Jovan Kresnadi */
/* NIM          : 13518135 */
/* Program      : Polinom.cpp */
/* Deskripsi    : Implementasi polinom */

#include "Polinom.hpp"
#include <iostream>

using namespace std;

Polinom::Polinom() {
    this -> derajat = 0;
    for (int i = 0; i < MAX_LENGTH; i++) {
        this -> koef[i] = 0;
    }
}

Polinom::Polinom(int derajat) {
    this -> derajat = derajat;
    for (int i = 0; i < MAX_LENGTH; i++) {
        this -> koef[i] = 0;
    }
}

Polinom::Polinom(const Polinom& other) {
    this -> derajat = other.derajat;
    for (int i = 0; i < MAX_LENGTH; i++) {
        this -> koef[i] = other.koef[i];
    }
}

Polinom::~Polinom() {
    // tidak ada new, maka kosong
}

Polinom& Polinom::operator=(const Polinom& P) {
    derajat = P.derajat;
    for (int i=0; i<MAX_LENGTH; i++) {
        koef[i] = P.koef[i];
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

Polinom operator+(const Polinom & P1, const Polinom & P2) {
    Polinom Ph;
    if (P1.getDerajat() > P2.getDerajat()) {
        Ph.setDerajat(P1.getDerajat());
    } else {
        Ph.setDerajat(P2.getDerajat());
    }
    for (int i = 0; i < Ph.getDerajat(); i++) {
        Ph.koef[i] = P1.koef[i] + P2.koef[i]; 
    }
    return Ph;
}
Polinom operator-(const Polinom & P1, const Polinom & P2) {
    Polinom Ph;
    if (P1.getDerajat() > P2.getDerajat()) {
        Ph.setDerajat(P1.getDerajat());
    } else {
        Ph.setDerajat(P2.getDerajat());
    }
    for (int i = 0; i < Ph.getDerajat(); i++) {
        Ph.koef[i] = P1.koef[i] - P2.koef[i]; 
    }
    return Ph;
}
Polinom operator*(const Polinom & P, const int n) {
    Polinom Ph;
    Ph.setDerajat(P.getDerajat());
    for (int i = 0; i < Ph.getDerajat(); i++) {
        Ph.koef[i] = P.koef[i] * n; 
    }
    return Ph;
}
Polinom operator*(const int n, const Polinom & P) {
    Polinom Ph;
    Ph.setDerajat(P.getDerajat());
    for (int i = 0; i < Ph.getDerajat(); i++) {
        Ph.koef[i] = n * P.koef[i]; 
    }
    return Ph;
}
Polinom operator/(const Polinom & P, const int n) {
    Polinom Ph;
    Ph.setDerajat(P.getDerajat());
    for (int i = 0; i < Ph.getDerajat(); i++) {
        Ph.koef[i] = P.koef[i] / n; 
    }
    return Ph;
}

void Polinom::input() {
    for (int i = 0; i<derajat; i++) {
        cin >> koef[i];
    }
}

void Polinom::printKoef() {
    for (int i = 0; i<derajat; i++) {
        cout << koef[i] << endl;
    }
}

int Polinom::substitute(int x) {
    int ret = 0, p = 1;
    for (int i = 0; i<derajat; i++) {
        ret += p * koef[i];
        p *= x;
    }
    return ret;
}

// Melakukan aksi derivasi terhadap Polinom.
// Lakukan pengurangan pada derajat tertinggi Polinom.
// Apabila derajat tertinggi = 0, hasil derivasi = 0 (dengan derajat tertinggi = 0)
Polinom Polinom::derive() {
    if (derajat == 0) {
        Polinom Ph;
        return Ph;
    } else {
        Polinom Ph(derajat-1);
        for (int i = 0; i<Ph.derajat; i++) {
            Ph.koef[i] = koef[i+1] * (i+1);
        }
        return Ph;
    }
}

// ** METHOD BONUS (TC 12,13,14) ** (Tidak wajib dikerjakan)
// Mencetak polinom dengan format: A+Bx^1+Cx^2+Dx^3...dst (diakhiri dengan end-of-line)
// Apabila suatu koefisien bernilai < 0, gunakan tanda "-" untuk menggantikan tanda "+"
// Apabila suatu koefisien bernilai 0, lewati koefisien tersebut dan lanjutkan ke koefisien selanjutnya
// Jika seluruh koefisien bernilai 0, keluarkan "0"
void Polinom::print() {
    cout << koef[0];
    for (int i = 1; i <= derajat; i++) {
        if (koef[i] < 0) cout << koef[i] << "x^" << i; 
        else if (koef[i] == 0) continue;
        else cout << "+" << koef[i] << "x^" << i;
    }
    cout << endl; // kata pak bos biar ganteng
}
