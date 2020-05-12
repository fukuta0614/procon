// abc165_f
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

// 非再帰
struct HLDecomposition {
    int n,pos;
    vector<vector<int> > G;
    vector<int> vid, head, sub, hvy, par, dep, inv, type;

    HLDecomposition(){}
    HLDecomposition(int sz):
            n(sz),pos(0),G(n),
            vid(n,-1),head(n),sub(n,1),hvy(n,-1),
            par(n),dep(n),inv(n),type(n){}

    void add_edge(int u, int v) {
        G[u].push_back(v);
        G[v].push_back(u);
    }

    void build(vector<int> rs=vector<int>(1,0)) {
        int c=0;
        for(int r:rs){
            dfs(r);
            bfs(r, c++);
        }
    }

    void dfs(int rt) {
        using T = pair<int,int>;
        stack<T> st;
        par[rt]=-1;
        dep[rt]=0;
        st.emplace(rt,0);
        while(!st.empty()){
            int v=st.top().first;
            int &i=st.top().second;
            if(i<(int)G[v].size()){
                int u=G[v][i++];
                if(u==par[v]) continue;
                par[u]=v;
                dep[u]=dep[v]+1;
                st.emplace(u,0);
            }else{
                st.pop();
                int res=0;
                for(int u:G[v]){
                    if(u==par[v]) continue;
                    sub[v]+=sub[u];
                    if(res<sub[u]) res=sub[u],hvy[v]=u;
                }
            }
        }
    }

    void bfs(int r,int c) {
        int &k=pos;
        queue<int> q({r});
        while(!q.empty()){
            int h=q.front();q.pop();
            for(int i=h;i!=-1;i=hvy[i]) {
                type[i]=c;
                vid[i]=k++;
                inv[vid[i]]=i;
                head[i]=h;
                for(int j:G[i])
                    if(j!=par[i]&&j!=hvy[i]) q.push(j);
            }
        }
    }

    // for_each(vertex)
    // [l,r] <- attention!!
    void for_each(int u, int v, const function<void(int, int)>& f) {
        while(1){
            if(vid[u]>vid[v]) swap(u,v);
            f(max(vid[head[v]],vid[u]),vid[v]);
            if(head[u]!=head[v]) v=par[head[v]];
            else break;
        }
    }

    // for_each(edge)
    // [l,r] <- attention!!
    void for_each_edge(int u, int v, const function<void(int, int)>& f) {
        while(1){
            if(vid[u]>vid[v]) swap(u,v);
            if(head[u]!=head[v]){
                f(vid[head[v]],vid[v]);
                v=par[head[v]];
            } else{
                if(u!=v) f(vid[u]+1,vid[v]);
                break;
            }
        }
    }

    int lca(int u,int v){
        while(1){
            if(vid[u]>vid[v]) swap(u,v);
            if(head[u]==head[v]) return u;
            v=par[head[v]];
        }
    }

    int distance(int u,int v){
        return dep[u]+dep[v]-2*dep[lca(u,v)];
    }

//    vector<vector<int>> lis_list;
//    map<int, int> convert;
    vector<int> lis;
    vector<int> A;

    vector<ll> ans;
    vector<P> memo;

    void solve(vector<int>& A_ref){

        A = A_ref;

//        set<int> st;
//        REP(i, n) st.insert(head[i]);
//        int light_num = 0;
//        for (auto idx: st){
//            convert[idx] = light_num++;
//        }
//
//        lis_list.assign(light_num, vector<int>());

        ans.assign(n, 0);
        memo.assign(n, {});
        rec(0);

//        print(lis_list);

        REP(i, n){
            print(ans[i]);
        }
//        print(accumulate(ALL(ans), 0ll));
    }


    void rec(int u){

//        int tmp_hv_idx = convert[head[u]];
//        vector<int>& lis = lis_list[tmp_hv_idx];

        auto it = lower_bound(ALL(lis), A[u]);
        if (it == lis.end()) {
            lis.emplace_back(A[u]);
            memo[u] = P(-1, -1);
        } else {
            int before = *it;
            (*it) = A[u];
            memo[u] = P(std::distance(lis.begin(), it), before);
        }

        ans[u] = (ll)lis.size();

        for (auto v: G[u]){
            if (v == par[u]) continue;

            if (head[v] != head[u]){
//                lis_list[convert[head[v]]] = lis_list[tmp_hv_idx];
                rec(v);
            }
        }

        if (hvy[u] != -1) {
            rec(hvy[u]);
        }

        if (memo[u].first == -1) {
            lis.pop_back();
        } else {
            lis[memo[u].first] = memo[u].second;
        }
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
        for(int nx:G[cur])if(nx != pre){
                depth[nx] = depth[cur] + 1;
                dfs(nx, cur);

                sub[cur] += sub[nx];
                if(max_sub < sub[nx]){
                    max_sub = sub[nx];
                    heavy[cur] = nx;
                }
            }
    }

    void dfs2(int root){
        int k = 0;
        stack<int> que({root});
        while(!que.empty()){
            int cur = que.top();
            que.pop();
            // curを先頭とするheavy-pathを処理
            for(int i=cur; i!=-1; i=heavy[i]){
                vid[i] = k++;
                inv[vid[i]] = i;
                head[i] = cur;
                // heavy-pathの先頭になるなら、queにpushする
                for(int nx:G[i])if(nx != par[i] && nx != heavy[i]){
                        que.push(nx);
                    }
            }
        }
    }

    int lca(int u, int v){
        while(1){
            if(vid[u] > vid[v]) swap(u,v);
            if(head[u] == head[v]) return u;
            v = par[head[v]];
        }
    }


    vector<vector<int>> lis_list;
    map<int, int> convert;
    vector<int> A;

    vector<int> ans;

    void solve(vector<int>& A_ref){

        A = A_ref;

        set<int> st;
        REP(i, n) st.insert(head[i]);
        int light_num = 0;
        for (auto idx: st){
            convert[idx] = light_num++;
        }

        lis_list.assign(light_num, vector<int>());

        ans.assign(n, 0);
        rec(0);

//        print(lis_list);

//        REP(i, n){
//            print(ans[i]);
//        }
        print(accumulate(ALL(ans), 0));
    }


    void rec(int u){
        int tmp_hv_idx = convert[head[u]];
        vector<int>& lis = lis_list[tmp_hv_idx];

        auto it = lower_bound(ALL(lis), A[u]);
        if (it == lis.end()) {
            lis.emplace_back(A[u]);
        } else {
            (*it) = A[u];
        }

        ans[u] = lis.size();

        for (auto v: G[u]){
            if (v == par[u]) continue;

            if (head[v] != head[u]){
                lis_list[convert[head[v]]] = lis_list[tmp_hv_idx];
                rec(v);
            }
        }

        if (heavy[u] != -1) {
            rec(heavy[u]);
        }

//        int lca = hl.lca(u,v);

//        st.update(hl.vid[lca] + 1, hl.vid[c] + 1, e[i].fi);
//        st.update(hl.vid[hl.head[c]], hl.vid[c] + 1, e[i].fi);
//        c = hl.par[hl.head[c]];
    }

};


int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N;
    cin >> N;
    vector<int> A(N);
    REP(i, N) cin >> A[i];

//    N = (1 << 18) - 1;
//    print(N);
//    A = vector<int>(N, 0);
//    REP(i, N) A[i] = i;

    HLDecomposition hl(N);

    REP(i, N-1) {
        int u, v;
        cin >> u >> v; u--; v--;
        hl.add_edge(u, v);
//        if (i < N/2){
//            hl.add_edge(i, 2*i+1);
//            hl.add_edge(i, 2*i+2);
//        }
    }
    hl.build();
//    print(hl.vid);
//    print(hl.head);
//    print(hl.hvy);

    hl.solve(A);

    return 0;
}
