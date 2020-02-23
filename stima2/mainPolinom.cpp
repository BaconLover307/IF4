/* Nama         : Gregorius Jovan Kresnadi */
/* NIM          : 13518135 */
/* Program      : mainPolinom.cpp */
/* Deskripsi    : Driver Perkalian Polinom */
/* Keterangan   : Tugas Besar StiMa 2: Pustaka Polinom dengan metode
                  Brute Force dan Divide and Conquer */

#include "PolinomBF.hpp"
#include "PolinomDNC.hpp"
#include <iostream>
#include <chrono>
#include <ratio>

#define SEED1 13518135
#define SEED2 16518017

using namespace std;
using namespace std::chrono;

int main() {
    cout << "[]  / \\ / \\ / \\ / \\ / \\  []" << endl;
    cout << " \\   Pengali 2 Polinom   / " << endl;
    cout << " \\ - - - - - - - - - - - / " << endl;
    cout << " \\        Metode:        / " << endl;
    cout << " \\    1. BruteForce      / " << endl;
    cout << " \\  2. Divide & Conquer  / " << endl;
    cout << "[]  \\ / \\ / \\ / \\ / \\ /  []" << endl;
    cout << "||" << endl;
    cout << "[]=>>  Masukan suku tertinggi polinom: ";
    int n;
    cin >> n;
    cout << endl;

    // Inisiasi
    PolinomBF PBF1(n+1);
    PolinomBF PBF2(n+1);
    PolinomBF PBFh;
    PolinomDnC PDnC1(n+1);
    PolinomDnC PDnC2(n+1);
    PolinomDnC PDnCh(n+n+1+1);

    // Perhitungan BF   

    cout << "[] Polinom 1 []\n";
    PBF1.FillPolinomBF(SEED1);
    //PBF1.print();
    cout << "\n[] Polinom 2 []\n";
    PBF2.FillPolinomBF(SEED2);
    //PBF2.print();
    PBFh = PBF1 * PBF2;

    // Perhitungan DnC
    cout << "\n[] Perkalian Polinom Metode Divide & Conquer []\n\n";
    PDnC1.FillPolinomDnC(SEED1);
    PDnC2.FillPolinomDnC(SEED2);
    int countPlus = 0;
    int countKali = 0;
    auto start = high_resolution_clock::now();
    PDnCh = Kali(PDnC1, PDnC2, countPlus, countKali);
    auto stop = high_resolution_clock::now();
    auto dur = duration_cast<microseconds>(stop-start);
    //PDnCh.print();
    cout << endl << "[] ============--------- - - - -  -  -   -" << endl;
    cout << "|| Jumlah operasi tambah: " << countPlus << endl;
    cout << "|| Jumlah operasi kali  : " << countKali << endl;
    cout << "|| Jumlah total operasi : " << countPlus + countKali << endl;
    cout << "|| Waktu penghitungan: ";
    cout << dur.count() << " microseconds" << endl;
    cout << "[] ============--------- - - - -  -  -   -" << endl;

    return 0;
}
