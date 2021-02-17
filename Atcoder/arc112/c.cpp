// arc112_c
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
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

struct Graph {

    int n;
    vector<vector<int>> edges;
    vector<int> subtree_size;
    Graph(int n_) : n(n_), edges(n_), subtree_size(n_, 0) {}

    void add_edge(int u, int v) {
        edges[u].emplace_back(v);
    }

    // 部分木の頂点数
    int get_subtree_size(int u) {
        int sz = 1;
        for (auto v: edges[u]) sz += get_subtree_size(v);
        return subtree_size[u] = sz;
    }

    int dfs(int u){

        int ret = 1;

        vector<int> even_bad;
        vector<int> even_good;
        vector<int> odd;
        for (auto v: edges[u]){
            int res = dfs(v);
            if (subtree_size[v] % 2 == 0){
                if (res > 0){
                    even_bad.emplace_back(res);
                } else {
                    even_good.emplace_back(res);
                }
            } else {
                odd.emplace_back(res);
            }
        }
        sort(ALL(odd));
        odd.emplace_back(accumulate(ALL(even_bad), 0));

        ret += accumulate(ALL(even_good), 0);
        REP(i, odd.size()){
            ret += (i % 2 == 0) ? odd[i] : -odd[i];
        }

        return ret;
    }

};

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N;
    cin >> N;
    Graph g(N);
    REPN(i, 1, N){
        int p; cin >> p; p--;
        g.add_edge(p, i);
    }
    g.get_subtree_size(0);
    int ans = (N + g.dfs(0)) / 2;

    print(ans);

    return 0;
}
