// abc174_f
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

#define INF (ll)(1e9)
#define MOD (1000000007)

#define print2D(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }
#define print_line(vec, n) {for(int idx=0;idx<(n-1);idx++) cout << (vec)[idx] << " "; cout << (vec)[(n)-1] << endl;}
template<class T> void print(const T& x){cout << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;


set<int> f(set<int>& a, set<int>& b) {
    if (a.size() < b.size()) {
        swap(a, b);
    }
    set<int> s(a);
    s.insert(b.begin(), b.end());

    return s;
}

template<typename T>
struct SegmentTree {
    int n;
    T ti;
    vector<T> dat;
    SegmentTree(T ti, int n_) : ti(ti) {
        n = 1;
        while (n < n_) n <<= 1;
        dat.assign(n << 1, ti);
    }
    void update(int k, T x) {
        k += n - 1;
        dat[k] = x;
        set<int> t{x};
        while (k > 0){
            int k_ = (k - 1) / 2;
            dat[k_] = f(dat[k_], t);
            k = k_;
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

    int N, Q;
    cin >> N >> Q;
    vector<int> C(N);
    REP(i, N) cin >> C[i];


    set<int> ti;
    auto segtree = SegmentTree<set<int>>(ti, N);


    REP(i, N){
        segtree.update(i, set<int>{C[i]});
    }

    REP(i, Q){
        int l, r;
        cin >> l >> r;
        l--, r--;
        set<int> x = segtree.query(l, r+1);
        print(x.size());
//        print(0);
    }


    return 0;
}
