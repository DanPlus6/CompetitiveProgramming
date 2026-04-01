// USACO 2023 December Bronze P2 - Cowntact Tracing 2
#include <bits/stdc++.h>
using namespace std;


// 🙏
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N; cin >> N;
    string S; cin >> S; set<char> chkSet(S.begin(),S.end());
    if (chkSet == set{'1'}) {cout << 1 << "\n"; return 0;}
    else if (chkSet == set{'0'}) {cout << 0 << "\n"; return 0;}
    
    S.insert(0,"0"); S += "0"; N++;
    vector<int> wlens;
    int l = 0, maxNights = 1e9;
    for (int r = 1; r <= N; r++) {
        if (S[r] != S[r-1]) {
            if (S[r] == '1') l = r;
            else {
                wlens.push_back(r-l);
                if (l == 1 || r == N) maxNights = min(maxNights,r-l-1);
                else {maxNights = min(maxNights,(r-l-1)/2);}
            }
        }
    }

    int res = 0, twoK = maxNights * 2;
    int denom = twoK + 1;
    for (int &wlen: wlens) {res += (wlen + twoK)/denom;}
    cout << res << "\n";


    // USACO's official solution (too lazy to figure this out)
    /*
    // find all the segments/windows
    vector<int> segments;
    int wlen = 0;
    for (int i = 0; i < N; i++){
        if (S[i] == '1') wlen++;
        else{ if (wlen > 0) segments.push_back(wlen); wlen = 0; }
    } if (wlen > 0) segments.push_back(wlen);

    array<int,2> minBlock = {static_cast<int>(1e9),static_cast<int>(1e9)}; // wtf
    int minEnd = static_cast<int>(1e9); // wtf
    int sind = 0; int eind = segments.size()-1;
    if (S[0] == '1') { minEnd = min(minEnd, segments[0]); sind++; }
    if (S[N-1] == '1') { minEnd = min(minEnd, segments[eind]); eind--; }
    for (int i = sind; i <= eind; i++){
        minBlock[segments[i]%2] = min(minBlock[segments[i]%2], segments[i]);
    }
    int denom = min(minEnd*2-1, min(minBlock[0]-1, minBlock[1]));
    int res = 0;
    for (int wlen: segments) res += (wlen+denom-1)/denom;
    cout << res << "\n";
    */


    // y my code no work
    /*
    set<char> chkSet(S.begin(),S.end());
    if (chkSet == set{'1'}) {cout << 1 << "\n"; return 0;}
    else if (chkSet == set{'0'}) {cout << 0 << "\n"; return 0;}

    
    bool iKnowWhatIamDoing = false;
    if (S[0] == '1' || S[N-1] == '1') {
        int maxNights = 0;
        int left = 0;
        for (int i=0;i<N;i++){ if (S[i]=='1')left++; else break; } if (left) left--;
        int right = 0; 
        for (int i=N-1;i>=0;i--){ if (S[i]=='1')right++; else break; } if (right) {right--;}

        if (S[0] == '1' && S[N-1] == '1') maxNights = min(left,right);
        else if (S[0] == '1') maxNights = left;
        else maxNights = right;
        if (maxNights == 0) {iKnowWhatIamDoing = true;}

        if (iKnowWhatIamDoing) {
            cout << count(S.begin(),S.end(),'1') << "\n"; return 0;
        } else {
            int res = 0;
            int wlen = 0;
            int denom = maxNights * 2 + 1;
            for (int i=0;i<N;i++) {
                if (S[i] == '1') wlen++;
                else if (S[i] == '0') {if (wlen) {res += ceil((double)wlen/denom); wlen = 0;}}
                if (i == N1 && wlen) {res += ceil((double)wlen/denom); wlen = 0;}
            }
            cout << res << "\n"; return 0;
        }

    } else {
        int maxNights = 1e9;
        vector<int> wlens;
        int wlen = 0;
        for (int i = 0; i < N; i++) {
            if (S[i] == '1') {wlen++;}
            else if (S[i] == '0') {
                if (!wlen) continue;
                else if (wlen == 1) {iKnowWhatIamDoing = true;}
                else if (!iKnowWhatIamDoing) {maxNights = min(maxNights,int((wlen-1)/2));}
                wlens.push_back(wlen); wlen = 0;
            }
            if (i == N-1 && wlen) {
                maxNights = min(maxNights,int((wlen-1)/2));
                wlens.push_back(wlen);
            }
        }

        int res = 0;
        if (iKnowWhatIamDoing) {
            cout << count(S.begin(),S.end(),'1') << "\n"; return 0;
        } else {
            int denom = maxNights * 2 + 1;
            for (int &i: wlens) { res += ceil((double)i/denom); }
        }
        cout << res << "\n"; return 0;
    }
    */

    return 0;
}
