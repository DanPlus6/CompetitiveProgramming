// USACO 2021 January Silver P2 - No Time to Paint
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define ALL(x) x.begin(), x.end()
#define endl '\n'
#define pb push_back


string fence;
int N, prefix[100001], suffix[100001];
// orz bruce and brian dean
void build(int *arr) {
    stack<char> stk;
    for (int i = 0; i < N; i++) {
        arr[i+1] = arr[i];
        while (!stk.empty() && stk.top() > fence[i]) stk.pop();
        if (stk.empty() || stk.top() < fence[i]) {
            stk.push(fence[i]);
            arr[i+1]++;
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int Q;
    cin >> N >> Q >> fence; 
    
    build(prefix);
    reverse(ALL(fence));
    build(suffix);
    
    for (int q = 0; q < Q; q++) {
        int l,r;
        cin >> l >> r;
        cout << prefix[l-1] + suffix[N-r] << endl;
    }


    return 0;
}
