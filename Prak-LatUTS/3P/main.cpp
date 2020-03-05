// Nama : Gregorius Jovan Kresnadi
// NIM  : 13518135
// Latihan UTS OOP

#include <iostream>
#include <map>

using namespace std;

int main() {
    int n, m;
    string temp;
    map<string, int>hojun;
    map<string, int>qila;
    
    cin >> n;
    for (int i=1;i<=n;++i) {
        cin >> temp;
        hojun[temp]++;
    }

    cin >> m;
    for (int i=1;i<=m;++i) {
        cin >> temp;
        if (hojun.find(temp) != hojun.end() )
            hojun[temp]--;
    }

    for (auto it = hojun.begin(); it != hojun.end(); ++it) {
        for (int i=0; i< it->second; ++i) {
            cout << it->first << endl;
        }
    }

  return 0;
}
