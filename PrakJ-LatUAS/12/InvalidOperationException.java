// Nama         : Gregorius Jovan Kresnadi
// NIM          : 13518135
// Tanggal      : 28-04-2020
// Topic 		: Exception

public class InvalidOperationException extends Throwable {

    private String opType;
    private String description;

    public InvalidOperationException(String opType, String description) {
        this.opType = opType;
        this.description = description;
    }

    public String getOpType() {return this.opType;}
    public String getDescription() {return this.description;}

}