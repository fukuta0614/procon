// abc200_e
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

ll func(ll n, ll k){

    if (k < n){
        return (k+1) * (k+2) / 2;
    } else if (k < 2*n){
        return (9*n-3*n*n+6*k*n-6*k-2*k*k-4)/2;
    } else {
        return (3*n-k-1) * (3*n-k-2) / 2;
    }
}

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    ll N, K;
    cin >> N >> K;

    vector<ll> table(3*N+1);
    ll sm = 0;
    ll x = 0;
    ll r = 0;
    REPN(i, 3, 3*N+1){
        table[i] = func(N, i-3);
        if (sm + table[i] >= K){
            x = i;
            r = K - sm;
            break;
        }
        sm += table[i];
    }

    print(x, table[x], r);

    sm = 0;
    REPN(i, 1, x){

        ll n = x - i;
        if (n <= N){
            ll tmp = n-1;
            if (sm + tmp >= r){
                ll a = i;
                ll b = r - sm;
                ll c = x - a - b;
                print(a, b, c);
                break;
            }
            sm += tmp;
        } else if (n <= 2*N){
            ll tmp = N - (n - N) + 1;
            if (sm + tmp >= r){
                ll a = i;
                ll b = r - sm + (n - N) - 1;
                ll c = x - a - b;
                print(a, b, c);
                break;
            }
            sm += tmp;
        } else {
            continue;
        }
    }

//    ll sm = 0;
//    REPN(i, 3, 3*N+1) {
//        sm += table[i];
//    }
//    print(table);




//    vector<ll> x(3*N+1);
//    REP(i, N) REP(j, N) REP(k, N){
//        x[i+j+k+3]++;
//    }
//    print(x);
//    sm = 0;
//    REPN(i, 3, 3*N+1) {
//        sm += x[i];
//    }
//    print(sm);

    return 0;
}
