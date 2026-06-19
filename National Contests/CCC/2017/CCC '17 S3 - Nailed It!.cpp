// CCC '17 S3 - Nailed It!
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define FILL(a, b) memset(a, b, sizeof(a))

constexpr int MM = 2005;

int freq[MM], boards[MM*2];

int main() {
    FILL(freq, 0);
    int N; scanf("%d",&N);

    for (int b, _=0;_<N;++_) {
        scanf("%d", &b);
        ++freq[b];
    }

    for (int i=1;i<MM;++i) {
        if (freq[i]) {
            boards[i*2] += freq[i] / 2;

            for (int j=i+1;j<MM;++j) {
                if (freq[j]) boards[i+j] += min(freq[i], freq[j]);
            }
        }
    }

    int maxH = 0, maxCombs = 0;
    for (int h=2;h<MM*2;++h) {
        if (boards[h] > maxH) {
            maxH = boards[h];
            maxCombs = 1;
        } else if (boards[h] == maxH) ++maxCombs;
    }

    printf("%d %d\n", maxH, maxCombs);

    return 0;
}
