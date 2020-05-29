// past02_n
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
        val[k] = val[k*2+1] + val[k*2+2];
    }

    void add(int a, int b, int x) {
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

    int N, Q;
    cin >> N >> Q;
    vector<tuple<int, int, int, int>> Area(N);
    REP(i, N){
         int x, y, d, c;
         cin >> x >> y >> d >> c;
         Area[i] = tie(x, y, d, c);
    }

    vector<tuple<int, int, int>> Building(Q);
    REP(i, Q) {
        int x, y;
        cin >> x >> y;
        Building[i] = tie(x, y, i);
    }
    sort(ALL(Building));

    // 座標圧縮
    vector<int> Ys{(int)-2e9-1, (int)2e9+1};
    REP(i, N) {
        int x, y, d, c;
        tie(x, y, d, c) = Area[i];
        Ys.emplace_back(y);
        Ys.emplace_back(y+d);
    }
    REP(i, Q){
        int x, y, idx;
        tie(x, y, idx) = Building[i];
        Ys.emplace_back(y);
    }

    //　重複要素を消す
    sort( ALL( Ys ) );
    Ys.erase( unique( ALL( Ys ) ), Ys.end() );

    // 新しい座標の取得
    vector<tuple<int, int, int, int>> AreaXMin(N);
    vector<tuple<int, int, int, int>> AreaXMax(N);
    REP(i, N) {
        int x, y, d, c;
        tie(x, y, d, c) = Area[i];
        int ymin = distance(Ys.begin(), lower_bound(ALL(Ys), y));
        int ymax = distance(Ys.begin(), lower_bound(ALL(Ys), y+d));
        AreaXMin[i] = tie(x, ymin, ymax, c);
        int xmax = x + d;
        AreaXMax[i] = tie(xmax, ymin, ymax, c);
    }
    sort(ALL(AreaXMin));
    sort(ALL(AreaXMax));

    REP(i, Q){
        int x, y, idx;
        tie(x, y, idx) = Building[i];
        y = distance(Ys.begin(), lower_bound(ALL(Ys), y));
        Building[i] = tie(x, y, idx);
    }

    LazySegmentTree<ll> st(Ys.size());

    int idxXMin = 0;
    int idxXMax = 0;
    vector<ll> ans(Q);
    REP(i, Q){
        int bx, by, bi;
        tie(bx, by, bi) = Building[i];

        while (idxXMin < N && get<0>(AreaXMin[idxXMin]) <= bx){
            int x, ymin, ymax, c;
            tie(x, ymin, ymax, c) = AreaXMin[idxXMin];
            st.add(ymin, ymax+1, c);

            idxXMin++;
        }

        while (idxXMax < N && get<0>(AreaXMax[idxXMax]) < bx){
            int x, ymin, ymax, c;
            tie(x, ymin, ymax, c) = AreaXMax[idxXMax];
            st.add(ymin, ymax+1, -c);

            idxXMax++;
        }

        ans[bi] = st.get_sum(by, by+1);
    }

    REP(i, Q){
        print(ans[i]);
    }


    return 0;
}
