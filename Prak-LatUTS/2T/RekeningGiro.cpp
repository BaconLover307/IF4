// Nama : Gregorius Jovan Kresnadi
// NIM  : 13518135
// Latihan UTS OOP

#include "RekeningGiro.h"
#include <bits/stdc++.h>

RekeningGiro::RekeningGiro(double s, double sb) : Rekening(s) {
    sukuBunga = sb;
}

void RekeningGiro::setSukuBunga(double sb) {
    sukuBunga = sb;
}

double RekeningGiro::getSukuBunga() const {
    return sukuBunga;
}

double RekeningGiro::hitungBunga() {
    return Rekening::getSaldo() * sukuBunga;
}
