// abc204_c
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
    vector<bool> used;

    Graph(int n_) : n(n_), edges(n_), used(n_) {}

    void add_edge(int u, int v) {
        edges[u].emplace_back(v);
    }

    int dfs(int u){
        used[u] = true;
        int tmp = 1;
        for (auto v: edges[u]){
            if (not used[v]){
                tmp += dfs(v);
            }
        }

        return tmp;
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
        int a, b;
        cin >> a >> b;
        a--; b--;
        g.add_edge(a, b);
    }

    int ans = 0;
    REP(i, N){
        g.used.assign(N, false);
        ans += g.dfs(i);
    }

    print(ans);



    return 0;
}
