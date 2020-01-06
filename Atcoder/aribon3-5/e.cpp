// aribon3-5_e
// AOJ 1088 School Excursion　
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

struct MinCostFlow {
    struct edge {int to, cap, cost, rev;};
    vector<vector<edge>> G;
    vector<vector<edge>> edges;
    int v_num;

    MinCostFlow(int n): v_num(n), edges(n), G(n) {}

    void add_edge(int from, int to, int cap, int cost) {
//        print(from, to, cap, cost);
        edges[from].emplace_back((edge){to, cap, cost, (int)edges[to].size()});
        edges[to].emplace_back((edge){from, 0, -cost, (int)edges[from].size() - 1});
    }

    int min_cost_flow(int s, int t, int f) {
        int res = 0;

        G = edges; //何度も呼ぶ用にコピーしとく変更

        while (f > 0) {

            vector<int> dist(v_num, INF);
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

    while (true){
        int N;
        cin >> N;
        if (N == 0) break;

        vector<int> M(N-1);
        vector<int> cumsum(N);
        vector<map<int, int>> y_maps(N-1);
        vector<vector<tuple<int, int, int>>> xyc(N-1);
        REP(i, N-1){
            cin >> M[i];
            REP(j, M[i]){
                int x, y, c;
                cin >> x >> y >> c;
                xyc[i].emplace_back(x, y, c);
                if (y_maps[i].count(y) == 0){
                    int sz = y_maps[i].size();
                    y_maps[i][y] = sz;
                }
            }
            cumsum[i+1] = cumsum[i] + y_maps[i].size();
        }

        int G;
        cin >> G;

        int v_num = 2 * cumsum[N-1];
        int s = v_num, t = s + 1;
        auto g = MinCostFlow(v_num+2);
        REP(i, N-1){
            REP(j, M[i]){
                int x, y, c;
                tie(x, y, c) = xyc[i][j];

                if (i == 0){
                    g.add_edge(s, cumsum[i] + y_maps[i][y], 1, c);
                } else {
                    for (auto e: y_maps[i-1]){
                        int y_prev = e.first;
                        if (y_prev <= x){
                            g.add_edge(cumsum[N-1] + cumsum[i-1] + y_maps[i-1][y_prev], cumsum[i] + y_maps[i][y], 1, c);
                        }
                    }
                }
            }
            for (auto e: y_maps[i]){
                int y = e.first;
                g.add_edge(cumsum[i] + y_maps[i][y], cumsum[N-1] + cumsum[i] + y_maps[i][y], 1, 0);
            }

        }

        for (auto e: y_maps[N-2]){
            int y = e.first;
            g.add_edge(cumsum[N-1] + cumsum[N-2] + y_maps[N-2][y], t, 1, 0);
        }

        int ans_class=0;
        int ans_cost=0;
        REP_REV(class_num, G+1){
            int res = g.min_cost_flow(s, t, class_num);
            if (res != -1){
                ans_class = class_num;
                ans_cost = res;
                break;
            }
        }

        print(ans_class, ans_cost);
    }


    return 0;
}
