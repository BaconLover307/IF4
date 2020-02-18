//#include "Polinom.hpp"
//#include "PolinomBF.hpp"
//#include "PolinomDNC.hpp"

#include <iostream>
#include <fstream>

using namespace std;

int main() {
    cout << "[]  / \\ / \\ / \\ / \\ / \\  []" << endl;
    cout << " \\   Pengali 2 Polinom   / " << endl;
    cout << " \\ - - - - - - - - - - - / " << endl;
    cout << " \\     Pilih metode:     / " << endl;
    cout << " \\    1. BruteForce      / " << endl;
    cout << " \\  2. DecreasenConquer  / " << endl;
    cout << "[]  \\ / \\ / \\ / \\ / \\ /  []" << endl << endl;

    int menu;
    //PolinomBF PBF1, PBF2;
    //PolinomBF PDnC1, PDnC2;
    string filename, line;

    cin >> menu;
    cout << endl;
    switch (menu) {
        case 3:
        // Baca file polinom untuk BF
        {
            //cout << "Enter filename: ";
            //cin  >> filename;
            ifstream MyReadFile("test.txt");
            while (getline (MyReadFile, line)) {
                if (line !=  ".") cout << line << endl;
                else break;
            }
            while (getline (MyReadFile, line)) {
                if (line !=  ".") cout << line << endl;
                else break;
            }
        }
        case 1:
        // Operasi kali polinom dengan BF
        {
            cout << "MEH1" << endl;
        }
        break;

        case 4:
        // Baca file polinom untuk DecreasenConquer
        {
            //cout << "Enter filename: ";
            //cin  >> filename;
            ifstream MyReadFile("test.txt");
            while (getline (MyReadFile, line)) {
                if (line !=  ".") cout << line << endl;
                else break;
            }
            while (getline (MyReadFile, line)) {
                if (line !=  ".") cout << line << endl;
                else break;
            }
        }
        case 2:
        // Operasi kali polinom dengan DecreasenConquer
        {
            cout << "MEH2" << endl;

        }
        break;

        default:
            cout << "Bacot" << endl;
        break;
    }
    /*
    Polinom A(2);
    Polinom B(3);
    cout << "Masukkan " << A.getDerajat() << " nilai untuk Polinom A " << endl;
    A.input();
    cout << "Masukkan " << B.getDerajat() << " nilai untuk Polinom B " << endl;
    B.input();
    cout << "Print doang" << endl;
    A.print();
    B.print();
    Polinom C;
    C = A + B;
    cout << "A + B" << endl;
    C.print();
    C = A - B;
    cout << "A - B" << endl;
    C.print();
    C = A * 3;
    cout << "A * 3" << endl;
    C.print();
    C = A.derive();
    cout << "Turunan A" << endl;
    C.print();
    cout << "Masukin x = 2 ke A" << endl;
    cout << A.substitute(2) << endl;
    return 0;
    */
}
