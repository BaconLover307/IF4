class InvalidInputCarException extends Exception {
    private int input;
    public InvalidInputCarException(int inp) {
        this.input = inp;
    } 

    public String getMessage() {
        String msg = "Input " + this.input + " diluar range";
        return msg;
    }
}