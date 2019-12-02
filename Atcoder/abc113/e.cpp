// abc113_e
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

#define MOD (1000000007)

#define print2D(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }
#define print_line(vec, n) {for(int i=0;i<(n-1);i++) cout << (vec)[i] << " "; cout << (vec)[(n)-1] << endl;}
template<class T> void print(const T& x){cout << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;


int h, w, g;
int dp[101][10];

int main(){
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    cin >> h >> w >> g;

    dp[0][0] = 1;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            for(int k = 0; k < (1 << w-1); k++){
                bool b = 0;
                for(int jj = 1; jj < w; jj++){
                    if((k >> jj) & (k >> (jj-1))) b = 1;
                }
                if(b) continue;

                if(j!=w-1 && (k >> j) & 1){
                    dp[i+1][j+1] += dp[i][j];
                    dp[i+1][j+1] %= MOD;
                }
                else if(j!=0 && (k >> j-1) & 1){
                    dp[i+1][j-1] += dp[i][j];
                    dp[i+1][j-1] %= MOD;
                }
                else{
                    dp[i+1][j] += dp[i][j];
                    dp[i+1][j] %= MOD;
                }
            }
        }
    }
    print(dp[h]);

    return 0;
}
