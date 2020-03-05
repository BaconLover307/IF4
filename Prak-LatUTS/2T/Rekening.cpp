// Nama : Gregorius Jovan Kresnadi
// NIM  : 13518135
// Latihan UTS OOP

#include "Rekening.h"
#include <bits/stdc++.h>

Rekening::Rekening(double s) {
    saldo = s<0 ? 0.0 : s;
}

void Rekening::setSaldo(double s) {
    saldo = s;
}

double Rekening::getSaldo() const {
    return saldo;
}

void Rekening::simpanUang(double s) {
    saldo += s;
}

bool Rekening::tarikUang(double s) {
    if (s<=saldo) {
        saldo -= s;
        return true;
    } else return false;
}
