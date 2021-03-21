//
// Created by 福田圭佑 on 2019/12/31.
//

typedef pair<ll, int> P;

struct Graph {

    struct Edge {
        int u, v;
        ll w;
        Edge() {}
        Edge(int u, int v, ll w) : u(u), v(v), w(w) {}
        friend ostream& operator<<(ostream& os, const Edge& e) {cout << "(" << e.u << "->" << e.v << "," << e.w << ")"; return os;}
    };

    int n;

    vector<vector<Edge>> edges;
    Graph(int n): n(n), edges(n) {}

    void add_edge(int u, int v, ll c){
        edges[u].emplace_back(u, v, c);
        edges[v].emplace_back(v, u, c);
    }

    ll dijkstra(int s, int t){

        priority_queue<P, vector<P>, greater<P> > pq;
        pq.push(P(0, s));

        vector<ll> dist(n, INF);
        dist[s] = 0;

        while (!pq.empty()){
            P p = pq.top(); pq.pop();

            ll cost = p.first;
            int u = p.second;

            for (auto edge: edges[u]){
                ll ncost = cost + edge.w;

                if (ncost < dist[edge.v]){
                    dist[edge.v] = ncost;
                    pq.emplace(ncost, edge.v);
                }
            }
        }
        return dist[t] == INF ? -1 : dist[t];
    }

    ll bfs(int s, int t){
        queue<int> q;
        q.emplace(s);

        vector<ll> dist(n, INF);
        dist[s] = 0;

        while (!q.empty()){
            int u = q.front(); q.pop();

            for (auto edge: edges[u]) if (dist[edge.u] + 1 < dist[edge.v]){
                    dist[edge.v] = dist[edge.u] + 1;
                    q.emplace(edge.v);
                }
        }
        return dist[t];
    }
};


struct Grid {

    int H, W;
    vector<string> S;

    const int dx[8]={ 1, 0, -1, 0, -1, 1, -1, 1};
    const int dy[8]={ 0, 1, 0, -1, -1, -1, 1, 1};
    bool bound_check(int i, int j) const {return (0 <= i) && (i < H) && (0 <= j) && (j < W);}

    [[nodiscard]] int hash_func(int i, int j) const {
        return i * W + j;
    }

    [[nodiscard]] tuple<int, int> rev_hash(int h) const{
        int i = h / W;
        int j = h % W;
        return tie(i, j);
    }

    Grid(int H, int W, vector<string>& S): H(H), W(W), S(S) {}

    // not verified yet
    ll dijkstra(int si, int sj, int gi, int gj){

        priority_queue<P, vector<P>, greater<P> > pq;
        pq.emplace(0, hash_func(si, sj));

        vector<ll> dist(H*W, INF);
        dist[hash_func(si, sj)] = 0;

        while (!pq.empty()){
            P p = pq.top(); pq.pop();

            ll cost = p.first;
            int hash = p.second;
            auto [i, j] = rev_hash(hash);

            for (int k = 0; k < 4; ++k) {
                int ni = i + dx[k];
                int nj = j + dy[k];
                if (not bound_check(ni, nj)) continue;
                if (S[ni][nj] == '#') continue;

                ll ncost = cost + 1;
                int nhash = hash_func(ni, nj);

                if (ncost < dist[nhash]) {
                    dist[nhash] = ncost;
                    pq.emplace(ncost, nhash);
                }
            }
        }
        return dist[hash_func(gi, gj)] == INF ? -1 : dist[hash_func(gi, gj)];
    }

    // abc088Dでverify
    ll bfs(int si, int sj, int gi, int gj){
        queue<int> q;
        q.emplace(hash_func(si, sj));

        vector<ll> dist(H*W, INF);
        dist[hash_func(si, sj)] = 0;

        while (!q.empty()) {
            int hash = q.front(); q.pop();
            auto [i, j] = rev_hash(hash);

            for (int k = 0; k < 4; ++k) {
                int ni = i + dx[k];
                int nj = j + dy[k];
                if (not bound_check(ni, nj)) continue;
                if (S[ni][nj] == '#') continue;

                int nhash = hash_func(ni, nj);
                if (dist[hash] + 1 < dist[nhash]) {
                    dist[nhash] = dist[hash] + 1;
                    q.emplace(nhash);
                }
            }
        }
        return dist[hash_func(gi, gj)] == INF ? -1 : dist[hash_func(gi, gj)];
    }
};
