// Nama     : Gregorius Jovan Kresnadi
// NIM      : 13518135
// Tanggal  : 16-04-2020
// Topik 	: Thread
import java.util.List;

public class ChunkLoader implements Runnable {
    // ... Anda boleh menambahkan atribut
    private Chunk c;
    private String file;

    public ChunkLoader(Chunk chunk, String chunkDataFilename) {
        this.c = chunk;
        this.file = chunkDataFilename;
        // ... Isilah constructor sesuai kebutuhan
    }

    @Override
    public void run() {
        // Membaca file dengan nama chunkDataFilename
        // Gunakan class CSVReader.
        CSVReader csv = new CSVReader(file, ",");
        csv.setSkipHeader(true);
        try {
            List<String[]> list = csv.read();
            for (String[] pos : list) {
                this.c.addTree(new Position(Integer.parseInt(pos[0]), Integer.parseInt(pos[1])));
            }
        } catch (Exception e) {
            // e.printStackTrace();
        }


        // Contoh file chunkDataFilename:
        // x,y
        // 1,18
        // 10,8
        // 6,12
        // Untuk setiap x dan y, tambahkan tree ke Chunk

        // Jika ada IOException pada saat membaca reader, catch Exception
        // tidak ada tree yang ditambahkan pada Chunk (tidak dithrow lagi)
    }
}
