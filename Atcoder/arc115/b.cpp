// arc115_b
#pragma GCC optimize ("O3")

#include <bits/stdc++.h>
#ifdef LOCAL
#include "../../debug_util/cxx-prettyprint/prettyprint.hpp"
#include "../../debug_util/rng.hpp"
#include "../../debug_util/timer.hpp"
#endif
using namespace std;

using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

#define REP(i, n) for (int i = 0 ; i < (int)(n) ; ++i)
#define REPN(i, m, n) for (int i = m ; i < (int)(n) ; ++i)
#define REP_REV(i, n) for (int i = (int)(n) - 1 ; i >= 0 ; --i)
#define REPN_REV(i, m, n) for (int i = (int)(n) - 1 ; i >= m ; --i)
#define ALL(x) x.begin(), x.end()

#define INF (ll)(1e15)
#define MOD (1000000007)

#define print2D(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }
#define print_line(vec, n) {for(int idx=0;idx<(n-1);idx++) cout << (vec)[idx] << " "; cout << (vec)[(n)-1] << endl;}
template<class T> void print(const T& x){cout << x << "\n";}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N;
    cin >> N;
    vector<vector<ll>> C(N, vector<ll>(N, 0));
    REP(i, N) REP(j, N) cin >> C[i][j];

    vector<ll> A(N), B(N);
    A[0] = 0;
    REP(j, N)  B[j] = C[0][j];

    bool valid = true;
    REPN(i, 1, N) REP(j, N){
        if (j == 0){
            A[i] = C[i][j] - B[j];
        } else {
            if (C[i][j] != A[i] + B[j]){
                valid = false;
                break;
            }
        }
    }

    ll mn = INF;
    REP(i, N){
        mn = min(mn, A[i]);
    }

    if (mn < 0){
        REP(i, N) {
            A[i] -= mn;
            B[i] += mn;
            if (B[i] < 0){
                valid = false;
                break;
            }
        }
    }

    if (valid){
        print("Yes");
        print_line(A, N);
        print_line(B, N);

        REP(i, N) REP(j, N){
            assert(A[i] + B[j] == C[i][j]);
        }
        REP(i, N){
            assert(A[i] >= 0);
            assert(B[i] >= 0);
        }
    } else {
        print("No");
    }

    return 0;
}
