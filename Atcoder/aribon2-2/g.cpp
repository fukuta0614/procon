// aribon2-2_g
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
#define INF ((1 << 29)-1)
#define MOD (1000000007)

#define ALL(x) x.begin(), x.end()
#define COUT(x) cout << x << endl
#define COUT_2DARR(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }

struct PreMain {PreMain(){std::cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;


int main() {
#ifdef LOCAL
    std::ifstream in("../arg.txt");
    std::cin.rdbuf(in.rdbuf());
#endif

    string S, T;
    cin >> S >> T;

    ull a = S.size(), b = T.size();
    REP_REV(i, a - b + 1){
        bool flag = true;
        REP(j, b){
            if (S[i+j] != '?' && S[i+j] != T[j]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            REP(j, b) S[i+j] = T[j];
            REP(j, a) { if (S[j] == '?') S[j] = 'a';}
            COUT(S);
            return 0;
        }
    }

    COUT("UNRESTORABLE");

    return 0;
}
