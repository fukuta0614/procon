// aribon3-4_d
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

template<typename T>
struct SegmentTree {
    using F = function<T(T, T)>;
    int n=1;
    F f;
    T ti;
    vector<T> dat;
    SegmentTree()= default;
    SegmentTree(F f, T ti, int n_) : f(f), ti(ti) {
        n = 1;
        while (n < n_) n <<= 1;
        dat.assign(n << 1, ti);
    }
    void init(F f_, T ti_, int n_) {
        f = f_;
        ti = ti_;
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
    friend ostream& operator<<(ostream& os, const SegmentTree<T>& st) {
        vector<T> v(st.n);
        REP(i, st.n) v[i] = st.dat[i+st.n-1];
        os << v; return os;
    }
};

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N, K;
    cin >> N >> K;
    vector<int> V(N);
    REP(i, N) cin >> V[i];

    auto tmp = V;
    sort(ALL(tmp));
    REP(i, N) V[i] = lower_bound(ALL(tmp), V[i]) - tmp.begin();

    auto f = [](int a, int b){return max(a, b);};
    int ti = 0;
    vector<SegmentTree<int>> dp(K+1, SegmentTree<int>(f, ti, N));

    REP(i, N){
        REPN_REV(k, 1, K+1){
            int x1 = dp[k].query(0, V[i]) + 1;
            int x2 = dp[k-1].query(V[i], N) + 1;
            dp[k].update(V[i], max(x1, x2));
        }

        int x = dp[0].query(0, V[i]) + 1;
        dp[0].update(V[i], x);
    }

    print(dp[K].query(0, N));




    return 0;
}
