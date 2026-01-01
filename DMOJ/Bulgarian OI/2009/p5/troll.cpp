#include <bits/stdc++.h>
#include <cmath>
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n = 74;
    unsigned long long i = 3148000000;
    while (n <= 250) {
        // string pw = to_string(i*i);
        // cout << i << " | " << pw << "\n";

        int mask = 0;
        for (char c : to_string(i*i)) { // formerly (char c: pw)
            if (c == '0') mask |= 1;
            else if (c == '4') mask |= 2;
            else if (c == '9') mask |= 4;
            else { mask = -1; break; }
        }
        
        ofstream tmp("checkpoint.tmp");
        tmp << i << "\n";
        tmp.flush(); tmp.close();
        rename("checkpoint.tmp","checkpoint.txt");

        if (mask != 7) { ++i; continue; }


        n++;
        ofstream f("troll.txt", ios_base::app | ios_base::out);
        f << to_string(i) << "\n";
        f.close();

        i++;
    }
    return 0;
}
