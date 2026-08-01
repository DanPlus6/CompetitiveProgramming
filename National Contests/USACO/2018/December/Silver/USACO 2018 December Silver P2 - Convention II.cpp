/**
 * Author: DanPlus6 // David Fu
 * Problem Name: USACO 2018 December Silver P2 - Convention II
 * Problem URL:  https://dmoj.ca/problem/usaco18decsilvp2
 * Problem Code: usaco18decsilvp2
 */
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
constexpr int MM = 1e5+5;

int N, a[MM], t[MM], idx[MM], res;
bool cmp(int i, int j) {
    return a[i]<a[j] || (a[i]==a[j] && i<j);
}

int main() {
    scanf("%d",&N);
    for (int i=0;i<N;++i) {
        scanf("%d %d",&a[i],&t[i]); idx[i] = i;
    }
    sort(idx,idx+N, cmp);

    int time=0;
    priority_queue<int,vi,greater<>> pq;
    for (int j=0;j<N;++j) {
        int i = idx[j];
        if (a[i] < time) pq.push(i);
        else {
            if (pq.empty()) time = a[i]+t[i];
            else {
                int k = pq.top(); pq.pop();
                res = max(res, time-a[k]);
                time += t[k];
                if (time >= a[i]) pq.push(i);
                else --j;
            }
        }
    }
    while (!pq.empty()) {
        int i = pq.top(); pq.pop();
        res = max(res, time-a[i]);
        time += t[i];
    }

    printf("%d\n",res);


    return 0;
}
