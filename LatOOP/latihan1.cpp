#include <iostream>

using namespace std;

class Kendaraan {
    private:
        int nomor;
        int tahun;
        string merk;
        string kategori;

    public:
        Kendaraan(int no, int thn, string mrk, string ktg) {
            this->nomor = no;
            this->tahun = thn;
            this->merk = mrk;
            this->kategori = ktg;
        }
        Kendaraan() : Kendaraan(0,0,"XXX","mobil") {}

        Kendaraan(const Kendaraan& other) {
            this->nomor = other.nomor;
            this->tahun = other.tahun;
            this->merk = other.merk;
            this->kategori = other.kategori;
        }
        ~Kendaraan() {

        }

        void PrintInfo() {
            cout << "Kategori : " << this->kategori << endl
                 << "No       : " << this->nomor << endl
                 << "Merk     : " << this->merk << endl
                 << "Tahun     : " << this->tahun << endl;
        }

        int BiayaSewa(int h) {
            if (this->kategori == "bus") {
                return h * 1000000;
            } else if (this->kategori == "minibus") {
                return (h <= 5) ? (5000000) : (5000000 + (h-5)*500000);
            } else if (this->kategori == "mobil") {
                return h * 500000;
            }
        }

        Kendaraan& operator=(const Kendaraan& other) {
            this->nomor = other.nomor;
            this->tahun = other.tahun;
            this->merk = other.merk;
            this->kategori = other.kategori;
            return *this;
        }

}