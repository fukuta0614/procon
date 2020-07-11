// abc087_d
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

#define INF (ll)(1e9)
#define MOD (1000000007)

#define print2D(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }
#define print_line(vec, n) {for(int i=0;i<(n-1);i++) cout << (vec)[i] << " "; cout << (vec)[(n)-1] << endl;}
template<class T> void print(const T& x){cout << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;


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

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N, M;
    cin >> N >> M;
    WeightedUnionFind<ll> uf(N);

    REP(i, M){
        int l, r, d;
        cin >> l >> r >> d;
        l--, r--;

        if (uf.same(l, r)){

            if (uf.diff(l, r) != d){
                print("No");
                return 0;
            }

        } else {
            uf.unite(l, r, d);
        }
    }
    print("Yes");

    return 0;
}
