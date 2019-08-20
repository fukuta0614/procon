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
#define ALL(x) x.begin(), x.end()

#define INF ((1 << 29)-1)
#define MOD (1000000007)

template<class T> void print(const T& x){cout << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

struct Edge {
    int to, color, weight;
    Edge(int to, int color, int weight):to(to),weight(weight),color(color) {}
};
ostream &operator<<(ostream &os, const Edge &e) {
    return os << '(' << e.to << ',' << e.color << ',' << e.weight << ')';
}

struct Query {
    int qid, color, coeff, y;
    Query(int qid, int color, int coeff, int y) : qid(qid), color(color), coeff(coeff), y(y){}
};

struct LCA {
    int n, log_n;

    vector<vector<Edge>> G;

    vector<int> depth;
    vector<int> cost;
    vector<vector<int>> par;

    int q_num = 0;
    vector<vector<Query>> qs;
    vector<int> color_cost;
    vector<int> color_num;

    vector<int> ans;

    LCA(int n) : n(n), G(n), depth(n), cost(n), qs(n), color_cost(n), color_num(n){
        log_n = 0;
        while ((1 << log_n) < n) ++log_n;
        par.assign(n + 1, vector<int>(log_n, n));
    }

    void add_edge(int a, int b, int c, int d) {
        G[a].emplace_back(b, c, d);
        G[b].emplace_back(a, c, d);
    }

    void add_query(int x, int y, int u, int v) {
        qs[u].emplace_back(q_num, x, 1, y);
        qs[v].emplace_back(q_num, x, 1, y);
        int c = operator()(u, v);
        qs[c].emplace_back(q_num, x, -2, y);
        ans.emplace_back(cost[u] + cost[v] - cost[c] * 2);
        q_num++;
    }

    void dfs(int v, int d = 0, int c = 0, int p = -1) {
        if (p != -1) par[v][0] = p;
        depth[v] = d;
        cost[v] = c;
        for (int i = 0; i < G[v].size(); ++i) {
            Edge e = G[v][i];
            if (e.to == p) continue;
            dfs(e.to, d + 1, c + e.weight, v);
        }
    }

    void dfs2(int v, int p = -1) {

        for (auto q : qs[v]){
            ans[q.qid] += q.coeff * (color_num[q.color] * q.y - color_cost[q.color]);
        }

        for (int i = 0; i < G[v].size(); ++i) {
            Edge e = G[v][i];
            if (e.to == p) continue;

            color_cost[e.color] += e.weight;
            color_num[e.color] += 1;
            dfs2(e.to,  v);
            color_num[e.color] -= 1;
            color_cost[e.color] -= e.weight;

        }
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

        g.add_query(x, y, u, v);
    }

    g.dfs2(0);

    REP(i, Q){
        print(g.ans[i]);
    }

    return 0;
}
