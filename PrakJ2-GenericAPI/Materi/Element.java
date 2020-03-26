// Nama         : Gregorius Jovan Kresnadi
// NIM          : 13518135
// Tanggal      : 19-03-2020
// Topik 		: Generic

public class Element {
    public static <T extends Number> T max_elmt(T[] arr, int N) {
        T max_res = arr[0];
        for (int i=0; i<N; i++) {
            if (max_res.doubleValue() < arr[i].doubleValue()) {
                max_res = arr[i];
            }
        }
        return max_res;
    }

    public static void main(String[] args) {
        Element e = new Element();
        Integer[] arr = new Integer[]{1,2,3};
        Integer max1 = e.<Integer>max_elmt(arr,3);
        Integer max2 = e.max_elmt(arr, 3);
    }
}
