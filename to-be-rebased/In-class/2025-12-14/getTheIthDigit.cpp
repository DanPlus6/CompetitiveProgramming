#include <bits/stdc++.h>
using namespace std;

long long integer,i;
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << "Input the number: ";
    cin >> integer;
    cout << "Input i: ";
    cin >> i;

    long long base = static_cast<long long>(pow(10,i));
    cout << integer / base % 10;

    return 0;
}
