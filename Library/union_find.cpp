//
// Created by 福田圭佑 on 2019/08/05.
//


struct UnionFind {
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2
    vector<int> rank;

    UnionFind(int N) : par(N), rank(N) { //最初は全てが根であるとして初期化
        for(int i = 0; i < N; i++) {par[i] = i; rank[i] = 0;}
    }

    int find(int x) { // データxが属する木の根を再帰で得る：find(x) = {xの木の根}
        if (par[x] == x) return x;
        return par[x] = find(par[x]);
    }

    void unite(int x, int y) { // xとyの木を併合
        int rx = find(x); //xの根をrx
        int ry = find(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま

        if(rank[rx] < rank[ry]) { // root が rx の木の方が root が ry の木よりも低い
            par[rx] = ry; // root ry に rx の木をつなぐ
        } else {
            par[ry] = rx; // root rx に ry の木をつなぐ
            if(rank[rx] == rank[ry]) ++rank[rx]; // 同じ高さだったならばまとめたことによって高さ +1
        }
    }

    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = find(x);
        int ry = find(y);
        return rx == ry;
    }
};