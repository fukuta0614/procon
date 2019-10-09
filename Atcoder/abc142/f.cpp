// abc142_f
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

    vector<int> visited, candidates, ans;
    vector<vector<int>> edges;
    vector<vector<int>> rev_edges;
    Graph(int n): edges(n), rev_edges(n), visited(n, 0) {}

    void add_edge(int u, int v){
        edges[u].emplace_back(v);
        rev_edges[v].emplace_back(u);
    }

    void dfs(int v, int s){
        if (visited[v]) return;

        visited[v] = 1;

        for (auto t: edges[v]) {
            if (t == s){
                if (ans.empty() || candidates.size() < ans.size()){
                    ans = candidates;
                }
                return;
            }
            candidates.emplace_back(t);
            dfs(t, s);
            candidates.pop_back();
        }
    }

    void dfs_wrap(int s){
        visited.assign(visited.size(), 0);
        candidates = {s};
        dfs(s, s);
    }
};


int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N, M;
    cin >> N >> M;

    Graph g(N);

    REP(i, M){
        int a, b;
        cin >> a >> b; a--; b--;
        g.add_edge(a, b);
    }

    vector<int> cand;
    REP(i, N){
        g.dfs_wrap(i);
    }

    if (g.ans.size() > 1){
        print(g.ans.size());
        for (auto v: g.ans) print(v+1);
    } else {
        print(-1);
    }


    return 0;
}