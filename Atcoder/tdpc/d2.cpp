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
#define ALL(x) x.begin(), x.end()

#define INF ((1 << 29)-1)
#define MOD (1000000007)

#define print2D(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }
void print() { cout << endl; }
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

int main() {
#ifdef LOCAL
    std::ifstream in("../arg.txt");
    std::cin.rdbuf(in.rdbuf());
#endif

    ull N, D;
    cin >> N >> D;

    int n2=0, n3=0, n5=0;
    while (D % 2 == 0) {D /= 2; n2++;}
    while (D % 3 == 0) {D /= 3; n3++;}
    while (D % 5 == 0) {D /= 5; n5++;}
    if (D > 1) {print(0); return 0;}

    double dp[101][n2+1][n3+1][n5+1] = {1.0};

    REP(i, N){
        REP(i2, n2+1) REP(i3, n3+1) REP(i5, n5+1){
            double p = dp[i][i2][i3][i5] / 6.0;
            dp[i+1][i2][i3][i5] += p;                        //1
            dp[i+1][min(n2, i2+1)][i3][i5] += p;             //2
            dp[i+1][i2][min(n3,i3+1)][i5] += p;              //3
            dp[i+1][min(n2, i2+2)][i3][i5] += p;             //4
            dp[i+1][i2][i3][min(n5, i5+1)] += p;             //5
            dp[i+1][min(n2, i2+1)][min(n3, i3+1)][i5] += p;  //6
        }
    }

    print(dp[N][n2][n3][n5]);

    return 0;
}
