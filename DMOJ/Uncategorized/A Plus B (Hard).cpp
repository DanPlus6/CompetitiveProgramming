// A Plus B (Hard)
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ALL(x) x.begin(), x.end()
#define LOOP(n) for (int _ = 0; _ < n; _++)

bool isAbsGreaterOrEqual(const string& a, const string& b) {
    if (a.length() != b.length()) return a.length() > b.length();
    return a >= b;
}

string addAbs(string &num1, string &num2) {
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

string subAbs(string a, string b) {
    string res;
    int borrow = 0, i = a.length() - 1, j = b.length() - 1;
    while (i >= 0) {
        int diff = (a[i--] - '0') - borrow - (j >= 0 ? b[j--] - '0' : 0);
        borrow = (diff < 0) ? 1 : 0;
        res.push_back((diff < 0 ? diff + 10 : diff) + '0');
    }
    while (res.length() > 1 && res.back() == '0') res.pop_back(); 
    reverse(res.begin(), res.end());
    return res;
}

string addSigned(string a, string b) {
    bool negA = (a[0] == '-'), negB = (b[0] == '-');
    string absA = negA ? a.substr(1) : a;
    string absB = negB ? b.substr(1) : b;

    if (negA == negB) {
        return (negA ? "-" : "") + addAbs(absA, absB);
    } 
    else {
        if (isAbsGreaterOrEqual(absA, absB)) {
            string res = subAbs(absA, absB);
            return (negA && res != "0") ? "-" + res : res;
        } else {
            string res = subAbs(absB, absA);
            return (negB && res != "0") ? "-" + res : res;
        }
    }
}


/* Orz bruce */
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N; cin >> N;
    string a,b;
    LOOP(N) {
        cin >> a >> b;
        cout << addSigned(a,b) << endl;
    }

    return 0;
}
