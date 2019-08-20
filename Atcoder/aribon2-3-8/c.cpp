// aribon2-3-8_c
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

int mod_pow(ll a,ll b,int mo){int ans=1;do{if(b&1)ans=1ll*ans*a%mo;a=1ll*a*a%mo;}while(b>>=1);return ans;}

ll factorial[200001];
void make_factorial(int mo){ factorial[0] = 1; REPN(i, 1, 200001) factorial[i] = (i * factorial[i-1]) % mo; }

ll nCk(int n, int k, int mo){
    ll a = factorial[n];
    ll b = factorial[n-k] * factorial[k] % mo;
    ll b_inv = mod_pow(b, mo-2, mo);
    return a * b_inv % mo;
}

void factorize(int n, map<int, int> &res){
    int sqrt_n = (int) sqrt(n);
    REPN(i, 2, sqrt_n+1){
        int cnt = 0;
        while (n % i == 0){
            cnt++;
            n /= i;
        }
        if (cnt > 0){
            res[i] = cnt;
        }
    }

    if (n > 1){
        res[n] = 1;
    }
}

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt");
    cin.rdbuf(in.rdbuf());
#endif

    make_factorial(MOD);

    int N, M;
    cin >> N >> M;

    map<int, int> factorize_res;
    factorize(abs(N), factorize_res);

    ll ans = 1;
    for (auto mp: factorize_res){
        int cnt = mp.second;
        ans *= nCk(M + cnt - 1, cnt, MOD);
        ans %= MOD;
    }

    ll tmp = 0;
    if (N > 0) {
        REP(i, M){
            if (i * 2 > M) break;
            tmp += nCk(M, i * 2, MOD);
            tmp %= MOD;
        }
    } else {
        REP(i, M){
            if (i * 2 + 1 > M) break;
            tmp += nCk(M, i * 2 + 1, MOD);
            tmp %= MOD;
        }
    }

    print(ans * tmp % MOD);

    return 0;
}
