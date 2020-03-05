// Nama : Gregorius Jovan Kresnadi
// NIM  : 13518135
// Latihan UTS OOP

#ifndef _TRIPLET_HPP_
#define _TRIPLET_HPP_

#include <iostream>

template <class A, class B, class C>
class Triplet {
private:
    A first;
    B second;
    C third;
public:
    Triplet() {}
    Triplet(A a, B b, C c) {
        this->first = a;
        this->second = b;
        this->third = c;
    }

    Triplet(const Triplet& tr) {
        this->first = tr.first;
        this->second = tr.second;
        this->third = tr.third;
    }

    A getFirst() {
        return this->first;
    }
    B getSecond() {
        return this->second;
    }
    C getThird() {
        return this->third;
    }

    void setFirst(A first) {
        this->first = first;
    }
    void setSecond(B second) {
        this->second = second;
    }
    void setThird(C third) {
        this->third = third;
    }

    bool operator==(const Triplet<A,B,C>& t) {
        return (this->first == t.first) && (this->second == t.second) && (this->third == t.third);
    }

    bool operator!=(const Triplet<A,B,C>& t) {
        return (this->first != t.first) || (this->second != t.second) || (this->third != t.third);
    }
};

#endif

