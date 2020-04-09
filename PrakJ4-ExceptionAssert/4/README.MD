Dalam programming, assertion juga digunakan untuk membuat tes. Sebagai contoh perhatikan kelas Account berikut:

```java
// File Account.java
public class Account {
  private int balance;
  private int numOfTransaction;

  public Account(int balance) {
    this.balance = balance;
    this.numOfTransaction = 0;
  }

  public int getBalance() {
    return this.balance;
  }

  public void transfer(Account other, int amount) throws InvalidAmountException {
    // Melakukan transfer dari akun rekening ini ke akun rekening other
    // serta menambahkan numOfTransaction.
    // Jika saldo (balance) rekening ini kurang dari amount, lemparkan InvalidAmountException
    // Asumsi amount selalu > 0
  }

  public int getNumOfTransaction() {
    return this.numOfTransaction;
  }
}


// File InvalidAmountException.java
public class InvalidAmountException extends Exception {
  //
}
```

Buatlah sebuah class AccountTest.java yang melakukan tes terhadap method transfer milik Account. Penting: untuk kebutuhan grading, gunakan AccountFactory, bukan constructor. AccountFactory sudah disediakan dalam grader. Contoh penggunaan:

```java
// File AccountTest.java
public class AccountTest {
  public AccountTest() {
     // Tidak melakukan apa-apa
  }

  public void test() {
     // Melakukan tes terhadap method transfer.
     // Asumsikan method lainnya benar.
     Account a = AccountFactory.withBalance(20);
  }
}
```

Kumpulkan AccountTest.java

Bagaimana soal ini akan dinilai:
*  Asisten memiliki 8 implementasi Account. Ada yang diimplementasikan dengan benar, ada yang memiliki bug di dalamnya.
*  Untuk tiap implementasi benar dan test Anda tidak gagal (semua assert true), Anda mendapat poin
*  Untuk tiap implementasi salah dan test Anda gagal (ada assert false), Anda mendapat poin