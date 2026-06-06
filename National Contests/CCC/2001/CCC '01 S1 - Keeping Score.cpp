// CCC '01 S1 - Keeping Score
#include <bits/stdc++.h>
#include <cctype>
using namespace std;

int suits[] = {0,0,0,0};
int ct[] = {0,0,0,0};
int PT(int csuit) {
    if (!ct[csuit]) suits[csuit] += 3;
    if (ct[csuit] == 1) suits[csuit] += 2;
    if (ct[csuit] == 2) suits[csuit] += 1;
    return suits[csuit];
}

int main() {
    string H; cin >> H;

    map<char,int> pt = {{'A',4},{'K',3},{'Q',2},{'J',1}};

    int csuit = -1;
    printf("Cards Dealt              Points\n");
    for (char &c: H) {
        if (c == 'C') { 
            csuit = 0; 
            printf("Clubs "); 
            continue;
        } if (c == 'D') { 
            csuit = 1; 
            printf("%d\n",PT(csuit-1));
            printf("Diamonds "); 
            continue;
        } if (c == 'H') { 
            csuit = 2; 
            printf("%d\n",PT(csuit-1));
            printf("Hearts "); 
            continue;
        } if (c == 'S') { 
            csuit = 3; 
            printf("%d\n",PT(csuit-1));
            printf("Spades "); 
            continue;
        }


        if (pt[c]) suits[csuit] += pt[c];

        if (c == '0') continue;
        if (c == '1') printf("10 ");
        else printf("%c ", c);
        ++ct[csuit];
    }
    printf("%d\n",PT(csuit));
    printf(" Total %d\n", suits[0]+suits[1]+suits[2]+suits[3]);

    return 0;
}
