// Nama : Gregorius Jovan Kresnadi
// NIM  : 13518135
// Latihan UTS OOP

#include "C.hpp"
#include <bits/stdc++.h>

using namespace std;

C::C() : B(), A() {
}

void C::sing() {
    B::sing();
    A::sing();
}