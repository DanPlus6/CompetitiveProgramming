// 3121. Count the Number of Special Characters II
#include <bits/stdc++.h>
using namespace std;

char alphal[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
char alphau[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

class Solution {
public:
    static int numberOfSpecialChars(string word) {
        unordered_map<char,int> idx = {{'A',-1},{'B',-1},{'C',-1},{'D',-1},{'E',-1},{'F',-1},{'G',-1},{'H',-1},{'I',-1},{'J',-1},{'K',-1},{'L',-1},{'M',-1},{'N',-1},{'O',-1},{'P',-1},{'Q',-1},{'R',-1},{'S',-1},{'T',-1},{'U',-1},{'V',-1},{'W',-1},{'X',-1},{'Y',-1},{'Z',-1},{'a',INT_MAX},{'b',INT_MAX},{'c',INT_MAX},{'d',INT_MAX},{'e',INT_MAX},{'f',INT_MAX},{'g',INT_MAX},{'h',INT_MAX},{'i',INT_MAX},{'j',INT_MAX},{'k',INT_MAX},{'l',INT_MAX},{'m',INT_MAX},{'n',INT_MAX},{'o',INT_MAX},{'p',INT_MAX},{'q',INT_MAX},{'r',INT_MAX},{'s',INT_MAX},{'t',INT_MAX},{'u',INT_MAX},{'v',INT_MAX},{'w',INT_MAX},{'x',INT_MAX},{'y',INT_MAX},{'z',INT_MAX}};
        
        for (int i = 0; i < word.length(); i++) {
            if (idx[word[i]] == -1) idx[word[i]] = i;
            else if (islower(word[i])) idx[word[i]] = i;
        }

        int res = 0;
        for (int i = 0; i < 26; i++) {
            if (idx[alphal[i]] < idx[alphau[i]]) ++res;
        }

        return res;
    }
};

