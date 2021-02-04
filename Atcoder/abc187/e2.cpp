// abc187_e
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

#define INF (ll)(1e9)
#define MOD (1000000007)

#define print2D(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }
#define print_line(vec, n) {for(int idx=0;idx<(n-1);idx++) cout << (vec)[idx] << " "; cout << (vec)[(n)-1] << endl;}
template<class T> void print(const T& x){cout << x << "\n";}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

struct Graph {

    int n;
    vector<vector<int>> edges;
    vector<int> depth;
    vector<ll> weight;

    Graph(int n_): n(n_), edges(n_), depth(n_), weight(n_) {

    }

    void add_edge(int u, int v){
        edges[u].emplace_back(v);
        edges[v].emplace_back(u);
    }

    void dfs(int v = 0, int p = -1, int d = 0) {
        depth[v] = d;
        for (auto e: edges[v]){
            if (e == p) continue;
            dfs(e, v, d+1);
        }
    }

    void dfs2(int v = 0, int p = -1, ll w = 0) {

        weight[v] += w;

        for (auto e: edges[v]){
            if (e == p) continue;

            dfs2(e, v, weight[v]);
        }
    }
};


int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N;
    cin >> N;

    auto g = Graph(N);

    vector<int> A(N-1), B(N-1);
    REP(i, N-1){
        cin >> A[i] >> B[i]; A[i]--, B[i]--;
        g.add_edge(A[i], B[i]);
    }

    g.dfs();

    int Q;
    cin >> Q;

    REP(i, Q){
        int t, e, x;
        cin >> t >> e >> x;
        e--;
        int a = A[e];
        int b = B[e];
        if (t == 1){ // a側に足す
            if (g.depth[a] < g.depth[b]){ // aのほうが上
                g.weight[0] += x;
                g.weight[b] -= x;
            } else { // bのほうが上
                g.weight[a] += x;
            }
        } else { // b側に足す
            if (g.depth[a] < g.depth[b]){ // aのほうが上
                g.weight[b] += x;
            } else {
                g.weight[0] += x;
                g.weight[a] -= x;
            }
        }
    }

    g.dfs2();

    REP(i, N){
        ll ans = g.weight[i];
        print(ans);
    }


    return 0;
}
