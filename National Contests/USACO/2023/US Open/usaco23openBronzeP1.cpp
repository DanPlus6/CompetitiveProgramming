// USACO 2023 US Open, Bronze Problem 1. FEB
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define endl '\n'
#define ALL(x) x.begin(), x.end()
#define PRIMLOOP(N) for (int i = 0; i < N; i++)
#define ILOOP(arr) for (int &i: arr)
#define pb push_back


int main() {
	int n; string s; cin >> n >> s;

	if (count(ALL(s), 'F') == n) s[0] = 'E';

	vi positions;
	PRIMLOOP(n) if (s[i] != 'F') positions.pb(i);

	int ones = positions[0] + n - 1 - positions.back();

	int mn = 0;
	int mx = 0;
	PRIMLOOP(positions.size()-1) {
		int a = positions[i];
		int b = positions[i + 1];
		mn += ((b - a) & 1) ^ (s[a] != s[b]);
		mx += b - a - (s[a] != s[b]);
	}

	vi res;
	for (int i = mn; i <= ones + mx; i += (ones == 0 ? 2 : 1)) res.pb(i);

	cout << res.size() << endl;
	ILOOP(res) cout << i << endl;
}
