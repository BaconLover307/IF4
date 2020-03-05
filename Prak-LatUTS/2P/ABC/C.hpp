// Nama : Gregorius Jovan Kresnadi
// NIM  : 13518135
// Latihan UTS OOP
#ifndef __C_HPP_
#define __C_HPP_

#include "A.hpp"
#include "B.hpp"

class C : public B, A {
public:
    C();
    void sing();
};

#endif