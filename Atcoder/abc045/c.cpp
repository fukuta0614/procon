// abc045_c
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define debug(x) cout << #x << ": " << (x) << endl
#define REP(i, n) for (int (i) = 0 ; (i) < (int)(n) ; ++(i))
#define REPN(i, m, n) for (int (i) = m ; (i) < (int)(n) ; ++(i))
#define REP_REV(i, n) for (int (i) = (int)(n) - 1 ; (i) >= 0 ; --(i))
#define all(x) x.begin(), x.end()
#define INF ((1 << 16)-1)
#define MOD (1000000007)
#define print(arr, n) REP(i, n) cout << arr[i] << " ";

struct PreMain {PreMain(){std::cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

int main() {
#ifdef LOCAL
    std::ifstream in("../arg.txt");
    std::cin.rdbuf(in.rdbuf());
#endif

    string s;
    cin >> s;

    int N = 1 << (s.size() - 1);
    ll ans = 0;
    REP(x, N){
        int n = x;
        ll tmp = s[0] - '0';
        REPN(i, 1, s.size()) {
            if (n & 1) {
                ans += tmp;
                tmp = s[i] - '0';
            } else {
                tmp = 10 * tmp + s[i] - '0';
            }
            n >>= 1;
        }
        ans += tmp;
    }
    cout << ans << endl;

    return 0;
}


