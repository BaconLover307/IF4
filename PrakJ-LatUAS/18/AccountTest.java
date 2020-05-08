// Nama     : Gregorius Jovan Kresnadi
// NIM      : 13518135
// Tanggal  : 08-05-2020
// Topik 	: Assertion

public class AccountTest {
    public AccountTest() {
       // Tidak melakukan apa-apa
    }
  
    public void test() {
       // Melakukan tes terhadap method transfer.
       // Asumsikan method lainnya benar.
       Account a = AccountFactory.withBalance(20);
       Account b = AccountFactory.withBalance(30);
        try {
            a.transfer(b, 20);
            assert (a.getBalance() == 0);
            assert (b.getBalance() == 50);
            assert (a.getNumOfTransaction() == 1);
            assert (b.getNumOfTransaction() == 1);
        } catch (InvalidAmountException e) {
            assert false;
        }

       Account c = AccountFactory.withBalance(20);
       Account d = AccountFactory.withBalance(30);
       try {
           c.transfer(d, 100);
           assert false;
       } catch (InvalidAmountException e) {
            assert (c.getBalance() == 20);
            assert (d.getBalance() == 30);
            assert (c.getNumOfTransaction() == 0);
            assert (d.getNumOfTransaction() == 0);
       }
    }
}