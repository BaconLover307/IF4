/* Nama         : Gregorius Jovan Kresnadi */
/* NIM          : 13518135 */
/* Program      : PolinomBF.hpp */
/* Deskripsi    : Header Perkalian polinom metode Brute Force */
/* Keterangan   : Tugas Besar StiMa 2: Pustaka Polinom dengan metode
                  Brute Force dan Divide and Conquer */

#ifndef POLINOMBF_HPP
#define POLINOMBF_HPP

#define RANGE 50

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

    friend PolinomBF operator+(const PolinomBF&, const PolinomBF&); // Penjumlahan 2 buah Polinom.
    friend PolinomBF operator*(const PolinomBF&, const PolinomBF&); // Perkalian PolinomBF dengan konstanta (sifat komutatif)

    // Mencetak polinom dengan format: A+Bx^1+Cx^2+Dx^3...dst (diakhiri dengan end-of-line)
    // Apabila suatu koefisien bernilai < 0, gunakan tanda "-" untuk menggantikan tanda "+"
    // Apabila suatu koefisien bernilai 0, lewati koefisien tersebut dan lanjutkan ke koefisien selanjutnya
    // Jika seluruh koefisien bernilai 0, keluarkan "0"
    void print();

  private:
    const static int MAX_LENGTH = 100000;
    int coef[MAX_LENGTH];
    int degree; // derajat tertinggi
};

#endif
