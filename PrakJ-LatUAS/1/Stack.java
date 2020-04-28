// Nama         : Gregorius Jovan Kresnadi
// NIM          : 13518135
// Tanggal      : 28-04-2020
// Topic 		: Intro

public class Stack {
    private int size;
    private int capacity;
    private int[] data;
    
    public Stack() {
        this.capacity = 10;
        this.size = 0;
        this.data = new int[this.capacity];
    }

    public Stack(int cap) {
        this.capacity = cap;
        this.size = 0;
        this.data = new int[this.capacity];
    }

    public void push(int x) {
        if (this.size < this.capacity)
            this.data[this.size++] = x;
    }

    public void push(int[] x) {
        int i = 0;
        while (this.size < this.capacity && i<x.length)
            this.data[this.size++] = x[i++];
    }

    public int pop() {
        if (this.size > 0) return this.data[--this.size];
        else return 0;
    }
}