/* Nama         : Gregorius Jovan Kresnadi */
/* NIM          : 13518135 */
/* Program      : PolinomDNC.hpp */
/* Deskripsi    : Header Perkalian polinom metode Divide and Conquer */
/* Keterangan   : Tugas Besar StiMa 2: Pustaka Polinom dengan metode
                  Brute Force dan Divide and Conquer */

#ifndef POLINOMDNC_HPP
#define POLINOMDNC_HPP

#define RANGE 50
#include <vector>

class PolinomDnC {
public:
  // Vars
  std::vector<int> P;
  int degree; //derajat tertinggi
  
  // ctor, cctor, dtor
  PolinomDnC();    // ctor Polinom dengan orde = 0
  PolinomDnC(int); // ctor Polinom dengan orde = n (sesuai parameter)
  PolinomDnC& operator=(const PolinomDnC&);
  ~PolinomDnC();

  // Mengisi polinom dengan angka sembarang
  void FillPolinomDnC();
  void FillPolinomDnC(int);

  void Mundur(int n);

  friend PolinomDnC operator+(const PolinomDnC&, const PolinomDnC&); // Perkalian Polinom dengan konstanta (sifat komutatif)
  friend PolinomDnC operator-(const PolinomDnC&, const PolinomDnC&); // Perkalian Polinom dengan konstanta (sifat komutatif)

  // Mencetak polinom dengan format: A+Bx^1+Cx^2+Dx^3...dst (diakhiri dengan end-of-line)
  // Apabila suatu koefisien bernilai < 0, gunakan tanda "-" untuk menggantikan tanda "+"
  // Apabila suatu koefisien bernilai 0, lewati koefisien tersebut dan lanjutkan ke koefisien selanjutnya
  // Jika seluruh koefisien bernilai 0, keluarkan "0"
  void print();

private:
};

PolinomDnC Kali(const PolinomDnC& P1, const PolinomDnC& P2, int &countPlus, int &countKali );

#endif
