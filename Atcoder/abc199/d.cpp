// abc199_d
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
//struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;


struct Graph {

    int n;
    vector<vector<int>> edges;

    vector<int> con_graph;
    vector<int> vals;

    vector<vector<int>> con_graph_list;
    ll tmp_ans = 0;

    Graph(int n_) : n(n_), edges(n_), con_graph(n_, -1), vals(n_, -1) {}

    void add_edge(int u, int v) {
        edges[u].emplace_back(v);
        edges[v].emplace_back(u);
    }

    void dfs0(int u, int p, int k){

        con_graph[u] = k;

        for (auto v: edges[u]){
            if (v == p) continue;
            if (con_graph[v] != -1) continue;
            dfs0(v, u, k);
        }
    }

    void dfs(int idx, int k){

        if (idx == con_graph_list[k].size()){
            tmp_ans++;
        } else {

            int u = con_graph_list[k][idx];

            vector<bool> tmp(3);
            for (auto v: edges[u]){
                if (vals[v] == -1) continue;
                tmp[vals[v]] = true;
            }

            REP(i, 3){
                if (tmp[i]) continue;
                vals[u] = i;
                dfs(idx+1, k);
                vals[u] = -1;
            }
        }
    }

    void func(){

        int k = 0;
        REP(i, n){
            if (con_graph[i] != -1) continue;
            dfs0(i, -1, k++);
        }

//        print(k);
        con_graph_list.resize(k);
        REP(u, n){
            con_graph_list[con_graph[u]].emplace_back(u);
        }

//        print(con_graph_list);

        ll ans = 1;

        REP(i, k){
            tmp_ans = 0;
            if (con_graph_list[i].size() == 1){
                ans *= 3;
            } else {
                vals[con_graph_list[i][0]] = 0;
                dfs(1, i);
                ans *= 3 * tmp_ans;
            }
        }

        print(ans);
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
        int a,b;
        cin >> a >> b;
        a--; b--;
        g.add_edge(a, b);
    }

    g.func();


    return 0;
}
