// CCC '20 J4 - Cyclic Shifts (Hard)
// Deterministic solution using Suffix Automaton (no hashing, no collisions)

#include <bits/stdc++.h>
using namespace std;

struct State {
    int link, len;
    int next[26];
    State() : link(-1), len(0) {
        memset(next, -1, sizeof(next));
    }
};

vector<State> st;
int lastState;

void sa_init() {
    st.clear();
    st.emplace_back();
    lastState = 0;
}

void sa_extend(char ch) {
    int c = ch - 'A';
    int cur = st.size();
    st.emplace_back();
    st[cur].len = st[lastState].len + 1;

    int p = lastState;
    while (p != -1 && st[p].next[c] == -1) {
        st[p].next[c] = cur;
        p = st[p].link;
    }

    if (p == -1) {
        st[cur].link = 0;
    } else {
        int q = st[p].next[c];
        if (st[p].len + 1 == st[q].len) {
            st[cur].link = q;
        } else {
            int clone = st.size();
            st.push_back(st[q]);
            st[clone].len = st[p].len + 1;
            while (p != -1 && st[p].next[c] == q) {
                st[p].next[c] = clone;
                p = st[p].link;
            }
            st[q].link = st[cur].link = clone;
        }
    }
    lastState = cur;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string T, S;
    cin >> T >> S;

    int N = T.size(), M = S.size();
    if (M > N) {
        cout << "no\n";
        return 0;
    }

    sa_init();
    for (char c : S) sa_extend(c);
    for (char c : S) sa_extend(c);

    int v = 0, l = 0;
    for (char ch : T) {
        int c = ch - 'A';
        if (st[v].next[c] != -1) {
            v = st[v].next[c];
            l++;
        } else {
            while (v != -1 && st[v].next[c] == -1)
                v = st[v].link;
            if (v == -1) {
                v = 0;
                l = 0;
            } else {
                l = st[v].len + 1;
                v = st[v].next[c];
            }
        }
        if (l >= M) {
            cout << "yes\n";
            return 0;
        }
    }

    cout << "no\n";
    return 0;
}
