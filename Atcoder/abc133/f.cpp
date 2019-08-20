// abc133_f
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
template<class T> void print(const T& x){cout << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
//struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

struct Edge {
    int to, color, weight;
    Edge(int to, int color, int weight):to(to),weight(weight),color(color) {}
};
ostream &operator<<(ostream &os, const Edge &e) {
    return os << '(' << e.to << ',' << e.color << ',' << e.weight << ')';
}

struct LCA {
    int n, log_n;

    vector<vector<Edge>> G;

    vector<int> depth;
    vector<int> cost;
    vector<vector<int>> par;

    vector<Edge> euler_tour;
    vector<Edge> euler_tour_num;
    vector<int> begin_indices;
    vector<vector<P>> euler_tour_list;
    vector<vector<P>> euler_tour_list_num;

    LCA(int n) : n(n), G(n), depth(n), cost(n), begin_indices(n), euler_tour_list(n), euler_tour_list_num(n) {
        log_n = 0;
        while ((1 << log_n) < n) ++log_n;
        par.assign(n + 1, vector<int>(log_n, n));
    }

    void add_edge(int a, int b, int c, int d) {
        G[a].emplace_back(b, c, d);
        G[b].emplace_back(a, c, d);
    }

    void dfs(int v, int d = 0, int c = 0, int p = -1) {
        if (p != -1) par[v][0] = p;
        depth[v] = d;
        cost[v] = c;
        for (int i = 0; i < G[v].size(); ++i) {
            Edge e = G[v][i];

            if (e.to == p) continue;

            begin_indices[e.to] = (int)euler_tour.size();
            euler_tour.emplace_back(e);
            euler_tour_num.emplace_back(e.to, e.color, +1);

            dfs(e.to, d + 1, c + e.weight, v);

            e.weight *= -1;
            euler_tour.emplace_back(e);
            euler_tour_num.emplace_back(e.to, e.color, -1);
        }
    }

    void init(int root = 0) {
        dfs(root);

        for (int i = 0; i < log_n - 1; ++i) {
            for (int v = 0; v < n; ++v) {
                par[v][i + 1] = par[par[v][i]][i];
            }
        }

        vector<int> cumsum(n, 0);
        vector<int> cumsum_num(n, 0);
        REP(i, euler_tour.size()) {
            auto e = euler_tour[i];

            cumsum[e.color] += e.weight;
            cumsum_num[e.color] += euler_tour_num[i].weight;

            euler_tour_list[e.color].emplace_back(i, cumsum[e.color]);
            euler_tour_list_num[e.color].emplace_back(i, cumsum_num[e.color]);
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

    int dist(int a, int b) {
        int c = operator()(a, b);
        return cost[a] + cost[b] - cost[c] * 2;
    }

    int changed_cost(int x, int c, int y){
        if (x == 0) return 0;

        if (euler_tour_list[c].empty()){
            return cost[x];
        }

        int idx = begin_indices[x];
        auto it = upper_bound(ALL(euler_tour_list[c]), P(idx,INF)) - 1;
        int sum_c = it->second;
        auto it2 = upper_bound(ALL(euler_tour_list_num[c]), P(idx,INF)) - 1;
        int num_c = it2->second;

        return cost[x] - sum_c + num_c * y;
    }

    int changed_dist(int x, int y, int u, int v){
        int c = operator()(u, v);
        return changed_cost(u, x, y) + changed_cost(v, x, y) - 2 * changed_cost(c, x, y);
    }

};


int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N, Q;
    cin >> N >> Q;

    auto g = LCA(N);
    REP(i, N-1){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        a--; b--; c--;
        g.add_edge(a, b, c, d);
    }
    g.init();


    REP(i, Q){
        int x, y, u, v;
        cin >> x >> y >> u >> v;
        x--; u--; v--;

        int ans = g.changed_dist(x, y, u, v);
        print(ans);
    }

    return 0;
}
