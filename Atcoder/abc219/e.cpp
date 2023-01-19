// abc219_e
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

#define INF (ll)(1e15)
#define MOD (1000000007)

#define print2D(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }
#define print_line(vec, n) {for(int idx=0;idx<(n-1);idx++) cout << (vec)[idx] << " "; cout << (vec)[(n)-1] << endl;}
template<class T> void print(const T& x){cout << x << "\n";}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

int dx[8]={ 1, 0, -1, 0, -1, 1, -1, 1};
int dy[8]={ 0, 1, 0, -1, -1, -1, 1, 1};
bool bound_check(int i, int j, int N, int M) {return (0 <= i) && (i < N) && (0 <= j) && (j < M);}
string to_bin(int n){ std::stringstream ss; ss << std::bitset<16>(n); return ss.str(); }

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

    vector<vector<int>> A(4, vector<int>(4, 0));

    int need = 0;
    REP(i, 4) REP(j, 4) {
        cin >> A[i][j];
        if (A[i][j]){
            need |= 1 << (4*i+j);
        }
    }

    int ans = 0;
    REPN(p, 1, 1 << 16){

        if ((p & need) != need) continue;

        int start = -1;
        REP(i, 4) REP(j, 4){
            if ( ((p >> (4*i+j)) & 1) && (start == -1)) {
                start = i * 4 + j;
            }
        }

        UnionFind uf(16);
        REP(i, 4) REP(j, 4){
            if (((p >> (i*4+j)) &1) == 0) continue;
            REP(k, 4){
                int ni = i + dx[k];
                int nj = j + dy[k];

                if (not bound_check(ni, nj, 4, 4)){
                    continue;
                }

                if (((p >> (ni*4+nj)) &1)) {
                    uf.unite(i*4+j, ni*4+nj);
                }
            }
        }

        UnionFind uf2(17);
        REP(i, 4) REP(j, 4){
            if ((p >> (i*4+j)) &1) continue;
            REP(k, 4){
                int ni = i + dx[k];
                int nj = j + dy[k];

                if (not bound_check(ni, nj, 4, 4)){
                    uf2.unite(i*4+j, 16);
                    continue;
                }

                if (!((p >> (ni*4+nj)) &1)) {
                    uf2.unite(i*4+j, ni*4+nj);
                }
            }
        }

        if (uf.get_size(start) == __builtin_popcount(p) && uf2.get_size(16) == (17 - __builtin_popcount(p))) {

            ans++;

//            print(to_bin(p));
//            vector<string> B(4);
//            REP(i, 4) REP(j, 4){
//                if ((p >> (4*i+j)) & 1){
//                    B[i] += '#';
//                } else {
//                    B[i] += '.';
//                }
//            }
//            REP(i, 4) print(B[i]);
        }
    }

    print(ans);


    return 0;
}
