/* Nama         : Gregorius Jovan Kresnadi */
/* NIM          : 13518135 */
/* Program      : PolinomBF.cpp */
/* Deskripsi    : Implementasi Perkalian polinom metode Brute Force */
/* Keterangan   : Tugas Besar StiMa 2: Pustaka Polnom dengan metode
                  Brute Force dan Decrease and Conquer */

#include "PolinomBF.hpp"
#include <iostream>

using namespace std;

PolnomBF::PolnomBF() {
    this -> derajat = 0;
    for (int i = 0; i < MAX_LENGTH; i++) {
        this -> koef[i] = 0;
    }
}

PolnomBF::PolnomBF(int derajat) {
    this -> derajat = derajat;
    for (int i = 0; i < MAX_LENGTH; i++) {
        this -> koef[i] = 0;
    }
}

PolnomBF::PolnomBF(const PolnomBF& other) {
    this -> derajat = other.derajat;
    for (int i = 0; i < MAX_LENGTH; i++) {
        this -> koef[i] = other.koef[i];
    }
}

PolnomBF::~PolnomBF() {
    // tidak ada new, maka kosong
}

PolnomBF& PolnomBF::operator=(const PolnomBF& P) {
    derajat = P.derajat;
    for (int i=0; i<MAX_LENGTH; i++) {
        koef[i] = P.koef[i];
    }
    return *this;
}

int PolnomBF::getKoefAt(int idx) const {
    return koef[idx];
}
int PolnomBF::getDerajat() const {
    return derajat;
}
void PolnomBF::setKoefAt(int idx, int val) {
    koef[idx] = val;
}
void PolnomBF::setDerajat(int idx) {
    derajat = idx;
}

PolnomBF operator+(const PolnomBF & P1, const PolnomBF & P2) {
    PolnomBF Ph;
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
PolnomBF operator-(const PolnomBF & P1, const PolnomBF & P2) {
    PolnomBF Ph;
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
PolnomBF operator*(const PolnomBF & P, const int n) {
    PolnomBF Ph;
    Ph.setDerajat(P.getDerajat());
    for (int i = 0; i < Ph.getDerajat(); i++) {
        Ph.koef[i] = P.koef[i] * n;
    }
    return Ph;
}
PolnomBF operator*(const int n, const PolnomBF & P) {
    PolnomBF Ph;
    Ph.setDerajat(P.getDerajat());
    for (int i = 0; i < Ph.getDerajat(); i++) {
        Ph.koef[i] = n * P.koef[i];
    }
    return Ph;
}
PolnomBF operator/(const PolnomBF & P, const int n) {
    PolnomBF Ph;
    Ph.setDerajat(P.getDerajat());
    for (int i = 0; i < Ph.getDerajat(); i++) {
        Ph.koef[i] = P.koef[i] / n;
    }
    return Ph;
}

void PolnomBF::input() {
    for (int i = 0; i<derajat; i++) {
        cin >> koef[i];
    }
}

void PolnomBF::printKoef() {
    for (int i = 0; i<derajat; i++) {
        cout << koef[i] << endl;
    }
}

int PolnomBF::substitute(int x) {
    int ret = 0, p = 1;
    for (int i = 0; i<derajat; i++) {
        ret += p * koef[i];
        p *= x;
    }
    return ret;
}

// Melakukan aksi derivasi terhadap PolnomBF.
// Lakukan pengurangan pada derajat tertinggi PolnomBF.
// Apabila derajat tertinggi = 0, hasil derivasi = 0 (dengan derajat tertinggi = 0)
PolnomBF PolnomBF::derive() {
    if (derajat == 0) {
        PolnomBF Ph;
        return Ph;
    } else {
        PolnomBF Ph(derajat-1);
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
void PolnomBF::print() {
    cout << koef[0];
    for (int i = 1; i <= derajat; i++) {
        if (koef[i] < 0) cout << koef[i] << "x^" << i;
        else if (koef[i] == 0) continue;
        else cout << "+" << koef[i] << "x^" << i;
    }
    cout << endl; // kata pak bos biar ganteng
}
