// Nama     : Gregorius Jovan Kresnadi
// NIM      : 13518135
// Tanggal  : 09-04-2020
// Topik 	: Assertion
 
// AccountTest.java

public class AccountTest {
    public AccountTest() {
    // Tidak melakukan apa-apa
    }

    public void test() {
        // Melakukan tes terhadap method transfer.
        // Asumsikan method lainnya benar.

        //! KALO TRANSFER GAGAL, numOfTransaction TETEP NAMBAH
        Account a = AccountFactory.withBalance(20);
        Account b = AccountFactory.withBalance(15);
        assert a.getNumOfTransaction() == 0;
        assert b.getNumOfTransaction() == 0;
        try {
            a.transfer(b,10);
        } catch (Exception e) {
        }
        assert a.getBalance() == 10;
        assert b.getBalance() == 25;
        assert a.getNumOfTransaction() == 1;
        assert b.getNumOfTransaction() == 0;
        
        try {
            a.transfer(b,-10);
            
        } catch (Exception e) {
        }
        assert a.getBalance() == 10;
        assert b.getBalance() == 25;
        assert a.getNumOfTransaction() == 2;
        assert b.getNumOfTransaction() == 0;

        try {
            b.transfer(a,100);
        } catch (Exception e) {
        }
        assert a.getBalance() == 10;
        assert b.getBalance() == 25;
        assert a.getNumOfTransaction() == 2;
        assert b.getNumOfTransaction() == 1;
        
        try {
            b.transfer(a,5);
        } catch (Exception e) {
        }
        assert a.getBalance() == 15;
        assert b.getBalance() == 20;
        assert a.getNumOfTransaction() == 2;
        assert b.getNumOfTransaction() == 2;
        try {
            b.transfer(a,10);
            a.transfer(b,10);
        } catch (Exception e) {
        }
        assert a.getBalance() == 15;
        assert b.getBalance() == 20;
        assert a.getNumOfTransaction() == 3;
        assert b.getNumOfTransaction() == 3;
    }
}