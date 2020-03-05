// Nama : Gregorius Jovan Kresnadi
// NIM  : 13518135
// Latihan UTS OOP

#ifndef __SUBSTRACTEXPRESSION_H_
#define __SUBSTRACTEXPRESSION_H_

#include "Expression.hpp"

class SubstractExpression : public BinaryExpression {
public:
    SubstractExpression(Expression*, Expression*);
    int solve();
};

#endif