/* Nama         : Gregorius Jovan Kresnadi */
/* NIM          : 13518135 */
/* Program      : PolinomDNC.cpp */
/* Deskripsi    : Implementasi Perkalian polinom metode Divide and Conquer */
/* Keterangan   : Tugas Besar StiMa 2: Pustaka Polinom dengan metode
                  Brute Force dan Divide and Conquer */

#include "PolinomDNC.hpp"
#include <iostream>
#include <vector>
#include <ctime>
#include "math.h"

using namespace std;

// ctor, dtor
PolinomDnC::PolinomDnC(int degree) {
    this->degree = degree;
    P.reserve(degree+1);
}

PolinomDnC::PolinomDnC() : PolinomDnC(1) {}

PolinomDnC& PolinomDnC::operator=(const PolinomDnC& Pol) {
    degree = Pol.degree;
    for (int i=0; i<Pol.P.size(); i++) {
        P.push_back(Pol.P[i]);
    }
    return *this;
}

PolinomDnC::~PolinomDnC() {}

// Mengisi polinom dengan angka sembarang
void PolinomDnC::FillPolinomDnC() {
    srand(time(NULL));
    for (int i = 0; i < degree; i++) {
        P.push_back(rand() % RANGE);
    }
}
void PolinomDnC::FillPolinomDnC(int SEED) {
    srand(SEED);
    for (int i = 0; i < degree; i++) {
        P.push_back(rand() % RANGE);
    }
}

// Operasi penjumlahan
PolinomDnC operator+(const PolinomDnC & P1, const PolinomDnC & P2) {
    PolinomDnC Ph;
    int i;
    if (P1.P.size() > P2.P.size()) {
        for(i = 0; i<P2.P.size(); i++) {
            Ph.P.push_back(P1.P[i] + P2.P[i]);
        }
        for(i; i<P1.P.size(); i++) {
            Ph.P.push_back(P1.P[i]);
        }
    } else {
        for(i = 0; i<P1.P.size(); i++) {
            Ph.P.push_back(P1.P[i] + P2.P[i]);
        }
        for(i; i<P2.P.size(); i++) {
            Ph.P.push_back(P2.P[i]);
        }
    }
    return Ph;
}

// Operasi pengurangan
PolinomDnC operator-(const PolinomDnC & P1, const PolinomDnC & P2) {
    PolinomDnC Ph;
    int i;
    if (P1.P.size() > P2.P.size()) {
        for(i = 0; i<P2.P.size(); i++) {
            Ph.P.push_back(P1.P[i] - P2.P[i]);
        }
        for(i; i<P1.P.size(); i++) {
            Ph.P.push_back(P1.P[i]);
        }
    } else {
        for(i = 0; i<P1.P.size(); i++) {
            Ph.P.push_back(P1.P[i] - P2.P[i]);
        }
        for(i; i<P2.P.size(); i++) {
            Ph.P.push_back(P2.P[i]);
        }
    }
    return Ph;
}

// Menaikkan derajat polinom sebanyak n
void PolinomDnC::Mundur(int n) {
    for (int i=0; i < n; i++) {
        P.insert(P.begin(), 0);
    }
}

// Mencetak polinom dengan format: A+Bx^1+Cx^2+Dx^3...dst
void PolinomDnC::print() {
    cout << P[0];
    for (int j= 1; j< P.size(); j++) {
        if (P[j] < 0) cout << P[j] << "x^" << j;
        else if (P[j] == 0) continue;
        else cout << "+" << P[j] << "x^" << j;
    }
    cout << endl;
}

// Fungsi perkalian 2 polinom
PolinomDnC Kali(const PolinomDnC& P1, const PolinomDnC& P2, long long int &countPlus, long long int &countKali) {
    if (P1.P.size() == 1) {
        PolinomDnC Ph(2);
        Ph.P.push_back(P1.P[0] * P2.P[0]);
        countKali+=1;
        return Ph;
    } else {
        int half1 = floor(P1.P.size()/2);
        int half2 = P1.P.size() - half1;
        PolinomDnC Ph(P1.P.size()*2);
        PolinomDnC P1A(half1), P1B(half2), P2A(half1), P2B(half2);
        PolinomDnC PX(half2*2), PY(half1), PZ(half2*2);
        PolinomDnC PXYZ(half2*2);
        int i;
        for (i=0; i<half1; i++) {
            P1A.P.push_back(P1.P[i]);
            P2A.P.push_back(P2.P[i]);
        }
        for (i; i<P1.P.size(); i++) {
            P1B.P.push_back(P1.P[i]);
            P2B.P.push_back(P2.P[i]);
        }
        PX = Kali(P1A+P1B, P2A+P2B, countPlus, countKali);
        PY = Kali(P1A,P2A,countPlus,countKali);
        PZ = Kali(P1B,P2B,countPlus,countKali);
        PXYZ = PX - PY - PZ;
        PXYZ.Mundur(floor(P1.P.size()/2));
        PZ.Mundur(2*floor(P1.P.size()/2));
        Ph = PY + PXYZ + PZ;
        countPlus += 4;
        return Ph;
    }
}
