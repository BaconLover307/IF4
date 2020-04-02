package Materi;

class Vector {
    private int size;
	private int capacity;
	private int[] data;

	public Vector() {
		capacity = 10;
		size = 0;
		data = new int[capacity];
	}

	public Vector(int cap) {
		capacity = cap;
		size = 0;
		data = new int[capacity];
	}

	public void push(int val) {
		if (capacity > size) {
			data[size] = val;
			size++;
		}
	}

    public int get(int idx) throws IndexOutOfBoundException {
        if (idx < 0 || idx >= this.size) {
            String msg = String.format("ERROR: The index %d you're trying to access is inaccessible", idx);
            throw new IndexOutOfBoundException(msg);
        }
        return this.data[idx];
    }
}