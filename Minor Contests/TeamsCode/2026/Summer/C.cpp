// note: solution was only partially accepted
#include <bits/stdc++.h>

using namespace std;

const long long M = 998244353;
const long long I = 1000000000LL;

long long ad(long long a, long long b) {
    return min(I, a + b);
}

long long ml(long long a, long long b) {
    if (a == 0 || b == 0) return 0;
    if (a >= I || b >= I) return I;
    if (a > I / b) return I;
    return min(I, a * b);
}

struct Nd {
    enum { L, C, R } t;
    long long sz = 0, s = 0;

    shared_ptr<vector<long long>> v;
    int a = 0, b = 0;

    Nd* l = nullptr;
    Nd* r = nullptr;

    Nd* ch = nullptr;
    long long cl = 0, cm = 0;
};

Nd* mk_l(shared_ptr<vector<long long>> v, int a, int b, long long s) {
    if (!v || a >= b) return nullptr;
    Nd* n = new Nd();
    n->t = Nd::L;
    n->sz = b - a;
    n->s = (s % M + M) % M;
    n->v = v;
    n->a = a;
    n->b = b;
    return n;
}

Nd* mk_c(Nd* l, Nd* r) {
    if (!l) return r;
    if (!r) return l;
    Nd* n = new Nd();
    n->t = Nd::C;
    n->l = l;
    n->r = r;
    n->sz = ad(l->sz, r->sz);
    n->s = (l->s + r->s) % M;
    return n;
}

Nd* mk_r(Nd* ch, long long cl, long long cm) {
    if (!ch || cl <= 0) return nullptr;
    if (cl == 1) return ch;
    if (ch->t == Nd::R) {
        long long nl = ml(ch->cl, cl);
        long long nm = (ch->cm * (cm % M)) % M;
        return mk_r(ch->ch, nl, nm);
    }
    Nd* n = new Nd();
    n->t = Nd::R;
    n->ch = ch;
    n->cl = cl;
    n->cm = (cm % M + M) % M;
    n->sz = ml(ch->sz, cl);
    n->s = (ch->s * n->cm) % M;
    return n;
}

Nd* pop_f(Nd* u) {
    if (!u) return nullptr;
    if (u->t == Nd::L) {
        long long pv = (*u->v)[u->a];
        long long ns = (u->s - pv % M + M) % M;
        return mk_l(u->v, u->a + 1, u->b, ns);
    }
    if (u->t == Nd::C) {
        Nd* nl = pop_f(u->l);
        return mk_c(nl, u->r);
    }
    if (u->t == Nd::R) {
        Nd* tp = pop_f(u->ch);
        long long rl = (u->cl == I ? I : u->cl - 1);
        long long rm = (u->cm - 1 + M) % M;
        Nd* rr = mk_r(u->ch, rl, rm);
        return mk_c(tp, rr);
    }
    return nullptr;
}

Nd* pop_b(Nd* u) {
    if (!u) return nullptr;
    if (u->t == Nd::L) {
        long long pv = (*u->v)[u->b - 1];
        long long ns = (u->s - pv % M + M) % M;
        return mk_l(u->v, u->a, u->b - 1, ns);
    }
    if (u->t == Nd::C) {
        Nd* nr = pop_b(u->r);
        return mk_c(u->l, nr);
    }
    if (u->t == Nd::R) {
        Nd* tp = pop_b(u->ch);
        long long rl = (u->cl == I ? I : u->cl - 1);
        long long rm = (u->cm - 1 + M) % M;
        Nd* rr = mk_r(u->ch, rl, rm);
        return mk_c(rr, tp);
    }
    return nullptr;
}

void flush(deque<long long>& lb, deque<long long>& rb, long long& ls, long long& rs, Nd*& mt) {
    if (!lb.empty()) {
        auto vec = make_shared<vector<long long>>(lb.begin(), lb.end());
        Nd* ln = mk_l(vec, 0, vec->size(), ls);
        mt = mk_c(ln, mt);
        lb.clear();
        ls = 0;
    }
    if (!rb.empty()) {
        auto vec = make_shared<vector<long long>>(rb.begin(), rb.end());
        Nd* rn = mk_l(vec, 0, vec->size(), rs);
        mt = mk_c(mt, rn);
        rb.clear();
        rs = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    auto iv = make_shared<vector<long long>>(n);
    long long is = 0;
    for (int i = 0; i < n; ++i) {
        cin >> (*iv)[i];
        is = (is + (*iv)[i]) % M;
    }

    Nd* mt = mk_l(iv, 0, n, is);
    deque<long long> lb, rb;
    long long ls = 0, rs = 0;
    bool rev = false;

    int q;
    cin >> q;
    while (q--) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            long long x;
            cin >> x;
            if (!rev) {
                rb.push_back(x);
                rs = (rs + x) % M;
            } else {
                lb.push_front(x);
                ls = (ls + x) % M;
            }
        } else if (tp == 2) {
            if (!rev) {
                if (!rb.empty()) {
                    long long v = rb.back();
                    rb.pop_back();
                    rs = (rs - v % M + M) % M;
                } else if (mt) {
                    mt = pop_b(mt);
                } else if (!lb.empty()) {
                    long long v = lb.back();
                    lb.pop_back();
                    ls = (ls - v % M + M) % M;
                }
            } else {
                if (!lb.empty()) {
                    long long v = lb.front();
                    lb.pop_front();
                    ls = (ls - v % M + M) % M;
                } else if (mt) {
                    mt = pop_f(mt);
                } else if (!rb.empty()) {
                    long long v = rb.front();
                    rb.pop_front();
                    rs = (rs - v % M + M) % M;
                }
            }
        } else if (tp == 3) {
            rev = !rev;
        } else if (tp == 4) {
            flush(lb, rb, ls, rs, mt);
            mt = mk_r(mt, 2, 2);
        } else if (tp == 5) {
            long long ans = (ls + (mt ? mt->s : 0) + rs) % M;
            cout << ans << "\n";
        }
    }

    return 0;
}
