
#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for (int (i) = 0 ; (i) < (int)(n) ; ++(i))
#define REPN(i, m, n) for (int (i) = m ; (i) < (int)(n) ; ++(i))
#define INF ((1 << 16)-1)

#define MAX_V 1000
struct edge {int to, cap, cost, rev;};

int V_num = 0;
vector<edge> G[MAX_V];
int dist[MAX_V];
int prev_v[MAX_V], prev_e[MAX_V];

void add_edge(int from, int to, int cap, int cost) {
    G[from].emplace_back((edge){to, cap, cost, (int)G[to].size()});
    G[to].emplace_back((edge){from, 0, -cost, (int)G[from].size() - 1});
}

int min_cost_flow(int s, int t, int f) {
    int res = 0;
    while (f > 0) {

        fill(dist, dist + V_num, INF);
        dist[s] = 0;

        // Bellman-Ford
        bool update = true;
        while (update) {
            update = false;
            REP(v, V_num) {
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

int main() {
#ifdef LOCAL
    std::ifstream in("../arg.txt");
    std::cin.rdbuf(in.rdbuf());
#endif

    int R, G, B;
    cin >> R >> G >> B;

    int s, t;

    s = V_num++; // s = 0
    t = 905; // s, r, g, b, -450~450, t

    add_edge(0, V_num++, R, 0);
    add_edge(0, V_num++, G, 0);
    add_edge(0, V_num++, B, 0);

    REPN(i, -450, 451) {
        add_edge(1, V_num, 1, abs(-100 - i));
        add_edge(2, V_num, 1, abs(i));
        add_edge(3, V_num, 1, abs(100 - i));
        add_edge(V_num, t, 1, 0);
        V_num++;
    }
    V_num++; // 906

    int ans = min_cost_flow(s, t, R + G + B);
    cout << ans << endl;

    return 0;
}
