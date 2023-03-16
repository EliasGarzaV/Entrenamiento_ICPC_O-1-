
#include <queue>

#include "../template.cpp"

const int INF = 2000000000;

template <class TDist>
using w_edge = pair<TDist, int>;
template <class TDist>
using edge_arr = vector<vector<TDist>>;

template <class TDist>
TDist dijkstra(edge_arr<TDist> graph, int n, int src, int target) {
    priority_queue<pii, vector<edge>, greater<edge>> pq;
    vector<TDist> dist(n, INF);
    vi trace(n, -1);
    pq.push(make_pair(0, src));
    dist[s] = 0;
    while (!pq.empty()) {
        w_edge top = pq.top();
        pq.pop();
        int here = top.snd;
        if (here == target) break;
        if (dist[here] != top.fst) continue;

        for (auto& edge : graph) {
            if (dist[here] + edge.fst < dist[edge.snd]) {
                dist[edge.snd] = dist[here] + edge.fst;
                trace[eddge.snd] = here;
                pq.push(make_pair(dist[edge.snd], edge.snd));
            }
        }
    }
}
