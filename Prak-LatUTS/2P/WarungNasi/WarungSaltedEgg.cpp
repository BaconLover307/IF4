// Nama : Gregorius Jovan Kresnadi
// NIM  : 13518135
// Latihan UTS OOP

#include "WarungSaltedEgg.hpp"
#include <bits/stdc++.h>

using namespace std;

WarungSaltedEgg::WarungSaltedEgg(int u, int n, int t, int ta, int a) : WarungNasi(u,n,t) {
    telurAsin = ta;
    ayam = a;
}

bool WarungSaltedEgg::masak(int p) {
    int n = WarungNasi::getNasi();
    int t = WarungNasi::getTelur();
    if ( n>=p && t>=p && telurAsin>=3*p && ayam>=p) {
        WarungNasi::setUang(WarungNasi::getUang() + p * 30000);
        return true;
    } else return false;
}