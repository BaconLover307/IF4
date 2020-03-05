// Nama : Gregorius Jovan Kresnadi
// NIM  : 13518135
// Latihan UTS OOP
// main.cpp
#include "A.hpp"
#include "B.hpp"

void setValA(A* a) {
    a -> setValue(888);
}

int main() {
  B b; /** ANDA HARUS MENGGUNAKAN DEFAULT CONSTRUCTOR */
  
  // Your code goes here :)
  // ...
  setValA(&b);
  b.setValue(10888);
  // ...
  
  b.print(); // OUTPUT: (888, 10888)
  return 0;
}