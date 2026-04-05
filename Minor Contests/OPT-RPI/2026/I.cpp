// Monopoly
#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

typedef long long ll;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pl> vll;
#define endl '\n'
#define ALL(x) x.begin(), x.end()
#define PRIMLOOP(N) for (int i = 0; i < N; i++)
#define pb push_back

#define GO 1
#define JAIL 2
#define RR 3
#define UTIL 4
#define CC 5
#define CH 6
#define G2J 7
#define NORM 8

int main() {
    int N; cin >> N;

    vi board(N);
    int jail = 0, go = 0;

    PRIMLOOP(N) {
        cin >> board[i];
        if (board[i] == JAIL) jail = i;
        if (board[i] == GO) go = i;
    }

    vl visits(N, 0);
    int current_pos = go;
    int doubles_count = 0;

    mt19937 gen(123456);
    uniform_int_distribution<> d3(1, 3), d4(1, 4), d6(1, 6);

    vi cc_deck(16), ch_deck(16);
    iota(ALL(cc_deck), 0);
    iota(ALL(ch_deck), 0);
    shuffle(ALL(cc_deck), gen);
    shuffle(ALL(ch_deck), gen);
    int cc_idx = 0, ch_idx = 0;

    const int IT = 10000000;
    for (int i = 0; i < IT; i++) {
        int r1 = d3(gen);
        int r2 = d3(gen);

        if (r1 == r2) {
            doubles_count++;
        } else {
            doubles_count = 0;
        }

        if (doubles_count == 3) {
            current_pos = jail;
            doubles_count = 0;
        } else {
            current_pos = (current_pos + r1 + r2) % N;

            if (board[current_pos] == G2J) {
                current_pos = jail;
            } 
            else if (board[current_pos] == CC) {
                int card = cc_deck[cc_idx];
                cc_idx = (cc_idx + 1) % 16;
                if (card == 0) current_pos = jail;
                else if (card == 1) current_pos = go;
            }
            else if (board[current_pos] == CH) {
                int card = ch_deck[ch_idx];
                ch_idx = (ch_idx + 1) % 16;
                int X = (current_pos - go + N) % N;
                switch (card) {
                    case 0:
                        current_pos = jail;
                        break;
                    case 1:
                        current_pos = go;
                        break;
                    case 2:
                        while (board[current_pos] != RR) current_pos = (current_pos + 1) % N;
                        break;
                    case 3:
                        while (board[current_pos] != RR) current_pos = (current_pos + 1) % N;
                        break;
                    case 4:
                        while (board[current_pos] != UTIL) current_pos = (current_pos + 1) % N;
                        break;
                    case 5:
                        current_pos = (current_pos - 3 + N) % N;
                        break;
                    case 6:
                        current_pos = (current_pos + d4(gen) + d4(gen)) % N;
                        break;
                    case 7:
                        current_pos = (current_pos + (d6(gen) * d6(gen))) % N;
                        break;
                    case 8:
                        current_pos = (current_pos + X) % N;
                        break;
                    case 9:
                        int temp = current_pos;
                        while (board[temp] != RR) temp = (temp + 1) % N;
                        int Y = (temp - go + N) % N;
                        current_pos = (current_pos + 2 * X + Y) % N;
                        break;
                }

                if (board[current_pos] == G2J) current_pos = jail;
            }
        }
        visits[current_pos]++;
    }

    vll res;
    PRIMLOOP(N) {
        res.pb({visits[i], i});
    }

    sort(ALL(res), greater<>());
    for (int i = 0; i < 3; ++i) {
        cout << setfill('0') << setw(2) << res[i].second;
    }
    cout << endl;

    return 0;
}
