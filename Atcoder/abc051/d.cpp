// abc051_d
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

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    struct Edge {
        int u, v, w;
        Edge() {}
        Edge(int u, int v, int w) : u(u), v(v), w(w) {}
    };

    int N, M;
    cin >> N >> M;

    vector<Edge> edges(M);
    vector<vector<int>> dist(N, vector<int>(N, INF));
    REP(i, N) dist[i][i] = 0;

    REP(i, M){
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        edges[i] = {a, b, c};
        dist[a][b] = c;
        dist[b][a] = c;
    }

    REP(k, N) REP(i, N) REP(j, N) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    }

//    REP(i, N) print(dist[i]);

    int ans = 0;
    REP(i, M){
        if (dist[edges[i].u][edges[i].v] < edges[i].w){
            ans++;
        }
    }

    print(ans);


    return 0;
}
