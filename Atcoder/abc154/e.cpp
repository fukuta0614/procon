// abc154_e
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
#define CHAR2INT(c) (c - '0')

#define print2D(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }
#define print_line(vec, n) {for(int i=0;i<(n-1);i++) cout << (vec)[i] << " "; cout << (vec)[(n)-1] << endl;}
template<class T> void print(const T& x){cout << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

ll dp[102][4][2] = {0};

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    string N;
    cin >> N;
    int K;
    cin >> K;

    dp[0][0][0] = 1;
    REP(i, N.size()){
        REP(j, K+1){
            REP(k, 2){
                int n = k ? 9 : CHAR2INT(N[i]);
                REP(d, n+1){
                    if (d == 0){
                        dp[i+1][j][k || (d!=n)] += dp[i][j][k];
                    } else {
                        if (j+1 < 4){
                            dp[i+1][j+1][k || (d!=n)] += dp[i][j][k];
                        }
                    }
//                    dp[i+1][(j+d)%D][k||(d!=n)] += dp[i][j][k] % MOD;
                }
            }
        }
    }
    print(dp[N.size()][K][0] + dp[N.size()][K][1]);

    int n = N.size();

    return 0;
}
