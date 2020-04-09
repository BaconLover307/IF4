public class Fruit {
  private FruitType type;
  
  public Fruit(FruitType type) {
    this.type = type;
  }
  
  private void announceFruitType() {
    // Mencetak nama buah dalam bahasa Indonesia sesuai dengan type dan diakhiri new line
    // tanpa tanda kutip
    // Contoh: "Apel"
    
    // Gunakan assert untuk mengetes asumsi bahwa kode tidak akan masuk ke bagian selain
    // FruitType yang telah didefinisikan
    // ...
    assert type.equals(FruitType.ORANGE) || type.equals(FruitType.APPLE) || type.equals(FruitType.BANANA) || type.equals(FruitType.WATERMELON);
    if (type.equals(FruitType.APPLE)) System.out.println("Apel");
    else if (type.equals(FruitType.BANANA)) System.out.println("Pisang");
    else if (type.equals(FruitType.ORANGE)) System.out.println("Jeruk");
    else if (type.equals(FruitType.WATERMELON)) System.out.println("Semangka");
  }
  
  private void peel() {
    // Memastikan bahwa FruitType dari objek ini adalah ORANGE atau BANANA
    // ...
    assert type == FruitType.ORANGE || type == FruitType.BANANA;
    // Mencetak "Peeling " tanpa tanda kutip diikuti dengan type dan new line
    // Contoh: "Peeling BANANA"
    System.out.println("Peeling " + type);
    
}

private void press() {
    // Memastikan bahwa FruitType dari objek ini adalah bukan BANANA
    // ...
    assert type != FruitType.BANANA;
    // Mencetak "Pressing " tanpa tanda kutip diikuti dengan type dan new line
    // Contoh: "Pressing WATERMELON"
    System.out.println("Pressing " + type);
}

private void removeCore() {
    // Memastikan bahwa FruitType dari objek ini adalah APEL
    // ...
    assert type == FruitType.APPLE;
    // Mencetak "Removing core " tanpa tanda kutip diikuti dengan type dan new line
    // Contoh: "Removing core APPLE"
    System.out.println("Removing core " + type);
  }

  // Suatu saat, bila ada programmer yang ingin menambahkan method public,
  // Ia sadar kalau tidak semua method dapat dipanggil, tergantung fruitType.
  // Method di atas private, sehingga boleh menggunakan assertion.
  // Bila public, sebaiknya menggunakan exception dibanding assertion.
}