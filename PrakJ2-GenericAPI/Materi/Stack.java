// Nama         : Gregorius Jovan Kresnadi
// NIM          : 13518135
// Tanggal      : 19-03-2020
// Topic 		: Generic
import java.util.*

public class Stack<T> {
    // size tidak dideklarasi karena sudah tersedia dari ArrayList
    private ArrayList<T> data;

    public Stack() {
        this.capacity = 10;
        this.data = new ArrayList<T>();
    }
}