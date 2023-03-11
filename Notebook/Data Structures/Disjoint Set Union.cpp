#include <vector>
using namespace std;
class DSU {
   public:
    vector<int> parent, size;

    DSU(int n) {
        parent = vector<int>(n);
        size = vector<int>(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int v) {
        return (v == parent[v]) ? v : parent[v] = find(parent[v]);
    }

    void insert(int v) {
        parent[v] = v;
        size[v] = 1;
    }

    void merge(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (size[a] < size[b]) swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }
};
