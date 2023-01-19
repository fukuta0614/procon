// abc201_f
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

template<typename T>
struct SegmentTree {
    using F = function<T(T, T)>;
    int n;
    F f;
    T ti;
    vector<T> dat;
    SegmentTree(F f, T ti, int n_) : f(f), ti(ti) {
        n = 1;
        while (n < n_) n <<= 1;
        dat.assign(n << 1, ti);
    }
    void update(int k, T x) {
        k += n - 1;
        dat[k] = x;
        while (k > 0){
            k = (k - 1) / 2;
            dat[k] = f(dat[k * 2 + 1], dat[k * 2 + 2]);
        }
    }
    T query(int a, int b, int k, int l, int r) {
        // [a, b)と[l, r)が交差しなければ単位元を返す
        if (r <= a || b <= l) return ti;

        // [a, b)が[l, r)を完全に含んでいればその節点の値
        if (a <= l && r <= b) return dat[k];

        int m = (l + r) / 2;
        T vl = query(a, b, k*2+1, l, m);
        T vr = query(a, b, k*2+2, m, r);
        return f(vl, vr);
    }
    T query(int a, int b) { // wrapper
        return query(a, b, 0, 0, n);
    }
};

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N;
    cin >> N;
    vector<int> P(N);
    vector<int> pos(N);
    REP(i, N) {
        cin >> P[i];
        pos[P[i]-1] = i;
    }

    vector<ll> A(N), B(N), C(N), minAB(N), minAC(N), cumsum_A(N+1), cumsum_minAB(N+1), cumsum_minAC(N+1);
    REP(i, N) {
        cin >> A[i] >> B[i] >> C[i];
        minAB[i] = min(A[i], B[i]);
        minAC[i] = min(A[i], C[i]);
        cumsum_A[i+1] = cumsum_A[i] + A[i];
        cumsum_minAB[i+1] = cumsum_minAB[i] + minAB[i];
        cumsum_minAC[i+1] = cumsum_minAC[i] + minAC[i];
    }

    auto f = [](ll a, ll b){return min(a, b);};
    ll ti = INF;
    auto segtree = SegmentTree<ll>(f, ti, N);

    vector<ll> dp(N, INF);
    ll ans = INF;
    REP(i, N) {
        dp[i] = min(cumsum_minAB[i], segtree.query(0, pos[i]) + cumsum_A[i]);

        segtree.update(pos[i], dp[i] - cumsum_A[i+1]);

        ans = min(ans, dp[i] + cumsum_minAC[N] - cumsum_minAC[i+1]);
    }
//    print(cumsum_minAC);
//    print(dp);

    print(ans);



    return 0;
}
