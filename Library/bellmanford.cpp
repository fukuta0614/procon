//
// Created by 福田圭佑 on 2019/12/08.
//

template<typename T>
struct BellmanFord{
    struct edge {
        int u, v;
        T w;
        edge() {}
        edge(int u, int v, T w) : u(u), v(v), w(w) {}
        friend ostream& operator<<(ostream& os, const edge& e) {cout << "(" << e.u << "->" << e.v << "," << e.w << ")"; return os;}
    };

    int n;
    vector< vector<int> > G;
    vector<int> used;
    vector<edge> edges;
    vector<T> ds;
    T INF;

    explicit BellmanFord(int n) : n(n), G(n), used(n, 0) { INF = numeric_limits<T>::max(); }

    void add_edge(int u, int v, T c) {
        edges.emplace_back(u, v, c);
        G[u].emplace_back(v);
    }

    T get_shortest_path(int s, int t, bool &neg_loop){
        ds.assign(n, INF);
        ds[s] = 0;

        for (int j = 0; j < n; j++) {
            bool update = false;
            for (auto e:edges) {
                if (ds[e.u] == INF) continue;

                if (ds[e.u] + e.w < ds[e.v]) {
                    ds[e.v] = ds[e.u] + e.w;
                    update = true;
                }
            }

            if (!update) break;

            if (j == n - 1) {
                neg_loop = true;
                return INF;
            }
        }
        neg_loop = false;
        return ds[t];
    }
};