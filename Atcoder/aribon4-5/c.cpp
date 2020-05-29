// aribon4-5_c
// AOJ2559 Minimum Spanning Tree
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A
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

#define INF ((ll)1e12)
#define MOD (1000000007)

#define print2D(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }
#define print_line(vec, n) {for(int i=0;i<(n-1);i++) cout << (vec)[i] << " "; cout << (vec)[(n)-1] << endl;}
template<class T> void print(const T& x){cout << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

struct UnionFind {
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2
    vector<int> rank;
    vector<int> size; // size[i]: iが親なら連結成分の数

    UnionFind(int N) : par(N), rank(N), size(N) { //最初は全てが根であるとして初期化
        for(int i = 0; i < N; i++) {par[i] = i; rank[i] = 0; size[i] = 1;}
    }

    int find(int x) { // データxが属する木の根を再帰で得る：find(x) = {xの木の根}
        if (par[x] == x) return x;
        return par[x] = find(par[x]);
    }

    void unite(int x, int y) { // xとyの木を併合
        int rx = find(x); //xの根をrx
        int ry = find(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま

        // rank[rx] >= rank[ry] となるように rx と ry を swap
        if(rank[rx] < rank[ry]) swap(rx, ry);

        // 同じ高さだったならばまとめたことによって高さ +1
        if(rank[rx] == rank[ry]) ++rank[rx];

        par[ry] = rx; // root rx に ry の木をつなぐ
        size[rx] += size[ry];
        size[ry] = 0;

    }

    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = find(x);
        int ry = find(y);
        return rx == ry;
    }

    int get_size(int x){
        int rx = find(x);
        return size[rx];
    }
};

template <typename T>
struct Graph {
    struct edge {
        int u, v; T w;
        int idx;
        edge() {}
        edge(int u, int v, T w, int idx) : u(u), v(v), w(w), idx(idx) {} //あとからもとの辺の順番を使うためidx追加
        bool operator<(const edge& a){return w < a.w;}
    };

    int n;
    vector<edge> edges;
    vector<bool> mst_edges;

    explicit Graph(int n) : n(n) {}

    void add_edge(int u, int v, T c, int idx) {
        edges.emplace_back(u, v, c, idx);
    }

    T kruskal() {
        sort(edges.begin(), edges.end());

        UnionFind uf(n);
        T min_cost = 0;

        mst_edges.assign(edges.size(), false);
        REP(i, edges.size()) {
            auto e = edges[i];
            if (not uf.same(e.u, e.v)) {
                min_cost += e.w;
                uf.unite(e.u, e.v);
                mst_edges[i] = true;
            }
        }

        if (uf.get_size(0) != n) return -1;
        return min_cost;
    }
};

struct HL_decomposition{
    int n;
    vector<vector<int>> G;
    vector<int> vid, inv, depth, par, heavy, head, sub;
    /*
    vid : HL分解後のグラフでの頂点ID
    inv : HL分解前のグラフでのvid[i]の頂点ID
    depth : rootからの距離
    par : 根付き木上での親
    heavy : heavy-path上における頂点iの次の頂点ID
    head : 頂点iが属するheavy-pathの先頭の頂点ID
    sub : 部分木のサイズ
    */

    HL_decomposition(){}
    HL_decomposition(int sz) : n(sz), G(n), vid(n), inv(n), depth(n), par(n), heavy(n,-1), head(n), sub(n) {}

    void add_edge(int u, int v){
        G[u].push_back(v);
        G[v].push_back(u);
    }

    void build(int root = 0){
        dfs(root, -1);
        dfs2(root);
    }

    void dfs(int cur, int pre){
        par[cur] = pre;
        sub[cur] = 1;
        int max_sub = 0;
        for (int nx:G[cur]) if (nx != pre) {
            depth[nx] = depth[cur] + 1;
            dfs(nx, cur);

            sub[cur] += sub[nx];
            if (max_sub < sub[nx]) {
                max_sub = sub[nx];
                heavy[cur] = nx;
            }
        }
    }

    void dfs2(int root) {
        int k = 0;
        stack<int> que({root});
        while (!que.empty()) {
            int cur = que.top(); que.pop();

            // curを先頭とするheavy-pathを処理
            for (int i = cur; i != -1; i = heavy[i]) {
                vid[i] = k++;
                inv[vid[i]] = i;
                head[i] = cur;
                // heavy-pathの先頭になるなら、queにpushする
                for (int nx: G[i]) if (nx != par[i] && nx != heavy[i]) {
                    que.push(nx);
                }
            }
        }
    }

    int lca(int u, int v) {
        while (true) {
            if (vid[u] > vid[v]) swap(u, v);
            if (head[u] == head[v]) return u;
            v = par[head[v]];
        }
    }
};

// 区間update, 区間min
template<typename T>
struct LazySegmentTree{
    int n;
    vector<T> val;
    vector<T> lazy;

    explicit LazySegmentTree(int n_){
        n = 1;
        while (n < n_) n <<= 1;

        val = vector<T>(n<<1, INF);
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

    int N, M;
    cin >> N >> M;

    vector<int> A(M), B(M);
    vector<ll> W(M);
    REP(i, M) {
        cin >> A[i] >> B[i] >> W[i];
        A[i]--; B[i]--;
        if (A[i] > B[i]) swap(A[i], B[i]);
    }

    // 一旦全部で最小全域木コスト作成
    Graph<ll> g(N);
    REP(i, M){
        g.add_edge(A[i], B[i], W[i], i);
    }
    ll min_cost = g.kruskal();

    // そもそも最小全域木が作れない場合
    if (min_cost == -1){
        REP(i, M) print(-1);
        return 0;
    }

    // HLD作成
    auto hl = HL_decomposition(N);
    REP(i, M){
        if(g.mst_edges[i]) {
            int u = g.edges[i].u;
            int v = g.edges[i].v;
            hl.add_edge(u, v);
        }
    }
    hl.build();

    // 遅延セグ木
    auto st = LazySegmentTree<ll>(N);

    // hld上でu, vのパス上の辺の重みを更新する (g.edgesはソートされてるのでそれ使う）
    REP_REV(i, M) {
        auto e = g.edges[i];
        if (g.mst_edges[i]) continue;

        int lca = hl.lca(e.u, e.v);

        for (auto c_: {e.u, e.v}){
            int c = c_;
            while (true) {
                if (hl.head[lca] == hl.head[c]) {
                    st.update(hl.vid[lca] + 1, hl.vid[c] + 1, e.w);
                    break;
                } else {
                    st.update(hl.vid[hl.head[c]], hl.vid[c] + 1, e.w);
                    c = hl.par[hl.head[c]];
                }
            }
        }
    }

    // 答え作成
    // mstに使われないやつは、最初に計算したコストになる
    // 使われてるやつは、自分の辺の代わりに上記の区間updateしたあとのminとなる辺を追加するのが最小
    vector<ll> ans(M);
    REP(i, M) {
        int idx = g.edges[i].idx;
        if (g.mst_edges[i]) {
            int u = g.edges[i].u;
            int v = g.edges[i].v;
            if (hl.par[v] != u) swap(u, v); // 数字が大きいほうが子とは限らない

            ll w = g.edges[i].w;
            ll val = st.get_min(hl.vid[v], hl.vid[v]+1);
            if (val == INF){
                ans[idx] = -1;
            } else {
                ans[idx] = val - w + min_cost;
            }
        } else {
            ans[idx] = min_cost;
        }
    }

    REP(i, M) print(ans[i]);

    return 0;
}