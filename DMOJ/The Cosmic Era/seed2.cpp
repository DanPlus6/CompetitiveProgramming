// The Cosmic Era P2 - Uneven Sand
#include <bits/stdc++.h>
// #include <cstdio>
// #include <cstring>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int l = 1, r = 2e9, mid;
    string response;
    // int l = 1, r = 2000000000;
    // char response[8];
    while (true) {
        mid = l + (r-l)/2; // mid = (l+r)/2;
        cout << mid << "\n" << flush;
        // int mid = l+(r-l)/2;
        // printf("%d\n",mid);
        // fflush(stdout);

        cin >> response;
        if (response == "SINKS") {l = mid+1;}
        else if (response == "FLOATS") {r = mid-1;}
        // scanf("%s",response);
        // if (!strcmp(response,"SINKS")) l = mid+1;
        // else if (!strcmp(response,"FLOATS")) r = mid-1;
        else break;
    }

    return 0;
}
