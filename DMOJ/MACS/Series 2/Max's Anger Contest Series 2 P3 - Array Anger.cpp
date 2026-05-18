// Max's Anger Contest Series 2 P3 - Array Anger
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define LOOP(n) for (int _ = 0; _ < n; _++)

int N,Q; 
vi psa;

int solve(int L, int S) {
    int low = L, high = N;
    int mid, ans, R=0;
    while (low <= high) {
        mid = (low + high) / 2;
        ans = psa[mid] - psa[L-1];

        if (ans >= S) {
            R = mid;
            high = mid-1;
        } else if (ans < S) {
            low = mid+1;
        } else {
            high = mid-1;
        }
    }
    
    return (R?R:N);
}

/* 😭 */
int main() {
    scanf("%d %d",&N,&Q);
    psa.resize(N+1); psa[0] = 0;
    for (int i = 1; i <= N; i++) { scanf("%d",&psa[i]); psa[i] += psa[i-1]; }

    char idc; int L,S;
    LOOP(Q) {
        scanf("%s %d %d",&idc,&L,&S);
        
        printf("%d\n", solve(L,S));
    }

    return 0;
}
