//
// Created by 福田圭佑 on 2019/07/27.
//

const int mod = 1e9 + 7;
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
    operator bool() const {return x>0;}

    mint pow(ll t) const {mint r=1,a=*this; do{if(t&1)r*=a;a*=a;}while(t>>=1);return r;}
    mint inv() const { return pow(mod-2); }
    mint& operator/=(const mint a) { return (*this) *= a.inv(); }
    mint operator/(const mint a) const { mint res(*this); return res/=a; }
};
ostream& operator<<(ostream& os, const mint& m) {cout << m.x; return os;}

// 階乗
struct Factorial {
    vector<mint> values;
    Factorial(int n) { values[0] = 1; for (int i = 1; i <= n; ++i) { values[i] = i * values[i-1]; }}
    mint operator()(int n){ return n >= 0 ? values[n] : 0;}
};

// 組み合わせ
mint nCk(int n, int k, Factorial& f){ return f(n) / (f(n-k) * f(k));}