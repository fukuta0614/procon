// abc146_d
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

    vector<vector<P>> edges;
    vector<int> cnt;
    int color_num;
    vector<int> edge_color;

    Graph(int n) : n(n), edges(n), cnt(n), edge_color(n-1) {}

    void add_edge(int i, int u, int v) {
        edges[u].emplace_back(v, i);
        edges[v].emplace_back(u, i);
        cnt[u]++;
        cnt[v]++;
    }

    void dfs(int u, int p, int c){

        int k = 1;
        for (auto e: edges[u]){
            int idx = e.second;
            int v = e.first;

            if (v == p) continue;

            if (k == c) k++;
            edge_color[idx] = k;
//            print(p, u, v, idx, k);
            dfs(v, u, k);
            k++;
        }
    }


    void calc(){

        int idx = max_element(ALL(cnt)) - cnt.begin();
        color_num = cnt[idx];

        dfs(idx, -1, -1);

        print(color_num);
        for (auto c: edge_color){
            print(c);
        }
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
        cin >> a >> b; a--; b--;
        g.add_edge(i, a, b);
    }

    g.calc();




    return 0;
}
