// Nama : Gregorius Jovan Kresnadi
// NIM  : 13518135
// Latihan UTS OOP

#include "SubstractExpression.hpp"
#include <bits/stdc++.h>

SubstractExpression::SubstractExpression(Expression* x, Expression* y) : BinaryExpression(x,y) {

}

int SubstractExpression::solve() {
    return x->solve() - y->solve();
}