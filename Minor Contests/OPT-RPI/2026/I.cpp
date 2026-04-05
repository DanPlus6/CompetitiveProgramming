// Monopoly
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;

const int GO = 1;
const int JAIL = 2;
const int RAIL = 3;
const int UTIL = 4;
const int CHEST = 5;
const int CHANCE = 6;
const int GOJAIL = 7;
const int NORM = 8;

ll visits[105];

void sim(vector<int>& a) {
    int pos = 0;
    int JAILPOS = 0;
    while (a[pos] != GO) pos++;
    while (a[JAILPOS] != JAIL) JAILPOS++;
    int GOPOS = pos;
    visits[GOPOS]--;

    int t = 1000000;
    pii prevroll = {-1, -1};
    pii prev2roll = {-1, -1};
    while (t-->0) {
        visits[pos]++;
        pii roll = {rand() % 3 + 1, rand() % 3 + 1};
        int sum = roll.first + roll.second;
        if (roll == prevroll && prev2roll == prevroll) {
            prevroll = {-1, -1};
            pos = JAILPOS; continue;
        }
        prev2roll = prevroll;
        prevroll = roll;
        pos = (pos + sum) % a.size();
        if (a[pos] == CHEST) {
            int r = rand() % 16;
            if (r == 0) pos = JAILPOS;
            else if (r == 1) pos = GOPOS;
        }
        else if (a[pos] == CHANCE) {
            int r = rand() % 16;
            if (r == 0) {
                prevroll = {-1, -1};
                pos = JAILPOS;
            }
            else if (r == 1) pos = GOPOS;
            else if (r == 2|| r == 3) {
                while (a[pos] != RAIL) pos = (pos + 1) % a.size();
            }
            else if (r == 4) {
                while (a[pos] != UTIL) pos = (pos + 1) % a.size();
            }
            else if (r == 5) {
                pos = (pos - 3 + a.size()) % a.size();
            }
            else if (r == 6) {
                int r1 =rand() % 4; int r2 = rand() % 4;
                pos = (pos + r1 + r2) % a.size();
            }
            else if (r == 7) {
                int r1 =rand() % 6; int r2 = rand() % 6;
                pos = (pos + r1 * r2) % a.size();
            }
            else if (r == 8) {
                int value = 0;
                int ptr = GOPOS;
                while (ptr != pos) {
                    value++; ptr = (ptr + 1) % a.size();
                }
                pos = (pos + value) % a.size();
            }
            else if (r == 9) {
                int x = 0;
                int ptr = GOPOS;
                while (ptr != pos) {
                    x++; ptr = (ptr + 1) % a.size();
                }
                int y = x;
                while (a[ptr] != RAIL) {
                    y++;
                    ptr = (ptr + 1) % a.size();
                }
                pos = (pos + 2*x + y) % a.size();
            }
        }
        else if (a[pos] == GOJAIL) {
            prevroll = {-1, -1};
            pos = JAILPOS;
        }
    }
    visits[pos]++;
}

void solve() {
    srand(time(NULL));
    int n; cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sim(a);

    vector<pair<ll, int>> results;
    for (int i = 0; i < n; i++) {
        results.push_back({visits[i], i});
    }
    sort(results.rbegin(), results.rend());
    int offset = 0;
    while (a[offset] != GO) offset++;
    int b = (results[0].second - offset + n) % n;
    int c = (results[1].second - offset + n) % n;
    int d = (results[2].second - offset + n) % n;
    if (b < 10) {
        cout << "0" << b;
    } else {
        cout << b;
    }
    if (c < 10) {
        cout << "0" << c;
    } else {
        cout << c;
    }
    if (d < 10) {
        cout << "0" << d;
    } else {
        cout << d;
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
