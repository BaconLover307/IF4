// Nama : Gregorius Jovan Kresnadi
// NIM  : 13518135
// Latihan UTS OOP

#include "WarungNasgor.hpp"
#include <bits/stdc++.h>

using namespace std;

WarungNasgor::WarungNasgor(int u, int n, int t, int k) : WarungNasi(u,n,t) {
    kecap = k;
}

bool WarungNasgor::masak(int p) {
    int n = WarungNasi::getNasi();
    int t = WarungNasi::getTelur();
    if ( n >= p && t >= p && kecap >= p) {
        WarungNasi::setUang(WarungNasi::getUang() + p * 15000);
        return true;
    } else return false;
}