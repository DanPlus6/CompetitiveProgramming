/**
 * Author: DanPlus6 // David Fu
 * Problem Name: 1260. Shift 2D Grid
 * Problem Code: shift-2d-grid
 * Problem URL:  https://leetcode.com/problems/shift-2d-grid/description/
 */
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
#define ALL(x) x.begin(), x.end()

class Solution {
public:
    vvi shiftGrid(vvi &A, int k) {
        int m = A[0].size(); 
        int F = m*A.size(); 
        
        if (!(k %= F)) return A;

        auto rev2d = [&](int l, int r){
            for (; l<r; ++l, --r) {
                swap(
                    A[l/m][l%m],
                    A[r/m][r%m]
                );
            }
        };

        rev2d(0,F-1);
        rev2d(0,k-1);
        rev2d(k,F-1);

        return A;
    }
};

