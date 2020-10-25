//
// Created by 福田圭佑 on 2019/08/05.
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


// 重み付きUnionFind
template< typename T >
struct WeightedUnionFind {
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2
    vector<int> rank;
    vector<int> size; // size[i]: iが親なら連結成分の数
    vector<T> weight; // weight[i]: i -> iの根までの重み

    WeightedUnionFind(int N) : par(N), rank(N, 0), size(N, 1), weight(N, 0) { //最初は全てが根であるとして初期化
        for (int i = 0; i < N; i++) {par[i] = i;}
    }

    int find(int x) { // データxが属する木の根を再帰で得る：find(x) = {xの木の根}
        if (par[x] == x) return x;

        // 親への重みを追加しながら根まで走査
        int rx = find(par[x]);
        weight[x] += weight[par[x]];
        return par[x] = rx;
    }

    bool unite(int x, int y, T w) { // x -> y の重みが w
        int rx = find(x); //xの根をrx
        int ry = find(y); //yの根をry
        if (rx == ry) return false; //xとyの根が同じ(=同じ木にある)時はそのまま

        w = -weight[x] + w + weight[y];

        // rank[rx] <= rank[ry] となるように rx と ry を swap
        if(rank[rx] > rank[ry]) { swap(rx, ry); w *= -1;  }

        // 同じ高さだったならばまとめたことによって高さ +1
        if(rank[rx] == rank[ry]) ++rank[ry];

        // rx -> ryの重みをセット
        weight[rx] = w;

        par[rx] = ry; // root ry に rx の木をつなぐ
        size[ry] += size[rx];
        size[rx] = 0;

        return true;
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

    T diff(int x, int y) { // x -> yの重みを返す
        find(x);
        find(y);
        return weight[x] - weight[y];
    }
};
