//
// Created by 福田圭佑 on 2020/01/05.
//

struct UnionFind {
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2
    vector<int> rank;
    vector<int> size; // size[i]: iが親なら連結成分の数

    UnionFind(int N) : par(N), rank(N), size(N) { //最初は全てが根であるとして初期化
        for(int i = 0; i < N; i++) {par[i] = i; rank[i] = 0; size[i] = 1;}
    }

    int find(int x) { // データxが属する木の根を再帰で得る：find(x) = {xの木の根}
        if (par[x] == x) return x;
        return par[x] = find(par[x]);
    }

    void unite(int x, int y) { // xとyの木を併合
        int rx = find(x); //xの根をrx
        int ry = find(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま

        // rank[rx] >= rank[ry] となるように rx と ry を swap
        if(rank[rx] < rank[ry]) swap(rx, ry);

        // 同じ高さだったならばまとめたことによって高さ +1
        if(rank[rx] == rank[ry]) ++rank[rx];

        par[ry] = rx; // root rx に ry の木をつなぐ
        size[rx] += size[ry];
        size[ry] = 0;

    }

    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = find(x);
        int ry = find(y);
        return rx == ry;
    }

    int get_size(int x){
        int rx = find(x);
        return size[rx];
    }
};

template <typename T>
struct Graph {
    struct edge {
        int u, v; T w;
        edge() {}
        edge(int u, int v, T w) : u(u), v(v), w(w) {}
        bool operator<(const edge& a){return w < a.w;}
    };

    int n;
    vector<edge> edges;

    explicit Graph(int n) : n(n) {}

    void add_edge(int u, int v, T c) {
        edges.emplace_back(u, v, c);
    }

    T kruskal() {
        sort(edges.begin(), edges.end());

        UnionFind uf(n);
        T min_cost = 0;

        for (auto e: edges) {
            if (not uf.same(e.u, e.v)) {
                min_cost += e.w;
                uf.unite(e.u, e.v);
            }
        }

        if (uf.get_size(0) != n) return -1;
        return min_cost;
    }
};