/* Nama         : Gregorius Jovan Kresnadi */
/* NIM          : 13518135 */
/* Tanggal      : 13-02-2020 */
#include "C.hpp"
#include <iostream>

using namespace std;

C::C() : A(), B() {
}

void C::sing() {
    B::sing();
    A::sing();
}