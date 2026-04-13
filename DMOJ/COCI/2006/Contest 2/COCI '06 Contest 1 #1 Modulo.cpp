// COCI '06 Contest 1 #1 Modulo
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    uint16_t A,B,C,D,E,F,G,H,I,J; 
    cin >> A >> B >> C >> D >> E >> F >> G >> H >> I >> J;
    set<int> mods;
    mods.insert(A%42); mods.insert(B%42); mods.insert(C%42); mods.insert(D%42); mods.insert(E%42); mods.insert(F%42); mods.insert(G%42); mods.insert(H%42); mods.insert(I%42); mods.insert(J%42); 
    cout << mods.size() << "\n";
    return 0;
}
