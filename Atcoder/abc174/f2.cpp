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
template<class T> void print(const T& x){cout << x << "\n";}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;



template <typename T>
struct RangeTree {
    int n;
    vector<vector<T>> dat;
    vector<T> val;

    explicit RangeTree(vector<T>& val_): val(val_) {
        n = 1;
        while (n < val.size()) n <<= 1;
        dat.assign(n << 1, vector<T>());

        build(0, 0, val.size());
    }

    void build(int k, int l, int r) {
        if (r-l == 1) {
            dat[k].emplace_back(val[l]);
        } else {
            int lch = 2*k+1, rch = 2*k+2;
            build(lch, l, (l+r)/2);
            build(rch, (l+r)/2, r);
            dat[k].resize(r-l);
            merge(dat[lch].begin(), dat[lch].end(), dat[rch].begin(), dat[rch].end(), dat[k].begin());
        }
    }

    int query(int i, int j, T x) {
        return query(i, j, x, 0, 0, val.size());
    }

    int query(int i, int j, T x, int k, int l, int r) {
        if (j <= l || r <= i) return 0;
        // x以下の要素の数
//        if (i <= l && r <= j) return upper_bound(dat[k].begin(), dat[k].end(), x) - dat[k].begin();
        // x未満の要素の数
        if (i <= l && r <= j) return lower_bound(dat[k].begin(), dat[k].end(), x) - dat[k].begin();
        int lch = query(i, j, x, 2*k+1, l, (l+r)/2);
        int rch = query(i, j, x, 2*k+2, (l+r)/2, r);
        return lch+rch;
    }
};


int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N, Q;
    cin >> N >> Q;
    vector<int> C(N);
    REP(i, N) {cin >> C[i]; C[i]--;}

    vector<int> last(N, N);
    vector<int> nxt(N);
    REP_REV(i, N){
        nxt[i] = last[C[i]];
        last[C[i]] = i;
    }

    // [l,r)で、r未満の要素の数を数える
    RangeTree<int> rt(nxt);

    REP(i, Q){
        int l, r;
        cin >> l >> r; l--;
        int ans = r - l - rt.query(l, r, r);
        print(ans);
    }


    return 0;
}
