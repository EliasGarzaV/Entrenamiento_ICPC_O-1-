#include "../template.cpp"

const ll inf = LLONG_MAX;

struct Edge {
    int u, v;
    int s() { return u < v ? u : -u; };
    ll w;
};
struct Node {
    ll dist = inf;
    int prev = -1;
};

// shortest path s to all nodes in O(V * E)
void bellmanFord(vector<Node>& nodes, vector<Edge>& edges, int s) {
    nodes[s].dist = 0;
    sort(all(edges), [](Edge a, Edge b) { return a.s() < b.s(); });

    int lim = sz(nodes) / 2 + 2;
    rep(i, 0, lim) for (Edge& e : edges) {
        Node curr = nodes[e.u], &dest = nodes[e.v];
        if (abs(curr.dist) == inf) continue;
        ll d = curr.dist + e.w;
        if (d < dest.dist) {
            dest.prev = e.u;
            dest.dist = (i < lim - 1 ? d : -inf);
        }
    }
    rep(i, 0, lim) for (Edge& e : edges) {
        if (nodes[e.u].dist == -inf) nodes[e.v].dist = -inf;
    }
}
