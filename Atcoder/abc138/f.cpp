// abc138_f
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

const int mod = 1e9 + 7;
struct mint {
    ll x;
    mint(ll x=0):x(x%mod){}
    mint(const mint& m):x(m.x){}
    mint& operator+=(const mint& a) { if ((x += a.x) >= mod) x -= mod; return *this; }
    mint& operator+=(const int& a) { if ((x += a) >= mod) x -= mod; return *this; }
    mint& operator-=(const mint& a) { if ((x += mod-a.x) >= mod) x -= mod; return *this; }
    mint& operator-=(const int& a) { if ((x += mod-a) >= mod) x -= mod; return *this; }
    mint& operator*=(const mint& a) { (x *= a.x) %= mod; return *this; }
    mint& operator*=(const int& a) { (x *= a) %= mod; return *this; }
    mint operator+(const mint& a) const { mint res(*this); return res+=a; }
    mint operator+(const int& a) const { mint res(*this); return res+=a; }
    mint operator-(const mint& a) const { mint res(*this); return res-=a; }
    mint operator-(const int& a) const { mint res(*this); return res-=a; }
    mint operator*(const mint& a) const { mint res(*this); return res*=a; }
    mint operator*(const int& a) const { mint res(*this); return res*=a; }
    bool operator==(const mint& a) const { return x == a.x;}
    bool operator==(const int& a) const { return x == a;}
    bool operator!=(const mint& a) const { return x != a.x;}
    bool operator!=(const int& a) const { return x != a;}
    operator bool() const {return x>0;}

    mint pow(ll t) const {mint r=1,a=*this; do{if(t&1)r*=a;a*=a;}while(t>>=1);return r;}
    mint inv() const { return pow(mod-2); }
    mint& operator/=(const mint& a) { return (*this) *= a.inv(); }
    mint operator/(const mint& a) const { mint res(*this); return res/=a; }

    friend ostream& operator<<(ostream& os, const mint& m) {cout << m.x; return os;}
    friend istream& operator>>(istream& is, mint& m) { return is >> m.x; }
};

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    ll L, R;
    cin >> L >> R;

    mint dp[62][2][2][2] = {0};
    dp[61][0][0][0] = 1;
    REP_REV(i, 61) REP(l, 2) REP(r, 2) REP(d, 2){

        int lx = (L & (1ll << i)) == (1ll << i);
        int rx = (R & (1ll << i)) == (1ll << i);

        mint tmp = dp[i+1][l][r][d];

        REP(a, 2) REP(b, 2){
            if(l == 0 && a == 0 && lx == 1) continue; // まだxがLより大きくない場合はaは0はだめ
            if(r == 0 && b == 1 && rx == 0) continue; // まだyがRより小さくない場合はbは1はだめ
            if(a > b) continue; // x > y はだめ
            if(d == 0 && a != b) continue; // MSBが確定していないうちにa != bはだめ。

            int nl = l || (lx == 0 && a == 1); // すでにxがLより大きい、もしくはaが超えたら、次はLより大きいでよい
            int nr = r || (rx == 1 && b == 0); // すでにyがRより小さい、もしくはbが下回ったら、次はRより小さいでよい
            int nd = d || (a==1 && b==1); // すでにMSBが確定している、もしくは今一致したら、次はMSB確定でよい
            dp[i][nl][nr][nd] += tmp;
        }
    }

    mint ans = 0;
    REP(l, 2) REP(r, 2) REP(d, 2) {
        ans += dp[0][l][r][d];
    }
    print(ans);


    return 0;
}
