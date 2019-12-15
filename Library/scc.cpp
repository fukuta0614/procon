//
// Created by 福田圭佑 on 2019/12/08.
//


struct SCC {

    int N;
    vector<int> tmp_order;
    vector<int> scc_group;
    vector<bool> used;
    vector<vector<int>> edges, rev_edges;

    SCC(int n): N(n), edges(n), rev_edges(n), scc_group(n, -1), used(n) {}

    void add_edge(int u, int v){
        edges[u].emplace_back(v);
        rev_edges[v].emplace_back(u);
    }

    void dfs(int i){
        used[i] = true;
        for (auto v: edges[i]){
            if (used[v]) continue;
            dfs(v);
        }
        tmp_order.emplace_back(i);
    }

    void dfs2(int i, int k){
        used[i] = true;
        scc_group[i] = k;
        for (auto v: rev_edges[i]){
            if (used[v]) continue;
            dfs2(v, k);
        }
    }

    int calc_scc(){

        REP(i, N){
            if (used[i]) continue;
            dfs(i);
        }

        used.assign(N, false);
        int k = 0;
        REP(i, N){
            int v = tmp_order[N-i-1];
            if (used[v]) continue;
            dfs2(v, k++);
        }

        return k;
    }
};