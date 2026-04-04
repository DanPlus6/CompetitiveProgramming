// CCC '23 J3 - Special Event
#include <bits/stdc++.h>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    // orz my brother catcatcats
    array<int,5> days = {0,0,0,0,0};
    vector<int> best;
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        for (int j = 0; j < 5; j++) {if (s[j] == 'Y') days[j]++;}
    }

    int high = 0;
    for (int i = 0; i < 5; i++) {
        if (days[i] > high) {
            high = days[i];
            best.clear();
            best.push_back(i+1);
        } else if (days[i] == high) {
            best.push_back(i+1);
        }
    }

    for (int i = 0, M = best.size()-1; i <= M; i++) {
        cout << best[i];
        if (i != M) {
            cout << ",";
        }
    }


    // lwk might've overcomplicated it
    // map<int,int> days = {{0,0},{1,0},{2,0},{3,0},{4,0}};
    // for (int i = 0; i < N; i++) {
    //     string ln; cin >> ln;
    //     for (int j = 0; j < 5; j++) {if (ln[j] == 'Y') days[j]++;}
    // }

    // vector<pair<int,int>> toSort(days.begin(),days.end());
    // sort(toSort.begin(),toSort.end(),[](pair<int,int> &a, pair<int,int> &b){return a.second < b.second;});

    // for (int i = 0; i < 4; i++) {if (toSort[i].second == toSort[4].second) cout << toSort[i].first+1 << ",";}
    // cout << toSort[4].first+1 << "\n";

    return 0;
}
