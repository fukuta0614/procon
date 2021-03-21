// abc192_e
#pragma GCC optimize ("O3")

#include <bits/stdc++.h>
#ifdef LOCAL
#include "../../debug_util/cxx-prettyprint/prettyprint.hpp"
#include "../../debug_util/rng.hpp"
#include "../../debug_util/timer.hpp"
#endif
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

#define REP(i, n) for (int i = 0 ; i < (int)(n) ; ++i)
#define REPN(i, m, n) for (int i = m ; i < (int)(n) ; ++i)
#define REP_REV(i, n) for (int i = (int)(n) - 1 ; i >= 0 ; --i)
#define REPN_REV(i, m, n) for (int i = (int)(n) - 1 ; i >= m ; --i)
#define ALL(x) x.begin(), x.end()

#define INF (ll)(1e18)
#define MOD (1000000007)

#define print2D(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }
#define print_line(vec, n) {for(int idx=0;idx<(n-1);idx++) cout << (vec)[idx] << " "; cout << (vec)[(n)-1] << endl;}
template<class T> void print(const T& x){cout << x << "\n";}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;


struct Graph {

    struct Edge {
        int u, v;
        ll w, k;
        Edge() {}
        Edge(int u, int v, ll w, ll k) : u(u), v(v), w(w), k(k) {}
        friend ostream& operator<<(ostream& os, const Edge& e) {cout << "(" << e.u << "->" << e.v << "," << e.w << ")"; return os;}
    };

    int n;

    vector<vector<Edge>> edges;
    Graph(int n): n(n), edges(n) {}

    void add_edge(int u, int v, ll c, ll k){
        edges[u].emplace_back(u, v, c, k);
        edges[v].emplace_back(v, u, c, k);
    }

    ll dijkstra(int s, int t){

        priority_queue<P, vector<P>, greater<P> > pq;
        pq.push(P(0, s));

        vector<ll> dist(n, INF);
        dist[s] = 0;

        while (!pq.empty()){
            P p = pq.top(); pq.pop();

            ll cost = p.first;
            int u = p.second;

            for (auto edge: edges[u]){
                ll r = cost % edge.k;
                ll ncost = cost + edge.w + (r == 0 ? 0 : edge.k - r);

//                print(u, edge.v, cost, ncost, edge.k, r);

                if (ncost < dist[edge.v]){
                    dist[edge.v] = ncost;
                    pq.emplace(ncost, edge.v);
                }
            }
        }
        return dist[t] == INF ? -1 : dist[t];
    }
};

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N, M, X, Y;
    cin >> N >> M >> X >> Y;
    X--; Y--;

    Graph g(N);

    REP(i, M){
        int a, b, t, k;
        cin >> a >> b >> t >> k;
        a--; b--;
        g.add_edge(a, b, t, k);
    }

    ll ans = g.dijkstra(X, Y);
    print(ans);

    return 0;
}
