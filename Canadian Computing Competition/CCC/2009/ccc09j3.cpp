// CCC '09 J3 - Good Times
#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")


int to(int time) {
    int t = ((time % 1440) + 1440) % 1440;
    int h = t / 60;
    int m = t % 60;

    return h*100+m;
}

/* Orz bruce */
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int T; cin >> T;
    cout << T << " in Ottawa\n";
    T = ((int)(T/100)*60 + T%100);
    
    cout << to(T - 180) << " in Victoria\n";
    cout << to(T - 120) << " in Edmonton\n";
    cout << to(T - 60) << " in Winnipeg\n";
    cout << to(T) << " in Toronto\n";
    cout << to(T + 60) << " in Halifax\n";
    cout << to(T + 90) << " in St. John's\n";

    return 0;
}
