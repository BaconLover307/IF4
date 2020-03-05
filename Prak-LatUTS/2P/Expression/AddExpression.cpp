// Nama : Gregorius Jovan Kresnadi
// NIM  : 13518135
// Latihan UTS OOP

#include "AddExpression.hpp"
#include <bits/stdc++.h>

AddExpression::AddExpression(Expression* x, Expression* y) : BinaryExpression(x,y) {

}

int AddExpression::solve() {
    return x->solve() + y->solve();
}