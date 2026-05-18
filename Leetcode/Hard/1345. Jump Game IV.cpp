// 1340. Jump Game V
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef unordered_set<int> si;
#define pb push_back

class Solution {
public:
    int minJumps(vector<int>& arr) {
        if (arr.size() <= 1) return 0;

        map<int,vi> graph;
        for (int i = 0; i < arr.size(); i++) {
            graph[arr[i]].pb(i);
        }


        vi curs; curs.pb(0);
        si vis;
        int res = 0;

        vi nex;
        while (!curs.empty()) {
            nex.clear();
            for (int node: curs) {
                if (node == arr.size()-1) return res;

                for (int child: graph[arr[node]]) {
                    if (!vis.count(child))  {
                        vis.insert(child);
                        nex.pb(child);
                    }
                }

                graph[arr[node]].clear();

                if (node + 1 < arr.size() && !vis.count(node+1)) {
                    vis.insert(node + 1);
                    nex.pb(node + 1);
                }
                if (node - 1 >= 0 && !vis.count(node - 1)) {
                    vis.insert(node - 1);
                    nex.pb(node - 1);
                }
            }

            curs = nex;
            ++res;
        }

        return res;
    }
};
