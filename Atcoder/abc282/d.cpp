// abc282_d
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

#define INF (ll)(1e15)
#define MOD (1000000007)

#define print2D(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }
#define print_line(vec, n) {for(int idx=0;idx<(n-1);idx++) cout << (vec)[idx] << " "; cout << (vec)[(n)-1] << endl;}
template<class T> void print(const T& x){cout << x << "\n";}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

struct Graph {

    int n;
    vector<vector<int>> edges;
    vector<int> color;
    bool not_bipartite = false;

    ll count[2];

    Graph(int n_) : n(n_), edges(n_), color(n_, -1) {}

    void add_edge(int u, int v) {
        edges[u].emplace_back(v);
        edges[v].emplace_back(u);
    }

    void dfs(int u, int c){

        if (color[u] != -1){
            if (color[u] != c){
                not_bipartite = true;
            }
            return;
        }
        color[u] = c;
        count[c]++;

        for (auto v: edges[u]){
            dfs(v, 1 - c);
        }
    }

};
int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    ll N, M;
    cin >> N >> M;
    Graph g(N);
    REP(i, M) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        g.add_edge(u, v);
    }

    ll ans = N * (N-1) / 2 - M;
    REP(i, N){
        if (g.color[i] == -1){
            g.count[0] = g.count[1] = 0;
            g.dfs(i, 0);

            if (g.not_bipartite){
                print(0);
                return 0;
            }
            ans -= g.count[0] * (g.count[0] - 1) / 2;
            ans -= g.count[1] * (g.count[1] - 1) / 2;
        }
    }
    print(ans);


    return 0;
}
