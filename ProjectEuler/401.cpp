#pragma GCC optimize ("O3")

#include <bits/stdc++.h>
#ifdef LOCAL
#include "../debug_util/cxx-prettyprint/prettyprint.hpp"
#include "../debug_util/rng.hpp"
#include "../debug_util/timer.hpp"
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

// 素数でないmodのmint
const int mod = 1e9;
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

    ll extgcd(ll a, ll b, ll& x, ll& y) const { ll d = a; if(b != 0){ d = extgcd(b, a%b, y, x); y -= (a/b) * x; } else{ x = 1; y = 0; } return d; }

    mint& operator/=(const mint& a) {
        ll d = gcd(x, a.x);
        d = gcd(d, mod);
        ll p = x / d;
        ll q = a.x / d;
        ll mod2 = mod / d;
        print(x, a.x, d, p, q, mod2);

        assert(gcd(p, mod2) == 1);

        ll s, t;
        extgcd(q, mod2, s, t);
        ll q_inv = (mod2 + s%mod2) % mod2;

        x = (p * q_inv) % mod2;
        return *this;
    }

    mint& operator/=(const int& a) { return (*this) /= mint(a); }
    mint operator/(const mint& a) const { mint res(*this); return res/=a; }
    mint operator/(const int& a) const { mint res(*this); return res/=a; }

    friend ostream& operator<<(ostream& os, const mint& m) {cout << m.x; return os;}
    friend istream& operator>>(istream& is, mint& m) { return is >> m.x; }
};

ll func(ll n){

    ll ret = 0;
    REPN(i, 1, n+1){
        ret += i*i * (n/i);
    }
    return ret;
}

ll f(ll n){
    return n*(n+1)*(2*n+1)/6;
}

mint f2(ll n){
    vector<ll> x{n, n+1, 2*n+1};
    REP(i, 3) if (x[i] % 2 == 0) x[i] /= 2;
    REP(i, 3) if (x[i] % 3 == 0) x[i] /= 3;

    mint ret = 1;
    REP(i, 3) ret *= mint(x[i]);
    return ret;
}

mint func_opt(ll n){

    ll s = sqrt(n);

    mint ret = 0;
    for (ll k = 1; k <= s; k++){
        ret += f2(n/k) + mint(k)*mint(k)*mint(n/k);
    }

    ret -= mint(s) * f2(s);

    return ret;
}

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

//    REPN(i, 1, 10){
//        print(func(i), func_opt(i));
//    }

    mint ans = func_opt((ll)1e15);
    print(ans);

    return 0;
}
