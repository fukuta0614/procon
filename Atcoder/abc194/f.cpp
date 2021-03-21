// abc194_f
#pragma GCC optimize ("O3")

#include <bits/stdc++.h>
#ifdef LOCAL
#include "../../debug_util/cxx-prettyprint/prettyprint.hpp"
#include "../../debug_util/rng.hpp"
#include "../../debug_util/timer.hpp"
#endif
using namespace std;

using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

#define REP(i, n) for (int i = 0 ; i < (int)(n) ; ++i)
#define REPN(i, m, n) for (int i = m ; i < (int)(n) ; ++i)
#define REP_REV(i, n) for (int i = (int)(n) - 1 ; i >= 0 ; --i)
#define REPN_REV(i, m, n) for (int i = (int)(n) - 1 ; i >= m ; --i)
#define ALL(x) x.begin(), x.end()

#define INF (ll)(1e15)
#define MOD (1000000007)

#define print2D(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }
#define print_line(vec, n) {for(int idx=0;idx<(n-1);idx++) cout << (vec)[idx] << " "; cout << (vec)[(n)-1] << endl;}
template<class T> void print(const T& x){cout << x << "\n";}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

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

string to_bin(int n){ std::stringstream ss; ss << std::bitset<16>(n); return ss.str(); }


int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    string N;
    int K;
    cin >> N >> K;

    vector<vector<mint>> dp(2, vector<mint>(1<<16, 0));

    vector<int> S(N.size());
    REP(i, N.size()){
        if ('0' <= N[i] && N[i] <= '9'){
            S[i] = N[i] - '0';
        } else {
            S[i] = N[i] - 'A' + 10;
        }
    }

//    dp[0][0] = 1;
//    REP(i, S.size()){
//        auto prev = dp;
//        dp.assign(2, vector<mint>(1<<16, 0));
//
//        REP(j, 2){
//            REP(k, 1 << 16){
//                REP(d, 16){
//                    if (j == 0 && d > S[i]) continue;
//                    if (prev[j][k] == 0) continue;
//                    if (k == 0 && d == 0) continue;
//
//                    int nj = j | (d < S[i]);
//                    int nk = k | (1 << d);
//
//                    dp[nj][nk] += prev[j][k];
//                }
//            }
//        }
//        dp[1][0] = 1;
//        dp[0][0] = 0;
//    }
//
//    mint ans = 0;
//    REP(j, 2) REP(k, 1 << 16){
//        if (__builtin_popcount(k) == K){
//            ans += dp[j][k];
//        }
//    }
//    print(ans);


    mint ans = 0;
    int tmp = 0;
    REP(i, S.size()){
        tmp |= 1 << S[i];

        int k = K - __builtin_popcount(tmp);

        ans += mint(16)S.size()-i-1).pow()
    }

    return 0;
}
