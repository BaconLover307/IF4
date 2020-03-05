// Nama : Gregorius Jovan Kresnadi
// NIM  : 13518135
// Latihan UTS OOP

#ifndef __ADDEXPRESSION_H_
#define __ADDEXPRESSION_H_

#include "Expression.hpp"

class AddExpression : public BinaryExpression {
public:
    AddExpression(Expression*, Expression*);
    int solve();
};

#endif