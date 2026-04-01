// A20 Gate
#include <bits/stdc++.h>
// #include <ios>
using namespace std;

int main() {
    int N; cin >> N;
    
    for (int i = 0; i < N; i++) {
        unsigned int adr;
        scanf("%X",&adr);
        if (adr & (1U << 20)) {
            printf("%08X %08X\n", adr ^ (1U << 20), adr);
        } else {
            printf("%08X\n", adr);
        }
    }

    // for (int i = 0; i < N; i++) {
    //     unsigned int adr;
    //     scanf("%X",&adr);
    //     if ((adr >> 20) & 1) {
    //         printf("%08X %08X\n", adr& ~(1 << 20), adr);
    //     } else {printf("%08X\n", adr);}
    // }


    // ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    // int N; cin >> N;
    // for (int i = 0; i < N; i++) {
    //     string adr; cin >> adr;
    //     int addr = stoul(adr,0,16);
    //     int a20 = 0x100000;
    //     if (addr & a20) {
    //         cout << setw(8) << setfill('0') << uppercase << hex << (addr& ~a20);
    //         cout << " " << adr << "\n";
    //     } else {cout << adr << "\n";}
    // }

    return 0;
}
