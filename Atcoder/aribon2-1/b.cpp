// aribon2-1_b
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
#define CHAR2INT(c) (c - '0')

struct PreMain {PreMain(){std::cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

int main() {
#ifdef LOCAL
    std::ifstream in("../arg.txt");
    std::cin.rdbuf(in.rdbuf());
#endif

    string s;
    cin >> s;

    int N = 1 << (s.size() - 1);
    REP(x, N){
        ll ans = CHAR2INT(s[0]);
        int n = x;
        REPN(i, 1, s.size()) {
            if (n & 1) {
                ans += CHAR2INT(s[i]);
            } else {
                ans -= CHAR2INT(s[i]);
            }
            n >>= 1;
        }

        if (ans == 7){
            n = x;
            cout << s[0];
            REPN(i, 1, s.size()) {
                if (n & 1) {
                    cout << "+" << s[i];
                } else {
                    cout << "-" << s[i];
                }
                n >>= 1;
            }
            cout << "=7" << endl;
            exit(0);
        }
    }
    return 0;
}


