// abc147_f
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
#define INF ((1 << 29)-1)

#define print2D(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }
#define print_line(vec, n) {for(int i=0;i<(n-1);i++) cout << (vec)[i] << " "; cout << (vec)[(n)-1] << endl;}
template<class T> void print(const T& x){cout << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;


int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int R, C, K;
    cin >> R >> C >> K;

    vector<string> S(R);
    REP(i, R) cin >> S[i];

    vector<vector<P>> LR(R, vector<P>(C));
    REP(i, R){
        int l=-1;
        REP(j, C){
            if (S[i][j] == 'x') {
                l = j;
            } else {
                LR[i][j].first = max(0, j - l);
            }
        }

        int r=C;
        REP_REV(j, C){
            if (S[i][j] == 'x') {
                r = j;
            } else {
                LR[i][j].second = max(0, r - j);
            }
        }
    }
//    REP(i, R) print(LR[i]);

    int ans = 0;
    REPN(i, K-1, R-K+1) REPN(j, K-1, C-K+1){

        bool is_valid = true;
        REP(k, K) {
            is_valid &= LR[i-k][j].first >= K - k;
            is_valid &= LR[i-k][j].second >= K - k;
            is_valid &= LR[i+k][j].first >= K - k;
            is_valid &= LR[i+k][j].second >= K - k;
        }

        if (is_valid)  ans++;
    }

    print(ans);

    return 0;
}
