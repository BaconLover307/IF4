/* Nama         : Gregorius Jovan Kresnadi */
/* NIM          : 13518135 */
/* Tanggal      : 20-02-2020 */
/* Program      : Vector.hpp */
/* Deskripsi    : Header vector berupa template*/


#ifndef _VECTOR_HPP_
#define _VECTOR_HPP_

#include <iostream>

using namespace std;

template <class T, int N>
class Vector {
private:
	T* elements;
public:
    Vector() {
        this->elements = new T[N];
    }

    Vector(const Vector& other) {
        this->elements = new T[N];
        for (int i = 0; i < N; i++) {
        	this->elements[i] = other.elements[i];
        }
    }

    ~Vector() {
        delete[] this->elements;
    }

    T& operator[](int idx) {
        return this->elements[idx];
    }

    Vector<T,N> operator+(const Vector<T,N>& other) {
        Vector result;
        for (int i = 0; i < N; i++) {
        	result.elements[i] = elements[i] + other.elements[i];
        }
        return result;
    }

    Vector<T,N> operator-(const Vector<T,N>& other) {
        Vector result;
        for (int i = 0; i < N; i++) {
        	result.elements[i] = elements[i] - other.elements[i];
        }
        return result;
    }

    bool operator<(const Vector& other) {
        for (int i = 0; i < N; i++) {
        	if (this->elements[i] != other.elements[i]) {
            	return this->elements[i] < other.elements[i];
        	}
        }
        return false; // vector sama
    }

    bool operator>(const Vector& other) {
        for (int i = 0; i < N; i++) {
        	if (this->elements[i] != other.elements[i]) {
            	return this->elements[i] > other.elements[i];
        	}
        }
        return false; // vector sama
    }

    friend ostream& operator<<(ostream& os, Vector<T,N> vector) {
        os << "<";
        for (int i = 0; i < N; i++) {
		    os << vector.elements[i];
		    if (i != N-1) {
		    	os << ",";
		    }
        }
        os << ">";
        return os;
    }

    friend istream& operator>>(istream& is, Vector<T,N>& vector) {
        for (int i = 0; i < N; i++) {
        	is >> vector.elements[i];
        }
        return is;
    }
};

#endif