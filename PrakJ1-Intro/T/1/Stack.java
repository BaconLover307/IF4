// Nama         : Gregorius Jovan Kresnadi
// NIM          : 13518135
// Tanggal      : 12-03-2020
// File 		: Stack.java

// nama file harus sama dengan nama class
class Stack {
	private int size;
	private int capacity;
	private int[] data;

	public Stack() {
		capacity = 10;
		size = 0;
		data = new int[capacity];
	}

	public Stack(int cap) {
		capacity = cap;
		size = 0;
		data = new int[capacity];
	}

	public void push(int x) {
		if (capacity > size) {
			data[size] = x;
			size++;
		}
	}

	public void push(int[] arrX) {
		for (int i=0; i<arrX.length && capacity>size; i++) {
			data[size] = arrX[i];
			size++;
		}
	}

	public int pop() {
		if (size > 0) {
			size--;
			return data[size];
		} else {
			return 0;
		}
	}
}