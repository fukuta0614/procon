//
// Created by 福田圭佑 on 2019/12/31.
//

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

    vector<int> dijkstra(int s, int L){

        using PP = pair<pair<int, ll>, int>;

        priority_queue<PP, vector<PP>, greater<PP>> pq;
        pq.push(PP( P(0, 0), s));

        vector<P> dist(n, P(INF,0));
        dist[s] = P(0,0);

        while (!pq.empty()){
            PP pp = pq.top(); pq.pop();

            int cnt = pp.first.first;
            ll l = pp.first.second;

            int v = pp.second;
//            if (v == t) return cnt;

            for (auto edge: edges[v]){

                int ncnt = cnt;
                ll nl = l + edge.w;

                if (nl > L){
                    ncnt++;
                    nl = edge.w;
                }

                P ncost = P(ncnt, nl);

                if (ncost < dist[edge.v]){
                    dist[edge.v] = ncost;
                    pq.push(PP(ncost, edge.v));
                }
            }
        }

        vector<int> ret(n);
        REP(i, n) ret[i] = dist[i].first;
        return ret;
    }
};