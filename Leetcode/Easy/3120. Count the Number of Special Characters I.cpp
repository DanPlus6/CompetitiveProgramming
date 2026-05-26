// 3120. Count the Number of Special Characters I
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {
        map<char,bool> seen;
        int res = 0;
        for (int i = 0; i < word.length(); i++) {
            char upper = toupper(word[i]), lower = tolower(word[i]);
            if (
                ((word[i] == upper && seen[lower]) ||
                (word[i] == lower && seen[upper]))
                &&
                !seen[word[i]]
            ) ++res;
            seen[word[i]] = true;
        }
        return res;
    }
};
