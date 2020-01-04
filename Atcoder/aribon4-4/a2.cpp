// aribon4-4_a
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
#define print_line(vec, n) {for(int i=0;i<(n-1);i++) cout << (vec)[i] << " "; cout << (vec)[(n)-1] << endl;}
template<class T> void print(const T& x){cout << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

// 区間update, 区間min
template<typename T>
struct LazySegmentTree{
    int n;
    vector<T> val;
    vector<T> lazy;

    explicit LazySegmentTree(int n_){
        n = 1;
        while (n < n_) n <<= 1;

        val = vector<T>(n<<1, 0);
        lazy = vector<T>(n<<1, -1);
    }
    void lazy_propagate(int k) {
        if (lazy[k] == -1) return;

        val[k] = lazy[k];
        if (k < n-1) {
            lazy[k*2+1] = lazy[k];
            lazy[k*2+2] = lazy[k];
        }
        lazy[k] = -1;
    }
    void update(int a, int b, int k, int l, int r, int x) {
        lazy_propagate(k);

        if (b <= l || r <= a) {
            return;
        }
        if (a <= l && r <= b) {
            lazy[k] = x;
            lazy_propagate(k);
            return;
        }
        int mid = (l+r)/2;
        update(a, b, k*2+1, l, mid, x);
        update(a, b, k*2+2, mid, r, x);
        val[k] = min(val[k*2+1], val[k*2+2]);
    }

    void update(int a, int b, int x) {
        update(a, b, 0, 0, n, x);
    }

    T get_min(int a, int b, int k, int l, int r) {
        lazy_propagate(k);

        if (b <= l || r <= a) {
            return INF;
        }
        if (a <= l && r <= b) {
            return val[k];
        }
        int mid = (l+r)/2;
        T sl = get_min(a, b, k*2+1, l, mid);
        T sr = get_min(a, b, k*2+2, mid, r);
        return min(sl, sr);
    }

    T get_min(int a, int b) {
        return get_min(a, b, 0, 0, n);
    }
};

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N;
    cin >> N;
    vector<int> H(N);
    REP(i, N) cin >> H[i];

    vector<int> L(N), R(N);

    vector<int> stk(N);
    int sz = 0;
    REP(i, N){
        while(sz > 0 && H[stk[sz-1]] >= H[i]) sz--;
        L[i] = sz == 0 ? 0 : stk[sz-1] + 1;
        stk[sz++] = i;
    }

    sz = 0;
    REP_REV(i, N){
        while(sz > 0 && H[stk[sz-1]] >= H[i]) sz--;
        R[i] = sz == 0 ? N : stk[sz-1];
        stk[sz++] = i;
    }
//
//    print(L);
//    print(R);

    vector<pair<int, int>> tmp(N);
    REP(i, N) tmp[i] = make_pair(H[i], i);
    sort(tmp.begin(), tmp.end());
    reverse(tmp.begin(), tmp.end());

    LazySegmentTree<ll> sst(N+1);

    int ans = 0;
    REP(i, N) {
        int idx = tmp[i].second;
        if(sst.get_min(L[idx], R[idx]) == 0) {
            ans++;
            sst.update(L[idx], R[idx], 1);
        }
        if(sst.get_min(0, N+1) == 1) break;
    }

    print(ans);

    return 0;
}
