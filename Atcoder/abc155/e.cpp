// abc155_e
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

#define CHAR2INT(c) (c - '0')

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    string S;
    cin >> S;
    int N = (int)S.size();

    // dp[i][0] : i番目まで見て、貸し借りなしの状態
    // dp[i][1] : i番目まで見て、1多い状態
    vector<vector<ll>> dp(N+1, vector<ll>(2, INF));
    dp[0][0] = 0;
    dp[0][1] = 1;
    REP(i, N){
        int d = S[i] - '0';
        dp[i+1][0] = min(dp[i+1][0], (min(d, 11-d) + dp[i][0]));
        dp[i+1][0] = min(dp[i+1][0], (10-d + dp[i][1]));

        dp[i+1][1] = min(dp[i+1][1], d+1 + dp[i][0]);
        dp[i+1][1] = min(dp[i+1][1], 9-d + dp[i][1]);
    }

//    print(dp);

    ll ans = dp[N][0];
    print(ans);


    return 0;
}
