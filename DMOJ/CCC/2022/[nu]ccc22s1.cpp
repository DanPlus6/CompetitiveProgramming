// CCC '22 S1 - Good Fours and Good Fives
#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    // orz mohamed_kachef2006
    int chunk5 = N/5;
    int chunk4in5 = chunk5/4;
    if (chunk5 >= (chunk4in5*4 + (N&3))) chunk4in5++;
    cout << chunk4in5 << "\n";

    
    // damn thats smart
    // array<int,20> N20 = {0,0,0,1,1,0,0,1,1,1,0,1,1,1,1,1,1,1,1,2};
    // if (N <= 20) {cout << N20[N-1] << endl; return 0;}

    // int lRes = floor(N/20), R = N%20;
    // if (!R) {cout << lRes+1 << "\n";}
    // else {cout << lRes + N20[R-1] << "\n";}


    // our brains are shrinking
    // int res = 0;
    // for (int fo = 0; fo <= (int)((N+3)/4); fo++) {for (int fi = 0; fi <= (int)((N+4)/5); fi++) {
    //     if ((4*fo + 5*fi) == N) res++;
    // }}
    // cout << res << endl;

    return 0;
}
