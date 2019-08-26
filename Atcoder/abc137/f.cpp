// abc137_f
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

int mod = 1e9 + 7;
struct mint {
    ll x;
    mint(ll a=0){x = a>=0 ? a%mod : mod-(-a)%mod;}
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
    mint operator-() const {mint res(*this); return mint(0)-res;}
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
    mint& operator/=(const int& a) { return (*this) *= mint(a).inv(); }
    mint operator/(const mint& a) const { mint res(*this); return res/=a; }
    mint operator/(const int& a) const { mint res(*this); return res/=a; }

    friend ostream& operator<<(ostream& os, const mint& m) {cout << m.x; return os;}
    friend istream& operator>>(istream& is, mint& m) { return is >> m.x; }
};


int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int p;
    cin >> p;
    mod = p;

    // (x-0)*(x-1)*...*(x-(p-1))を求めておく。
    vector<mint> numerator_all(p+1, 0);
    numerator_all[0] = 1;
    REP(i, p){
        auto prev = numerator_all;
        numerator_all.assign(p+1, 0);

        // (x-0)*(x-1)*...*(x-(i-1)) -> (c0 + c1 x + c2 x^2 +..)とすると
        // (x-0)*(x-1)*...*(x-(i-1))*(x-i) -> (c0 + c1 x + c2 x^2 +..) (x - i)なので展開する
        REP(k, p) numerator_all[k+1] += prev[k];
        REP(k, p) numerator_all[k] -= prev[k] * i;
    }

    // ラグランジュ補間
    vector<mint> ans(p, 0);
    REP(i, p){
        int a; cin >> a;
        if (a == 0) continue;

        // 分母は普通に計算
        mint denominator = 1;
        REP(k, p) if (k != i) denominator *= mint(i - k);
        mint denominator_inv = denominator.inv();

        // 分子 上で求めた(x-0)*(x-1)*...*(x-(p-1))からx-iを割る。割り算の筆算する。
        mint coef = 0;
        REP_REV(k, p){
            coef = coef * i + numerator_all[k+1];
            ans[k] += coef * denominator_inv;
        }
    }

    REP(i, p-1) cout << ans[i] << " ";
    cout << ans[p-1] << endl;

    return 0;
}
