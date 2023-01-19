// arc116_e
#pragma GCC optimize ("O3")

#include <bits/stdc++.h>
#ifdef LOCAL
#include "../../debug_util/cxx-prettyprint/prettyprint.hpp"
#include "../../debug_util/rng.hpp"
#include "../../debug_util/timer.hpp"
#endif
using namespace std;

using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

#define REP(i, n) for (int i = 0 ; i < (int)(n) ; ++i)
#define REPN(i, m, n) for (int i = m ; i < (int)(n) ; ++i)
#define REP_REV(i, n) for (int i = (int)(n) - 1 ; i >= 0 ; --i)
#define REPN_REV(i, m, n) for (int i = (int)(n) - 1 ; i >= m ; --i)
#define ALL(x) x.begin(), x.end()

#define INF (ll)(1e9)
#define MOD (1000000007)

#define print2D(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }
#define print_line(vec, n) {for(int idx=0;idx<(n-1);idx++) cout << (vec)[idx] << " "; cout << (vec)[(n)-1] << endl;}
template<class T> void print(const T& x){cout << x << "\n";}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
//struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

struct Graph {

    int n;
    vector<vector<int>> edges;
    vector<int> depth;
    vector<int> par;
    vector<int> leaves;
    Graph(int n_) : n(n_), edges(n_), depth(n_), par(n_){}

    void add_edge(int u, int v) {
        edges[u].emplace_back(v);
        edges[v].emplace_back(u);
    }

    void dfs(int u = 0, int p = -1, int d = -1){

        depth[u] = d;
        par[u] = p;

        if (edges[u].size() == 1 && edges[u][0] == p){
            leaves.emplace_back(u);
            return;
        }

        for (auto v: edges[u]){
            if (v == p) continue;
            dfs(v, u, depth[u]+1);
        }
    }

    int func(int x){

        vector<bool> done(n, false);

        auto tmp_leaves = leaves;

        int need = 0;
        vector<int> dist(n, INF);
        while (true){
            set<int> nodes;
            for (auto u: tmp_leaves){
                done[u] = true;
                int v = u;
                REP(i, x){
                    v = par[v];
                    done[v] = true;
                }
                nodes.emplace(v);
            }
            print(x, nodes);
            need += nodes.size();
            priority_queue<P, vector<P>, greater<>> pq;

            for (auto u: nodes){
                pq.emplace(0, u);
                dist[u] = 0;
            }
            while (not pq.empty()){
                auto p = pq.top(); pq.pop();
                int d = p.first;
                int u = p.second;

                if (d == x) continue;

                for (auto v: edges[u]){
                    if (done[v]) continue;
                    done[v] = true;
                    if (d + 1 < dist[v]){
                        dist[v] = d + 1;
                        pq.emplace(dist[v], v);
                    }
                }
            }
            vector<int> undone;
            tmp_leaves.clear();
            REP(i, n) if (not done[i]) {
                undone.emplace_back(i);
                bool is_leaf = true;
                for (auto v: edges[i]) {
                    if (v == par[i]) continue;
                    if (not done[v]) {is_leaf = false; break;}
                }
                if (is_leaf){
                    tmp_leaves.emplace_back(i);
                }
            }

            print(undone, tmp_leaves, need);

            if (undone.empty()){
                break;
            }
        }
        print("end", x, need);
        return need;
    }

};


int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N, K;
    cin >> N >> K;
    Graph g(N);
    REP(i, N-1){
        int u, v;
        cin >> u >> v; u--; v--;
        g.add_edge(u, v);
    }

    g.dfs();
    print(g.leaves);

    int ok = N;
    int ng = 0;
    while (ok - ng > 1){
        int x = (ok + ng) / 2;
        if (g.func(x) <= K){
            ok = x;
        } else {
            ng = x;
        }
    }

    int ans = ok;
    print(ans);

    return 0;
}
