// License Plates
#include <bits/stdc++.h>
using namespace std;

char alpha[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
#define ALL(x) x.begin(), x.end()
#define LOOP(n) for (int _ = 0; _ < n; _++)
#define PRIMLOOP(N) for (int i = 0; i < N; i++)
#define CLOOP(s) for (char c: s)
typedef vector<int> vi;

/*
 * Complete the 'classifyPlate' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING plate as parameter.
*/
string classifyPlate(string plate) {
    string letters = plate.substr(0, 3);
    string digits_s = plate.substr(3, 4);

    vi d(4);
    PRIMLOOP(4) d[i] = digits_s[i] - '0';

    string res = "";

    bool firstHalf = true, secondHalf = true;
    CLOOP(letters) {
        if(c < 'A' || c > 'M') firstHalf = false;
        if(c < 'N' || c > 'Z') secondHalf = false;
    }
    if (firstHalf) res += 'B';
    if (secondHalf) res += 'E';

    bool incL = (letters[1] == letters[0] + 1 && letters[2] == letters[1] + 1);
    bool decL = (letters[1] == letters[0] - 1 && letters[2] == letters[1] - 1);
    bool incD = (d[1] == d[0] + 1 && d[2] == d[1] + 1 && d[3] == d[2] + 1);
    bool decD = (d[1] == d[0] - 1 && d[2] == d[1] - 1 && d[3] == d[2] - 1);

    if ((incL || decL) ^ (incD || decD)) {
        if (incL || incD) res += 'I';
        if (decL || decD) res += 'D';
    }

    bool isHex = true;
    for (char c : letters) if(c > 'F') isHex = false;
    if (isHex) res += 'H';

    bool isOctal = (digits_s[0] != '0');
    for( int val : d) if(val > 7) isOctal = false;
    if(isOctal) res += 'O';

    bool palL = (letters[0] == letters[2]);
    bool palD = (d[0] == d[3] && d[1] == d[2]);
    if (palL || palD) res += 'P';

    bool repL = (letters[0] == letters[1] || letters[0] == letters[2] || letters[1] == letters[2]);
    bool repD = false;
    for (int i=0; i<4; i++) 
        for (int j=i+1; j<4; j++) 
            if (d[i] == d[j]) repD = true;
    if (repL || repD) res += 'R';

    if ((d[0]+d[1]+d[2] == d[3]) || (d[0]+d[1]+d[3] == d[2]) || 
       (d[0]+d[2]+d[3] == d[1]) || (d[1]+d[2]+d[3] == d[0])) {
        res += 'S';
    }

    if (res.empty()) return "NONE";
    sort(ALL(res));
    return res;
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    string plate;
    getline(cin, plate);

    string result = classifyPlate(plate);

    fout << result << "\n";

    fout.close();

    return 0;
}
