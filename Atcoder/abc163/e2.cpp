// abc163_e
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

#define INF ((ll)1e15)
#define MOD (1000000007)

#define print2D(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }
#define print_line(vec, n) {for(int i=0;i<(n-1);i++) cout << (vec)[i] << " "; cout << (vec)[(n)-1] << endl;}
template<class T> void print(const T& x){cout << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

struct MinCostFlow {
    struct edge {
        int to, cap, rev; ll cost;
    };
    vector<vector<edge>> G;
    int v_num;

    MinCostFlow(int n): v_num(n), G(n) {}

    void add_edge(int from, int to, int cap, ll cost) {
        G[from].emplace_back((edge){to, cap, (int)G[to].size(), cost});
        G[to].emplace_back((edge){from, 0, (int)G[from].size() - 1, -cost});
    }

    ll min_cost_flow(int s, int t, int f) {
        ll res = 0;

        while (f > 0) {

            vector<ll> dist(v_num, INF);
            vector<int> prev_v(v_num, 0), prev_e(v_num, 0);
            dist[s] = 0;

            // Bellman-Ford
            bool update = true;
            while (update) {
                update = false;
                REP(v, v_num) {
                    if (dist[v] == INF) continue;

                    REP(i, G[v].size()) {
                        edge &e = G[v][i];
                        if (e.cap > 0 && dist[e.to] > dist[v] + e.cost) {
                            dist[e.to] = dist[v] + e.cost;
                            prev_v[e.to] = v;
                            prev_e[e.to] = i;
                            update = true;
                        }
                    }
                }
            }

            //
            if (dist[t] == INF){
                return  -1;
            }

            // 最短経路に流す
            int d = f;
            for (int v = t; v != s; v = prev_v[v]){
                d = min(d, G[prev_v[v]][prev_e[v]].cap);
            }

            f -= d;
            res += d * dist[t];
            for (int v = t; v != s; v = prev_v[v]){
                edge &e = G[prev_v[v]][prev_e[v]];
                e.cap -= d;
                G[v][e.rev].cap += d;
            }
        }
        return res;
    }
};

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N;
    cin >> N;
    vector<ll> A(N);
    REP(i, N) cin >> A[i];


    int s = 2 * N, t = s + 1;
    auto g = MinCostFlow(2*N+2);
    int ans = 0;

    REP(i, N) g.add_edge(s, i, 1, 0);
    REP(i, N) g.add_edge(N+i, t, 1, 0);
    REP(i, N) REP(j, N){
        g.add_edge(i, N+j, 1, -A[i] * abs(i - j));
    }

    ans += -g.min_cost_flow(s, t, N);

    print(ans);

    return 0;
}
