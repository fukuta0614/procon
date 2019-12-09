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

    // TPDC R-グラフ用

    int calc(){
        make_dag();

        // 推移閉包
        vector<vector<bool>> reachable(K, vector<bool>(K, false));
        REP(i, K) for (auto v: scc_edges[i]) reachable[i][v] = true;
        REP(k, K) REP(i, K) REP(j, K) {
            reachable[i][j] = reachable[i][j] | (reachable[i][k] & reachable[k][j]);
        }

        scc_num[0] = 0; // ダミー頂点なのでスコアは0にする。

        // dp[i][j] : 頂点0から頂点i, jまでそれぞれ進んだ2つの道のスコアの最大値
        vector<vector<int>> dp(K+1, vector<int>(K+1, 0));
        REP(i, K) REPN(j, i+1, K){
            dp[i][j] = max(dp[i][j], scc_num[i] + scc_num[j]);
            REPN(k, j+1, K){
                if (reachable[i][k]) dp[j][k] = max(dp[j][k], dp[i][j] + scc_num[k]);
                if (reachable[j][k]) dp[i][k] = max(dp[i][k], dp[i][j] + scc_num[k]);

            }
        }

        int ans = 0;
        REP(i, K) REP(j, K){
            ans = max(ans, dp[i][j]);
        }

        return ans;
    }
};



int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N;
    cin >> N;

    SCC g(N+1);
    REP(i, N) REP(j, N){
        int x; cin >> x;
        if (x) g.add_edge(i+1, j+1);
    }

    // 全部に辺を持つダミー頂点を追加
    REPN(i, 1, N+1) {
        g.add_edge(0, i);
    }

    int ans = g.calc();
    print(ans);

    return 0;
}
