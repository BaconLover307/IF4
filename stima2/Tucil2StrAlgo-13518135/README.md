# Tucil2-Stima -- Perkalian Dua Polinom dengan Algoritma Brute Force dan Divide and Conquer
Program ini adalah contoh pengaplikasian strategi algoritma Brute Force dan Divide and Conquer untuk menyelesaikan melakukan perkalian dua buah polinom berderajat sama

## Instalasi Program
Program ini dibuat menggunakan bahasa pemrograman C++ oleh karena itu dibutuhkan compiler G++ yang dapat diperoleh dari MinGW. Compiler dapat diunduh melalui https://sourceforge.net/projects/mingw-w64/

### Cara Kompilasi Kode Program
Untuk mengompilasi program, buka terminal komputer Anda dan pergi ke directory di mana program disimpan. Kemudian silakan ketikkan perintah seperti di bawah ini:

```
C:\Users\<user>\Documents\Tucil2StrAlgo-13518135>
# cd src
C:\Users\<user>\Documents\Tucil2StrAlgo-13518135\src>
# g++ -o main mainPolinom.cpp PolinomBF.cpp PolinomDNC.cpp
```
Setelah perintah di atas diketikkan dan tidak muncul pesan error, maka program berhasil di kompilasi

### Cara Menjalankan Program #1
Setelah program berhasil dikompilasi, maka program dapat dijalankan. Untuk menjalankan programnya, pada terminal dan dari directory src silakan jalankan programnya. Berikut adalah instruksi untuk menjalankan programnya :
```
C:\Users\<user>\Documents\Tucil2StrAlgo-13518135\src>
# main
```
### Cara Menjalankan Program #2
Untuk menjalankan program yang telah tersedia sebelumnya, silakan buka terminal di directory di mana program disimpan dan ketikkan perintah di bawah ini untuk menjalankan programnya
```
C:\Users\<user>\Documents\Tucil2StrAlgo-13518135>
# cd bin
C:\Users\<user>\Documents\Tucil2StrAlgo-13518135\bin>
# main
```

```
[]  / \ / \ / \ / \ / \  []
\   Pengali 2 Polinom   /
\ - - - - - - - - - - - /
\        Metode:        /
\    1. BruteForce      /
\  2. Divide & Conquer  /
[]  \ / \ / \ / \ / \ /  []
||                         
[]=>>  Masukan suku tertinggi polinom:  
```
Jika program berhasil dijalankan, maka akan muncul menu utama program seperti di atas.

## Cara Menggunakan Program
Ketika program dijalankan, maka Anda hanya perlu mengetikkan derajat tertinggi polinom yang akan dibuat. Lalu program akan 2 buah polinom dengan koefisien acak, mengkalkulasikan hasil perkaliannya, dan menampilkan hasil perkalian, jumlah operasi penjumlahan, perkalian, dan waktu eksekusi dari kedua strategi algoritma yang digunakan.

## Cara Mengubah Seed Randomizer
Koefisien dari polinom yang dibuat adalah acak, namun dalam bahasa komputer, tidak ada yang benar-benar acak, namun fungsi rand() akan mengikuti sebuah pola yang diatur oleh sebuah seed. Seed ini dapat diatur sedemikian rupa untuk menghasilkan suatu pola. Untuk mengubah seed yang digunakan, dapat dibuka file mainPolinom.cpp dan mengubah nilai yang tertera seperti di bawah ini:
```
#define SEEDX 13518135
#define SEEDY 16518017

// ! UBAH SEED DISINI
#define SEED1 
#define SEED2 SEEDX+time(0)

```
Seed yang akan digunakan oleh fungsi rand() adalah SEED1 dan SEED2. Untuk mengubahnya, silakan mengubah nilai yang tertera di sebelahnya.

## Kontributor
Program ini dibuat untuk memenuhi salah satu Tugas Kecil IF2211 Strategi Algoritma Teknik Informatika ITB. Adapun pembuat dari program ini adalah:
- Gregorius Jovan Kresnadi - 13518135

