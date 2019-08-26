// aribon3-4_a
// D - 25個の整数
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

struct CombinationGenerator {
    ll sup, ret;
    bool first;
    CombinationGenerator(int n, int k): sup(1ll<<n), ret((1ll<<k)-1) {first = true;}
    ll operator()(){
        if (first) {first = false; return ret;}
        if (ret == 0) return -1;
        ll x = ret & -ret, y = ret + x;
        ret = ((ret & ~y) / x >> 1) | y;
        return ret < sup ? ret : -1;
    }
};

bool is_valid(int p, ll mask){
    int i = p / 5;
    int j = p % 5;
    if (0 < i && i < 4 && ((mask >> ((p - 5)) ^ (mask >> (p + 5))) & 1)) return false;
    if (0 < j && j < 4 && ((mask >> ((p - 1)) ^ (mask >> (p + 1))) & 1)) return false;
    return true;
}

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    vector<int> pos(26, -1);
    vector<bool> used(25, false);
    REP(i, 5) REP(j, 5) {
        int n; cin >> n;
        if (n) {
            pos[n] = i * 5 + j;
            used[i*5+j] = true;
        }
    }

    const int sz = 25;

    vector<int> dp(1 << sz, 0);

    dp[0] = 1;
    REPN(n, 1, sz + 1){
        // n個bitが立つbit列を列挙
        CombinationGenerator g(25, n-1);
        while (true){
            ll mask = g();
            if (mask < 0) break;

            if (dp[mask] == 0) continue;

            if (pos[n] != -1) {
                if (is_valid(pos[n], mask)){
                    dp[mask | (1 << pos[n])] += dp[mask];
                    dp[mask | (1 << pos[n])] %= mod;
                }
            } else {
                REP(p, sz){
                    if (mask & (1 << p)) continue;
                    if (used[p]) continue;

                    if (is_valid(p, mask)){
                        dp[mask | (1 << p)] += dp[mask];
                        dp[mask | (1 << p)] %= mod;
                    }
                }
            }
        }

    }

    print(dp[(1 << sz) - 1]);
    return 0;
}
