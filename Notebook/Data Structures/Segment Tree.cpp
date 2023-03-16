#include "../template.cpp"
#define MAXN 1000000

template <class T>
class SegmentTree {
    typedef vector<T> vt;
    vt tree;
    SegmentTree() : tree(vt(4 * MAXN)) {}
    SegmentTree(vt a) : tree(vt(4 * a.size())) {}
    void build(vt a, int v, int tl, int tr) {
        if (tl == tr) {
            tree[v] = a[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(a, v * 2, tl, tm);
            build(a, v * 2 + 1, tm + 1, tr);
            tree[v] = tree[v * 2] + tree[v * 2 + 1];
        }
    }
    T sum(int v, int tl, int tr, int l, int r) {
        if (l > r) return 0;
        if (l == tl && r == tr) {
            return tree[v];
        }
        int tm = (tl + tr) / 2;
        return sum(v * 2, tl, tm, l, min(r, tm)) +
               sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    }
    void update(int v, int tl, int tr, int pos, T new_val) {
        if (tl == tr) {
            tree[v] = new_val;
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(v * 2, tl, tm, pos, new_val);
            else
                update(v * 2 + 1, tm + 1, tr, pos, new_val);
            tree[v] = tree[v * 2] + tree[v * 2 + 1];
        }
    }
};