/* Nama         : Gregorius Jovan Kresnadi */
/* NIM          : 13518135 */
/* Program      : PolinomDNC.hpp */
/* Deskripsi    : Header Perkalian polinom metode Divide and Conquer */
/* Keterangan   : Tugas Besar StiMa 2: Pustaka Polinom dengan metode
                  Brute Force dan Divide and Conquer */

#ifndef POLINOMDNC_HPP
#define POLINOMDNC_HPP

#define RANGE 100
#include <vector>

class PolinomDnC {
public:
  // Vars
  std::vector<int> P;
  int degree; // derajat tertinggi
  
  // ctor, cctor, dtor
  PolinomDnC();    // ctor Polinom dengan orde = 0
  PolinomDnC(int); // ctor Polinom dengan orde = n (sesuai parameter)
  PolinomDnC& operator=(const PolinomDnC&);
  ~PolinomDnC();

  // Mengisi polinom dengan angka sembarang
  void FillPolinomDnC();
  void FillPolinomDnC(int);

  // Operator overloading
  friend PolinomDnC operator+(const PolinomDnC&, const PolinomDnC&);
  friend PolinomDnC operator-(const PolinomDnC&, const PolinomDnC&);
  
  // Menaikkan derajat polinom sebanyak n
  void Mundur(int n);

  // Mencetak polinom dengan format: A+Bx^1+Cx^2+Dx^3...dst
  void print();

};

// Fungsi perkalian 2 polinom
PolinomDnC Kali(const PolinomDnC& P1, const PolinomDnC& P2, long long int &countPlus, long long int &countKali );

#endif
