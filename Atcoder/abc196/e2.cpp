// abc196_e
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

void solve(){
    ll N;
    cin >> N;
    vector<ll> A(N), T(N);
    REP(i, N) cin >> A[i] >> T[i];

    ll Q;
    cin >> Q;
    vector<ll> X(Q);
    REP(i, Q) cin >> X[i];

//    std::random_device rd;
//    auto x = rd();
//    std::mt19937 mt(x);
//    N = 10;
//    A.assign(N, 0);
//    T.assign(N, 0);
//    REP(i, N) A[i] = mt() % 10000, T[i] = (mt() % 3)+1;
//    Q = 10;
//    X.assign(Q, 0);
//    REP(i, Q) X[i] = mt() % 1000000;
//
//    auto Y = X;
//    REP(i, N){
//        REP(j, Q){
//            if (T[i] == 1){
//                Y[j] += A[i];
//            } else if (T[i] == 2){
//                Y[j] = max(Y[j], A[i]);
//            } else {
//                Y[j] = min(Y[j], A[i]);
//            }
//        }
//    }

    vector<int> order(Q);
    iota(ALL(order), 0);
    sort(ALL(order), [&](int i, int j){ return X[i] < X[j];});
    sort(ALL(X));

    ll sm = 0;
    int mn=0, mx=Q-1;
    REP(i, N){

        if (T[i] == 1){
            sm += A[i];
        } else if (T[i] == 2){
            X[mn] = max(X[mn], A[i] - sm);
            while (mn < mx && X[mn+1] <= A[i] - sm) {
                mn++;
                X[mn] = A[i] - sm;
            }
        } else {
            X[mx] = min(X[mx], A[i] - sm);
            while (mn < mx && X[mx-1] >= A[i] - sm) {
                mx--;
                X[mx] = A[i] - sm;
            }
        }
    }

    ll a = X[mn];
    ll b = X[mx];
    if (mx == mn){
        REP(i, Q){
            X[i] = a + sm;
        }
    } else {
        REP(i, mn+1){
            X[i] = a + sm;
        }
        REPN(i, mn+1, mx){
            X[i] += sm;
        }
        REPN(i, mx, Q){
            X[i] = b + sm;
        }
    }

    vector<ll> ans(Q);
    REP(i, Q){
        ans[order[i]] = X[i];
    }
    REP(i, Q){
        print(ans[i]);
    }
}


int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    solve();

    return 0;
}
