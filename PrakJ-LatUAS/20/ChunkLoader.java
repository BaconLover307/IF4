public class ChunkLoader implements Runnable {
    // ... Anda boleh menambahkan atribut

    public ChunkLoader(Chunk chunk, String chunkDataFilename) {
        // ... Isilah constructor sesuai kebutuhan
    }

    @Override
    public void run() {
        // Membaca file dengan nama chunkDataFilename
        // Gunakan class CSVReader.
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
