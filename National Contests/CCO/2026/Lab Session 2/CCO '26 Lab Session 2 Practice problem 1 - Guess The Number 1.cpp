// CCO '26 Lab Session 2 Practice Problem 1 - Guess The Number 1
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int N; cin >> N;

    string a,b;
    int lo = 1, hi = N, mid;
    while (true) {
        mid = (lo+hi)/2; 
        cout << mid << endl;
        
        cin >> a >> b;
        if (b == "right") break;
        if (b == "low") lo = mid+1;
        else if (b == "high") hi = mid-1;
    }

    return 0;
}
