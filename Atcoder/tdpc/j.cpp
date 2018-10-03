// tdpc_j

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define debug(x) cout << #x << ": " << (x) << endl
#define REP(i, n) for (int (i) = 0 ; (i) < (int)(n) ; ++(i))
#define REPN(i, m, n) for (int (i) = m ; (i) < (int)(n) ; ++(i))
#define REP_REV(i, n) for (int (i) = (int)(n) - 1 ; (i) >= 0 ; --(i))
#define INF ((1 << 16)-1)
#define MOD (1000000007)
#define print(arr, n) REP(i, n) cout << arr[i] << " ";

int N;
double dp[1 << 16];

double bit_dp(int n) {

    if (dp[n] != -1) return dp[n];

    double ans = INF;
    REPN(idx, 1, 16 - 1) {
        double tmp = 1;
        int ar = 0;
        REPN(k, -1, 2){
            int next_n = n & ~(1 << (idx + k));
            if (next_n == n) ar++;
            else tmp += bit_dp(next_n) / 3.0;
        }
        if (ar == 3) continue;
        else if (ar == 2) tmp *= 3.0;
        else if (ar == 1) tmp *= 1.5;
        ans = min(ans, tmp);
    }

    dp[n] = ans;
    return ans;
}


int main() {
//    std::ifstream in("../arg.txt");
//    std::cin.rdbuf(in.rdbuf());
    cout << fixed << setprecision(10);

    cin >> N;
    int n = 0;
    REP(i, N) {
        int x;
        cin >> x;
        n += 1 << x;
    }

    REPN(i, 1, (1<<16)) dp[i] = -1;
    cout << bit_dp(n) << endl;

    return 0;

}