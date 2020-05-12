// abc149_e
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

#define INF (ll)(1e12)
#define MOD (1000000007)

#define print2D(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }
#define print_line(vec, n) {for(int i=0;i<(n-1);i++) cout << (vec)[i] << " "; cout << (vec)[(n)-1] << endl;}
template<class T> void print(const T& x){cout << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

ll N, M;
vector<ll> A;
vector<ll> cumsum;

// 幸福度、積だと勘違いした使えそうなので残しとく
//ll count_mul(ll x, ll& sm){
//
//    ll cnt = 0;
//    REP(i, N){
//        ll d = (x + A[i] - 1) / A[i];
//        auto idx = distance(A.begin(), lower_bound(ALL(A), d));
//        cnt += N - idx;
//        sm += A[i] * (cumsum[N] - cumsum[idx]);
//        print(x, i, idx, N-idx, A[i] * (cumsum[N] - cumsum[idx]));
//    }
//
//    return cnt;
//}

ll count_sum(ll x, ll& sm){

    ll cnt = 0;
    REP(i, N){
        ll d = x - A[i];
        auto idx = distance(A.begin(), lower_bound(ALL(A), d));
        cnt += N - idx;
        sm += (N-idx) * A[i] + (cumsum[N] - cumsum[idx]);
//        print(x, i, idx, N-idx, (N-idx) * A[i] + (cumsum[N] - cumsum[idx]));
    }

    return cnt;
}


int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    cin >> N >> M;
    A.assign(N, 0);
    REP(i, N) cin >> A[i];
    sort(ALL(A));

    cumsum.assign(N+1, 0);
    REP(i, N) cumsum[i+1] = A[i] + cumsum[i];

    // x以上の和の数がM以上になる最大のx
    ll ok = 0;
    ll ng = INF;
    while (ng - ok > 1){

        ll mid = (ok + ng) / 2;

        ll sm = 0;
        ll cnt = count_sum(mid, sm);
        if (cnt >= M){
            ok = mid;
        } else {
            ng = mid;
        }
    }

    ll ans = 0;
    ll cnt = count_sum(ok, ans);
    if (cnt > M){
        ans -= (cnt-M) * ok;
    }

    print(ans);

    return 0;
}
