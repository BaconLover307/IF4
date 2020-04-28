// Nama     : Gregorius Jovan Kresnadi
// NIM      : 13518135
// Tanggal  : 16-04-2020
// Topik 	: Reflection

import java.lang.Class;
import java.lang.reflect.Field;
import java.lang.reflect.Method;

public class LaptopTest {
    // Anda boleh menambahkan atribut yang diperlukan
    private Class c;

    public LaptopTest(String className) {
        /**
         * Memeriksa apakah ada kelas dengan nama className.
         * Jika tidak, tuliskan "Tidak ada kelas dengan nama yang diberikan" (tanpa petik) ke layar
         */
        try {
            c = className.getClass();
        } catch (Exception e) {
            System.out.println("Tidak ada kelas dengan nama yang diberikan");
        }
    }

    public boolean testMethods() {
        Method m;
        if (c.getMethods().length == 1) {
            // Jika nama method bukan getRamSize, tuliskan "Nama method harus getRamSize" (tanpa petik) ke layar
            try {
                m = c.getDeclaredMethod("getRamSize");
            } catch (Exception e) {
                System.out.println("Nama method harus getRamSize");
                return false;
            }
            // Jika tipe return bukan Integer, tuliskan "Tipe return method harus Integer" (tanpa petik) ke layar
            if (m.getGenericReturnType() != Integer.class) {
                System.out.println("Tipe return method harus Integer");
                return false;
            } else {
                return true;
            }

        } else {
            // Menuliskan "Banyaknya method hanya boleh 1" (tanpa petik) ke layar
            System.out.println("Banyaknya method hanya boleh 1");
            return false;
        }
        // Return true jika semua tes berhasil
        // Jika ada 1 yang salah, return false
    }

    public boolean testFields() {
        Field[] fields = c.getFields();
        Field field;
        if (fields.length == 1) {
            // Jika nama field bukan serialNumber, tuliskan "Nama field harus serialNumber" (tanpa petik) ke layar
            try {
                field = c.getDeclaredField("serialNumber");
                // Jika tipe return bukan String, tuliskan "Tipe field harus String" (tanpa petik) ke layar
                if (field.getGenericType() != String.class) {
                    System.out.println("Tipe field harus String");
                    return false;
                } else {
                    return true;
                }
            } catch (Exception e) {
                System.out.println("Nama field harus serialNumber");
                return false;
            }
        } else {
            // Menuliskan "Banyaknya field hanya boleh 1" (tanpa petik) ke layar
            System.out.println("Banyaknya field hanya boleh 1");
            return false;
        }
        // Return true jika semua tes berhasil
        // Jika ada 1 yang salah, return false
    }
}
