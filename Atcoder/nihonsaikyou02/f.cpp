// nihonsaikyou02_f
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
//struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;


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
    void add(int k, T x){
        auto org = query(k, k+1);
        update(k, org + x);
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

    ll N, M, Q;
    cin >> N >> M >> Q;

    vector<int> T(Q), X(Q), Y(Q);
    REP(i, Q) cin >> T[i] >> X[i] >> Y[i];

    set<int> y_set{0};
    REP(i, Q) y_set.emplace(Y[i]);

    vector<ll> y_order(ALL(y_set)); // 0, 5, 10, 20, 30
    map<int, int> y_map; // 0 -> 0, 5 -> 1, 10 -> 2, ..
    REP(i, y_order.size()){
        y_map[y_order[i]] = i;
    }

    auto f = [](ll a, ll b){return a + b;};
    ll ti = 0;

    int y_num = y_set.size();
    auto segtree_a_idx = SegmentTree<ll>(f, ti, y_num);
    auto segtree_a_val = SegmentTree<ll>(f, ti, y_num);
    auto segtree_b_idx = SegmentTree<ll>(f, ti, y_num);
    auto segtree_b_val = SegmentTree<ll>(f, ti, y_num);

    segtree_a_idx.add(0, N);
    segtree_b_idx.add(0, M);

    vector<ll> A(N), B(M);

//    print(y_map);

    ll ans = 0;
    REP(i, Q){
        X[i]--;
        if (T[i] == 1){
            ll v = A[X[i]];

            int idx1 = y_map[v];
            int idx2 = y_map[Y[i]];

            if (idx1 < idx2){
                ll lower_num = segtree_b_idx.query(0, idx1);

                ll middle_num = segtree_b_idx.query(idx1, idx2);
                ll middle_sum = segtree_b_val.query(idx1, idx2);

                ans += -lower_num * v - middle_sum + Y[i] * (lower_num + middle_num);
            } else {
                ll lower_num = segtree_b_idx.query(0, idx1);

                ll middle_num = segtree_b_idx.query(0, idx2);
                ll middle_sum = segtree_b_val.query(idx2, idx1);

                ans += -lower_num * v + middle_sum + Y[i] * middle_num;
            }

            segtree_a_idx.add(idx1, -1);
            segtree_a_idx.add(idx2, 1);
            segtree_a_val.add(idx1, -v);
            segtree_a_val.add(idx2, Y[i]);

            A[X[i]] = Y[i];

        } else {
            ll v = B[X[i]];

            int idx1 = y_map[v];
            int idx2 = y_map[Y[i]];

            if (idx1 < idx2){
                ll lower_num = segtree_a_idx.query(0, idx1);

                ll middle_num = segtree_a_idx.query(idx1, idx2);
                ll middle_sum = segtree_a_val.query(idx1, idx2);

                ans += -lower_num * v - middle_sum + Y[i] * (lower_num + middle_num);
            } else {
                ll lower_num = segtree_a_idx.query(0, idx1);

                ll middle_num = segtree_a_idx.query(0, idx2);
                ll middle_sum = segtree_a_val.query(idx2, idx1);

                ans += -lower_num * v + middle_sum + Y[i] * middle_num;
            }

            segtree_b_idx.add(idx1, -1);
            segtree_b_idx.add(idx2, 1);
            segtree_b_val.add(idx1, -v);
            segtree_b_val.add(idx2, Y[i]);

            B[X[i]] = Y[i];
        }

//        print(A);
//        print(B);
        print(ans);
    }




    return 0;
}
