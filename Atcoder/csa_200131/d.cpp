// csa_200131_d
// Flip Game
// https://csacademy.com/contest/interview-archive/task/flip-game
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

#define print2D(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }
#define print_line(vec, n) {for(int i=0;i<(n-1);i++) cout << (vec)[i] << " "; cout << (vec)[(n)-1] << endl;}
template<class T> void print(const T& x){cout << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N, M;
    cin >> N >> M;
    vector<vector<int>> mat_origin(N, vector<int>(M, 0));
    REP(i, N) REP(j, M) cin >> mat_origin[i][j];

    ll ans = 0;

    // MSB列をflipするかしないか
    REP(k, 2){
        auto mat = mat_origin;
        if (k == 1) {
            REP(i, N) REP(j, M) mat[i][j] ^= 1;
        }

        // MSBを見て、行をflipするかしないか
        REP(i, N){
            if (mat[i][0] == 0){
                REP(j, M) mat[i][j] ^= 1;
            }
        }

        // MSB以降、1のほうが多ければそのまま、0が多ければ反転
        REPN(j, 1, M){
            int cnt = 0;
            REP(i, N) cnt += mat[i][j];
            if (N - cnt > cnt) {
                REP(i, N) mat[i][j] ^= 1;
            }
        }

        // 結果計算
        ll tmp = 0;
        REP(i, N) REP(j, M){
            tmp += mat[i][j] * (1ll << (M-j-1));
        }
        ans = max(ans, tmp);
    }

    print(ans);

    return 0;
}
