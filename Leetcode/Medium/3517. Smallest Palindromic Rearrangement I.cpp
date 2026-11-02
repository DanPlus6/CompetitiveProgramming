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
#define LOOP(n) for (int _ = 0; _ < n; _++)

class Solution {
public:
    string smallestPalindrome(string s) {
        int N = s.length(), freq[26]{};
        for (int i=0;i<(N>>1);++i) ++freq[s[i]-'a'];

        for (int i=0,c=0; c<26; ++c) {
            for (;freq[c]--; ++i) {
                s[i] = c+'a';
                s[N-i-1] = c+'a';
            }
        }

        return s;
    }
};
