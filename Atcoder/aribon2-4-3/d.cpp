// aribon2-4-3_d
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

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt");
    cin.rdbuf(in.rdbuf());
#endif

    int N, Q;
    cin >> N >> Q;

    auto uf = UnionFind(2 * N);

    int w, x, y, z;
    REP(q, Q){
        cin >> w >> x >> y >> z;
        x--; y--;

        if (w == 1){
            if (z % 2 == 0){
                uf.unite(x, y);
                uf.unite(x + N, y + N);
            } else {
                uf.unite(x, y + N);
                uf.unite(x + N, y);
            }
        } else{

            if (uf.same(x, y) || uf.same(x+N, y+N)){
                print("YES");
            } else {
                print("NO");
            }
        };
    }

    return 0;
}
