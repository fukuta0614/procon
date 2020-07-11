// aising2020_d
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
#define print_line(vec, n) {for(int i=0;i<(n-1);i++) cout << (vec)[i] << " "; cout << (vec)[(n)-1] << endl;}
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
    mint pow(mint t) const {mint r=1,a=*this; do{if(t.x&1)r*=a;a*=a;}while(t.x>>=1);return r;}
    mint inv() const { return pow(mod-2); }
    mint& operator/=(const mint& a) { return (*this) *= a.inv(); }
    mint& operator/=(const int& a) { return (*this) *= mint(a).inv(); }
    mint operator/(const mint& a) const { mint res(*this); return res/=a; }
    mint operator/(const int& a) const { mint res(*this); return res/=a; }

    friend ostream& operator<<(ostream& os, const mint& m) {cout << m.x; return os;}
    friend istream& operator>>(istream& is, mint& m) { return is >> m.x; }
};


// 階乗
struct Factorial {
    vector<mint> values;
    explicit Factorial(int n): values(n+1, 0) { values[0] = 1; for (int i = 1; i <= n; ++i) { values[i] = values[i-1] * i;}}
    mint operator()(int n){ return n >= 0 ? values[n] : mint(0);}
};


vector<ll> memo;
ll func(ll x){
    if (memo[x] != -1) return memo[x];

    ll n = __builtin_popcount(x);
    return memo[x] = func(x % n) + 1;
}

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif
    int N;
    cin >> N;
    string X;
    cin >> X;

    memo.assign(N+1, -1);
    memo[0] = 0;

//    REP(i, 4){
//        print(i, func(i));
//    }

    int num = 0;
    REP(i, N){
        num += (X[i] == '1');
    }

    vector<ll> res(2, 0);
    vector<vector<ll>>  tmp(2, vector<ll>(N+1, 1));
    vector<int> mod{num+1, num-1};
    REP(i, N){
        REP(k, 2){
            if (mod[k] == 0) continue;
            res[k] += (X[N-1-i] == '1') * tmp[k][i];
            res[k] %= mod[k];
            tmp[k][i+1] = tmp[k][i] * 2;
            tmp[k][i+1] %= mod[k];
        }
    }

    REP(i, N){

        ll x=0;
        ll ans;
        if (X[i] == '1'){
            if (num == 1){
                ans = 0;
            } else {
                x = res[1];
                x -= tmp[1][N-1-i];
                x = (x + mod[1]) % mod[1];
                ans = func(x) + 1;
            }
        } else {
            x = res[0];
            x += tmp[0][N-1-i];
            x = (x + mod[0]) % mod[0];
            ans = func(x) + 1;
        }

//        print(i, x, ans);
        print(ans);
    }




    return 0;
}
