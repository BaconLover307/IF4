// Nama         : Gregorius Jovan Kresnadi
// NIM          : 13518135
// Tanggal      : 19-03-2020
// File 		: Mahasiswa.java

import java.lang.Comparable;

class Mahasiswa implements Comparable<Mahasiswa> {
  private float ipk;
  private int kodeJurusan;
  private int angkatan;

  public Mahasiswa(int kodeJurusan, int angkatan, float ipk) {
    this.ipk = ipk;
    this.kodeJurusan = kodeJurusan;
    this.angkatan = angkatan;
  }

  public int getKodeJurusan() {
      return this.kodeJurusan;
  }

  public int getAngkatan() {
      return this.angkatan;
  }

  public float getIpk() {
      return this.ipk;
  }

  public int compareTo(Mahasiswa m) {
    // compareTo mengembalikan:
    // 0 bila this sama dengan m
    // 1 bila this lebih dari m
    // -1 bila this kurang dari m
    if (this.kodeJurusan < m.kodeJurusan) {
        return -1;
    } else if (this.kodeJurusan == m.kodeJurusan) {
        if (this.angkatan > m.angkatan) {
            return -1;
        } else if (this.angkatan == m.angkatan) {
            if (this.ipk > m.ipk) {
                return -1;
            } else if (this.ipk == m.ipk) {
                return 0;
            } else return 1;
        } else return 1;
    } return 1;
  }
}