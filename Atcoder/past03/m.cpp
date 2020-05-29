// past03_m
#include <bits/stdc++.h>
#ifdef LOCAL
#include "../cxx-prettyprint/prettyprint.hpp"
#endif
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;

#define REP(i, n) for (int (i) = 0 ; (i) < (int)(n) ; ++(i))
#define REPN(i, m, n) for (int (i) = m ; (i) < (int)(n) ; ++(i))
#define REP_REV(i, n) for (int (i) = (int)(n) - 1 ; (i) >= 0 ; --(i))
#define REPN_REV(i, m, n) for (int (i) = (int)(n) - 1 ; (i) >= m ; --(i))
#define ALL(x) x.begin(), x.end()

#define INF (ll)(1e9)
#define MOD (1000000007)

#define print2D(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }
#define print_line(vec, n) {for(int i=0;i<(n-1);i++) cout << (vec)[i] << " "; cout << (vec)[(n)-1] << endl;}
template<class T> void print(const T& x){cout << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

struct Graph {

    int n;
    vector<vector<int>> edges;

    Graph(int n_) : n(n_), edges(n_) {}

    void add_edge(int u, int v) {
        edges[u].emplace_back(v);
        edges[v].emplace_back(u);
    }

    int dijkstra(int s, int t){

        vector<int> dist(n, INF);
        dist[s] = 0;

        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push(P(0, s));

        while (!pq.empty()){

            P p = pq.top(); pq.pop();

            int cost = p.first;
            int u = p.second;

            if (u == t) return cost;

            for (auto v: edges[u]) {
                int ncost = cost + 1;
                if (ncost < dist[v]){
                    dist[v] = ncost;
                    pq.push(P(ncost, v));
                }
            }
        }

        print("impossible");
        return -1;
    }
};


struct Graph2 {

    struct Edge {
        int u, v;
        ll w;
        Edge(int u, int v, ll w) : u(u), v(v), w(w) {}
        friend ostream& operator<<(ostream& os, const Edge& e) {cout << "(" << e.u << "->" << e.v << "," << e.w << ")"; return os;}
    };

    int n;

    vector<vector<Edge>> edges;
    Graph2(int n): n(n), edges(n) {}

    void add_edge(int u, int v, ll c){
        edges[u].emplace_back(u, v, c);
        edges[v].emplace_back(v, u, c);
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
        int u, v;
        cin >> u >> v;
        u--; v--;
        g.add_edge(u, v);
    }

    int s;
    cin >> s;
    s--;

    int K;
    cin >> K;
    vector<int> need_visit(K);
    REP(i, K) {
        cin >> need_visit[i];
        need_visit[i]--;
    }

    // 始点s -> Kとする
    Graph2 g2(K+1);
    REP(i, K) REPN(j, i+1, K){
        int w = g.dijkstra(need_visit[i], need_visit[j]);
        g2.add_edge(i, j, w);
    }
    REP(i, K){
        int w = g.dijkstra(s, need_visit[i]);
        g2.add_edge(K, i, w);
    }

//    print(g2.edges);

//    vector<int> town2idx(N, -1);
//    REP(i, K){
//        town2idx[need_visit[i]] = i;
//    }
    int mx = (1 << K) * (K+1);
    vector<int> dist(mx, INF);
    dist[K] = 0;

    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push(P(0, K));

    while (!pq.empty()){

        P p = pq.top(); pq.pop();

        int cost = p.first;
        int node = p.second;
        int x = node / (K+1);
        int u = node % (K+1);

//        print(x, u, cost);

        if (x == ((1<<K)-1)){
            print(cost);
            return 0;
        }

        for (auto e: g2.edges[u]) {
            int ncost = cost + e.w;
            int nextx = x;
            if (e.v != K){
                nextx |= (1 << e.v);
            }
            int nextp = (K+1) * nextx + e.v;
            if (ncost < dist[nextp]){
                dist[nextp] = ncost;
                pq.push(P(ncost, nextp));
            }
        }
    }




    return 0;
}
