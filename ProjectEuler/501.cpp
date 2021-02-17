#pragma GCC optimize ("O3")

#include <bits/stdc++.h>
#ifdef LOCAL
#include "../debug_util/cxx-prettyprint/prettyprint.hpp"
#include "../debug_util/rng.hpp"
#include "../debug_util/timer.hpp"
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

#define INF (ll)(1e9)
#define MOD (1000000007)

#define print2D(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }
#define print_line(vec, n) {for(int idx=0;idx<(n-1);idx++) cout << (vec)[idx] << " "; cout << (vec)[(n)-1] << endl;}
template<class T> void print(const T& x){cout << x << "\n";}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
//struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

struct FastFactorization{
    vector<int> smallest_divisor;

    explicit FastFactorization(int N): smallest_divisor(N+1, -1){
        smallest_divisor[1] = 1;
        for (int n=2; n<=N; n++){
            if (smallest_divisor[n] != -1) continue;
            for (int x = n; x <= N; x+=n) smallest_divisor[x] = n;
        }
    }

    int operator()(int N){
        map<int, int> res;
        int n = N;
        while (n > 1) {
            int d = smallest_divisor[n];
            res[d]++;
            n /= d;
        }
        int ret = 1;
        for (auto [a, x]: res){
            ret *= x+1;
        }
        return ret;
    };
};

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    FastFactorization factorize(1e6+1);

    start_time();

    int ret = 0;
    REPN(i, 1, 1e5+1){
        if (8 == factorize(i)){
            ret++;
        }
    }

    REP(i, 1e5){
        if (8 == factorize(i+1)){
            ret++;
        }
    }
    print(ret);
    print_time();

    auto v = random_vector<int>(100, 10);
    print(v);

    return 0;
}
