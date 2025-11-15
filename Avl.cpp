#include <bits/stdc++.h>
using namespace std;

struct N
{
    int k, h;
    N *l, *r;
    N(int x) : k(x), h(1), l(0), r(0) {}
};
int H(N *n) { return n ? n->h : 0; }
int B(N *n) { return H(n->l) - H(n->r); }

N *Rr(N *y)
{
    N *x = y->l;
    y->l = x->r;
    x->r = y;
    y->h = max(H(y->l), H(y->r)) + 1;
    x->h = max(H(x->l), H(x->r)) + 1;
    return x;
}

N *Rl(N *x)
{
    N *y = x->r;
    x->r = y->l;
    y->l = x;
    x->h = max(H(x->l), H(x->r)) + 1;
    y->h = max(H(y->l), H(y->r)) + 1;
    return y;
}

N *ins(N *n, int k)
{
    if (!n)
        return new N(k);
    if (k < n->k)
        n->l = ins(n->l, k);
    else
        n->r = ins(n->r, k);
    n->h = max(H(n->l), H(n->r)) + 1;
    int b = B(n);
    if (b > 1 && k < n->l->k)
        return Rr(n);
    if (b < -1 && k > n->r->k)
        return Rl(n);
    if (b > 1 && k > n->l->k)
    {
        n->l = Rl(n->l);
        return Rr(n);
    }
    if (b < -1 && k < n->r->k)
    {
        n->r = Rr(n->r);
        return Rl(n);
    }
    return n;
}

N *minN(N *n)
{
    while (n->l)
        n = n->l;
    return n;
}

N *delN(N *n, int k)
{
    if (!n)
        return n;
    if (k < n->k)
        n->l = delN(n->l, k);
    else if (k > n->k)
        n->r = delN(n->r, k);
    else
    {
        if (!n->l)
            return n->r;
        if (!n->r)
            return n->l;
        N *t = minN(n->r);
        n->k = t->k;
        n->r = delN(n->r, t->k);
    }
    n->h = max(H(n->l), H(n->r)) + 1;
    int b = B(n);
    if (b > 1 && B(n->l) >= 0)
        return Rr(n);
    if (b > 1 && B(n->l) < 0)
    {
        n->l = Rl(n->l);
        return Rr(n);
    }
    if (b < -1 && B(n->r) <= 0)
        return Rl(n);
    if (b < -1 && B(n->r) > 0)
    {
        n->r = Rr(n->r);
        return Rl(n);
    }
    return n;
}

void in(N *n, vector<int> &o)
{
    if (n)
    {
        in(n->l, o);
        o.push_back(n->k);
        in(n->r, o);
    }
}

int main()
{
    ifstream f("input.txt");
    int x;
    vector<int> a;
    while (f >> x)
        a.push_back(x);
    f.close();

    N *r = 0;
    for (int v : a)
        r = ins(r, v);

    r = delN(r, 10);
    r = delN(r, 20);

    vector<int> o;
    in(r, o);
    ofstream g("output.txt");
    for (int v : o)
        g << v << " ";
}
