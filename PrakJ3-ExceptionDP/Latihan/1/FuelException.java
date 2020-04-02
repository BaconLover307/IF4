class FuelException extends Exception {
    private String fuel;
    public FuelException(String fuel) {
        this.fuel = fuel;
    } 

    public String getMessage() {
        String msg = "Bensin jenis " + this.fuel + " tidak sesuai";
        return msg;
    }
}