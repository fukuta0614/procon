//
// Created by 福田圭佑 on 2021/01/11.
//

struct Graph {
    int n;
    vector<vector<int>> edges;

    Graph(int n_): n(n_), edges(n_) {}

    void add_edge(int u, int v){
        edges[u].emplace_back(v);
        edges[v].emplace_back(u);
    }
};