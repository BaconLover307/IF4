Pada soal ini, Anda diminta mencoba kembali soal Map pada praktikum sebelumnya. Namun kali ini, gunakan Java API Map. Berikut deskripsi soal (ada perubahan di paragraf terakhir):

Hojun dan Qila sedang bermain. Hojun memiliki N buah kata, dan Qila memiliki M buah kata. Baik kata-kata Hojun maupun Qila, mungkin ada kata yang terulang.

Mula-mula, Hojun akan menuliskan N kata tersebut di atas kertas. Lalu, Qila akan membacakan kata-katanya satu demi satu. Untuk tiap kata, Hojun akan mencoret kata tersebut bila ada di kertas. Jika tidak ada (atau ada, tapi sudah dicoret semua), maka Hojun akan diam saja.

Kini tugas Anda adalah membuat kelas Game yang memiliki static method static void run(String[] hojun, String[] qila). hojun adalah daftar kata Hojun dengan panjang N dan qila adalah daftar kata Qila dengan panjang M. Program akan menuliskan daftar kata yang tidak dicoret di atas kertas, dipisahkan oleh baris baru. Urutan dari kata yang dituliskan sembarang.
 Contoh Input |	Contoh Output
--------------|---------------
// qila |
Budi |
Budi |
adalah | Budi
Budi | Budi
// hojun | adalah
Budi |
Bermain |
Bola |
Adalah |
 | 
// qila |
Saya |
Suka |
Pemograman | Saya
Java | Suka
// hojun | Pemrograman
Tuan | Java
Putri |
Tidur |
 | 
// qila | 
Saya | 
Mengantuk | 
// hojun | 
Saya | 
Ingin | 
Tidur |
Karena |
Mengantuk | 

Kumpulkan Game.java

Catatan: Di soal ini, kamu juga bisa membandingkan: apa bedanya menggunakan HashMap dan SortedMap?