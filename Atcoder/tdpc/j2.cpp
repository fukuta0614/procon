
#include <bits/stdc++.h>
using namespace std;

#define isex(p) ()
double dp[65536];

int main() {
    std::ifstream in("../arg.txt");
    std::cin.rdbuf(in.rdbuf());

    int n, i, j, k, x[16], t[16], cnt;
    double tmp;
    cin >> n;
    for (i = 0; i <= 15; i++)t[i] = -1;
    for (i = 0; i < n; i++) {
        cin >> x[i];
        t[x[i]] = i;
    }
    dp[0] = 0.0;
    for (i = 1; i < (1 << n); i++) {
        dp[i] = 10000000.0;
        for (j = 1; j <= 14; j++) {
            tmp = 1.0;
            cnt = 0;
            for (k = j - 1; k <= j + 1; k++) {
                if ((t[k] >= 0) && (i & (1 << (t[k])))) {
                    tmp = tmp + dp[i ^ (1 << (t[k]))] / 3.0;
                    cnt++;
                }
            }
            if (!cnt)continue;
            tmp = tmp * 3.0 / cnt;
            if (dp[i] > tmp)dp[i] = tmp;
        }
    }
    printf("%.9lf\n", dp[(1 << n) - 1]);
    return 0;
}
