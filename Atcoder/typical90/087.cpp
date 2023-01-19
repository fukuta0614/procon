// typical90_087
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


int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    ll N, P, K;
    cin >> N >> P >> K;

    vector<vector<ll>> A(N, vector<ll>(N));
    REP(i, N) REP(j, N) cin >> A[i][j];

    auto cnt_path = [&](ll X){

        auto dist = A;
        REP(i, N) REP(j, N) dist[i][j] = (dist[i][j] == -1 ? X : dist[i][j]);

        // warshall-floyd
        REP(k, N) REP(i, N) REP(j, N){
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }

        ll cnt = 0;
        REP(i, N) REPN(j, i + 1, N) {
            if (dist[i][j] <= P) {
                cnt++;
            }
        }
        return cnt;
    };

    // X=0のときにP以下で行ける数がそもそもKより少ないと、Xを大きくしても更に少なくなるだけ
    ll cnt_0 = cnt_path(0);
    if (cnt_0 < K){
        print(0);
        return 0;
    }

    // X=infのときにP以下で行ける数がそもそもKより多いと、Xを小さくしても更に多くなるだけ
    ll cnt_inf = cnt_path(2e9);
    if (cnt_inf > K){
        print(0);
        return 0;
    }

    // ちょうどKだと、どんだけ大きくしてもKなので、無限
    if (cnt_inf == K){
        print("Infinity");
        return 0;
    }

    // P以下で行ける数がK以上になるようなXの最大値
    ll ok = 0;
    ll ng = 2e9;
    while (ng - ok > 1){

        ll X = (ok + ng) / 2;
        ll cnt = cnt_path(X);
        if (cnt >= K){
            ok = X;
        } else {
            ng = X;
        }
    }

    ll X_inf = ok;

    // P以下で行ける数がK以下になるようなXの最小値
    ok = 2e9;
    ng = 0;
    while (ok - ng > 1){

        ll X = (ok + ng) / 2;
        ll cnt = cnt_path(X);
        if (cnt <= K){
            ok = X;
        } else {
            ng = X;
        }
    }

    ll X_sup = ok;

//    ll ans = X_sup - X_inf + 1;
    ll ans = X_inf - X_sup + 1;

//    print(X_inf);
//    print(X_sup);

    print(ans);


    return 0;
}
