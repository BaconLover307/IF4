/* Nama         : Gregorius Jovan Kresnadi */
/* NIM          : 13518135 */
/* Program      : PolinomBF.cpp */
/* Deskripsi    : Implementasi Perkalian polinom metode Brute Force */
/* Keterangan   : Tugas Besar StiMa 2: Pustaka Polinom dengan metode
                  Brute Force dan Divide and Conquer */

#include "PolinomBF.hpp"
#include <iostream>
#include <cstdlib>
#include <chrono>
#include <ratio>

using namespace std;
using namespace std::chrono;

// ctor, cctor, dtor, op=
PolinomBF::PolinomBF(int degree) {
    this -> degree = degree;
    for (int i = 0; i < MAX_LENGTH; i++) {
        this -> coef[i] = 0;
    }
}

PolinomBF::PolinomBF() : PolinomBF(0) {};

PolinomBF::~PolinomBF() {}

// Mengisi polinom dengan angka sembarang
void PolinomBF::FillPolinomBF() {
    srand(time(NULL));
    for (int i = 0; i < degree; i++) {
        coef[i] = rand() % RANGE;
    }
}

void PolinomBF::FillPolinomBF(int SEED) {
    srand(SEED);
    for (int i = 0; i < degree; i++) {
        coef[i] = rand() % RANGE;
    }
}

// getter, setter
int PolinomBF::getCoefAt(int idx) const {
    return coef[idx];
}
int PolinomBF::getDegree() const {
    return degree;
}
void PolinomBF::setCoefAt(int idx, int val) {
    coef[idx] = val;
}
void PolinomBF::setDegree(int idx) {
    degree = idx;
}

// Operasi penjumlahan
PolinomBF operator+(const PolinomBF & P1, const PolinomBF & P2) {
    PolinomBF Ph;
    Ph.setDegree(P1.getDegree());
    for (int i = 0; i < Ph.getDegree(); i++) {
        Ph.coef[i] = P1.coef[i] + P2.coef[i];
    }
    return Ph;
}

// Operasi perkalian
PolinomBF operator*(const PolinomBF & P1, const PolinomBF & P2) {
    PolinomBF Ph;
    long long int opTambah = 0;
    long long int opKali = 0;
    cout << "\n[] Perkalian Polinom Metode Brute Force []\n";

    // Perhitungan
    auto start = high_resolution_clock::now();
    Ph.setDegree(P1.getDegree() + P2.getDegree());
    for (int i = 0; i < P1.getDegree(); i++) {
        for (int j = 0; j < P2.getDegree(); j++) {
            Ph.coef[i+j] += P1.coef[i] * P2.coef[j];
            opTambah++;
            opKali++;
        }
    }
    auto stop = high_resolution_clock::now();
    
    // Results
    Ph.print();
    auto dur = duration_cast<microseconds>(stop-start);
    cout << endl << "[] ============--------- - - - -  -  -   -" << endl;
    cout << "|| Jumlah operasi tambah: " << opTambah << endl;
    cout << "|| Jumlah operasi kali  : " << opKali << endl;
    cout << "|| Jumlah total operasi : " << opTambah + opKali << endl;
    cout << "|| Waktu penghitungan: ";
    cout << dur.count() << " microseconds" << endl;
    cout << "[] ============--------- - - - -  -  -   -" << endl;
    return Ph;
}

// Mencetak polinom dengan format: A+Bx^1+Cx^2+Dx^3...dst
void PolinomBF::print() {
    cout << coef[0];
    for (int i = 1; i <= degree; i++) {
        if (coef[i] < 0) cout << coef[i] << "x^" << i;
        else if (coef[i] == 0) continue;
        else cout << "+" << coef[i] << "x^" << i;
    }
    cout << endl;
}
