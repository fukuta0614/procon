// abc153_f
#include <bits/stdc++.h>
#ifdef LOCAL
#include "../cxx-prettyprint/prettyprint.hpp"
#endif
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

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


// 区間add, 区間sum
template<typename T>
struct LazySegmentTree{
    int n;
    vector<T> val;
    vector<T> lazy;
    vector<int> width;

    explicit LazySegmentTree(int n_){
        n = 1;
        while (n < n_) n <<= 1;

        val = vector<T>(n<<1, 0);
        lazy = vector<T>(n<<1, 0);
        width = vector<int>(n<<1, 1);
        for (int i = n-2; i >= 0; i--) {
            width[i] = width[i*2+1] + width[i*2+2];
        }
    }
    void lazy_propagate(int k) {
        val[k] += lazy[k] * width[k];
        if (k < n-1) {
            lazy[k*2+1] += lazy[k];
            lazy[k*2+2] += lazy[k];
        }
        lazy[k] = 0;
    }
    void add(int a, int b, int k, int l, int r, T x) {
        lazy_propagate(k);

        if (b <= l || r <= a) {
            return;
        }
        if (a <= l && r <= b) {
            lazy[k] += x;
            lazy_propagate(k);
            return;
        }
        int mid = (l+r)/2;
        add(a, b, k*2+1, l, mid, x);
        add(a, b, k*2+2, mid, r, x);
        val[k] = val[k*2+1] + val[k*2+2];
    }

    void add(int a, int b, T x) {
        add(a, b, 0, 0, n, x);
    }

    T get_sum(int a, int b, int k, int l, int r) {
        lazy_propagate(k);

        if (b <= l || r <= a) {
            return 0;
        }
        if (a <= l && r <= b) {
            return val[k];
        }
        int mid = (l+r)/2;
        T sl = get_sum(a, b, k*2+1, l, mid);
        T sr = get_sum(a, b, k*2+2, mid, r);
        return sl + sr;
    }

    T get_sum(int a, int b) {
        return get_sum(a, b, 0, 0, n);
    }
};

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N, D, A;
    cin >> N >> D >> A;
    vector<P> XH(N);
    REP(i, N) cin >> XH[i].first >> XH[i].second;
    sort(ALL(XH));

    vector<ll> H(N); // 何回爆破する必要があるか
    vector<ll> R(N); //この一個前まで爆破される
    int r = 0;
    REP(l, N){
        while (r < N-1 && XH[r+1].first <= XH[l].first + 2 * D){
            r++;
        }
        R[l] = r;
        H[l] = (XH[l].second + A - 1) / A;
    }

    LazySegmentTree<ll> st(N);
    REP(i, N){
        st.add(i, i+1, H[i]);
    }

    ll ans = 0;
    REP(i, N){
        ll val = st.get_sum(i, i+1);
        if (val > 0){
            st.add(i, R[i]+1, -val);
            ans += val;
        }
    }

    print(ans);


    return 0;
}
