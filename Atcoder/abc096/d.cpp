// abc096_d
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

#define INF (ll)(1e9)
#define MOD (1000000007)

#define print2D(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }
#define print_line(vec, n) {for(int idx=0;idx<(n-1);idx++) cout << (vec)[idx] << " "; cout << (vec)[(n)-1] << endl;}
template<class T> void print(const T& x){cout << x << "\n";}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

struct EratosthenesSieve{
    vector<bool> is_prime;
    EratosthenesSieve(int N): is_prime(N+1, true){
        is_prime[0] = is_prime[1] = false;
        for (int n=2; n<=N; n++){
            if (not is_prime[n]) continue;
            for (int i = 2; n * i <= N; i++) is_prime[n * i] = false;
        }
    }
};

struct CombinationGenerator {
    ll sup, ret;
    bool first;
    CombinationGenerator(int n, int k): sup(1ll<<n), ret((1ll<<k)-1) {first = true;}
    ll operator()(){
        if (first) {first = false; return ret;}
        if (ret == 0) return -1;
        ll x = ret & -ret, y = ret + x;
        ret = ((ret & ~y) / x >> 1) | y;
        return ret < sup ? ret : -1;
    }
};

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N;
    cin >> N;

    int MAX = 55555;
    EratosthenesSieve sieve(MAX);

    vector<int> ans;
    REP(i, MAX+1){
        if (sieve.is_prime[i] && i % 5 == 1){
            ans.emplace_back(i);
        }
    }
//    print(ans.size());

    print_line(ans, N);


    return 0;
}
