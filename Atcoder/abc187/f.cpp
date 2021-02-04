// abc187_f
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
//struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

int N, M;
vector<vector<bool>> edges;
vector<bool> is_complete_graph;
vector<int> memo;

int dfs(int bit){

    if (memo[bit] != -1) return memo[bit];

    if (is_complete_graph[bit]) return memo[bit] = 1;

    int ret = INF;
    for (int p = bit; p > 0; p = (p - 1) & bit) {
        if (p == bit) continue;
        ret = min(ret, dfs(p) + dfs(bit ^ p));
    }

//    vector<int> bit_on;
//    REP(i, N) if ((p >> i) & 1) bit_on.emplace_back(i);
//    int n = bit_on.size();
//
//    int ret = INF;
//    REPN(x, 1, (1 << n)-1){
//        int q = 0;
//        REP(i, n) if ((x >> i) & 1) q |= 1 << bit_on[i];
//        ret = min(ret, dfs(q) + dfs(p ^ q));
//    }

    return memo[bit] = ret;
}

string to_hex(int n){ std::stringstream ss; ss << std::hex << n; return ss.str(); }
string to_oct(int n){ std::stringstream ss; ss << std::oct << n; return ss.str(); }
string to_bin(int n){ std::stringstream ss; ss << std::bitset<8>(n); return ss.str(); }

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif
    cin >> N >> M;

    edges.assign(N, vector<bool>(N, false));
    REP(i, N) edges[i][i] = true;
    REP(i, M){
        int a, b;
        cin >> a >> b; a--; b--;
        edges[a][b] = true;
        edges[b][a] = true;
    }

//    print(edges);
    is_complete_graph.assign(1<<N, false);
    REP(p, 1 << N){
        vector<int> nodes;
        REP(i, N) {
            if (((p >> i) & 1)) {
                nodes.emplace_back(i);
            }
        }
        int n = nodes.size();
        bool complete = true;
        REP(i, n) REPN(j, i+1, n){
            complete &= edges[nodes[i]][nodes[j]];
        }
        is_complete_graph[p] = complete;
    }

    memo.assign(1<<N, -1);
    int ans = dfs((1<<N)-1);

    print(ans);

    return 0;
}
