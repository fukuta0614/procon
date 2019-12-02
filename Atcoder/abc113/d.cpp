// abc113_d
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
#define print_line(vec, n) {for(int i=0;i<(n-1);i++) cout << (vec)[i] << " "; cout << (vec)[(n)-1] << endl;}
template<class T> void print(const T& x){cout << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;


const int mod = 1e9 + 7;
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

    int H, W, K;
    cin >> H >> W >> K;

    vector<mint> dp(W);
    dp[0] = 1;
    REP(h, H) {
        auto prev = dp;
        dp.assign(W, 0);
        REP(k, 1 << W - 1) {
            bool valid = true;
            REP(t, W - 2) { if (((k >> t) & 0b11) == 0b11) valid = false; }
            if (not valid) continue;

            REP(i, W) {
                if (i > 0 && ((k >> (i-1)) & 1)){
                    dp[i-1] += prev[i];
                } else if (i < W-1 && ((k >> i) & 1)){
                    dp[i+1] += prev[i];
                } else {
                    dp[i] += prev[i];
                }
            }
        }
    }
    print(dp[K-1]);

//    vector<mint> d2(1000);
//    d2[0] = 1;
//    REPN(i, 1, 1000){
//        d2[i] = d2[i-1] * 2;
//    }
//    auto f = [&](int n){
//        if (n < 0) return (mint)0;
//        return d2[n];
//    };
//    if (i-1 < 0) {
//        ;
//    } else if (i-1 == 0|| i-1  == W-2){
//        dp[i] += prev[i-1] * f(W-3);
//    } else {
//        dp[i] += prev[i-1] * f(W-4);
//    }
//
//    if (i == 0 || i == W - 1){
//        dp[i] += prev[i] * f(W-2);
//    } else {
//        dp[i] += prev[i] * f(W-3);
//    }
//
//    if (i+1 > W-1) {
//        ;
//    } else if (i+1 == 1 || i+1 == W-1){
//        dp[i] += prev[i+1] * f(W-3);
//    } else {
//        dp[i] += prev[i+1] * f(W-4);
//    }

    return 0;
}
