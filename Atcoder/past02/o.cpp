// past02_o
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

#define INF (ll)(1e15)
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

    // セグ木 (区間maxがしたい）
    auto f = [](int a, int b){return max(a, b);};
    int ti = 0;
    auto st = SegmentTree<ll>(f, ti, N);

    // セグ木 値セット 各頂点iの親ノードへの辺の重みをセットする
    REP(i, M){
        if(g.mst_edges[i]) {
            int u = g.edges[i].u;
            int v = g.edges[i].v;
            ll w = g.edges[i].w;
            if (hl.par[v] != u) swap(u, v);
            st.update(hl.vid[v], w);
        }
    }

    // 頂点u,vを結ぶ辺iがもとの最小全域木に含まれるならそれが最小
    // そうでないなら、辺iの重みを足して、木のu,vパス上の辺の中で重みが最大のものを引いたもの
    vector<ll> ans(M);
    REP(i, M) {
        auto e = g.edges[i];
        if (g.mst_edges[i]) {
            ans[e.idx] = min_cost;
            continue;
        }

        int lca = hl.lca(e.u, e.v);

        ll mx = 0;
        for (auto c_: {e.u, e.v}){
            int c = c_;
            while (true) {
                if (hl.head[lca] != hl.head[c]) {
                    mx = max(mx, st.query(hl.vid[hl.head[c]], hl.vid[c] + 1));
                    c = hl.par[hl.head[c]];
                } else {
                    mx = max(mx, st.query(hl.vid[lca] + 1, hl.vid[c] + 1));
                    break;
                }
            }
        }
        ans[e.idx] = min_cost + e.w - mx;
    }

    REP(i, M){
        print(ans[i]);
    }


    return 0;
}
