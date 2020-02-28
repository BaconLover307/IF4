// Nama : Gregorius Jovan Kresnadi
// NIM  : 13518135
// Latihan UTS OOP

#include "BunchOfKeys.hpp"

using namespace std;

BunchOfKeys::BunchOfKeys() {
    n_keys = 0;
}

void BunchOfKeys::add() {
    n_keys += 1;
}

void BunchOfKeys::shake() {
    if (n_keys > 1) {
        for (int i=0; i<n_keys;i++) {
            cout << "krincing\n";
        }
    } else {
        cout << "Tidak terjadi apa-apa\n";
    }
}
