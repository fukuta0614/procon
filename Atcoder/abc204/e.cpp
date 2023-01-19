// abc204_e
#pragma GCC optimize ("O3")

#include <bits/stdc++.h>
#ifdef LOCAL
#include "../../debug_util/cxx-prettyprint/prettyprint.hpp"
#include "../../debug_util/rng.hpp"
#include "../../debug_util/timer.hpp"
#endif
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
        ll c, d;
        Edge() {}
        Edge(int u, int v, ll c, ll d) : u(u), v(v), c(c), d(d) {}
        friend ostream& operator<<(ostream& os, const Edge& e) {cout << "(" << e.u << "->" << e.v << "," << e.c << ")"; return os;}
    };

    int n;

    vector<vector<Edge>> edges;
    Graph(int n): n(n), edges(n) {}

    void add_edge(int u, int v, ll c, ll d){
        edges[u].emplace_back(u, v, c, d);
        edges[v].emplace_back(v, u, c, d);
    }

    long double f(long double x, long double d){
        return x + d / (x + 1);
    }

    ll f_ll(ll x, ll d){
        return x + d / (x + 1);
    }

    ll get_min(ll x0, ll d){

        ll inf = x0;
        ll sup = 1e16;
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

    ll get_min2(ll x0, ll d){

        ll sqd = ll(sqrt(d));

        sqd = abs(sqd - sqrt(d)) < abs(1 + sqd - sqrt(d)) ? sqd : sqd+1;

        if (x0 <= sqd - 1){
            return f_ll(sqd-1, d);
        } else {
            return f_ll(x0, d);
        }
    }

    ll dijkstra(int s, int t){

        priority_queue<P, vector<P>, greater<> > pq;
        pq.push(P(0, s));

        vector<ll> dist(n, INF);
        dist[s] = 0;

        while (!pq.empty()){
            P p = pq.top(); pq.pop();

            ll cost = p.first;
            int u = p.second;

            if (cost > dist[u]) continue;

            for (auto edge: edges[u]){
                if (cost + edge.c >= dist[edge.v]){
                    continue;
                }
                ll ncost = get_min(cost, edge.d) + edge.c;

                if (ncost < dist[edge.v]){
                    dist[edge.v] = ncost;
                    pq.emplace(ncost, edge.v);
                }
            }
        }
        return dist[t] == INF ? -1 : dist[t];
    }
};


int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N, M;
    cin >> N >> M;
//    N = 1e5;
//    M = 1e5;
    Graph g(N);


    REP(i, M){
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        a--; b--;
//        a = mt() % N;
//        b = mt() % N;
//        c = mt() % ll(1e9);
//        d = mt() % ll(1e9);
        g.add_edge(a, b, c, d);
    }

    ll ans = g.dijkstra(0, N-1);
    print(ans);

//    std::mt19937 mt(0);
//    REP(i, 10000000){
//
//        ll x0 = mt() % ll(1e9);
//        ll d = mt() % ll(1e9);
//        ll s1 = g.get_min(x0, d);
//        ll s2 = g.get_min2(x0, d);
//
//        if (s1 != s2){
//            print(i, x0, d, s1, s2);
//        }
//
//    }

    return 0;
}
