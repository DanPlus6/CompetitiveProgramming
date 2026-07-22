/**
 * Author: DanPlus6 // David Fu
 * Problem Name: DMOPC '21 Contest 7 P2 - Knitting Scarves
 * Problem Code: dmopc21c7p2
 * Problem URL:  https://dmoj.ca/problem/dmopc21c7p2
 */
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node *prev;
    Node *next;

    Node() : val(-1), prev(nullptr), next(nullptr) {}
    Node(int v) : val(v), prev(nullptr), next(nullptr) {}
    Node(int x, Node *prev) : val(x), prev(prev), next(nullptr) {}
    Node(int x, Node *prev, Node *next) : val(x), prev(prev), next(next) {}

    Node *fwd(int n) {
        Node* cur = this;
        while (n-- && cur) cur = cur->next;
        return cur;
    }

    Node *bwd(int n) {
        Node* cur = this;
        while (n-- && cur) cur = cur->prev;
        return cur;
    }

    Node* find(int v) {
        for (Node *cur = this; cur; cur = cur->next) {
            if (cur->val == v) return cur;
        }
        return nullptr;
    }
};

int main() {
    int N,Q; scanf("%d %d",&N,&Q);
    if (N == 1) { printf("1\n"); return 0; }

    Node *head = new Node();
    Node *tail = head;
    vector<Node*> scarf(N+1); scarf[0] = head;
    for (int i=1;i<=N;++i) {
        Node *new_node = new Node(i);
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
        scarf[i] = new_node;
    }
    tail->next = new Node();
    tail->next->prev = tail;
    tail = tail->next;

    for (int l,r,k; Q--;) {
        scanf("%d %d %d",&l,&r,&k);
        Node *pos = scarf[k];
        Node *lft = scarf[l];
        Node *rit = scarf[r];

        rit->next->prev = lft->prev;
        lft->prev->next = rit->next;

        pos->next->prev = rit;
        rit->next = pos->next;

        pos->next = lft;
        lft->prev = pos;
    }

    for (head = head->next; head != tail; head = head -> next) {
        printf("%d%c",head->val, (head->next!=tail)?' ':'\n');
    }

    return 0;
}
