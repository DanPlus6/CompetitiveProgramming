/**
 * Author: DanPlus6 // David Fu
 * Problem Name: USACO 2020 December Silver P2 - Rectangular Pasture
 * Problem URL:  https://dmoj.ca/problem/usaco20decs2
 * Problem Code: usaco20decs2
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pi> vii;
#define ALL(x) x.begin(), x.end()

bool cmpx(const pi &a, const pi &b) { return a.first < b.first; }
bool cmpy(const pi &a, const pi &b) { return a.second < b.second; }
int sum(const vvi &A, int ri,int rj,int ci,int cj) {
    return A[rj][cj] - A[rj][ci-1] - A[ri-1][cj] + A[ri-1][ci-1];
}

int main() {
    int N; scanf("%d",&N);
    vii nums(N);
    for (int i=0;i<N;++i) {
        scanf("%d %d",&nums[i].first,&nums[i].second);
    }

    sort(ALL(nums),cmpx); for (int i=0;i<N;++i) nums[i].first = i+1;
    sort(ALL(nums),cmpy); for (int i=0;i<N;++i) nums[i].second = i+1;

    vvi grid(N+1, vi(N+1));
    for (auto &[x,y]: nums) grid[x][y] = 1;
    for (int i=1;i<=N;++i) {
        for (int j=1;j<=N;++j) {
            grid[i][j] += (grid[i-1][j] + grid[i][j-1] - grid[i-1][j-1]);
        }
    }

    sort(ALL(nums),cmpx);
    ll res = 0;
    for (int i=0;i<N;++i) {
        for (int j=i+1;j<N;++j) {
            auto [ri,ci] = nums[i];
            auto [rj,cj] = nums[j];
            ci = min(ci, nums[j].second);
            cj = max(cj, nums[i].second);

            int abv = sum(grid,1,ri-1,ci,cj), blw = sum(grid,rj+1,N,ci,cj);
            res += (abv + 1) * (blw + 1);
        }

    }

    printf("%lld\n",res+N+1);

    return 0;
}
