#include "../template.cpp"

template <class T>
struct Edge {
    int u, v;
    T weight;
    bool operator<(Edge const& other) { return weight < other.weight; }
};

template <class T>
vector<Edge<T>> kruskal(vector<Edge<T>>& edges, int n) {
    int cost = 0;
    vector<int> tree_id(n);
    vector<Edge> result;
    for (int i = 0; i < n; i++) tree_id[i] = i;

    sort(edges.begin(), edges.end());

    for (Edge& e : edges) {
        if (tree_id[e.u] != tree_id[e.v]) {
            cost += e.weight;
            result.push_back(e);

            int old_id = tree_id[e.u], new_id = tree_id[e.v];
            for (int i = 0; i < n; i++) {
                if (tree_id[i] == old_id) tree_id[i] = new_id;
            }
        }
    }

    return result;
}
