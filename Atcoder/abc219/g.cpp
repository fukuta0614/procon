// abc219_g
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

    Graph(int n_): n(n_), edges(n_) {}

    void add_edge(int u, int v){
        edges[u].emplace_back(v);
        edges[v].emplace_back(u);
    }
};

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N, M, Q;
    cin >> N >> M >> Q;

    Graph g(N);
    REP(i, M){
        int u, v; cin >> u >> v; u--; v--;
        g.add_edge(u, v);
    }

    int m = sqrt(M);

    vector<vector<int>> big_edges(N);
    REP(i, N){
        for (auto v: g.edges[i]){
            if (g.edges[v].size() >= m){
                big_edges[i].emplace_back(v);
            }
        }
    }

    vector<P> scores(N, {-1, -1});
    REP(i, N) scores[i].second = i;
    vector<P> propagate(N, {-1, -1});

    REP(i, Q){
        int x; cin >> x; x--;

        for (auto v: big_edges[x]){
            if (propagate[v].first > scores[x].first){
                scores[x] = propagate[v];
            }
        }

        if (g.edges[x].size() >= m){
            // 次数が大きいときは、query indexと更新命令を保持
            propagate[x] = {i, scores[x].second};

        } else {
            // 次数が小さいときは、全部更新する。
            for (auto v: g.edges[x]){
                scores[v] = {i, scores[x].second};
            }
        }

//        print(i);
//        auto tmp = scores;
//        REP(j, N) tmp[j].second++;
//        print_line(tmp, N);
//        auto tmp2 = propagate;
//        REP(j, N) tmp2[j].second++;
//        print_line(tmp2, N);
    }


    vector<int> ans(N);
    REP(x, N){
        for (auto v: big_edges[x]){
            if (propagate[v].first > scores[x].first){
                scores[x] = propagate[v];
            }
        }
        ans[x] = scores[x].second + 1;
    }

    print_line(ans, N);

    return 0;
}
