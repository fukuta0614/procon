// abc129_d
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

    int H, W;
    cin >> H >> W;
    vector<vector<bool>> G;
    G.assign(H+2, vector<bool>(W+2, false));

    REPN(i, 1, H+1) {
        string s;
        cin >> s;
        REPN(j, 1, W+1){
            if (s[j-1] == '.') G[i][j] = true;
        }
    }

    struct D {int l,u,r,d;};
    vector<vector<D>> X;
    X.assign(H+2, vector<D>(W+2, {-1,-1,-1,-1}));

    int ans = 0;
    REPN(i, 1, H+1) REPN(j, 1, W+1){

        if (G[i][j] == false) continue;

        if (X[i][j].l == -1){

            int tmp = 0;
            while (G[i][j+tmp]) {
                tmp++;
            }

            REP(k, tmp){
                X[i][j+k].l = k;
                X[i][j+k].r = tmp - k - 1;
            }
        }

        if (X[i][j].u == -1){

            int tmp = 0;
            while (G[i+tmp][j]) {
                tmp++;
            }

            REP(k, tmp){
                X[i+k][j].u = k;
                X[i+k][j].d = tmp - k - 1;

            }
        }

        ans = max(ans, X[i][j].l + X[i][j].r + X[i][j].u + X[i][j].d + 1);

    }

    print(ans);

    return 0;
}
