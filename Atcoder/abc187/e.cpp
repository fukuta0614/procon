// abc187_e
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

// 頂点のオイラーツアー
struct Graph {

    int n;
    vector<vector<int>> edges;
    vector<int> begin_indices, end_indices;
    vector<int> euler_tour;
    vector<int> depth;

    Graph(int n_): n(n_), edges(n_), begin_indices(n_), end_indices(n_), depth(n_) {

    }

    void add_edge(int u, int v){
        edges[u].emplace_back(v);
        edges[v].emplace_back(u);
    }

    void dfs(int v = 0, int p = -1, int d = 0) {

        depth[v] = d;

        begin_indices[v] = euler_tour.size();
        euler_tour.emplace_back(v);

        for (auto e: edges[v]){
            if (e == p) continue;

            dfs(e, v, d+1);
            euler_tour.emplace_back(v);
        }

        end_indices[v] = euler_tour.size();
    }
};

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

    int N;
    cin >> N;

    auto g = Graph(N);

    vector<int> A(N-1), B(N-1);
    REP(i, N-1){
        cin >> A[i] >> B[i]; A[i]--, B[i]--;
        g.add_edge(A[i], B[i]);
    }

    g.dfs();

    auto segtree = LazySegmentTree<ll>(g.euler_tour.size());

    int Q;
    cin >> Q;

    REP(i, Q){
        int t, e, x;
        cin >> t >> e >> x;
        e--;
        int a = A[e];
        int b = B[e];
        if (t == 1){ // a側に足す
            if (g.depth[a] < g.depth[b]){ // aのほうが上
                segtree.add(g.begin_indices[0], g.end_indices[0], x);
                segtree.add(g.begin_indices[b], g.end_indices[b], -x);
            } else { // bのほうが上
                segtree.add(g.begin_indices[a], g.end_indices[a], x);
            }
        } else { // b側に足す
            if (g.depth[a] < g.depth[b]){ // aのほうが上
                segtree.add(g.begin_indices[b], g.end_indices[b], x);
            } else {
                segtree.add(g.begin_indices[0], g.end_indices[0], x);
                segtree.add(g.begin_indices[a], g.end_indices[a], -x);
            }
        }
    }

    REP(i, N){
        ll ans = segtree.get_sum(g.begin_indices[i], g.begin_indices[i]+1);
        print(ans);
    }


    return 0;
}
