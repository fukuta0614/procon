// abc128_c
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
template<class T> void print(const T& x){cout << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt");
    cin.rdbuf(in.rdbuf());
#endif

    int N, M;
    cin >> N >> M;

    vector<vector<bool>> S(M, vector<bool>(N, false));
    vector<int> p(N);

    int k, idx;
    REP(i, M){
        cin >> k;
        REP(j, k) {
            cin >> idx;
            S[i][idx-1] = true;
        }
    }
    REP(i, M) cin >> p[i];

    int ans = 0;
    REP(_n, 1 << N){

        int sm = 0;
        REP(m, M){
            int n = _n;
            int tmp = 0;
            REP(i, N){
                tmp += (n & 1) && S[m][i];
                n >>= 1;
            }

            if (tmp % 2 == p[m]) {
                sm++;
            }
        }

        if (sm == M){
            ans++;
        }
    }

    print(ans);

    return 0;
}
