template<typename T>
struct LCA {
    int n, log_n;

    vector<vector<int>> to;
    vector<vector<T>> weight;

    vector<int> depth;
    vector<T> cost;
    vector<vector<int>> par;

    LCA(int n) : n(n), to(n), weight(n), depth(n), cost(n) {
        log_n = 0;
        while ((1 << log_n) < n) ++log_n;
        par.assign(n + 1, vector<int>(log_n, n));
    }

    void add_edge(int a, int b, T c = 1) {
        to[a].push_back(b);
        to[b].push_back(a);
        weight[a].push_back(c);
        weight[b].push_back(c);
    }

    void dfs(int v, int d = 0, T c = 0, int p = -1) {
        if (p != -1) par[v][0] = p;
        depth[v] = d;
        cost[v] = c;
        for (int i = 0; i < to[v].size(); ++i) {
            int u = to[v][i];
            if (u == p) continue;
            dfs(u, d + 1, c + weight[v][i], v);
        }
    }

    void init(int root = 0) {
        dfs(root);

        for (int i = 0; i < log_n - 1; ++i) {
            for (int v = 0; v < n; ++v) {
                par[v][i + 1] = par[par[v][i]][i];
            }
        }
    }

    // LCA
    int operator()(int a, int b) {
        if (depth[a] > depth[b]) swap(a, b);

        for (int i = log_n - 1; i >= 0; --i) {
            if (((depth[b] - depth[a]) >> i) & 1) b = par[b][i];
        }

        if (a == b) return a;

        for (int i = log_n - 1; i >= 0; --i) {
            if (par[a][i] != par[b][i]) {
                a = par[a][i];
                b = par[b][i];
            }
        }
        return par[a][0];
    }

    int length(int a, int b) {
        int c = operator()(a, b);
        return depth[a] + depth[b] - depth[c] * 2;
    }

    T dist(int a, int b) {
        int c = operator()(a, b);
        return cost[a] + cost[b] - cost[c] * 2;
    }
};