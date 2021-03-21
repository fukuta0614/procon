// abc088_d
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


struct Grid {

    int H, W;
    vector<string> S;

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

    Grid(int H, int W, vector<string>& S): H(H), W(W), S(S) {}

    // not verified yet
    ll dijkstra(int si, int sj, int gi, int gj){

        priority_queue<P, vector<P>, greater<P> > pq;
        pq.emplace(0, hash_func(si, sj));

        vector<ll> dist(H*W, INF);
        dist[hash_func(si, sj)] = 0;

        while (!pq.empty()){
            P p = pq.top(); pq.pop();

            ll cost = p.first;
            int hash = p.second;
            auto [i, j] = rev_hash(hash);

            for (int k = 0; k < 4; ++k) {
                int ni = i + dx[k];
                int nj = j + dy[k];
                if (not bound_check(ni, nj)) continue;
                if (S[ni][nj] == '#') continue;

                ll ncost = cost + 1;
                int nhash = hash_func(ni, nj);

                if (ncost < dist[nhash]) {
                    dist[nhash] = ncost;
                    pq.emplace(ncost, nhash);
                }
            }
        }
        return dist[hash_func(gi, gj)] == INF ? -1 : dist[hash_func(gi, gj)];
    }

    // abc088Dでverify
    ll bfs(int si, int sj, int gi, int gj){
        queue<int> q;
        q.emplace(hash_func(si, sj));

        vector<ll> dist(H*W, INF);
        dist[hash_func(si, sj)] = 0;

        while (!q.empty()) {
            int hash = q.front(); q.pop();
            auto [i, j] = rev_hash(hash);

            for (int k = 0; k < 4; ++k) {
                int ni = i + dx[k];
                int nj = j + dy[k];
                if (not bound_check(ni, nj)) continue;
                if (S[ni][nj] == '#') continue;

                int nhash = hash_func(ni, nj);
                if (dist[hash] + 1 < dist[nhash]) {
                    dist[nhash] = dist[hash] + 1;
                    q.emplace(nhash);
                }
            }
        }
        return dist[hash_func(gi, gj)] == INF ? -1 : dist[hash_func(gi, gj)];
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

    int num = 0;
    REP(i, H) REP(j, W){
        num += S[i][j] == '.';
    }

    Grid g(H, W, S);
    ll d = g.bfs(0, 0, H-1, W-1);

    if (d == -1){
        print(-1);
    } else {
        ll ans = num - (d+1);
        print(ans);
    }


    return 0;
}
