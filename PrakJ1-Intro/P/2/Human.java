// Nama         : Gregorius Jovan Kresnadi
// NIM          : 13518135
// Tanggal      : 19-03-2020
// File 		: Human.java

// Diberikan kelas Animal, buatlah kelas turunan Cow dan Human.
// Kelas Human memiliki constructor yang tidak menerima argumen. Jumlah kakinya (legs) adalah 2.
//      Ia akan menjadi kenyang bila makan apapun, kecuali "teman", 
//      Bila ia berlari, ia tidak akan memanggil Animal.run, namun menuliskan "Human is running" ke layar, diikuti newline.
// Penting: gunakan method .equals() pada String untuk memeriksa apakah dua buah string sama atau tidak. Contoh:
// Kumpulkan file Cow.java dan Human.java dalam Animal.zip.

class Human extends Animal {
    public Human() {
        super(2);
    }

    public void eat(String food) {
        if (!food.equals("teman")) {
            this.hungry = false;
        }
    }

    public void run() {
        System.out.println("Human is running");
    }
}