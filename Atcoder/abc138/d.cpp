// abc138_d
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


struct Graph {

    int n;
    vector<vector<int>> edges;
    vector<int> begin_indices, end_indices;
    vector<int> euler_tour;

    Graph(int n_): n(n_) {
        edges.assign(n, vector<int>());
        begin_indices.assign(n, 0);
        end_indices.assign(n, 0);
    }

    void add_edge(int u, int v){
        edges[u].emplace_back(v);
        edges[v].emplace_back(u);
    }

    void dfs(int v = 0, int p = -1) {

        begin_indices[v] = euler_tour.size();
        euler_tour.emplace_back(v);

        for (auto e: edges[v]){
            if (e == p) continue;

            dfs(e, v);
            euler_tour.emplace_back(v);
        }

        end_indices[v] = euler_tour.size();
    }
};


struct SegTree{
    int size;
    vector<long long> val;
    vector<long long> lazy;
    vector<int> width;

    SegTree(int n_){
        size = 1;
        while (size < n_) size <<= 1;
        val = vector<long long>(size*2, 0);
        lazy = vector<long long>(size*2, 0);
        width = vector<int>(size*2, 1);

        for (int i = size-2; i >= 0; i--) {
            width[i] = width[i*2+1] + width[i*2+2];
        }
    }
    void lazy_propagate(int p) {
        if (lazy[p] > 0) {
            val[p] += lazy[p] * width[p];
            if (p < size-1) {
                lazy[p*2+1] += lazy[p];
                lazy[p*2+2] += lazy[p];
            }
            lazy[p] = 0;
        }
    }

    void add(int wishl, int wishr, int watchl, int watchr, int k, int x) {
        if (wishr <= watchl || watchr <= wishl) {
            lazy_propagate(k);
            return;
        }
        if (wishl <= watchl && watchr <= wishr) {
            lazy[k] += x;
            lazy_propagate(k);
            return;
        }
        int mid = (watchl+watchr)/2;
        lazy_propagate(k);
        add(wishl, wishr, watchl, mid, k*2+1, x);
        add(wishl, wishr, mid, watchr, k*2+2, x);
        val[k] = val[k*2+1] + val[k*2+2];
    }
    void add(int wishl, int wishr, int x) {
        add(wishl, wishr, 0, size, 0, x);
    }

    long long getsum(int wishl, int wishr, int watchl, int watchr, int k) {
        if (wishr <= watchl || watchr <= wishl) {
            return 0;
        }
        if (wishl <= watchl && watchr <= wishr) {
            lazy_propagate(k);
            return val[k];
        }
        int mid = (watchl+watchr)/2;
        lazy_propagate(k);
        long long sl = getsum(wishl, wishr, watchl, mid, k*2+1);
        long long sr = getsum(wishl, wishr, mid, watchr, k*2+2);
        return sl + sr;
    }
    long long getsum(int wishl, int wishr) {
        return getsum(wishl, wishr, 0, size, 0);
    }
};


int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N, Q;
    cin >> N >> Q;

    auto g = Graph(N);

    REP(i, N-1){
        int a, b;
        cin >> a >> b; a--; b--;
        g.add_edge(a, b);
    }

    g.dfs();

    auto segtree = SegTree(g.euler_tour.size());

    REP(i, Q){
        int p, x;
        cin >> p >> x; p--;
        segtree.add(g.begin_indices[p], g.end_indices[p], x);
    }

    ll ans;
    REP(i, N-1){
        ans = segtree.getsum(g.begin_indices[i], g.begin_indices[i]+1);
        cout << ans << " ";
    }
    ans = segtree.getsum(g.begin_indices[N-1], g.begin_indices[N-1]+1);
    cout << ans << endl;

    return 0;
}
