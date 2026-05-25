// CCC '02 S2 - Fraction Action
#include <bits/stdc++.h>
using namespace std;

int X,Y;
int main() {
    scanf("%d\n%d",&X,&Y);

    if (X % Y == 0) { printf("%d\n",X/Y); return 0; }
    if (X == Y) { printf("%d\n",1); return 0; }
    if (X == 0) { printf("0\n"); return 0; }

    if (X > Y) {
        int whole = X/Y;
        int num = X - Y*whole;
        int gcd = __gcd(num,Y);
        if (gcd == 1) printf("%d %d/%d\n", whole, num, Y);
        else printf("%d %d/%d\n", whole, num/gcd, Y/gcd);
    } else {
        int gcd = __gcd(X,Y);
        printf("%d/%d\n", X/gcd, Y/gcd);
    }

    return 0;
}
