// aribon4-3_b
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

#define INF ((1 << 29)-1)
#define MOD (1000000007)

#define print2D(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }
#define print_line(vec, n) {for(int i=0;i<(n-1);i++) cout << (vec)[i] << " "; cout << (vec)[(n)-1] << endl;}
template<class T> void print(const T& x){cout << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

// DAG張り直し用改変
struct SCC {

    int N;
    vector<int> tmp_order;
    vector<int> scc_group;
    vector<bool> used;
    vector<vector<int>> edges, rev_edges;

    SCC(int n): N(n), edges(n), rev_edges(n), scc_group(n, -1), used(n) {}

    void add_edge(int u, int v){
        edges[u].emplace_back(v);
        rev_edges[v].emplace_back(u);
    }

    void dfs(int i){
        used[i] = true;
        for (auto v: edges[i]){
            if (used[v]) continue;
            dfs(v);
        }
        tmp_order.emplace_back(i);
    }

    void dfs2(int i, int k){
        used[i] = true;
        scc_group[i] = k;
        for (auto v: rev_edges[i]){
            if (used[v]) continue;
            dfs2(v, k);
        }
    }

    int calc_scc(){

        REP(i, N){
            if (used[i]) continue;
            dfs(i);
        }

        used.assign(N, false);
        int k = 0;
        REP(i, N){
            int v = tmp_order[N-i-1];
            if (used[v]) continue;
            dfs2(v, k++);
        }

        return k;
    }

    // ↓ DAG

    int K;
    vector<vector<int>> scc_edges;
    vector<int> scc_num;
    vector<vector<int>> scc_vertices;

    void dfs3(int i, int k){
        used[i] = true;
        for (auto v: edges[i]){
            if (used[v]) continue;
            int nk = scc_group[v];
            if (nk != k){
                // 別のsccへの辺をはる。すでにはっていなければ
                if (not scc_edges[k].empty() && find(ALL(scc_edges[k]), nk) != scc_edges[k].end()) continue;
                scc_edges[k].emplace_back(nk);
            } else {
                dfs3(v, k);
            }
        }
    }

    void make_dag(){
        K = calc_scc();

        scc_vertices.assign(K, vector<int>());
        REP(i, N) scc_vertices[scc_group[i]].emplace_back(i);

        scc_num.assign(K, 0);
        REP(k, K) scc_num[k] = scc_vertices[k].size();

        used.assign(N, false);
        scc_edges.assign(K, vector<int>());
        REP(k, K){
            int i = scc_vertices[k][0];
            dfs3(i, k);
        }
//        print(edges);
//        print(scc_group);
//
//        print(scc_vertices);
//        print(scc_num);
//        print(scc_edges);
    }
};


struct MinCostFlow {
    struct edge {int to, cap, cost, rev;};
    vector<vector<edge>> G;
    int v_num;

    MinCostFlow(int n): v_num(n), G(n) {}

    void add_edge(int from, int to, int cap, int cost) {
        G[from].emplace_back((edge){to, cap, cost, (int)G[to].size()});
        G[to].emplace_back((edge){from, 0, -cost, (int)G[from].size() - 1});
    }

    int min_cost_flow(int s, int t, int f) {
        int res = 0;


        while (f > 0) {

            vector<int> dist(v_num, INF);
            vector<int> prev_v(v_num, 0), prev_e(v_num, 0);
            dist[s] = 0;

            // Bellman-Ford
            bool update = true;
            while (update) {
                update = false;
                REP(v, v_num) {
                    if (dist[v] == INF) continue;

                    REP(i, G[v].size()) {
                        edge &e = G[v][i];
                        if (e.cap > 0 && dist[e.to] > dist[v] + e.cost) {
                            dist[e.to] = dist[v] + e.cost;
                            prev_v[e.to] = v;
                            prev_e[e.to] = i;
                            update = true;
                        }
                    }
                }
            }

            //
            if (dist[t] == INF){
                return  -1;
            }

            // 最短経路に流す
            int d = f;
            for (int v = t; v != s; v = prev_v[v]){
                d = min(d, G[prev_v[v]][prev_e[v]].cap);
            }

            f -= d;
            res += d * dist[t];
            for (int v = t; v != s; v = prev_v[v]){
                edge &e = G[prev_v[v]][prev_e[v]];
                e.cap -= d;
                G[v][e.rev].cap += d;
            }
        }
        return res;
    }
};

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N;
    cin >> N;

    SCC g(N);
    REP(i, N) REP(j, N){
        int x; cin >> x;
        if (x) g.add_edge(i, j);
    }
    g.make_dag();

    int n = g.K;
    auto edges = g.scc_edges;
    auto scores = g.scc_num;

    MinCostFlow g2(2*n+2);
    int S=2*n, T=S+1;
    REP(i, n) g2.add_edge(S, i, INF, 0);
    REP(i, n) g2.add_edge(n+i, T, INF, 0);
    REP(i, n){
        g2.add_edge(i, i+n, 1, -scores[i]);
        g2.add_edge(i, i+n, INF, 0);
    }
    REP(i, n) for (auto j: edges[i]){
        g2.add_edge(i+n, j, INF, 0);
    }

    int ans = -g2.min_cost_flow(S, T, 2);
    print(ans);

    return 0;
}
