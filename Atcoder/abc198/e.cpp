// abc198_e
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
    vector<int> C;

    vector<int> used;
    vector<int> ans;

    Graph(int n_, vector<int>& C) : n(n_), edges(n_), C(C), used(2e5) {

    }

    void add_edge(int u, int v) {
        edges[u].emplace_back(v);
        edges[v].emplace_back(u);
    }

    void dfs(int u, int p = -1){

        if (used[C[u]] == 0){
            ans.emplace_back(u);
        }

        used[C[u]]++;

        for (auto v: edges[u]){
            if (v == p) continue;
            dfs(v, u);
        }

        used[C[u]]--;
    }

};

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N;
    cin >> N;
    vector<int> C(N);
    REP(i, N) cin >> C[i];

    Graph g(N, C);
    REP(i, N-1){
        int a, b;
        cin >> a >> b; a--; b--;
        g.add_edge(a, b);
    }

    g.dfs(0);

    sort(ALL(g.ans));

    for (auto v: g.ans){
        print(v+1);
    }

    return 0;
}
