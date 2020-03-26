// Nama         : Gregorius Jovan Kresnadi
// NIM          : 13518135
// Tanggal      : 26-03-2020
// Topik 		: API
import java.util.*;

public class Test {
    private List<Integer> list;
    private int n;

    public Test(List<Integer> list, int n) {
        this.list = list;
        this.n = n;
    }
    public void reset() {
        this.list.clear();
        for (int i=0; i<n; i++) {
            this.list.add(0);
        }
    }

    public long get(int idx) {
        reset();
        long start = Util.getTime();
        list.get(idx);
        long finish = Util.getTime();
        return finish - start;
    }

    public long del(int idx, int t) {
        reset();
        long start = Util.getTime();
        for (int i=0; i<t; i++) {
            list.remove(idx);
            n--;
        }
        long finish = Util.getTime();
        return finish - start;

    }
}
