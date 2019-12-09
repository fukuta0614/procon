// aribon4-3_c
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

struct SCC {

    int N;
    vector<int> tmp_order;
    vector<int> scc_group;
    vector<bool> used;
    vector<vector<int>> edges, rev_edges;

    SCC(int n): N(n), edges(n), rev_edges(n), scc_group(n, -1), used(n) {}

    void add_edge(int u, int v){
        edges[u].emplace_back(v);
        rev_edges[v].emplace_back(u);
    }

    void dfs(int i){
        used[i] = true;
        for (auto v: edges[i]){
            if (used[v]) continue;
            dfs(v);
        }
        tmp_order.emplace_back(i);
    }

    void dfs2(int i, int k){
        used[i] = true;
        scc_group[i] = k;
        for (auto v: rev_edges[i]){
            if (used[v]) continue;
            dfs2(v, k);
        }
    }

    int calc_scc(){

        REP(i, N){
            if (used[i]) continue;
            dfs(i);
        }

        used.assign(N, false);
        int k = 0;
        REP(i, N){
            int v = tmp_order[N-i-1];
            if (used[v]) continue;
            dfs2(v, k++);
        }

        return k;
    }
};

struct TwoSat{

    int N;
    SCC scc;
    vector<bool> res;

    TwoSat(int n): N(n), scc(2 * n), res(n){}

    void add_closure(int a, bool apos, int b, bool bpos){ // a V b をグラフへ
        scc.add_edge(a + (apos ? N : 0), b + (bpos ? 0 : N)); // not a -> b
        scc.add_edge(b + (bpos ? N : 0), a + (apos ? 0 : N)); // not b -> a
    }

    bool exec() {
        scc.calc_scc();

        for (int i = 0; i < N; i++) {
            if (scc.scc_group[i] == scc.scc_group[i + N]) return false;
            res[i] = scc.scc_group[i] > scc.scc_group[i + N];
        }
        return true;
    }

    bool operator()(int k){
        return res[k];
    }

};


int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif
    // yukicoder No.274 The Wall

    int N, M;
    cin >> N >> M;

    vector<int> L(N), R(N);
    REP(i, N){
        cin >> L[i] >> R[i];
    }

    auto intersect = [](int l1, int r1, int l2, int r2){
        if (l1 > l2) swap(l1, l2), swap(r1, r2);
        return l2 <= r1;
    };

    // 0~N-1: True(ひっくり返さない), N~2N-1: False(ひっくり返す)
    TwoSat sat(N);
    REP(i, N) REPN(j, i+1, N){

        bool b1 = intersect(L[i], R[i], L[j], R[j]);
        bool b2 = intersect(L[i], R[i], M-R[j]-1, M-L[j]-1);
        bool b3 = intersect(M-R[i]-1, M-L[i]-1, L[j], R[j]);
        bool b4 = intersect(M-R[i]-1, M-L[i]-1, M-R[j]-1, M-L[j]-1);

        if (b1) sat.add_closure(i, false, j, false);
        if (b2) sat.add_closure(i, false, j, true);
        if (b3) sat.add_closure(i, true, j, false);
        if (b4) sat.add_closure(i, true, j, true);
    }

    bool flag = sat.exec();
    print(flag ? "YES" : "NO");

    return 0;
}