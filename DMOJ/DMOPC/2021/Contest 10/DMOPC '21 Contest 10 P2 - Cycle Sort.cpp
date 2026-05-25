// DMOPC '21 Contest 10 P2 - Cycle Sort
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

#define rt(x,k) rotate(x.begin(), x.begin()+(k%x.size()), x.end())

void printv(const vi &arr) {
    for (int i = 0; i < arr.size(); i++) 
        printf("%d%c", arr[i], (i+1<arr.size()?' ':'\n'));
}

int main() {
    int N; scanf("%d",&N);
    vi arr(N); 
    int p1 = -1, p2 = -1;
    for (int i = 0; i < N; i++) {
        scanf("%d",&arr[i]);
        if (arr[i] == 1) p1 = i;
        if (arr[i] == 2) p2 = i;
    }

    if (N == 1) { printf("1\n"); return 0; }

    if (arr[(p1+1) % N] == 2) {
        rt(arr,p1);
        vi pos(N+2);
        for (int i=0;i<N;i++) pos[arr[i]] = i;

        for (int i=2;i<N;i++) {
            if (arr[i] != i+1) {
                swap(arr[i],arr[pos[i+1]]);
                break;
            }
        }

        printv(arr);
    } else {
        // move 2 after 1
        vi arr_a = arr;
        int after1 = (p1+1)%N;
        swap(arr_a[p2], arr_a[after1]);
        rt(arr_a, p1);

        // move 1 before 2
        vi arr_b = arr;
        int bf2 = (p2-1+N)%N;
        swap(arr_b[p1], arr_b[bf2]);
        rt(arr_b, bf2);

        // swap 1 and 2
        swap(arr[p1], arr[p2]);
        rt(arr, p2);

        const vi &res = min(arr, min(arr_b, arr_a));
        printv(res);
    }

    return 0;
}
