// csa_200125_a
// Crossing Tree
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


struct Graph {

    vector<int> prev;
    vector<vector<int>> edges;
    Graph(int n): edges(n), prev(n, -1){}

    void add_edge(int u, int v){
        edges[u].emplace_back(v);
        edges[v].emplace_back(u);
    }

    int max_dist = 0;
    int max_dist_idx = -1;
    void dfs(int v, int d=0, int p=-1){
        prev[v] = p;

        if (d > max_dist){
            max_dist = d;
            max_dist_idx = v;
        }

        for (auto t: edges[v]) {
            if (t == p) continue;
            dfs(t, d+1, v);
        }
    }


    vector<int> ans;
    void dfs2(int v, int dst, int p=-1){

        ans.emplace_back(v+1);

        if (v == dst) return;

        // 一番遠いところへ向かうパス以外は一回vに帰ってくる
        for (auto t: edges[v]) {
            if (t == p) continue;
            if (t == prev[v]) continue;

            dfs2(t, dst, v);
            ans.emplace_back(v+1);
        }

        if (p != prev[v]){
            dfs2(prev[v], dst, v);
        }
    }

    void calc(void){

        dfs(0);
        int u = max_dist_idx;

        max_dist = 0;
        dfs(u);
        int v = max_dist_idx;

        // u, vが一番遠い２点
        // prevを計算してるのでv->uでいく
        dfs2(v, u);

        print(ans.size()-1);
        print_line(ans, ans.size());
    }
};

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N;
    cin >> N;

    Graph g(N);
    REP(i, N-1){
        int a, b;
        cin >> a >> b;
        a--; b--;
        g.add_edge(a, b);
    }

    g.calc();


    return 0;
}
