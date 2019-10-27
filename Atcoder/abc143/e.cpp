// abc143_e
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

    struct Edge {
        int u, v;
        ll w;
        Edge() {}
        Edge(int u, int v, ll w) : u(u), v(v), w(w) {}
        friend ostream& operator<<(ostream& os, const Edge& e) {cout << "(" << e.u << "->" << e.v << "," << e.w << ")"; return os;}
    };

    int n;

    vector<vector<Edge>> edges;
    Graph(int n): n(n), edges(n) {}

    void add_edge(int u, int v, ll c){
        edges[u].emplace_back(u, v, c);
        edges[v].emplace_back(v, u, c);
    }

    vector<int> dijkstra(int s, int L){

        using PP = pair<pair<int, ll>, int>;

        priority_queue<PP, vector<PP>, greater<PP>> pq;
        pq.push(PP( P(0, 0), s));

        vector<P> dist(n, P(INF,0));
        dist[s] = P(0,0);

        while (!pq.empty()){
            PP pp = pq.top(); pq.pop();

            int cnt = pp.first.first;
            ll l = pp.first.second;

            int v = pp.second;
//            if (v == t) return cnt;

            for (auto edge: edges[v]){

                int ncnt = cnt;
                ll nl = l + edge.w;

                if (nl > L){
                    ncnt++;
                    nl = edge.w;
                }

                P ncost = P(ncnt, nl);

                if (ncost < dist[edge.v]){
                    dist[edge.v] = ncost;
                    pq.push(PP(ncost, edge.v));
                }
            }
        }

        vector<int> ret(n);
        REP(i, n) ret[i] = dist[i].first;
        return ret;
    }
};

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N, M, L;
    cin >> N >> M >> L;

    Graph g(N);

    REP(i, M){
        int a, b, c;
        cin >> a >> b >> c; a--; b--;
        if (c <= L) {
            g.add_edge(a, b, c);
        }
    }

    vector<vector<int>> dist;
    REP(i, N){
        dist.emplace_back(g.dijkstra(i, L));
    }

    int Q;
    cin >> Q;
    REP(i, Q){
        int s, t;
        cin >> s >> t; s--; t--;
        int ans = dist[s][t];
        if (ans == INF){
            print(-1);
        } else {
            print(ans);
        }
    }


    return 0;
}
