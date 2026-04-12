// A Plus B (Hard)
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ALL(x) x.begin(), x.end()
#define LOOP(n) for (int _ = 0; _ < n; _++)


string addStrings(string &num1, string &num2) {
    int it1 = num1.length()-1, it2 = num2.length()-1;

    string res = "";
    int tmpSum, carry = 0;
    while (it1 >= 0 || it2 >= 0 || carry) {
        tmpSum = ((it1 >= 0)? num1[it1--] - '0' : 0) + ((it2 >= 0)? num2[it2--] - '0' : 0) + carry;

        res += (tmpSum % 10 + '0');
        carry = tmpSum / 10;
    }

    reverse(ALL(res));
    return res;
}

/* Orz bruce */
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N; cin >> N;
    string a,b;
    LOOP(N) {
        cin >> a >> b;
        cout << addStrings(a,b) << endl;
    }

    return 0;
}
