// abc167_c
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

    int N, M, X;
    cin >> N >> M >> X;

    vector<ll> C(N);
    vector<vector<ll>> A(N, vector<ll>(M, 0));
    REP(i, N){
        cin >> C[i];
        REP(j, M) cin >> A[i][j];
    }

    ll ans = INF;
    REP(p, 1 << N){

        vector<ll> D(M, 0);
        ll cost = 0;
        REP(i, N) if ((p >> i) & 1){

            cost += C[i];
            REP(j, M){
                D[j] += A[i][j];
            }

        }

        bool is_valid = true;
        REP(j, M){
            if (D[j] < X) {
                is_valid = false;
                break;
            }
        }

        if (is_valid){
            ans = min(ans, cost);
        }
    }

    if (ans == INF){
        print(-1);
    } else {
        print(ans);
    }


    return 0;
}
