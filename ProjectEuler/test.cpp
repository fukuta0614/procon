#pragma GCC optimize ("O3")

#include <bits/stdc++.h>
#include <atcoder/modint>
#ifdef LOCAL
#include "../debug_util/cxx-prettyprint/prettyprint.hpp"
#include "../debug_util/rng.hpp"
#include "../debug_util/timer.hpp"
#endif
using namespace std;
using namespace atcoder;

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
//struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

//using mint2 = modint1000000007;

const int mod = 1e9 + 7;
struct mint {
    ll x;
    mint() : x(0) {}
    template < class T, std::enable_if_t<std::is_integral_v<T> && std::is_signed_v<T>, std::nullptr_t> = nullptr >
    mint(T v) {x = static_cast<ll>(v % mod); if (x < 0) x += mod;}
    template < class T, std::enable_if_t<std::is_integral_v<T> && std::is_unsigned_v<T>, std::nullptr_t> = nullptr >
    mint(T v) {x = static_cast<ll>(v % mod);}

    mint& operator++() { x++; if (x == mod) x = 0; return *this;}
    mint& operator--() { if (x == 0) x = mod; x--; return *this;}
    mint operator++(int) { mint result = *this; ++*this; return result;}
    mint operator--(int) { mint result = *this; --*this; return result;}

    mint operator+() const { return *this; }
    mint operator-() const { return mint(0)-*this;}
    explicit operator bool() const {return x>0;}

    mint& operator+=(const mint& a) { if ((x += a.x) >= mod) x -= mod; return *this; }
    mint& operator-=(const mint& a) { if ((x += mod-a.x) >= mod) x -= mod; return *this; }
    mint& operator*=(const mint& a) { (x *= a.x) %= mod; return *this; }

    mint pow(ll t) const {mint r=1,a=*this; do{if(t&1)r*=a;a*=a;}while(t>>=1);return r;}
    mint inv() const { return pow(mod-2); }
    mint& operator/=(const mint& a) { return (*this) *= a.inv(); }

    friend bool operator==(const mint& lhs, const mint& rhs) { return lhs.x == rhs.x;}
    friend bool operator!=(const mint& lhs, const mint& rhs) { return lhs.x != rhs.x;}

    friend mint operator+(const mint& lhs, const mint& rhs) { return mint(lhs) += rhs; }
    friend mint operator-(const mint& lhs, const mint& rhs) { return mint(lhs) -= rhs; }
    friend mint operator*(const mint& lhs, const mint& rhs) { return mint(lhs) *= rhs; }
    friend mint operator/(const mint& lhs, const mint& rhs) { return mint(lhs) /= rhs; }

    friend ostream& operator<<(ostream& os, const mint& m) {os << m.x; return os;}
    friend istream& operator>>(istream& is, mint& m) { return is >> m.x; }
};

int func(int a, int b){
    return a - b;
}


struct Rational {
    using ll = long long;

    ll p, q;
    Rational() : p(0), q(1) {};
    Rational(ll p) : p(p), q(1) {};
    Rational(ll p, ll q) : p(p), q(q) {};

    void reduction(){ ll d = gcd(p, q); if (q < 0 && d > 0) d *= -1; p /= d; q /= d;}

    Rational& operator+=(const Rational& a) { p = p * a.q + a.p * q; q = q * a.q; reduction(); return *this; }
    Rational& operator-=(const Rational& a) { p = p * a.q - a.p * q; q = q * a.q; reduction(); return *this; }
    Rational& operator*=(const Rational& a) { p *= a.p; q *= a.q; reduction(); return *this; }
    Rational& operator/=(const Rational& a) { p *= a.q; q *= a.p; reduction(); return *this; }

    Rational operator+() const { return *this; }
    Rational operator-() const { return Rational(0)-*this;}
    explicit operator bool() const {return p!=0;}

    friend bool operator==(const Rational& lhs, const Rational& rhs) { return lhs.p == rhs.p && lhs.q == rhs.q;}
    friend bool operator!=(const Rational& lhs, const Rational& rhs) { return lhs.p != rhs.p || lhs.q != rhs.q;}

    friend Rational operator+(const Rational& lhs, const Rational& rhs) { return Rational(lhs) += rhs; }
    friend Rational operator-(const Rational& lhs, const Rational& rhs) { return Rational(lhs) -= rhs; }
    friend Rational operator*(const Rational& lhs, const Rational& rhs) { return Rational(lhs) *= rhs; }
    friend Rational operator/(const Rational& lhs, const Rational& rhs) { return Rational(lhs) /= rhs; }

    friend ostream& operator<<(ostream& os, const Rational& a) {if (a.q == 1) {cout << (long long)a.p;} else {cout << (long long)a.p << "/" << (long long)a.q;}; return os;}
};



int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

//    mint a = mt() % 100;
//    print(a.x);
//
//    mint b = 100 * a;
//    mint c = a * 100;
//    print(b, c);
//
//    mint d = -100;
//    mint e = 100ull;
//
//    print(d, e);
//
//    mint x = 10;
//    mint y = 20;
//    int z = func(x, y);

    Rational a(3, 5);
    Rational b(1, 2);
    Rational c = a * b;


    return 0;
}
