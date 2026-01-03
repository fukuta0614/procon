// tessoku_b_068
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

// DAG張り直し用改変
struct SCC {

    int N;
    vector<int> tmp_order;
    vector<int> scc_group;
    vector<bool> used;
    vector<vector<int>> edges, rev_edges;

    SCC(int n): N(n), scc_group(n, -1), used(n), edges(n), rev_edges(n) {}

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
    }

    // 各成分の入次数を計算
    vector<int> scc_indegree;
    void calc_indegree(){

        scc_indegree.assign(K, 0);

        REP(i, K){
            for (auto j: scc_edges[i]){
                scc_indegree[j]++;
            }
        }
    }

    // 068用
    vector<int> scc_score;

    int dfs4(int u) {
        int tmp = scc_score[u];
        for (auto v: scc_edges[u]){
            tmp += dfs4(v);
        }
        return tmp;
    }

    void dfs5(int u){
        used[u] = true;
        for (auto v: scc_edges[u]){
            dfs5(v);
        }
    }


    void func(vector<int>& P) {
        make_dag();
        calc_indegree();

        scc_score.assign(K, 0);
        REP(i, K){
            for (auto v: scc_vertices[i]){
                scc_score[i] += P[v];
            }
        }

        int ans = 0;
        used.assign(K, false);
        REP(i, K) {
            if (used[i]) continue;

            int tmp = dfs4(i);
            if (scc_score[i] > 0 && tmp > 0){
                ans += tmp;
                dfs5(i);
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

    vector<int> P(N);
    REP(i, N) cin >> P[i];

    SCC g(N);
    REP(i, M){
        int s, t;
        cin >> s >> t; s--; t--;
        g.add_edge(s, t);
    }

    g.func(P);

    return 0;
}
