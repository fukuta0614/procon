// abc079_d
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
    int H, W;
    cin >> H >> W;
    vector<vector<int>> C(10, vector<int>(10, 0));
    REP(i, 10) REP(j, 10) cin >> C[i][j];

    vector<vector<int>> S(H, vector<int>(W, 0));
    REP(i, H) REP(j, W) cin >> S[i][j];

    REP(k, 10) REP(i, 10) REP(j, 10){
        C[i][j] = min(C[i][j], C[i][k] + C[k][j]);
    }

//    REP(i, 10) print(C[i]);

    ll ans = 0;
    REP(i, H) REP(j, W){
        if (S[i][j] != -1){
            ans += C[S[i][j]][1];
        }
    }

    print(ans);


    return 0;
}
