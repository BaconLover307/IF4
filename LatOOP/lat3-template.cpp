#include <iostream>
using namespace std;

class Jam {
  private:
    int hour, minute, second;
  public:
    Jam(int h, int m, int s) : hour(h), minute(m), second(s) {}
    Jam() : hour(0), minute(0), second(0) {}
    int GetH() {
      return hour;
    }
    int GetM() {
      return minute;
    }
    int GetS() {
      return second;
    }
    bool operator<(const Jam t) {
      int s1 = hour * 3600 + minute * 60 + second;
      int s2 = t.hour * 3600 + t.minute*60 + t.second;
      return s1<s2;
    }
};

ostream &operator<<(ostream& out, const Jam t) {

    return out;
}

class Point {
private:
    int x, y;
public:
    Point(int xx, int yy) : x(xx), y(yy) {};
    Point() : x(0), y(0) {}
    int GetX() {
        return x;
    }
    int GetY() {
        return y;
    }

}

template <class T>
T MinArray(T * arr, int n) {
  T ret = arr[0];
  for (int i = 1; i<n; i++) {
    if (arr[i] < ret) {
      ret = arr[i];
    }
  }
  return ret;
}
template <class T>
void printArray(T * arr, int n) {
    if (n == 0) {
        cout << "Array kosong" << endl;
        return;
    }


}

int main() {
  int arrInt[6] = {1, 2, 30, 40, 55, 66};
  float arrReal[6] = {1.2, 2.3, 3.4, 4.5, 5.6, 6.7};
  Jam arrJam[3] = {Jam(3,2,1), Jam(1,2,3), Jam(3,3,3)};
  cout << minArray<int>(arrInt, 6) << '\n';
  cout << minArray<float>(arrReal, 6) << '\n';
  cout << minArray<Jam>(arrJam, 3) << '\n';
  char arrChat[5] = {'j', 'o', 'v', 'a', 'n'};
  printArray<int>(arrInt, 6);
  printArray<float>(arrReal, 6);
  printArray<Jam>(arrJam, 3);
  Point


}
