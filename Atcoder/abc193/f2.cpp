// abc193_f
#pragma GCC optimize ("O3")

#include <bits/stdc++.h>
#include <atcoder/all>
#ifdef LOCAL
#include "../../debug_util/cxx-prettyprint/prettyprint.hpp"
#include "../../debug_util/rng.hpp"
#include "../../debug_util/timer.hpp"
#endif
using namespace std;

using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

#define REP(i, n) for (int i = 0 ; i < (int)(n) ; ++i)
#define REPN(i, m, n) for (int i = m ; i < (int)(n) ; ++i)
#define REP_REV(i, n) for (int i = (int)(n) - 1 ; i >= 0 ; --i)
#define REPN_REV(i, m, n) for (int i = (int)(n) - 1 ; i >= m ; --i)
#define ALL(x) x.begin(), x.end()

#define INF (ll)(1e15)
#define MOD (1000000007)

#define print2D(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }
#define print_line(vec, n) {for(int idx=0;idx<(n-1);idx++) cout << (vec)[idx] << " "; cout << (vec)[(n)-1] << endl;}
template<class T> void print(const T& x){cout << x << "\n";}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N;
    cin >> N;
    vector<string> c(N);
    for(string& s : c) cin >> s;
    for(int i = 0; i < N; i++) for(int j = 0; j < N; j++){
            if((i ^ j) & 1 && c[i][j] != '?') c[i][j] ^= 'B' ^ 'W';
        }
    const int S = N * N, T = S + 1;
    atcoder::mf_graph<int> g(S + 2);
    for(int i = 0; i < N; i++) for(int j = 0; j < N - 1; j++){
            const int x = i * N + j;
//            g.change_edge(g.add_edge(x, x + 1, 2), 2, 1);
            g.add_edge(x, x + 1, 1);
            g.add_edge(x+1, x, 1);
        }
    for(int i = 0; i < N - 1; i++) for(int j = 0; j < N; j++){
            const int x = i * N + j;
//            g.change_edge(g.add_edge(x, x + N, 2), 2, 1);
            g.add_edge(x, x + N, 1);
            g.add_edge(x + N, x, 1);
        }
    for(int i = 0; i < N; i++) for(int j = 0; j < N; j++){
            const int x = i * N + j;
            if(c[i][j] == 'B') g.add_edge(S, x, 4);
            if(c[i][j] == 'W') g.add_edge(x, T, 4);
        }
    cout << 2 * N * (N - 1) - g.flow(S, T) << endl;

    return 0;
}
