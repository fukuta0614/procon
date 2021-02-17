// arc112_d
#pragma GCC optimize ("O3")

#include <bits/stdc++.h>
#ifdef LOCAL
#include "../../debug_util/cxx-prettyprint/prettyprint.hpp"
#include "../../debug_util/rng.hpp"
#include "../../debug_util/timer.hpp"
#endif
using namespace std;

using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

#define REP(i, n) for (int i = 0 ; i < (int)(n) ; ++i)
#define REPN(i, m, n) for (int i = m ; i < (int)(n) ; ++i)
#define REP_REV(i, n) for (int i = (int)(n) - 1 ; i >= 0 ; --i)
#define REPN_REV(i, m, n) for (int i = (int)(n) - 1 ; i >= m ; --i)
#define ALL(x) x.begin(), x.end()

#define INF (ll)(1e9)
#define MOD (1000000007)

#define print2D(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }
#define print_line(vec, n) {for(int idx=0;idx<(n-1);idx++) cout << (vec)[idx] << " "; cout << (vec)[(n)-1] << endl;}
template<class T> void print(const T& x){cout << x << "\n";}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

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


int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    REP(i, H) cin >> S[i];

    UnionFind uf(H+W);
    uf.unite(0, H);
    uf.unite(H-1, H);
    uf.unite(0, H+W-1);
    uf.unite(H-1, H+W-1);

    REP(i, H) REP(j, W){
        if (S[i][j] == '#'){
            uf.unite(i, H+j);
        }
    }

    set<int> x, y;
    REP(i, H) x.emplace(uf.find(i));
    REP(i, W) y.emplace(uf.find(H+i));

    int ans = min(x.size(), y.size()) - 1;
    print(ans);

    return 0;
}
