// aribon4-3_a
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
};

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N, E;
    cin >> N >> E;

    SCC g(N);
    REP(i, E){
        int s, t;
        cin >> s >> t;
        g.add_edge(s, t);
    }

    g.calc_scc();

    int Q;
    cin >> Q;
    REP(i, Q){
        int u, v;
        cin >> u >> v;
        int ans = int(g.scc_group[u] == g.scc_group[v]);
        print(ans);
    }

    return 0;
}
