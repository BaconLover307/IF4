// Nama : Gregorius Jovan Kresnadi
// NIM  : 13518135
// Latihan UTS OOP

#include "NegativeExpression.hpp"
#include <bits/stdc++.h>

NegativeExpression::NegativeExpression(Expression* x) : UnaryExpression(x) {

}

int NegativeExpression::solve() {
    return x->solve() * -1;
}