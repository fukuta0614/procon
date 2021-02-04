// abc186_e
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

#define INF (ll)(1e9)
#define MOD (1000000007)

#define print2D(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }
#define print_line(vec, n) {for(int idx=0;idx<(n-1);idx++) cout << (vec)[idx] << " "; cout << (vec)[(n)-1] << endl;}
template<class T> void print(const T& x){cout << x << "\n";}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}


ll extgcd(ll a, ll b, ll& x, ll& y){
    ll d = a;
    if(b != 0){
        d = extgcd(b, a%b, y, x);
        y -= (a/b) * x;
    }else{
        x = 1; y = 0;
    }
    return d;
}

ll inv_mod(ll a, ll mod){
    ll x, y;
    extgcd(a, mod, x, y);
    return (mod + x%mod) % mod;
}

random_device rd;
mt19937 mt(rd());

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int T;
    cin >> T;

    while (T--){
        ll N, S, K;
        cin >> N >> S >> K;

//        N = mt() % 1000;
//        S = mt() % N;
//        K = mt() % 1000;

        ll a = K;
        ll b = N-S;

        ll d = gcd(a, N);
        if (b % d != 0){
            print(-1);
            continue;
        }

        a /= d;
        b /= d;
        N /= d;

        ll ans = b * inv_mod(a, N);
        ans %= N;

        print(ans);

//
//        ll ans2 = -1;
//        REP(i, N){
//            if ((S + K * i) % N == 0){
//                ans2 = i;
//                break;
//            }
//        }
////        print(ans2);
//        print(N, S, K, a, b, ans, ans2);

    }

    return 0;
}
