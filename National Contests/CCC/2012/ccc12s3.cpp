// CCC '12 S3 - Absolutely Acidic
#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;
typedef vector<int> vi;
typedef priority_queue<int> max_ipq;
typedef priority_queue<int, vi, greater<int>> min_ipq;
#define ALL(x) x.begin(), x.end()
#define endl '\n'
#define ILOOP(n) for (int i = 0; i < n; i++)
#define pb push_back


int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    map<int,int> ct;
    ILOOP(N) {
        int r; cin >> r;
        ct[r]++;   
    }

    map<int,pair<max_ipq,min_ipq>> nums_by_freq;
    max_ipq freqs;
    for (pi cpair: ct) {
        int freq = cpair.second, num = cpair.first;
        freqs.push(freq);
        nums_by_freq[freq].first.push(num);
        nums_by_freq[freq].second.push(num);
    }
    
    if (nums_by_freq[freqs.top()].first.size() > 1) {
        cout << nums_by_freq[freqs.top()].first.top() - nums_by_freq[freqs.top()].second.top() << endl;
    } else {
        int mfreq = nums_by_freq[freqs.top()].first.top(); freqs.pop();
        auto smfreq = nums_by_freq[freqs.top()];
        
        int topsfreq = abs(mfreq - smfreq.first.top());
        int botsfreq = abs(mfreq - smfreq.second.top());
        cout << max(topsfreq,botsfreq) << endl;
    }

    return 0;
}
