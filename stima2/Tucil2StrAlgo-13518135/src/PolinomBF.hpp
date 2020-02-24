/* Nama         : Gregorius Jovan Kresnadi */
/* NIM          : 13518135 */
/* Program      : PolinomBF.hpp */
/* Deskripsi    : Header Perkalian polinom metode Brute Force */
/* Keterangan   : Tugas Besar StiMa 2: Pustaka Polinom dengan metode
                  Brute Force dan Divide and Conquer */

#ifndef POLINOMBF_HPP
#define POLINOMBF_HPP

#define RANGE 100

class PolinomBF {
  public:
    // ctor, dtor
    PolinomBF();    // ctor PolinomBF dengan orde = 0
    PolinomBF(int); // ctor PolinomBF dengan orde = n (sesuai parameter)
    ~PolinomBF();

    // Mengisi polinom dengan angka sembarang
    void FillPolinomBF();
    void FillPolinomBF(int SEED);

    // getter, setter
    int getCoefAt(int idx) const;
    int getDegree() const;
    void setCoefAt(int idx, int val);
    void setDegree(int);

    // Operator overloading
    friend PolinomBF operator+(const PolinomBF&, const PolinomBF&);
    friend PolinomBF operator*(const PolinomBF&, const PolinomBF&);

    // Mencetak polinom dengan format: A+Bx^1+Cx^2+Dx^3...dst
    void print();

  private:
    const static int MAX_LENGTH = 100000;
    int coef[MAX_LENGTH];
    int degree; // derajat tertinggi
};

#endif
