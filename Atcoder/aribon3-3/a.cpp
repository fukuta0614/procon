// aribon3-3_a
// Range Query - Range Minimum Query (RMQ)
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A&lang=jp
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
    T query(int a, int b, int k=0, int l=0, int r=-1) {
        if (r < 0) r = n;

        // [a, b)と[l, r)が交差しなければ単位元を返す
        if (r <= a || b <= l) return ti;

        // [a, b)が[l, r)を完全に含んでいればその節点の値
        if (a <= l && r <= b) return dat[k];

        int m = (l + r) / 2;
        T vl = query(a, b, k*2+1, l, m);
        T vr = query(a, b, k*2+2, m, r);
        return f(vl, vr);
    }
};

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N,Q;
    cin >> N >> Q;

    auto f = [](int a, int b){ return min(a, b); };
    int ti = (int)((1ll<<31) - 1);
    auto st = SegmentTree<int>(f, ti, N);

    REP(i, Q){
        int c, x, y;
        cin >> c >> x >> y;
        if (c == 0){
            st.update(x, y);
        } else {
            int ans = st.query(x, y+1);
            print(ans);
        }
    }

    return 0;
}
