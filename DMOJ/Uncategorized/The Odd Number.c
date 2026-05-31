// The Odd Number - odd
#include <stdio.h>

int main() {
    int n; scanf("%d",&n);
    int res = 0;
    for (int x; n--;) {
        scanf("%d",&x);
        res ^= x;
    }

    printf("%d\n",res);

    return 0;
}
