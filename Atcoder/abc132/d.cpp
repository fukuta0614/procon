// abc132_d
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

ll factorial[2001];
void make_factorial(int mo){ factorial[0] = 1; REPN(i, 1, 2001) factorial[i] = (i * factorial[i-1]) % mo; }
ll get_factorial(int n){ return n >= 0 ? factorial[n] : 0; }

ll nCk(int n, int k, int mo){
    ll a = get_factorial(n);
    ll b = get_factorial(n-k) * get_factorial(k) % mo;
    ll b_inv = mod_pow(b, mo-2, mo);
    return a * b_inv % mo;
}

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N, K;
    cin >> N >> K;

    int b = K;
    int r = N - K;

    make_factorial(MOD);

    REPN(i, 1, K+1){
        ll ans = (nCk(r+1, i, MOD) * nCk(b-1, i-1, MOD)) % MOD;
        print(ans);
    }

    return 0;
}
