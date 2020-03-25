# Tucil3-Stima -- Penyelesaian Persoalan 15-Puzzle dengan Algoritma Branch and Bound
Program ini adalah contoh pengaplikasian strategi algoritma Branch and Bound untuk menyelesaikan sebuah 15-puzzle

## Author
Program ini dibuat untuk memenuhi salah satu Tugas Kecil IF2211 Strategi Algoritma Teknik Informatika ITB. Adapun pembuat dari program ini adalah:
- Gregorius Jovan Kresnadi - 13518135

## Instalasi Program - Windows / Linux
Program ini dibuat menggunakan bahasa pemrograman Python oleh karena itu dibutuhkan sebuah Python3 interpreter. Python dapat diunduh melalui https://www.python.org/downloads/

## Instalasi Program - Linux
Program ini dibuat menggunakan bahasa pemrograman python oleh karena itu dibutuhkan sebuah Python3 interpreter. Python dapat diunduh dengan cara membuka terminal komputer, dan mengetik perintah berikut:
```bash
$ sudo apt-get install python3.7
```
## Meletakkan File untuk Dibaca
Sebelum menjalankan program, pastikan Anda sudah meletakan file .txt pada folder test. Ketika mendownload file, sudah terdapat 6 buah file yang tersedia untuk dibaca program. Namun jika Anda ingin program membaca file lain, maka file .txt yang diletakkan pada folder .txt harus memiliki format penulisan seperti contoh berikut:
```
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16 
```
Setiap angka wajib dipisahkan dengan sebuah spasi, dan angka yang ditulis adalah angka 1 sampai 16, dengan angka 16 akan dibaca program sebagai kotak kosong. Angka yang diketik tidak perlu berurutan.

Keterangan 6 file yang sudah terdapat pada folder test:
* puzzle.txt - File Default, Sukses
* tc1.txt - Sukses
* tc2.txt - Sukses
* tc3.txt - Sukses
* tc4.txt - Gagal
* tc5.txt - Gagal

### Cara Menjalankan Program
Untuk menjalankan program, silakan buka terminal pada directory di mana program disimpan dan ketikkan perintah di bawah ini untuk menjalankan programnya:
```bash
C:\Users\<user>\Documents\Tucil3StrAlgo-13518135>
# cd src
C:\Users\<user>\Documents\Tucil3StrAlgo-13518135\bin>
# py main.py
```

```
[]=======================[]
||    15 Puzzle Solver   ||
|| - - - - - - - - - - - ||
||         File :        ||
||    1. Use Default     ||
||      (puzzle.txt)     ||
||    2. Input file      ||
[]=======================[]
||
[]=>> 
```
Jika program berhasil dijalankan, maka akan muncul menu utama program seperti di atas.

## Cara Menggunakan Program
Ketika program dijalankan, maka Anda memiliki 2 pilihan, yaitu pilihan 1 yang akan membaca file default (puzzle.txt), dan pilihan 2 yang akan meminta masukan nama file. Pastikan nama file yang diketik sudah terdapat pada folder test. Lalu program akan menyelesaikan 15-puzzle dari file .txt, dan menampilkan jumlah simpul yang dibangun, langkah yang digunakan dalam penyelesaian puzzle, waktu eksekusi dari algoritma yang digunakan.

Kemudian Anda diberikan pilihan untuk menampilkan visualisasi langkah dari penyelesaian puzzle. Ketik 'y' untuk menampilkan semua matriks dari simpul yang dilalui sampai ke simpul tujuan.



