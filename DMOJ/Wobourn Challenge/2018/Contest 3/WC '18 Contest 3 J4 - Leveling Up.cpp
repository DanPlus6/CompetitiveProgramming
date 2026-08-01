/**
 * Author: DanPlus6 // David Fu
 * Problem Name: WC '18 Contest 3 J4 - Leveling Up
 * Problem URL:  https://dmoj.ca/problem/wc18c3j4
 * Problem Code: wc18c3j4
 */
#include <bits/stdc++.h>
using namespace std;

typedef tuple<int ,int, int> ti;
typedef vector<ti> vti;

int main() {
    int N,S,L; scanf("%d\n%d %d",&N,&S,&L);
    priority_queue<ti,vti,greater<>> lft,rit;
    for (int p,g,m; N--;) {
        scanf("%d %d %d",&p,&m,&g);
        if (p = p-S; p >= 0) rit.push({p,m,g});
        else lft.push({abs(p),m,g});
    }

    bool pos = true;
    while (pos) {
        pos = false;
        if (!lft.empty()) {
            if (ti l = lft.top(); L >= get<1>(l)) {
                L += get<2>(l);
                lft.pop();
                pos = true;
            }
        }                           
        if (!rit.empty()) {
            if (ti r = rit.top(); L >= get<1>(r)) {
                L += get<2>(r);
                rit.pop();
                pos = true;
            }
        }

        if (!pos) break;
    }

    printf("%d\n",L);
    return 0;
}
