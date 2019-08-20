// abc131_f
#include <bits/stdc++.h>
#ifdef LOCAL
#include "../cxx-prettyprint/prettyprint.hpp"
#endif
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;

#define REP(i, n) for (int (i) = 0 ; (i) < (int)(n) ; ++(i))
#define REPN(i, m, n) for (int (i) = m ; (i) < (int)(n) ; ++(i))
#define REP_REV(i, n) for (int (i) = (int)(n) - 1 ; (i) >= 0 ; --(i))
#define REPN_REV(i, m, n) for (int (i) = (int)(n) - 1 ; (i) >= m ; --(i))
#define ALL(x) x.begin(), x.end()

#define INF ((1 << 29)-1)
#define MOD (1000000007)

#define print2D(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }
template<class T> void print(const T& x){cout << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;


struct UnionFind {
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2
    vector<int> rank;
    vector<int> size;

    UnionFind(int N) : par(N), rank(N), size(N) { //最初は全てが根であるとして初期化
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

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N;
    cin >> N;
    const int max_xy = 100001;
    vector<int> X(N), Y(N);
    vector<vector<int>> x_list(max_xy), y_list(max_xy);

    REP(i, N){
        cin >> X[i] >> Y[i];
        x_list[X[i]].emplace_back(i);
        y_list[Y[i]].emplace_back(i);
    }

    auto uf = UnionFind(N);

    REP(i, max_xy){
        if (x_list[i].empty()) continue;

        for (auto x: x_list[i]){
            uf.unite(x, x_list[i][0]);
        }
    }

    REP(i, max_xy){
        if (y_list[i].empty()) continue;

        for (auto y: y_list[i]){
            uf.unite(y, y_list[i][0]);
        }
    }

    vector<set<int>> x_num_list(N), y_num_list(N);
    vector<int> point_num(N, 0);

    REP(i, N){
        int conn_idx = uf.find(i);
        x_num_list[conn_idx].insert(X[i]);
        y_num_list[conn_idx].insert(Y[i]);
        point_num[conn_idx]++;
    }

    ll ans = 0;
    REP(i, N){
        ans += x_num_list[i].size() * y_num_list[i].size() - point_num[i];
    }

    print(ans);


    return 0;
}
