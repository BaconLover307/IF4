/* Nama         : Gregorius Jovan Kresnadi */
/* NIM          : 13518135 */
/* Tanggal      : 20-02-2020 */
/* Program      : main.cpp */
/* Deskripsi    : STL */

#include <bits/stdc++.h>
// Sudah include :
// #include <iostream>
// #include <vector>
// dll.

using namespace std;

int main() {
    int n;
    cin >> n;
    if (n<=0) {
        cout << "-\n";
        cout << "-\n";
        cout << "-\n";
        cout << "-\n";
        cout << "0\n";
        return 0;
    }
    vector<int> a, b;
    int x;
    for (int i = 0; i<n; i++) {
        cin >> x;
        a.push_back(x);
        b.push_back(x);
    }

    if (a.size() == 0) {
        cout << "-\n";
        cout << "-\n";
        cout << "-\n";
        cout << "-\n";
        cout << "0\n";
        return 0;
    } 
    
    // Mean
    double m = 0;
    for (int i=0; i < n; i++) {
        m += a[i];
    }
    cout << m/n << endl;

    // Median
    sort(b.begin(), b.end());
    if (x%2==0) cout << ((double)b[n/2+1]+(double)b[n/2])/2 << endl; 
    else cout << b[n/2] << endl;

    // Modus
    int maxcnt = 0, maxnum =0, count=0;
    for (int i=0; i<n; i++) {
        if (i==n-1 || b[i] != b[i+1]) {
            count++;
            if (count > maxcnt) {
                maxcnt = count;
                maxnum = b[i];
            }
            count = 0;
        } else {
            count++;
        }
    }
    cout << maxnum << endl;

    // Vector lama + modus
    for (int i=0; i<maxcnt; i++) a.push_back(maxnum);
    for (int i=0; i<a.size(); i++) {
        cout << a[i];
        if (i != a.size()-1) {
            cout << " ";
        }
    }
    cout << endl;

    // Size vector baru
    cout << a.size() << endl;
    return 0;
}