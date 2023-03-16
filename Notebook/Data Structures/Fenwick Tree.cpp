#include "../template.cpp"

#define LSOne(S) ((S) & -(S))
typedef vector<int> vi;

template <class T>
class FenwickTree {
    typedef vector<T> vt;
    vi ft;
    FenwickTree(int m) { ft.assign(m + 1, 0); }
    // f is frequency array
    FenwickTree(const vt &f) { build(f); }
    void build(const vt &f) {
        int m = f.size() - 1;
        ft.assign(m + 1, 0);
        for (int i = 1; i <= m; i++) {
            ft[i] += f[i];
            if (i + LSOne(i) <= m)
                ft[i + LSOne(i)] += ft[i];
        }
    }
    int rsq(int j) {
        int sum = 0;
        for (; j; j -= LSOne(j)) sum += ft[j];
        return sum;
    }
    int rsq(int i, int j) { return rsq(j) - rsq(i - 1); }
    void update(int i, int v) {
        for (; i < ft.size(); i += LSOne(i)) ft[i] += v;
    }
};


template<class T>
class RUPQ {
    FenwickTree<T> ft;
    RUPQ(int m) : ft(FenwickTree<T>(m)) {}
    void range_update(int ui, int uj, int v) {
        ft.update(ui, v);
        ft.update(uj + 1, -v);
    }
    T point_query(int i) { return ft.rsq(i);}
};