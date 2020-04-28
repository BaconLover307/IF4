// Nama         : Gregorius Jovan Kresnadi
// NIM          : 13518135
// Tanggal      : 28-04-2020
// Topic 		: Exception

public class Matrix {

    private int[][] data;
    private int nRow;
    private int nColumn;

    public Matrix() {
        nRow = 1;
        nColumn = 1;
        data = new int[1][1];
        data[0][0] = 0;
    }

    // Diasumsikan nRow > 0 dan nColumn > 0
    public Matrix(int nRow, int nColumn) {
        this.nRow = nRow;
        this.nColumn = nColumn;
        data = new int[nRow][nColumn];
        for (int i = 0; i < nRow; i++) {
            for (int j = 0; j < nColumn; j++) {
                data[i][j] = 0;
            }
        }
    }

    public int getNRow() {
        return nRow;
    }

    public int getNColumn() {
        return nColumn;
    }

    // TODO
    // Mengembalikan elemen pada (rowPosition, colPosition)
    // Jika rowPosition atau colPosition diluar range dari matriks, lemparkan IndexOutOfBoundsException dengan pesan "Indeks diluar matriks."
    public int getValueAt(int rowPosition, int colPosition) throws IndexOutOfBoundsException {
        if (rowPosition >= this.nRow || rowPosition < 0 || colPosition >= this.nColumn || colPosition < 0) {
            throw new IndexOutOfBoundsException("Indeks diluar matriks.");
        } else {
            return data[rowPosition][colPosition];
        }
    }
    
    // TODO
    // Mengisi matriks pada (rowPosition, colPosition) dengan element
    // Jika rowPosition atau colPosition diluar range dari matriks, lemparkan IndexOutOfBoundsException dengan pesan "Indeks diluar matriks."
    public void setValueAt(int rowPosition, int colPosition, int element) throws IndexOutOfBoundsException {
        if (rowPosition >= this.nRow || rowPosition < 0|| colPosition >= this.nColumn || colPosition < 0) {
            throw new IndexOutOfBoundsException("Indeks diluar matriks.");
        } else {
            data[rowPosition][colPosition] = element;
        }
    }

    // TODO
    // Mengembalikan matriks baru yang merupakan hasil penambahan matriks ini dengan matriks other.
    // Jika ukuran kedua matriks tidak sama, lemparkan InvalidOperationException dengan : 
    //   opType : 'add' (tanpa petik)
    //   description 'Ukuran matriks tidak sama.' (tanpa petik)
    public Matrix add(Matrix other) throws InvalidOperationException {
        if (this.nColumn == other.nColumn && this.nRow == other.nRow) {
            Matrix result = new Matrix(this.nRow, this.nColumn);
            for (int i = 0; i < this.nRow; i++) {
                for (int j = 0; j < this.nColumn; j++) {
                    int elm = this.getValueAt(i, j) + other.getValueAt(i, j);
                    result.setValueAt(i, j, elm);
                }
            }
            return result;
        } else {
            throw new InvalidOperationException("add", "Ukuran matriks tidak sama.");
        }
    }
    
    // TODO
    // Mengembalikan matriks baru yang merupakan hasil perkalian antara matriks ini dengan matriks other.
    // Operasi perkalian valid jika jumlah kolom dari matriks ini sama dengan jumlah baris matriks other.
    // Jika tidak valid, lemparkan InvalidOperationException dengan :
    //   opType : 'multiply' (tanpa petik)
    //   description : 'Ukuran kolom matriks pertama tidak sama dengan ukuran baris matriks kedua.' (tanpa petik)
    public Matrix multiply(Matrix other) throws InvalidOperationException {
        if (this.nColumn ==  other.nRow) {
            Matrix result = new Matrix(this.nRow, other.getNColumn());
            for (int i = 0; i < this.nRow; i++) {
                for (int j = 0; j < other.getNColumn(); j++) {
                    int currentResult = 0;
                    for (int k = 0; k < other.getNRow(); k++) {
                        currentResult += this.getValueAt(i, k) * other.getValueAt(k, j);
                    }
                    result.setValueAt(i, j, currentResult);
                }
            }
            return result;
        } else {
            throw new InvalidOperationException("multiply", "Ukuran kolom matriks pertama tidak sama dengan ukuran baris matriks kedua.");
        }
    }

    @Override
    public String toString() {
        StringBuffer buffer = new StringBuffer();
        for (int i = 0; i < nRow; i++) {
            buffer.append(data[i][0]);
            for (int j = 1; j < nColumn; j++) {
                buffer.append(String.format(" %d", data[i][j]));
            }
            buffer.append("\n");
        }
        return buffer.toString();
    }

}