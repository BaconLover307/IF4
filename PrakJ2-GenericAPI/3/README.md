Java menyediakan 2 implementasi List, yakni ArrayList dan LinkedList. Kedua kelas ini memiliki implementasi yang berbeda. Kini kita ingin bereksperimen untuk menjawab pertanyaan "kapan kita menggunakan ArrayList, kapan kita menggunakan LinkedList?"

Buatlah sebuah kelas Test:

* Memiliki private attribute list dengan tipe List<Integer>
* Memiliki private attribute n dengan tipe int
* Memiliki public method void reset(), yang memanggil clear() dari list dan mengisi list dengan n buah bilangan 0.
* Memiliki public method long get(int idx) yang jika dipanggil:
  * Mereset list dengan memanggil method reset
  * Mencatat waktu sekarang (start) dalam milisekon
  * Mengambil indeks ke idx dari list
  * Mencatat waktu sekarang (finish) dalam milisekon
  * Mengembalikan waktu finish - start
* Memiliki public method long del(int idx, int t) yang jika dipanggil:
  * Mereset list dengan memanggil method reset
  * Mencatat waktu sekarang (start) dalam milisekon
  * Menghapus elemen ke-idx dari list sebanyak t kali
  * Mencatat waktu sekarang (finish) dalam miliseko>
  * Mengembalikan waktu finish - start

Lihat contoh Main.java. Untuk mengukur waktu, Anda wajib menggunakan Util.java

Kumpulkan Test.java