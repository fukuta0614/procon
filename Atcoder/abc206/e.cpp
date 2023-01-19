// abc206_e
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

// 何度も素因数分解を行う場合の高速版
// エラトステネスの篩っぽく、その整数を割る最小の整数を配列として格納する
struct FastFactorization{
    vector<int> smallest_divisor;

    FastFactorization(int N): smallest_divisor(N+1, -1){
        smallest_divisor[1] = 1;
        for (int n=2; n<=N; n++){
            if (smallest_divisor[n] != -1) continue;
            for (int x = n; x <= N; x+=n) smallest_divisor[x] = n;
        }
    }

    vector<int> operator()(int N){
        set<int> res;
        int n = N;
        while (n > 1) {
            int d = smallest_divisor[n];
            res.emplace(d);
            n /= d;
        }
        return vector<int>(ALL(res));
    };
};


int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int L, R;
    cin >> L >> R;

    FastFactorization fast_fac(R);

    ll ans = 0;
    REPN(x, max(2, L), R+1){

        vector<int> fac = fast_fac(x);

        // x < y <= R かつ gcd(x, y) == 1を満たすyの数
        ll tmp = 0;
        REP(p, 1 << fac.size()){

            int bincount = 0;
            int d = 1;
            REP(i, fac.size()) if ((p >> i) & 1){
                bincount++;
                d *= fac[i];
            }

            int m = R / d - x / d;

            if (bincount % 2 == 0){
                tmp += m;
            } else {
                tmp -= m;
            }
        }

        // x < y <= R かつ gcd(x, y) != 1を満たすyの数
        tmp = R-x - tmp;

        // ↑から、xの倍数となるyを引く
        tmp -= R/x - 1;

        //
        ans += tmp;
    }

    print(2 * ans);

//    ll tmp = 0;
//    REPN(i, L, R+1) REPN(j, i+1, R+1){
//        int d = gcd(i, j);
//        if (d != 1 && i != d){
//            tmp++;
//        }
//    }
//    print(2 * tmp);

    return 0;
}
