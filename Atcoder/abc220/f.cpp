// abc220_f
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

    vector<ll> par, depth, subsum, subsize;
    vector<ll> ans;
    vector<vector<int>> subsum_list, subsize_list;

    explicit Graph(int n_): n(n_), edges(n_), par(n_), depth(n_), subsum(n_), subsize(n_), ans(n_), subsum_list(n_), subsize_list(n_) {}

    void add_edge(int u, int v){
        edges[u].emplace_back(v);
        edges[v].emplace_back(u);
    }

    void dfs(int u, int p = -1){

        par[u] = p;
        if (p != -1){
            depth[u] = depth[p] + 1;
        }


        for (auto v: edges[u]){
            if (v == p) continue;

            dfs(v, u);
            subsum[u] += subsum[v] + subsize[v] + 1;
            subsize[u] += subsize[v] + 1;
        }
    }


    void dfs2(int u, int p = -1){

        if (p == -1){
            ans[u] = subsum[u];
        } else {

            ans[u] += subsum[u];
            ans[u] += ans[p] - (subsum[u] + subsize[u] + 1) + (n - 1 - subsize[u]);
        }

        for (auto v: edges[u]){
            if (v == p) continue;
            dfs2(v, u);
        }
    }
};

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N;
    cin >> N;

    Graph g(N);
    REP(i, N-1){
        int u, v; cin >> u >> v; u--; v--;
        g.add_edge(u, v);
    }

    g.dfs(0);
    g.dfs2(0);

//    print(g.par);
//    print(g.subsize);
//    print(g.subsum);


    REP(i, N){
        print(g.ans[i]);
    }

    return 0;
}
