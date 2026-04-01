// CCC '08 J1 - Body Mass Index
#include <bits/stdc++.h>
using namespace std;


/* Orz bruce */
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    float w,h; cin >> w >> h;
    float bmi = w/(h*h);
    if (bmi > 25) cout << "Overweight\n";
    else if (bmi >= 18.5 && bmi <= 25.0) cout << "Normal weight\n";
    else if (bmi < 18.5) cout << "Underweight\n";

    return 0;
}

