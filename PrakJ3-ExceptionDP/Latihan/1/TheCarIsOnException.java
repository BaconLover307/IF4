class TheCarIsOnException extends Exception {
    public TheCarIsOnException() {
    } 

    public String getMessage() {
        String msg = "Mobil sudah menyala";
        return msg;
    }
}