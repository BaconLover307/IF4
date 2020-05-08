// Nama         : Gregorius Jovan Kresnadi
// NIM          : 13518135
// Tanggal      : 07-05-2020
// Topic 		: Collection

import java.util.List;

public class Test {
    private List<Integer> list;
    private int n;

    public Test(List<Integer> l, int n) {
        this.list = l;
        this.n = n;
    }

    public void reset() {
        list.clear();
        for (int i = 0; i<n; i++) {
            list.add(0);
        }
    }

    public long get(int idx) {
        reset();
        long start = Util.getTime();
        Integer x = list.get(idx);
        long finish = Util.getTime();
        return finish - start;
    }
    
    public long del(int idx, int t) {
        reset();
        long start = Util.getTime();
        for (int i = 0; i<t; i++) {
            list.remove(idx);
        }
        long finish = Util.getTime();
        return finish - start;
    }
}