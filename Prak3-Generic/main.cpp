/* Nama         : Gregorius Jovan Kresnadi */
/* NIM          : 13518135 */
/* Tanggal      : 27-02-2020 */

#include <iostream>
#include <map>

using namespace std;

int main() {
    int n, m;
    cin >> n;
    map<int, string>hojun;
    map<int, string>::iterator it1;
    for (int i=1;i<=n;i++) {
        string input;
        cin >> input;
        hojun[i] = input;
    }

    cin >> m;
    map<int, string>qila;
    map<int, string>::iterator it2;
    for (int i=1;i<=m;i++) {
        string input;
        cin >> input;
        qila[i] = input;
    }
    for (int i=1; i<n; i++) {
        for (int j=1; j<m; j++) {
            if (hojun[i] == qila[j]) {
                hojun.erase(i);
                qila.erase(j);
            }
        }
    }

    for (it1 = hojun.begin(); it1 != hojun.end(); it1++) {
        cout << it1->second << endl;
    }

  return 0;
}
