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
    
    return 0;
}
