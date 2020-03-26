// Nama         : Gregorius Jovan Kresnadi
// NIM          : 13518135
// Tanggal      : 26-03-2020
// Topik 		: Generic

public class MyPair<K,V> {
    private K key;
    private V value;

    public MyPair(K key, V value) {
        this.key = key;
        this.value = value;
    }

    public K getKey() {
        return this.key;
    }
    public V getVal() {
        return this.value;
    }
    public void setKey(K key) {
        this.key = key;
    }
    public void setVal(V val) {
        this.value = val;
    }

    public boolean isEqual(MyPair<K,V> pair) {
        return (this.key == pair.key) && (this.value == pair.value);
    }

    public int nearEQ(MyPair<K,V> pair) {
        if (isEqual(pair)) return 3;
        else if ((this.key == pair.key) && (this.value != pair.value)) return 1;
        else if ((this.key != pair.key) && (this.value == pair.value)) return 2;
        else return 0;
    }
}
