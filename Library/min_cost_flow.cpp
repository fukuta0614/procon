struct MinCostFlow {
    struct edge {int to, cap, cost, rev;};
    vector<vector<edge>> G;
    int v_num;

    MinCostFlow(int n): v_num(n), G(n) {}

    void add_edge(int from, int to, int cap, int cost) {
        G[from].emplace_back((edge){to, cap, cost, (int)G[to].size()});
        G[to].emplace_back((edge){from, 0, -cost, (int)G[from].size() - 1});
    }

    int min_cost_flow(int s, int t, int f) {
        int res = 0;


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