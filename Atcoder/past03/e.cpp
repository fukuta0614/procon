// past03_e
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
#define print_line(vec, n) {for(int i=0;i<(n-1);i++) cout << (vec)[i] << " "; cout << (vec)[(n)-1] << endl;}
template<class T> void print(const T& x){cout << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;


struct Graph {

    int n;
    vector<vector<int>> edges;
    vector<int> colors;

    Graph(int n_): n(n_), edges(n_), colors(n_){}

    void add_edge(int u, int v){
        edges[u].emplace_back(v);
        edges[v].emplace_back(u);
    }

    void spread(int u){
        for (auto v: edges[u]){
            colors[v] = colors[u];
        }
    }
};


int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N, M, Q;
    cin >> N >> M >> Q;
    Graph g(N);
    REP(i, M){
        int u, v;
        cin >> u >> v;
        u--; v--;
        g.add_edge(u, v);
    }

    REP(i, N){
        cin >> g.colors[i];
    }

    REP(i, Q){
        int t;
        cin >> t;
        if (t == 1){
            int x;
            cin >> x;
            x--;
            print(g.colors[x]);
            g.spread(x);
        } else {
            int x, y;
            cin >> x >> y;
            x--;
            print(g.colors[x]);

            g.colors[x] = y;
        }



    }

    return 0;
}
