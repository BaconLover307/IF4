// Nama : Gregorius Jovan Kresnadi
// NIM  : 13518135
// Latihan UTS OOP

#ifndef __NEGATIVEEXPRESSION_H_
#define __NEGATIVEEXPRESSION_H_

#include "Expression.hpp"

class NegativeExpression : public UnaryExpression {
public:
    NegativeExpression(Expression*);
    int solve();
};

#endif