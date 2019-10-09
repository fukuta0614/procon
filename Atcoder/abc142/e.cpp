// abc142_e
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
template<class T> void print(const T& x){cout << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N, M;
    cin >> N >> M;

    vector<int> A(M), C(M);
    REP(i, M){
        cin >> A[i];
        int b; cin >> b;
        REP(j, b) {
            int c; cin >> c;
            C[i] |= 1 << (--c);
        }
    }

    vector<int> dp(1<<N, INF);
    dp[0] = 0;

    REP(i, M){
        REP(n, 1<<N){
            dp[n | C[i]] = min(dp[n | C[i]], dp[n] + A[i]);
        }
    }

    int ans = dp[(1<<N) - 1] != INF ? dp[(1<<N) - 1] : -1;
    print(ans);

    return 0;
}
