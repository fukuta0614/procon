//
// Created by 福田圭佑 on 2019/07/27.
//

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


//ll extgcd(ll a, ll b, ll& x, ll& y) const { ll d = a; if(b != 0){ d = extgcd(b, a%b, y, x); y -= (a/b) * x; } else{ x = 1; y = 0; } return d; }
//
//mint& operator/=(const mint& a) {
//    ll d = gcd(x, a.x);
//    d = gcd(d, mod);
//    ll p = x / d;
//    ll q = a.x / d;
//    ll mod2 = mod / d;
//    print(x, a.x, d, p, q, mod2);
//
//    assert(gcd(p, mod2) == 1);
//
//    ll s, t;
//    extgcd(q, mod2, s, t);
//    ll q_inv = (mod2 + s%mod2) % mod2;
//
//    x = (p * q_inv) % mod2;
//    return *this;
//}

// 階乗
struct Factorial {
    vector<mint> values;
    explicit Factorial(int n): values(n+1, 0) { values[0] = 1; for (int i = 1; i <= n; ++i) { values[i] = values[i-1] * i;}}
    mint operator()(int n){ return n >= 0 ? values[n] : mint(0);}
};

// 組み合わせ
mint nCk(int n, int k, Factorial& f){ return f(n) / (f(n-k) * f(k));}

// nが大きく、n!を予め計算できないとき
mint nCk(ll n, ll k) {
    mint denominator = 1, numerator = 1;
    REP(i, k) { numerator *= (n - i); denominator *= (i + 1); }
    mint ret = numerator / denominator;
    return ret;
}

mint nPk(int n, int k, Factorial& f){ return f(n) / f(n-k);}

mint nHk(int n, int k, Factorial& f){ return nCk(n+k-1, k-1, f);}
