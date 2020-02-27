/* Nama         : Gregorius Jovan Kresnadi */
/* NIM          : 13518135 */
/* Tanggal      : 27-02-2020 */

#include <iostream>
#include <map>

using namespace std;

int main() {
    int n, m;
    cin >> n;
    map<string, bool>hojun;
    map<string, bool>::iterator it1;
    for (int i=0;i<n;i++) {
        string input;
        cin >> input;
        hojun[input] = true;
    }

    cin >> m;
    map<string, bool>qila;
    map<string, bool>::iterator it2;
    for (int i=0;i<m;i++) {
        string input;
        cin >> input;
        qila[input] = true;
    }
    for (it2 = qila.begin(); it2 != qila.end(); it2++) {
        if (hojun.find(it2->first) != hojun.end()) {
            hojun[it2->first] = false;
        }
        continue;
    }


    for (it1 = hojun.begin(); it1 != hojun.end(); it1++) {
        if (it1->second == true) {
            cout << it1->first << endl;
        }
    }

  return 0;
}
