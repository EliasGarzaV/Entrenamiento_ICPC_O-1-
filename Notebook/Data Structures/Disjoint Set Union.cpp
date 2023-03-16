#include "../template.cpp"

class DSU {
   public:
    vector<int> parent, rank;
    DSU(int n) {
        parent = vector<int>(n);
        rank = vector<int>(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int find(int v) {
        return (v == parent[v]) ? v : parent[v] = find(parent[v]);
    }
    void insert(int v) { parent[v] = v; rank[v] = 0; }
    void merge(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (rank[a] < rank[b]) swap(a, b);
            parent[b] = a;
            if (rank[a] == rank[b]) rank[a]++; // size[a] += size[b];
        }
    }
};
