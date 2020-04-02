// Nama         : Gregorius Jovan Kresnadi
// NIM          : 13518135
// Tanggal      : 02-04-2020
// Topik 		: Exception
 
class InvalidOperationException extends Exception {
    private String opType;
    private String description;
    
    public InvalidOperationException(String op, String desc) {
        this.opType = op;
        this.description = desc;
	}
	
	public String getOpType() {return this.opType;}
	public String getDescription() {return this.description;}
}