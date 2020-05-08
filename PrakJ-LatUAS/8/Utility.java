// Nama         : Gregorius Jovan Kresnadi
// NIM          : 13518135
// Tanggal      : 07-05-2020
// Topic 		: Generic

public class Utility {
    public static <T extends Number> double getMidpoint(T[] arr) {
        int len = arr.length;
        if (len % 2 == 0) {
            return (arr[len/2].doubleValue() + arr[len/2-1].doubleValue())/2;
        } else {
            return arr[len/2].doubleValue();
        }
    }

    public static <T> T getMidpoint(T[] arr) {
        return arr[arr.length/2];
    }

    public static <T> T getLast(T[] arr) {
        return arr[arr.length - 1];
    }

    public static <T extends Number> double getAverage(T[] arr) {
        double tot = 0;
        for (T t : arr) {
            tot = tot + t.doubleValue();
        }
        return tot/arr.length;
    }
}