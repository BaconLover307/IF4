
import java.lang.reflect.*;
public class LaptopTest {
    // Anda boleh menambahkan atribut yang diperlukan
    Class c;

    public LaptopTest(String className) {
        /**
         * Memeriksa apakah ada kelas dengan nama className.
         * Jika tidak, tuliskan "Tidak ada kelas dengan nama yang diberikan" (tanpa petik) ke layar
         */
        try {
            c = Class.forName(className);
        } catch (Exception e) {
            System.out.println("Tidak ada kelas dengan nama yang diberikan");
        }
    }

    public boolean testMethods() {
        Method[] methods = c.getDeclaredMethods();
        if (methods.length == 1) {
            Method m = methods[0];
            Class p = m.getReturnType();
            // System.out.println(p.getName());
            if (p.getName() == "java.lang.Integer" && m.getName() == "getRamSize") {
                return true;
            }
            if (m.getName() != "getRamSize") {
                System.out.println("Nama method harus getRamSize");
            }
            if (p.getName() != "java.lang.Integer") {
                System.out.println("Tipe return method harus Integer");
            }
            return false;
            // Jika nama method bukan getRamSize, tuliskan "Nama method harus getRamSize" (tanpa petik) ke layar
            // Jika tipe return bukan Integer, tuliskan "Tipe return method harus Integer" (tanpa petik) ke layar
        } else {
            System.out.println("Banyaknya method hanya boleh 1");
            return false;
            // Menuliskan "Banyaknya method hanya boleh 1" (tanpa petik) ke layar
        }
        // Return true jika semua tes berhasil
        // Jika ada 1 yang salah, return false
    }

    public boolean testFields() {
        Field[] fields = c.getDeclaredFields();
        if (fields.length == 1) {
            Field f = fields[0];
            Class p = f.getType();
            if (p.getName() == "java.lang.String" && f.getName() == "serialNumber") {
                return true;
            }
            if (f.getName() != "serialNumber") {
                System.out.println("Nama field harus serialNumber");
            }
            if (p.getName() != "java.lang.String") {
                System.out.println("Tipe field harus String");
            }
            return false;
            // Jika nama field bukan serialNumber, tuliskan "Nama field harus serialNumber" (tanpa petik) ke layar
            // Jika tipe return bukan String, tuliskan "Tipe field harus String" (tanpa petik) ke layar
        } else {
            System.out.println("Banyaknya field hanya boleh 1");
            return false;
            // Menuliskan "Banyaknya field hanya boleh 1" (tanpa petik) ke layar
        }
        // Return true jika semua tes berhasil
        // Jika ada 1 yang salah, return false
    }
}