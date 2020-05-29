// abc168_d
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


struct Graph {

    int n;
    vector<vector<int>> edges;
    vector<int> par;
    vector<int> dist;

    Graph(int n_): n(n_), edges(n_), par(n_, -1), dist(n_, INF) {}

    void add_edge(int u, int v){
        edges[u].emplace_back(v);
        edges[v].emplace_back(u);
    }

    void bfs(void) {

        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push(P(0, 0));

        dist[0] = 0;

        while (!pq.empty()){
            P p = pq.top(); pq.pop();

            int cost = p.first;
            int u = p.second;

            for (auto v: edges[u]){

                int ncost = cost + 1;

                if (ncost < dist[v]){
                    dist[v] = ncost;
                    par[v] = u;
                    pq.push(P(ncost, v));
                }
            }
        }
    }
};



int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N, M;
    cin >> N >> M;
    Graph g(N);
    REP(i, M){
        int a, b;
        cin >> a >> b; a--; b--;
        g.add_edge(a, b);
    }

    g.bfs();

    REP(i, N){
        if (g.dist[i] == INF){
            print("No");
            return 0;
        }
    }

    print("Yes");
    REPN(i, 1, N){
        print(g.par[i]+1);
    }


    return 0;
}
