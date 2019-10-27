// edpc_g
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

    int n;

    vector<vector<int>> edges;
    vector<vector<int>> rev;
    vector<int> memo;

    Graph(int n): n(n), edges(n), rev(n){}


    void add_edge(int u, int v){
        edges[u].emplace_back(v);
        rev[v].emplace_back(u);
    }

    vector<int> topological_sort(){
        queue<int> q;

        REP(i, n){
            if (rev[i].empty()) q.push(i);
        }

        vector<int> ret;
        while (!q.empty()){
            int u = q.front(); q.pop();
            ret.emplace_back(u);

            for (auto v: edges[u]){
                rev[v].erase(remove(ALL(rev[v]), u), rev[v].end());
                if (rev[v].empty()){
                    q.push(v);
                }
            }
        }
        return ret;
    }

    int dfs(int u){

        if (memo[u] != -1) return memo[u];

        int tmp = 0;
        for (auto v: edges[u]){
            tmp = max(tmp, dfs(v) + 1);
        }

        return memo[u] = tmp;

    }

    int dfs(){

        memo.assign(n, -1);

        int ret = 0;
        REP(i, n){
            ret = max(ret, dfs(i));
        }

        return ret;
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
        int x, y;
        cin >> x >> y; x--; y--;
        g.add_edge(x, y);
    }

    int ans = g.dfs();

    print(ans);



    return 0;
}
