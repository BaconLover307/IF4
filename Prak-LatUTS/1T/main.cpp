// Nama : Gregorius Jovan Kresnadi
// NIM  : 13518135
// Latihan UTS OOP

#include "A.hpp"
#include <iostream>

using namespace std;

int main() {
    A a('1');
    A *b = new A('2');
    A c(a);
    c = *b;
    c.show();
    delete b;
}