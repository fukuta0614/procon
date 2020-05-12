// abc166_d
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
    mint pow(mint t) const {mint r=1,a=*this; do{if(t.x&1)r*=a;a*=a;}while(t.x>>=1);return r;}
    mint inv() const { return pow(mod-2); }
    mint& operator/=(const mint& a) { return (*this) *= a.inv(); }
    mint& operator/=(const int& a) { return (*this) *= mint(a).inv(); }
    mint operator/(const mint& a) const { mint res(*this); return res/=a; }
    mint operator/(const int& a) const { mint res(*this); return res/=a; }

    friend ostream& operator<<(ostream& os, const mint& m) {cout << m.x; return os;}
    friend istream& operator>>(istream& is, mint& m) { return is >> m.x; }
};


ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}

vector<ll> get_divisors(ll n){
    vector<ll> res;
    for (int i = 1; i * i <= n; i++){
        if (i * i == n){
            res.emplace_back(i);
            break;
        }
        if (n % i == 0){
            res.emplace_back(i);
            res.emplace_back(n / i);
        }
    }
    sort(ALL(res));
    return res;
}

vector<ll> factorize(ll n){
    ll tmp = n;
    vector<ll> res;
    for (ll a = 2; a * a <= n; a++) { int cnt = 0; while (tmp % a == 0){ cnt++; tmp /= a; } if (cnt > 0) res.emplace_back(a); }
    if (tmp > 1) res.emplace_back(tmp);
    return res;
}

void solve_100(ll N, ll K){
    vector<ll> res(K);
    res[0] = K;
    REPN(i, 1, K){
        res[i] = gcd(i, K);
    }

    ll n = N / K;
    ll r = N % K;

    mint ans = 0;
    REP(i, K){
        if (i == 0){
            ans += mint((n+1)*K*n/2);
        } else {
            ans += mint(((i + (n-1)*K + i) * n / 2) * K / res[i]);
        }
    }

    REPN(i, 1, r+1){
        ans += mint((i + n * K) * (K / res[i]));
    }

    print(ans);
}

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    ll N, K;
    cin >> N >> K;

    mint ans = 0;

    vector<ll> divs = get_divisors(K);
    for (auto div : divs){
        // n以下のkと互いに素な数の和
        ll n = N / div;
        ll k = K / div;

        mint tmp = 0;
        vector<ll> fac = factorize(k);
        REP(p, 1 << fac.size()){

            int bincount = 0;
            ll d = 1;
            REP(i, fac.size()) if ((p >> i) & 1){
                bincount++;
                d *= fac[i];
            }
            mint m = n / d;
            if (bincount % 2 == 0){
                tmp += m * (m + 1) / mint(2) * mint(d);
            } else {
                tmp -= m * (m + 1) / mint(2) * mint(d);
            }
//            print(m, tmp);
        }
//        print("div", div, tmp, tmp * mint(K));
        ans += tmp * mint(K);
    }

    print(ans);

    return 0;
}
