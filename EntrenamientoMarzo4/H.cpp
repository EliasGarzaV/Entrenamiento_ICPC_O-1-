#include <algorithm>
#include <math.h>
#include <cstdio>
#include <deque>
#include <iomanip>
#include <iostream>
#include <queue>
#include <map>
#include <list>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <cstring>
#include <climits>
#define ll long long
#define ull unsigned long long
#define FOR(m,s,n,u) for(int m=s; m<n; m+=u)
#define ROF(m,s,n,u) for(int m=n; m>=s; m-=u)
#define FORb(m,s,n,u,k) for(int m=s; m<n&&k; m+=u)
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define PI 3.1415926535897932384626433832795028841971
#define INF 0x3f3f3f3f
#define EPS 1e-9
#define MOD(x) ((x%mod)+mod)%mod
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vi vector<int>
#define pii pair<int,int>
#define min(a,b) a<b?a:b
using namespace std;

typedef vector<long long> VD;
typedef vector<VD> VVD;
typedef vector<long long> VI;

long long MinCostMatching(const vector<vector<long long> > &cost, VI &Lmate, VI &Rmate) {
    int n = int(cost.size());
    // construct dual feasible solution
    VD u(n);
    VD v(n);
    for (int i = 0; i < n; i++) {
        u[i] = cost[i][0];
        for (int j = 1; j < n; j++) u[i] = min(u[i], cost[i][j]);
    }
    for (int j = 0; j < n; j++) {
        v[j] = cost[0][j] - u[0];
        for (int i = 1; i < n; i++) v[j] = min(v[j], cost[i][j] - u[i]);
    }
    // construct primal solution satisfying complementary slackness
    Lmate = VI(n, -1);
    Rmate = VI(n, -1);
    int mated = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (Rmate[j] != -1) continue;
                if (fabs(cost[i][j] - u[i] - v[j]) < 1e-10) {
                Lmate[i] = j;
                Rmate[j] = i;
                mated++;
                break;
            }
        }
    }
    VD dist(n);
    VI dad(n);
    VI seen(n);
    // repeat until primal solution is feasible
    while (mated < n) {
        // find an unmatched left node
        int s = 0;
        while (Lmate[s] != -1) s++;
        // initialize Dijkstra
        fill(dad.begin(), dad.end(), -1);
        fill(seen.begin(), seen.end(), 0);
        for (int k = 0; k < n; k++)
        dist[k] = cost[s][k] - u[s] - v[k];
        int j = 0;
        while (true) {
            // find closest
            j = -1;
            for (int k = 0; k < n; k++) {
                if (seen[k]) continue;
                if (j == -1 || dist[k] < dist[j]) j = k;
            }
            seen[j] = 1;
            // termination condition
            if (Rmate[j] == -1) break;
            // relax neighbors
            const int i = Rmate[j];
            for (int k = 0; k < n; k++) {
                if (seen[k]) continue;
                const double new_dist = dist[j] + cost[i][k] - u[i] - v[k];
                if (dist[k] > new_dist) {
                    dist[k] = new_dist;
                    dad[k] = j;
                }
            }
        }
        // update dual variables
        for (int k = 0; k < n; k++) {
            if (k == j || !seen[k]) continue;
            const int i = Rmate[k];
            v[k] += dist[k] - dist[j];
            u[i] -= dist[k] - dist[j];
        }
        u[s] += dist[j];
        // augment along path
        while (dad[j] >= 0) {
            const int d = dad[j];
            Rmate[j] = Rmate[d];
            Lmate[Rmate[j]] = j;
            j = d;
        }
        Rmate[j] = s;
        Lmate[s] = j;
        mated++;
    }
    double value = 0;
    for (int i = 0; i < n; i++)
    value += cost[i][Lmate[i]];
    return value;
}



int main() {

    sync;

    int n; cin>>n;

    vector<vector<long long>> adj(n, vector<long long>(n));
    vector<vector<long long>> cost;

    for(int i = 0; i < n; i++){
        if(i % 2 == 0){
            cost.push_back(vector<long long>());
        }
        for(int j = 0; j <n; j++){


            cin >> adj[i][j];

            if( i % 2 == 0 && j % 2 == 1){
                ull costo = adj[i][j];
                if(j > 1){
                    costo += adj[i][j - 2];
                }
                cost[i / 2].push_back(costo);
            }
        }

        if( n % 2 == 1 && i % 2 == 0){
            cost[i / 2].pb(adj[i][n - 2]);
        }
    }

   


/*

4
0 3 2 13
3 0 8 9
2 8 0 5
13 9 5 0


5
0 14 11 1 15
14 0 1 11 1
11 1 0 13 12
1 11 13 0 1
15 1 12 1 0


    

    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < n - 2; j++) {
            cout << cost[i][j] << " ";
        }
        cout << endl;
    }
      */
    VI L;
    VI R;

    cout << MinCostMatching(cost, L, R )<< endl;
  

    return 0;
}


