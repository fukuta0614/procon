// arc111_b
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
//struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

struct Graph {

    int n;
    vector<vector<int>> edges;

    bool is_tree = false;
    vector<int> used;

    Graph(int n_) : n(n_), edges(n_), used(n_) {}

    void add_edge(int u, int v) {
        edges[u].emplace_back(v);
        edges[v].emplace_back(u);
    }

    int dfs(int u = -1, int p = -1){

        if (used[u]) return 0;

        if (p == -1){
            is_tree = false;
        }

        int cnt = 1;
        used[u] = true;

        for (auto v: edges[u]){
            if (v == p) continue;

            if (used[v]){
                is_tree = true;
                continue;
            }

            cnt += dfs(v, u);
        }

        if (p == -1){
            return is_tree ? cnt : cnt - 1;
        }

        return cnt;
    }
};


int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    const int mx = 400001;
    Graph g(mx);

    int N;
    cin >> N;
    REP(i, N){
        int a, b;
        cin >> a >> b; a--; b--;
        g.add_edge(a, b);
    }

    int ans = 0;
    REP(i, mx){
        ans += g.dfs(i);
    }

    print(ans);

    return 0;
}
