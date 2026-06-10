// 2196. Create Binary Tree From Descriptions
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* createBinaryTree(vector<vi> &D) {
        unordered_map<int, TreeNode*> nodes;
        int root = 0;

        for (vi &d: D) {
            int p = d[0], c = d[1], l = d[2];
            if (!nodes.contains(p)) {
                nodes[p] = new TreeNode(p);
                root ^= p;
            }
            if (!nodes.contains(c)) {
                nodes[c] = new TreeNode(c);
                root ^= c;
            }

            if (l) nodes[p]->left = nodes[c];
            else nodes[p]->right = nodes[c];
            root ^= c;
        }

        return nodes[root];
    }
};
        
