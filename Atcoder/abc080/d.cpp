// abc080_d
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

#define INF (ll)(1e9)
#define MOD (1000000007)

#define print2D(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }
#define print_line(vec, n) {for(int idx=0;idx<(n-1);idx++) cout << (vec)[idx] << " "; cout << (vec)[(n)-1] << endl;}
template<class T> void print(const T& x){cout << x << "\n";}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;


// 区間add, 区間max
template<typename T>
struct LazySegmentTree{
    int n;
    vector<T> val;
    vector<T> lazy;

    explicit LazySegmentTree(int n_){
        n = 1;
        while (n < n_) n <<= 1;

        val = vector<T>(n<<1, 0);
        lazy = vector<T>(n<<1, 0);
    }
    void lazy_propagate(int k) {
        val[k] += lazy[k];
        if (k < n-1) {
            lazy[k*2+1] += lazy[k];
            lazy[k*2+2] += lazy[k];
        }
        lazy[k] = 0;
    }
    void add(int a, int b, int k, int l, int r, int x) {
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
        val[k] = max(val[k*2+1], val[k*2+2]);
    }

    void add(int a, int b, int x) {
        add(a, b, 0, 0, n, x);
    }

    T get_max(int a, int b, int k, int l, int r) {
        lazy_propagate(k);

        if (b <= l || r <= a) {
            return 0;
        }
        if (a <= l && r <= b) {
            return val[k];
        }
        int mid = (l+r)/2;
        T sl = get_max(a, b, k*2+1, l, mid);
        T sr = get_max(a, b, k*2+2, mid, r);
        return max(sl, sr);
    }

    T get_max(int a, int b) {
        return get_max(a, b, 0, 0, n);
    }
};


int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N, C;
    cin >> N >> C;

    int maxT = 1e5+10;
    auto segtree = LazySegmentTree<int>(maxT);

    vector<vector<P>> inp(C);
    REP(i, N){
        int s, t, c;
        cin >> s >> t >> c;
        inp[c-1].emplace_back(s, t);
    }

    REP(i, C){
        if (inp[i].empty()) continue;
        sort(ALL(inp[i]));
        REP(j, inp[i].size()){
            int s = inp[i][j].first;
            while (j < inp[i].size() - 1 && inp[i][j].second == inp[i][j+1].first){
                j++;
            }
            int t = inp[i][j].second;
            segtree.add(s, t+1, 1);
        }
    }
    int ans = segtree.get_max(0, maxT+1);
    print(ans);


    return 0;
}
