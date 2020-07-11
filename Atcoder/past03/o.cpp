// past03_o
#include <bits/stdc++.h>
#ifdef LOCAL
#include "../cxx-prettyprint/prettyprint.hpp"
#endif
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, int> P;

#define REP(i, n) for (int (i) = 0 ; (i) < (int)(n) ; ++(i))
#define REPN(i, m, n) for (int (i) = m ; (i) < (int)(n) ; ++(i))
#define REP_REV(i, n) for (int (i) = (int)(n) - 1 ; (i) >= 0 ; --(i))
#define REPN_REV(i, m, n) for (int (i) = (int)(n) - 1 ; (i) >= m ; --(i))
#define ALL(x) x.begin(), x.end()

#define INF (ll)(1e15)
#define MOD (1000000007)

#define print2D(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }
#define print_line(vec, n) {for(int i=0;i<(n-1);i++) cout << (vec)[i] << " "; cout << (vec)[(n)-1] << endl;}
template<class T> void print(const T& x){cout << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;


template <typename T>
struct MinCostFlow {
    struct edge {int to, cap; T cost; int rev;};
    vector<vector<edge>> G;
    int v_num;

    MinCostFlow(int n): v_num(n), G(n) {}

    void add_edge(int from, int to, int cap, T cost) {
        G[from].emplace_back((edge){to, cap, cost, (int)G[to].size()});
        G[to].emplace_back((edge){from, 0, -cost, (int)G[from].size() - 1});
    }

    T min_cost_flow(int s, int t, int f) {
        T res = 0;

        while (f > 0) {

            vector<T> dist(v_num, INF);
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

    int N, M;
    cin >> N >> M;
    vector<ll> A(N), B(N);
    REP(i, N) cin >> A[i];
    REP(i, N) cin >> B[i];
    vector<ll> R(3);
    REP(i, 3) cin >> R[i];

    // 0-2 ラウンド
    // 3-3+N-1 各棒
    // 3+N, 3+N+1 始点終点

    int s = N+3, t = N+4;
    auto g = MinCostFlow<ll>(N+5);

    REP(i, 3) g.add_edge(s, i, M, 0);

    REP(i, 3) REP(j, N){
        ll score = A[j] * (ll)pow(B[j], i+1) % R[i];
        g.add_edge(i, 3+j, 1, -score);
    }

    REP(j, N){
        ll penalty;
        penalty = A[j] * (ll)pow(B[j], 1);
        g.add_edge(3+j, t, 1, penalty);
        penalty = A[j] * (ll)pow(B[j], 2) - A[j] * (ll)pow(B[j], 1);
        g.add_edge(3+j, t, 1, penalty);
        penalty = A[j] * (ll)pow(B[j], 3) - A[j] * (ll)pow(B[j], 2);
        g.add_edge(3+j, t, 1, penalty);
    }

    ll ans = -g.min_cost_flow(s, t, 3*M);

    print(ans);

    return 0;
}
