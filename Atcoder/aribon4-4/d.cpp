// aribon4-4_d
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

    int N;
    cin >> N;
    vector<ll> X(N);
    REP(i, N) cin >> X[i];

    ll L;
    cin >> L;

    int tmp = 0;
    int log_n = (int)log2(N) + 1;
    vector<vector<int>> next(log_n+1, vector<int>(N+1, 0));
    REP(i, N){
        while (tmp < N-1 && X[tmp+1] - X[i] <= L) tmp++;
        next[0][i] = tmp;
    }
    next[0][N-1] = N;
    next[0][N] = N;

    REP(k, log_n){
        REP(i, N+1){
            next[k+1][i] = next[k][next[k][i]];
        }
    }

//    REP(k, log_n) print(1 << k, next[k]);

    int Q;
    cin >> Q;
    REP(i, Q){
        int a, b;
        cin >> a >> b; a--; b--;
        if (a > b) swap(a, b);

        int j = a;
        int ans = 0;
        REP_REV(k, log_n+1){
            if (next[k][j] <= b){
                j = next[k][j];
                ans += 1 << k;
            }
        }
        if (j < b) ans++;
        print(ans);
    }


    return 0;
}
