/**
 * Author: DanPlus6 // David Fu
 * Problem Name: Steepness
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef tuple<int ,int, int> ti;
typedef pair<pi, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pl;
typedef tuple<ll,ll,ll> tl;
typedef pair<ll,pl> pll;
typedef pair<string, int> psi;
typedef vector<int> vi;
typedef unordered_set<int> si;
typedef set<ll> sl;
typedef queue<int> qi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef vector<pi> vii;
typedef vector<ti> vti;
typedef vector<pl> vll;
typedef vector<tl> vtl;
typedef vector<bool> vb;
#define endl '\n'
#define FILL(a, b) memset(a, b, sizeof(a))
#define ALL(x) x.begin(), x.end()
#define LOOP(n) for (int _ = 0; _ < n; _++)
#define pb push_back
#define fi first
#define se second

int main() {
    int T; scanf("%d",&T);
    for (int N,M; T--;) {
        scanf("%d",&N);
        vl A(N+1); for (int i=1;i<=N;++i) scanf("%lld",&A[i]);
        
        scanf("%d",&M); 
        
        multiset<ll> max_S;
        multiset<double> min_S;
        set<pair<ll, int>> points;
        
        for (int i = 1; i <= N; ++i) {
            points.insert({A[i], i});
            if (i > 1) {
                max_S.insert(abs(A[i] - A[i-1]));
            }
        }
        
        auto it = points.begin();
        auto next_it = it;
        ++next_it;
        while (next_it != points.end()) {
            double slope = (double)(next_it->fi - it->fi) / abs(next_it->se - it->se);
            min_S.insert(slope);
            ++it;
            ++next_it;
        }
        
        cout << fixed << setprecision(6);
        cout << (double)(*max_S.rbegin()) << " " << (*min_S.begin()) << "\n";
        
        for (int i=0,p;i<M;++i) {
            ll nv,ov; scanf("%d %lld",&p,&nv);
            
            ov = A[p];
            if (p > 1) {
                max_S.erase(max_S.find(abs(A[p] - A[p-1])));
                max_S.insert(abs(nv - A[p-1]));
            }
            if (p < N) {
                max_S.erase(max_S.find(abs(A[p+1] - A[p])));
                max_S.insert(abs(A[p+1] - nv));
            }
            
            auto curr = points.find({ov, p});
            auto prev = curr;
            auto next = curr;
            bool has_prev = (curr != points.begin());
            bool has_next = false;
            
            ++next;
            if (next != points.end()) {
                has_next = true;
            }
            
            if (has_prev && has_next) {
                prev--;
                min_S.erase(min_S.find((double)(curr->fi - prev->fi) / abs(curr->se - prev->se)));
                min_S.erase(min_S.find((double)(next->fi - curr->fi) / abs(next->se - curr->se)));
                min_S.insert((double)(next->fi - prev->fi) / abs(next->se - prev->se));
            } else if (has_prev) {
                prev--;
                min_S.erase(min_S.find((double)(curr->fi - prev->fi) / abs(curr->se - prev->se)));
            } else if (has_next) {
                min_S.erase(min_S.find((double)(next->fi - curr->fi) / abs(next->se - curr->se)));
            }
            
            points.erase(curr);
            A[p] = nv;
            
            auto res = points.insert({nv, p});
            curr = res.fi;
            prev = curr; next = curr;
            
            has_prev = (curr != points.begin());
            has_next = false;
            
            next++;
            if (next != points.end()) {
                has_next = true;
            }
            
            if (has_prev && has_next) {
                prev--;
                min_S.erase(min_S.find((double)(next->fi - prev->fi) / abs(next->se - prev->se)));
                min_S.insert((double)(curr->fi - prev->fi) / abs(curr->se - prev->se));
                min_S.insert((double)(next->fi - curr->fi) / abs(next->se - curr->se));
            } else if (has_prev) {
                prev--;
                min_S.insert((double)(curr->fi - prev->fi) / abs(curr->se - prev->se));
            } else if (has_next) {
                min_S.insert((double)(next->fi - curr->fi) / abs(next->se - curr->se));
            }
            
            cout << (double)(*max_S.rbegin()) << " " << (*min_S.begin()) << "\n";
        }
    }

    return 0;
}
