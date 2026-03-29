// 451. Sort Characters By Frequency
#include <bits/stdc++.h>
using namespace std;

typedef pair<char,int> myPair;
#define LOOP(n) for (int _ = 0; _ < n; _++)
#define ALL(x) x.begin(), x.end()
#define CLOOP(s) for (char c: s)
#define pb push_back


class Solution {
public:
    static string frequencySort(string &s) {
        string res = "";

        vector<myPair> resFreq; {
            map<char,int> freq;
            CLOOP(s) freq[c]++;

            for (auto &[c,f]: freq) resFreq.pb({c,f});
            sort(ALL(resFreq), [](myPair a, myPair b){return a.second > b.second;});
        }

        for (auto &[c,f]: resFreq) LOOP(f) res += c;

        return res;
    }
};

