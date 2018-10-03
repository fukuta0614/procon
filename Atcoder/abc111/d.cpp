// abc111_d

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


int main() {
//    std::ifstream in("../arg.txt");
//    std::cin.rdbuf(in.rdbuf());

    int N;
    cin >> N;

    int X[1024], Y[1024];

    REP(i, N) {
        cin >> X[i] >> Y[i];
    }

    REPN(i, 1, N){
        if ( (abs(X[i]) + abs(Y[i])) % 2 != (abs(X[0]) + abs(Y[0])) % 2 ) {
            cout << -1 << endl;
            return 0;
        }
    }

    int m = 31;
    vector<ll> d;
    REP_REV(i, m) d.push_back(1ll << i);
    if ((X[0] + Y[0]) % 2 == 0) {
        d.push_back(1);
        m += 1;
    }

    cout << m << endl;
    print(d, d.size());
    puts("");

    REP(j, N) {
        ll x = X[j], y = Y[j];
        string s = "";

        REP(i, d.size()) {
            if (abs(x) > abs(y)) {
                if (x > 0) {s += "R"; x -= d[i];}
                else {s += "L"; x += d[i];}
            }
            else {
                if (y > 0){ s += "U"; y -= d[i];}
                else { s += "D";y += d[i]; }
            }
        }
        cout << s << endl;
    }
}
