// abc067_d
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

template<typename T>
struct LCA {
    int n, log_n;

    vector<vector<int>> to;
    vector<vector<T>> weight;

    vector<int> depth;
    vector<int> subtree_size;
    vector<T> cost;
    vector<vector<int>> par;

    LCA(int n) : n(n), to(n), weight(n), depth(n), cost(n), subtree_size(n) {
        log_n = 0;
        while ((1 << log_n) < n) ++log_n;
        par.assign(n + 1, vector<int>(log_n, n));
    }

    void add_edge(int a, int b, T c = 1) {
        to[a].push_back(b);
        to[b].push_back(a);
        weight[a].push_back(c);
        weight[b].push_back(c);
    }

    int dfs(int v, int d = 0, T c = 0, int p = -1) {
        if (p != -1) par[v][0] = p;
        depth[v] = d;
        cost[v] = c;

        int sz = 1;
        for (int i = 0; i < to[v].size(); ++i) {
            int u = to[v][i];
            if (u == p) continue;
            sz += dfs(u, d + 1, c + weight[v][i], v);
        }
        return subtree_size[v] = sz;
    }

    void init(int root = 0) {
        dfs(root);

        for (int i = 0; i < log_n - 1; ++i) {
            for (int v = 0; v < n; ++v) {
                par[v][i + 1] = par[par[v][i]][i];
            }
        }
    }

    // LCA
    int operator()(int a, int b) {
        if (depth[a] > depth[b]) swap(a, b);

        for (int i = log_n - 1; i >= 0; --i) {
            if (((depth[b] - depth[a]) >> i) & 1) b = par[b][i];
        }

        if (a == b) return a;

        for (int i = log_n - 1; i >= 0; --i) {
            if (par[a][i] != par[b][i]) {
                a = par[a][i];
                b = par[b][i];
            }
        }
        return par[a][0];
    }

    int length(int a, int b) {
        int c = operator()(a, b);
        return depth[a] + depth[b] - depth[c] * 2;
    }

    T dist(int a, int b) {
        int c = operator()(a, b);
        return cost[a] + cost[b] - cost[c] * 2;
    }
};

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N;
    cin >> N;

    LCA<int> g(N);
    REP(i, N-1){
        int a, b;
        cin >> a >> b;
        a--; b--;
        g.add_edge(a, b);
    }
    g.init();

    int lca = g(0, N-1);

    vector<int> path1;
    int v = 0;
    while (v != lca){
        path1.emplace_back(v);
        v = g.par[v][0];
    }

    vector<int> path2;
    v = N-1;
    while (v != lca){
        path2.emplace_back(v);
        v = g.par[v][0];
    }
    reverse(ALL(path2));

    vector<int> path;
    path.insert(path.end(), ALL(path1));
    path.emplace_back(lca);
    path.insert(path.end(), ALL(path2));

    // 最後にfennecが到達する場所
    int idx = ((path.size() + 1) / 2) - 1;


    int p, q;
    if (g.depth[0] <= g.depth[N-1]){ // fennecがlcaを取るパターン
        q = g.subtree_size[path[idx+1]];
        p = N - q;
    } else { // snukeがlcaを取るパターン
        p = g.subtree_size[path[idx]];
        q = N - p;
    }
//    print(lca, path, idx, p, q);

    if (p > q){ // pとqが同じなら、先にとるfennecが負ける
        print("Fennec");
    } else {
        print("Snuke");
    }


    return 0;
}
