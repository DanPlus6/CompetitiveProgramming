/**
 * Author: DanPlus6 // David Fu
 * Problem Name: 3517. Smallest Palindromic Rearrangement I
 * Problem URL:  https://leetcode.com/problems/smallest-palindromic-rearrangement-i/description/
 * Problem Code: smallest-palindromic-rearrangement-i
 */
#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")

typedef vector<int> vi;
#define ALL(x) x.begin(), x.end()
#define LOOP(n) for (int _ = 0; _ < n; _++)

class Solution {
public:
    string smallestPalindrome(string &s) {
        vi freq(26,0);
        for (char &c: s) ++freq[c-'a'];

        char mid; string res = "";
        for (int i=0;i<26;++i) {
            printf("%c\n",i+'a');
            if (freq[i]&1) mid = i+'a';
            LOOP(freq[i]/2) res += i+'a';
        }

        sort(ALL(res));
        string mirror(res.rbegin(),res.rend());
        if (s.length()&1) res += mid;
        res += mirror;
        return res;
    }
};
