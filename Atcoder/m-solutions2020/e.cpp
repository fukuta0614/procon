// m-solutions2020_e
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

#define INF (ll)(1e20)
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
    vector<ll> X(N), Y(N), P(N);
    REP(i, N){
        cin >> X[i] >> Y[i] >> P[i];
    }

    int M2 = 1 << N;
    vector<vector<ll>> dist_x(M2, vector<ll>(N));
    vector<vector<ll>> dist_y(M2, vector<ll>(N));
    REP(m, M2){
        REP(i, N){
            ll sx = abs(X[i]);
            ll sy = abs(Y[i]);
            REP(d, N){
                if ((m >> d) & 1){
                    sx = min(sx, abs(X[i] - X[d]));
                    sy = min(sy, abs(Y[i] - Y[d]));
                }
            }
            dist_x[m][i] = sx;
            dist_y[m][i] = sy;
        }
    }

    int M3 = pow(3, N);
    vector<ll> ans(N+1, INF);
    REP(m, M3){
        int mx = 0;
        int my = 0;
        int k = 0;
        int n = m;
        REP(d, N){
            if (n % 3 == 1){
                mx += 1 << d;
                k++;
            } else if (n % 3 == 2){
                my += 1 << d;
                k++;
            }
            n /= 3;
        }

        ll sm = 0;
        REP(i, N){
            sm += P[i] * min(dist_x[mx][i], dist_y[my][i]);
        }
        ans[k] = min(ans[k], sm);
    }

    REP(i, N+1){
        print(ans[i]);
    }

    return 0;
}
