// abc250_d
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
//struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

struct EratosthenesSieve{
    vector<bool> is_prime;

    // n以下の素数の数
    vector<int> prime_count;

    EratosthenesSieve(int N): is_prime(N+1, true), prime_count(N+1, 0){
        is_prime[0] = is_prime[1] = false;
        for (int n=2; n<=N; n++){
            if (not is_prime[n]) continue;
            for (int i = 2; n * i <= N; i++) is_prime[n * i] = false;
        }

        REPN(n, 1, N+1){
            prime_count[n] = prime_count[n-1] + is_prime[n];
        }
    }
};

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    ll N;
    cin >> N;

    EratosthenesSieve sieve(1e6);

    ll ans = 0;
    for (ll q = 1; q <= N; q++){
        if (q * q * q > N) break;
        if (not sieve.is_prime[q]) continue;

        ll a = N / (q*q*q);
        ll b = min(a, q-1);
        ans += sieve.prime_count[b];
//        print(q, a, b, ans);
    }

    print(ans);


    return 0;
}
