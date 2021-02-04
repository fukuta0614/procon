// abc190_e
#include <bits/stdc++.h>
#ifdef LOCAL
#include "../cxx-prettyprint/prettyprint.hpp"
#endif
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define REP(i, n) for (int (i) = 0 ; (i) < (int)(n) ; ++(i))
#define REPN(i, m, n) for (int (i) = m ; (i) < (int)(n) ; ++(i))
#define REP_REV(i, n) for (int (i) = (int)(n) - 1 ; (i) >= 0 ; --(i))
#define REPN_REV(i, m, n) for (int (i) = (int)(n) - 1 ; (i) >= m ; --(i))
#define ALL(x) x.begin(), x.end()

#define INF (ll)(1e9)
#define MOD (1000000007)

#define print2D(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }
#define print_line(vec, n) {for(int idx=0;idx<(n-1);idx++) cout << (vec)[idx] << " "; cout << (vec)[(n)-1] << endl;}
template<class T> void print(const T& x){cout << x << "\n";}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

typedef pair<ll, int> P;

struct Graph {

    struct Edge {
        int u, v;
        ll w;
        Edge() {}
        Edge(int u, int v, ll w) : u(u), v(v), w(w) {}
        friend ostream& operator<<(ostream& os, const Edge& e) {cout << "(" << e.u << "->" << e.v << "," << e.w << ")"; return os;}
    };

    int n;

    vector<vector<Edge>> edges;
    Graph(int n): n(n), edges(n) {}

    void add_edge(int u, int v, ll c){
        edges[u].emplace_back(u, v, c);
        edges[v].emplace_back(v, u, c);
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

            if (u == t) {
                return cost;
            }

            for (auto edge: edges[u]){

                ll ncost = cost + edge.w;

                if (ncost < dist[edge.v]){
                    dist[edge.v] = ncost;
                    pq.emplace(ncost, edge.v);
                }
            }
        }
        return INF;
    }

    vector<ll> bfs(int s){
        queue<int> q;
        q.emplace(s);

        vector<ll> dist(n, INF);
        dist[s] = 0;

        while (!q.empty()){
            int u = q.front(); q.pop();

            for (auto edge: edges[u]) if (dist[edge.u] + 1 < dist[edge.v]){
                dist[edge.v] = dist[edge.u] + 1;
                q.emplace(edge.v);
            }
        }
        return dist;
    }
};

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N, M;
    cin >> N >> M;
    Graph g(N);
    REP(i, M){
        int a, b; cin >> a >> b;
        a--; b--;
        g.add_edge(a, b, 1);
    }

    int K;
    cin >> K;
    vector<int> C(K);
    REP(i, K) {cin >> C[i]; C[i]--; }

    vector<vector<ll>> dist(K, vector<ll>(K, 0));
    REP(i, K) {
        auto d = g.bfs(C[i]);
        REP(j, K) dist[i][j] = d[C[j]];
    }

//    REP(i, K) print(dist[i]);

    vector<vector<ll>> dp(1 << K, vector<ll>(K, INF));
    REP(i, K) dp[1 << i][i] = 1;

    // 巡回セールスマン
    REP(p, 1 << K) {
        REP(i, K) REP(j, K) {
            if (i == j) continue;
            if ((p >> j) & 1) continue;

            int q = p | (1 << j);
            dp[q][j] = min(dp[q][j], dp[p][i] + dist[i][j]);
        }
    }
    ll ans = INF;
    REP(i, K){
        ans = min(ans, dp[(1<<K)-1][i]);
    }

    print(ans == INF ? -1 : ans);

    return 0;
}
