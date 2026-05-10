// Largest Permutation - largeperm
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef priority_queue<int, vi> ipq;
#define endl '\n'
#define PRIMLOOP(N) for (int i = 0; i < N; i++)

/* Orz bruce */
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N,K; cin >> N >> K;
    map<int,int> idxByVal;
    ipq greatest;
    vi arr(N); PRIMLOOP(N) {
        cin >> arr[i];
        greatest.push(arr[i]);
        idxByVal[arr[i]] = i;
    }

    for (int i = 0; i < N && K; i++) {
        if (arr[i] != greatest.top()) {
            idxByVal[arr[i]] = idxByVal[greatest.top()];
            arr[idxByVal[greatest.top()]] = arr[i];
            arr[i] = greatest.top();

            --K;
        }
        greatest.pop();
    }

    for (int i = 0; i < arr.size(); i++) cout << arr[i] << " \n"[i == arr.size()-1];

    return 0;
}
