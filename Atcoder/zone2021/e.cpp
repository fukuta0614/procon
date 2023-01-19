// zone2021_e
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
//struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

struct Grid {

    int H, W;
    vector<vector<ll>> A, B;

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

    Grid(int H, int W, vector<vector<ll>>& A, vector<vector<ll>>& B): H(H), W(W), A(A), B(B) {}

    ll dijkstra(int si, int sj, int gi, int gj){

        priority_queue<P, vector<P>, greater<P> > pq;
        pq.emplace(0, hash_func(si, sj));

        vector<vector<ll>> dist(H, vector<ll>(W, INF));
        dist[si][sj] = 0;

//        print(si, sj, gi, gj);

        while (!pq.empty()){
            P p = pq.top(); pq.pop();

            ll cost = p.first;
            int hash = p.second;
            auto [i, j] = rev_hash(hash);

            if (cost >= dist[gi][gj]){
                return dist[gi][gj];
            }

            if (cost > dist[i][j]){
                continue;
            }

            for (int k = 0; k < 3; ++k) {
                int ni = i;
                int nj = j;
                ll ncost = cost;

                if (k == 0){
                    nj++;
                    ncost += A[i][j];
                } else if (k == 1){
                    nj--;
                    ncost += j > 0 ? A[i][j-1] : 0;
                } else {
                    ni++;
                    ncost += B[i][j];
                }
                if (not bound_check(ni, nj)) continue;

                if (ncost < dist[ni][nj]) {
                    dist[ni][nj] = ncost;
                    pq.emplace(ncost, hash_func(ni, nj));
                }
            }

            REPN(k, 1, i+1){
                int ni = i-k;
                int nj = j;
                ll ncost = cost + 1+k;

                if (ncost < dist[ni][nj]) {
                    dist[ni][nj] = ncost;
                    pq.emplace(ncost, hash_func(ni, nj));
                }
            }
        }

//        print(A);
//        print(B);
//        REP(i, H){
//            print(dist[i]);
//        }
        return -1;
    }

};


int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int R, C;
    cin >> R >> C;
    vector<vector<ll>> A(R, vector<ll>(C, INF));
    REP(i, R) REP(j, C-1) cin >> A[i][j];
    vector<vector<ll>> B(R, vector<ll>(C, INF));
    REP(i, R-1) REP(j, C) cin >> B[i][j];

    Grid g(R, C, A, B);

//    print(R, C);
//    print(A);
//    print(B);

    ll ans = g.dijkstra(0, 0, R-1, C-1);
    print(ans);

    return 0;
}
