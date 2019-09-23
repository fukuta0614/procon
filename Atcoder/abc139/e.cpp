// abc138_e
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

struct Graph {

    vector<int> depth, visited;
    vector<vector<int>> edges;
    Graph(int n): edges(n), depth(n, -1), visited(n, 0) {}

    void add_edge(int u, int v){
        edges[u].emplace_back(v);
    }

    int dfs(int v){
        if (depth[v] >= 0) return depth[v];
        if (visited[v]) return INF;

        visited[v] = 1;
        int d = 1;
        for (auto t: edges[v]) {
            d = max(d, dfs(t)+1);
        }
        return depth[v] = d;
    }
};
int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N;
    cin >> N;
    vector<vector<int>> A;
    A.assign(N, vector<int>(N-1, 0));
    REP(i, N) REP(j, N-1){
        cin >> A[i][j];  A[i][j]--;
    }

    auto g = Graph(N*N+1);
    REP(i, N) REP(j, N-2) {
        int a = i < A[i][j] ? i*N+A[i][j] : A[i][j]*N+i;
        int b = i < A[i][j+1] ? i*N+A[i][j+1] : A[i][j+1]*N+i;
        g.add_edge(a, b);
    }

    int ans = 0;
    REP(i, N){
        int a = i < A[i][0] ? i*N+A[i][0] : A[i][0]*N+i;
        ans = max(ans, g.dfs(a));
    }

    if (ans >= INF){
        print(-1);
    } else {
        print(ans);
    }
    return 0;
}
