// abc137_e
#include <bits/stdc++.h>
#ifdef LOCAL
#include "../cxx-prettyprint/prettyprint.hpp"
#endif
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define REP(i, n) for (int (i) = 0 ; (i) < (int)(n) ; ++(i))
#define REPN(i, m, n) for (int (i) = m ; (i) < (int)(n) ; ++(i))
#define REP_REV(i, n) for (int (i) = (int)(n) - 1 ; (i) >= 0 ; --(i))
#define REPN_REV(i, m, n) for (int (i) = (int)(n) - 1 ; (i) >= m ; --(i))
#define ALL(x) x.begin(), x.end()

#define MOD (1000000007)

#define print2D(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }
template<class T> void print(const T& x){cout << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;


template<typename T>
struct BellmanFord{
    struct edge {
        int u, v;
        T w;
        edge() {}
        edge(int u, int v, T w) : u(u), v(v), w(w) {}
        friend ostream& operator<<(ostream& os, const edge& e) {cout << "(" << e.u << "->" << e.v << "," << e.w << ")"; return os;}
    };

    int n;
    vector< vector<int> > G;
    vector<bool> used, reach;
    vector<edge> edges;
    vector<T> ds;
    T INF;

    explicit BellmanFord(int n) : n(n), G(n), used(n, 0), reach(n, 0) { INF = numeric_limits<T>::max(); }

    void add_edge(int u, int v, T c) {
        edges.emplace_back(u, v, c);
        G[u].emplace_back(v);
    }

    void dfs(int v){
        if(used[v]) return;
        used[v]=true;
        for(int u:G[v]) dfs(u);
    }

    T get_shortest_path(int s, int t, bool &neg_loop){
        // 各ノードがtにたどり着けるかどうか
        for (int i = 0; i < n; i++) {
            fill(used.begin(), used.end(), 0);
            dfs(i);
            reach[i] = used[t];
        }

        ds.assign(n, INF);
        ds[s] = 0;

        for (int j = 0; j < n; j++) {
            bool update = false;
            for (auto e:edges) {
                if(!reach[e.u]||!reach[e.v]||ds[e.u]==INF) continue;

                if (ds[e.u] + e.w < ds[e.v]) {
                    ds[e.v] = ds[e.u] + e.w;
                    update = true;
                }
            }

            if (!update) break;

            if (j == n - 1) {
                neg_loop = true;
                return INF;
            }
        }
        neg_loop = false;
        return ds[t];
    }
};

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N, M, P;
    cin >> N >> M >> P;

    BellmanFord<ll> g(N);
    map<pair<int, int>, ll> mp;
    REP(i, M){
        int a, b; ll c;
        cin >> a >> b >> c; a--; b--;
        g.add_edge(a, b, P - c);
    }

    // 勝手に辺をまとめたらだめだった。。。。。。。。。。。
//    for (auto p: mp){
//        int a = p.first.first;
//        int b = p.first.second;
//        ll c = p.second;
//        g.add_edge(a, b, P - c);
//    }

    bool negloop;
    ll ans =  g.get_shortest_path(0, N-1, negloop);

    if (negloop){
        print(-1);
    } else {
        print(max(-ans, 0ll));
    }


    return 0;
}
