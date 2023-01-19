// abc204_e
//#pragma GCC optimize ("O3")

#include <bits/stdc++.h>
//#ifdef LOCAL
//#include "../../debug_util/cxx-prettyprint/prettyprint.hpp"
//#include "../../debug_util/rng.hpp"
//#include "../../debug_util/timer.hpp"
//#endif
using namespace std;

using ll = long long;
using ull = unsigned long long;
using P = pair<ll, ll>;

#define REP(i, n) for (int i = 0 ; i < (int)(n) ; ++i)
#define REPN(i, m, n) for (int i = m ; i < (int)(n) ; ++i)
#define REP_REV(i, n) for (int i = (int)(n) - 1 ; i >= 0 ; --i)
#define REPN_REV(i, m, n) for (int i = (int)(n) - 1 ; i >= m ; --i)
#define ALL(x) x.begin(), x.end()

#define INF (ll)(1e17)
#define MOD (1000000007)

#define print2D(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }
#define print_line(vec, n) {for(int idx=0;idx<(n-1);idx++) cout << (vec)[idx] << " "; cout << (vec)[(n)-1] << endl;}
template<class T> void print(const T& x){cout << x << "\n";}
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
    }

    long double f(long double x, long double d){
        return x + d / (x + 1);
    }

    ll f_ll(ll x, ll d){
        return x + d / (x + 1);
    }

    ll get_min(ll x0, ll d){

        ll inf = x0;
        ll sup = 1e10;
        while (sup - inf > 1){
            ll x = (sup + inf) / 2;

            if (f(x, d) - f(x-1, d) > 0){
                sup = x;
            } else {
                inf = x;
            }
        }
        ll a = f_ll(sup, d);
        ll b = f_ll(inf, d);
        ll c = f_ll(max(x0, inf-1), d);
        return min({a, b, c});
    }

    vector<ll> dijkstra(int s){

        priority_queue<P, vector<P>, greater<> > pq;
        pq.push(P(0, s));

        vector<ll> dist(n, INF);
        dist[s] = 0;

        while (!pq.empty()){
            P p = pq.top(); pq.pop();

            ll cost = p.first;
            int u = p.second;

            for (auto edge: edges[u]){
                ll ncost = cost + edge.w;

                if (ncost < dist[edge.v]){
                    dist[edge.v] = ncost;
                    pq.emplace(ncost, edge.v);
                }
            }
        }
        return dist;
    }
};


int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N, M, r;
    cin >> N >> M >> r;
    Graph g(N);

    REP(i, M){
        ll a, b, c;
        cin >> a >> b >> c;
        g.add_edge(a, b, c);
    }

    vector<ll> ans = g.dijkstra(r);
    REP(i, N){
        if (ans[i] == INF){
            print("INF");
        } else {
            print(ans[i]);
        }
    }

    return 0;
}
