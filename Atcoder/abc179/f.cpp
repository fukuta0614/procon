// abc179_f
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
template<class T> void print(const T& x){cout << x << "\n";}
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

        val = vector<T>(n<<1, INF); // TODO 初期値セット
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

    ll N, Q;
    cin >> N >> Q;


    LazySegmentTree<int> w_left(N), w_top(N);
    w_left.update(0, N+1, N-1);
    w_top.update(0, N+1, N-1);

    ll ans = (N-2) * (N-2);
    int left = N-1, top = N-1;
    REP(i, Q){
        int t, a;
        cin >> t >> a; a--;
        if (t == 1){ // 上におく

            int y = w_top.get_min(a, a+1);
            if (a < left){
                w_left.update(0, y+1, a);
                left = a;
            }
//            w_top.update(a, a+1, 0);
            ans -= (y-1);

        } else {

            int x = w_left.get_min(a, a+1);
            if (a < top){
                w_top.update(0, x+1, a);
                top = a;
            }
//            w_left.update(a, a+1, 0);
            ans -= (x-1);
        }
//        print("top");
//        REP(k, N){
//            cout << w_top.get_min(k, k+1) << " ";
//        }
//        cout << endl;
//
//        print("left");
//        REP(k, N){
//            cout << w_left.get_min(k, k+1) << " ";
//        }
//        cout << endl;
//        print(ans);

    }

    print(ans);


    return 0;
}
