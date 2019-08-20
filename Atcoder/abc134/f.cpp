// abc134_f
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

template <int mod>
struct mint {
    ll x;
    mint(ll x=0):x(x%mod){}
    mint(const mint& m):x(m.x){}
    mint& operator+=(const mint a) { if ((x += a.x) >= mod) x -= mod; return *this; }
    mint& operator-=(const mint a) { if ((x += mod-a.x) >= mod) x -= mod; return *this; }
    mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this; }
    mint operator+(const mint a) const { mint res(*this); return res+=a; }
    mint operator-(const mint a) const { mint res(*this); return res-=a; }
    mint operator*(const mint a) const { mint res(*this); return res*=a; }
    bool operator==(const mint a) const { return x == a.x;}
    bool operator==(const ll a) const { return x == a;}
    bool operator==(const int a) const { return x == a;}
    bool operator!=(const mint a) const { return x != a.x;}
    bool operator!=(const ll a) const { return x != a;}
    bool operator!=(const int a) const { return x != a;}
    explicit operator bool() const {return x>0;}

    mint pow(ll t) const {mint r=1,a=*this; do{if(t&1)r*=a;a*=a;}while(t>>=1);return r;}
    mint inv() const { return pow(mod-2); }
    mint& operator/=(const mint a) { return (*this) *= a.inv(); }
    mint operator/(const mint a) const { mint res(*this); return res/=a; }
};
template <int mod> ostream& operator<<(ostream& os, const mint<mod>& m) {cout << m.x; return os;}


mint<MOD> dp[51][51][2605];

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N, K;
    cin >> N >> K;

    dp[0][0][0] = 1;
    REP(i, N){
        REP(j, i+1){
            REP(k, K+1){
                int nj;
                // どっちも保留
                nj = j + 1;
                dp[i+1][nj][k+2*nj] += dp[i][j][k];

                // どっちもi+1同士でつなぐ
                nj = j;
                dp[i+1][nj][k+2*nj] += dp[i][j][k];

                // どっちかを保留とつなぐ
                nj = j;
                dp[i+1][nj][k+2*nj] += dp[i][j][k] * 2*j;

                // どっちも保留とつなぐ
                if (j > 0){
                    nj = j-1;
                    dp[i+1][nj][k+2*nj] += dp[i][j][k] * j * j;
                }
            }
        }
    }

    print(dp[N][0][K]);




    return 0;
}
