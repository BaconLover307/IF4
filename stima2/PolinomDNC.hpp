/* Nama         : Gregorius Jovan Kresnadi */
/* NIM          : 13518135 */
/* Program      : PolinomDNC.hpp */
/* Deskripsi    : Header Perkalian polinom metode Decrease and Conquer */
/* Keterangan   : Tugas Besar StiMa 2: Pustaka Polinom dengan metode
                  Brute Force dan Decrease and Conquer */
#ifndef POLINOMBF_HPP
#define POLINOMBF_HPP

class Polinom {
public:
  // ctor, cctor, dtor, op=
  // untuk konstruktor, inisialisasi seluruh nilai koefisien dengan 0.
  Polinom();    // ctor Polinom dengan orde = 0
  Polinom(int); // ctor Polinom dengan orde = n (sesuai parameter)
  Polinom(const Polinom&);
  ~Polinom();
  Polinom& operator=(const Polinom&);

  // getter, setter
  int getKoefAt(int idx) const;
  int getDerajat() const;
  void setKoefAt(int idx, int val);
  void setDerajat(int);

  friend Polinom operator*(const Polinom&, const Polinom&); // Perkalian Polinom dengan konstanta (sifat komutatif)

  // member function
  // Melakukan pembacaan koefisien sejumlah derajat Polinom, dimulai dari x^0 (konstanta)
  void input();

  // Mencetak seluruh koefisien polinom. Untuk setiap koefisien akhiri dengan end-of-line
  // Cetaklah apa adanya dari koefisien ke-0 hingga derajat tertinggi (termasuk apabila koefisien = 0)
  void printKoef();

  // Mencetak polinom dengan format: A+Bx^1+Cx^2+Dx^3...dst (diakhiri dengan end-of-line)
  // Apabila suatu koefisien bernilai < 0, gunakan tanda "-" untuk menggantikan tanda "+"
  // Apabila suatu koefisien bernilai 0, lewati koefisien tersebut dan lanjutkan ke koefisien selanjutnya
  // Jika seluruh koefisien bernilai 0, keluarkan "0"
  void print();

private:
  const static int MAX_LENGTH = 10000;
  int koef[MAX_LENGTH];
  int degree; // derajat tertinggi
};

#endif
