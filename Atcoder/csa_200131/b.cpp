// csa_200131_b
// Binary Isomorphism
// https://csacademy.com/contest/archive/task/binary-isomorphism/statement/

// https://www.hamayanhamayan.com/entry/2018/03/15/111227　これ見た。
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


struct RootedTreeHash{

    int mod = 1e9 + 7;

    int n;
    vector<vector<int>> edges;
    vector<int> depth;
    vector<int> rnd;


    RootedTreeHash(int n, vector<int>& rnd): n(n), edges(n), depth(n), rnd(rnd) {}

    void add_edge(int u, int v){
        edges[u].emplace_back(v);
    }

    int dfs(int v, int d=0) {
        depth[v] = d;

        vector<int> hashs;
        for (auto t: edges[v]) {
            auto h = dfs(t, d+1);
            hashs.emplace_back(h);
        }

        // 深さごとにrndを変えると良いっぽい。
        ll ret = 1;
        for (auto h : hashs) {
            ret = (ret * (rnd[depth[v]] + h)) % mod;
        }

        return int(ret);
    }


};

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int T;
    cin >> T;
    while (T--){
        int N;
        cin >> N;

        // ハッシュ計算用乱数生成
        vector<int> rnd(N);
        int seed = 2020;
        mt19937 mt(seed);
        REP(i, N) rnd[i] = mt();

        RootedTreeHash rth1(N, rnd), rth2(N, rnd);

        int root1=0;
        REP(i, N){
            int p; cin >> p;
            if (p == 0){
                root1 = i;
            } else {
                p--;
                rth1.add_edge(p, i);
            }
        }

        int root2=0;
        REP(i, N){
            int p; cin >> p;
            if (p == 0){
                root2 = i;
            } else {
                p--;
                rth2.add_edge(p, i);
            }
        }

        auto h1 = rth1.dfs(root1);
        auto h2 = rth2.dfs(root2);
        if (h1 == h2){
            print(1);
        } else {
            print(0);
        }
    }

    return 0;
}
