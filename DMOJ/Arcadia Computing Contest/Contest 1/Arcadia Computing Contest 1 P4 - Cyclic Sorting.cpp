// Arcadia Computing Contest 1 P4 - Cyclic Sorting
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef unordered_set<int> si;


int main() {
    int N,Q; scanf("%d %d",&N,&Q);
    vi arr(N); for (int i=0;i<N;i++) scanf("%d",&arr[i]);

    si s;
    for (int i = 0; i < N; i++) if (arr[(i-1+N)%N] > arr[i]) s.insert(i);

    for (int i,x; Q > 0; Q--) {
        scanf("%d %d",&i,&x);
        --i;

        s.erase(i); 
        s.erase((i+1)%N);
        arr[i] = x;

        if (arr[(i-1+N)%N] > arr[i]) s.insert(i);
        if (arr[(i)] > arr[(i+1)%N]) s.insert((i+1)%N);

        if (s.size() > 1) printf("-1\n");
        else if (s.size() == 0) printf("0\n");
        else if (s.size() == 1) {
            int l = *s.begin();
            printf("%d\n", min(l, N-l));
        }
    }

    return 0;
}
