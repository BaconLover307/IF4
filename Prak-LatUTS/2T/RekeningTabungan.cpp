// Nama : Gregorius Jovan Kresnadi
// NIM  : 13518135
// Latihan UTS OOP

#include "RekeningTabungan.h"
#include <bits/stdc++.h>

RekeningTabungan::RekeningTabungan(double s, double bt) : Rekening(s) {
    biayaTransaksi = bt;
}

void RekeningTabungan::setBiayaTransaksi(double bt) {
    biayaTransaksi = bt;
}

double RekeningTabungan::getBiayaTransaksi() const {
    return biayaTransaksi;
}

void RekeningTabungan::simpanUang(double s) {
    Rekening::simpanUang(s);
    Rekening::setSaldo(Rekening::getSaldo()-biayaTransaksi);
}

bool RekeningTabungan::tarikUang(double s) {
    if (Rekening::tarikUang(s)) {
        Rekening::setSaldo(Rekening::getSaldo() - biayaTransaksi);
        return true;
    } else return false;
}