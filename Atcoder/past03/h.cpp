// past03_h
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
#define print_line(vec, n) {for(int i=0;i<(n-1);i++) cout << (vec)[i] << " "; cout << (vec)[(n)-1] << endl;}
template<class T> void print(const T& x){cout << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N, L;
    cin >> N >> L;
    vector<bool> A(L+4);
    REP(i, N) {
        int a; cin >> a;
        A[a] = true;
    }
    int T1, T2, T3;
    cin >> T1 >> T2 >> T3;

    vector<int> dp(L+4);

    REPN(i, 1, L+4){

        dp[i] = INF;
        dp[i] = min(dp[i], dp[i-1] + T1);

        if (i-2>=0){
            dp[i] = min(dp[i], dp[i-2] + T1 + T2);
        }

        if (i-4>=0){
            dp[i] = min(dp[i], dp[i-4] + T1 + 3 * T2);
        }

        if (A[i]){
            dp[i] += T3;
        }
    }

    int ans = INF;
    ans = min(ans, dp[L]);
    if (L-1 >= 0) ans = min(ans, dp[L-1] + (T1 + T2) / 2);
    if (L-2 >= 0) ans = min(ans, dp[L-2] + (T1 + 3 * T2) / 2);
    if (L-3 >= 0) ans = min(ans, dp[L-3] + (T1 + 5 * T2) / 2);
    print(ans);


    return 0;
}
