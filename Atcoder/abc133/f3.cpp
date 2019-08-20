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
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

#define MAX_N 100100
#define MAX_LOG_N 100100

struct Edge {int n, c, w; Edge(int n, int c, int w) : n(n), c(c), w(w){}};

int N;
vector<Edge> G[MAX_N];
int par[MAX_N][MAX_LOG_N];
int depth[MAX_N];
int dist[MAX_N];
vector<int> euler_tour;
vector<int> euler_tour_cumsum;
int begin_indices[MAX_N], end_indices[MAX_N];


void dfs(int v, int p, int d) {
    par[v][0] = p;
    depth[v] = d;

    for (auto e: G[v]){
        if (e.n == p) continue;

        dist[e.n] = dist[p] + e.w;
        begin_indices[e.n] = (int)euler_tour.size();
        euler_tour.emplace_back(e.w);

        dfs(e.n, v, d + 1);

        end_indices[e.n] = (int)euler_tour.size();
        euler_tour.emplace_back(-e.w);
    }

}

void fill_lca_table() {
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < N; j++) {
            if (par[j][i] == -1){
                par[j][i + 1] = -1;
            } else {
                par[j][i + 1] = par[par[j][i]][i];
            }
        }
    }
}

int lca(int u, int v) {
    if (depth[u] > depth[v]) swap(u, v);

    for (int i = 19; i >= 0; i--) {
        if (((depth[v] - depth[u]) >> i) & 1) v = par[v][i];
    }

    if (u == v) return u;

    for (int i = 19; i >= 0; i--) {
        if (par[u][i] != par[v][i]) {
            u = par[u][i];
            v = par[v][i];
        }
    }
    return par[u][0];
}

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N, Q;
    cin >> N >> Q;

    REP(i, N-1){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        a--; b--;
        G[a].emplace_back(b, c, d);
        G[b].emplace_back(a, c, d);
    }

    dfs(0, -1, 0);
    fill_lca_table();

    print(euler_tour);

    int sm = 0;
    for (auto w: euler_tour){
        sm += w;
        euler_tour_cumsum.emplace_back(sm);
    }

    print(euler_tour_cumsum);
    print(dist);

    vector<int> x;
    REP(i, N) {
        x.emplace_back(euler_tour_cumsum[begin_indices[i]]);
    }

    print(x);
    print(begin_indices);
    print(end_indices);


    return 0;
}
