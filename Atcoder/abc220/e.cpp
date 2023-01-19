// abc220_e
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

const int mod = 998244353;
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

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N, D;
    cin >> N >> D;


    // ある頂点以下の距離dの数
    auto subtree = [](int d){
        return mint(2).pow(d);
    };

    mint ans = 0;
    REP(i, N){

        mint tmp = 0;
        // その頂点より下側
        if (N - i - 1 >= D) {
            tmp += mint(2).pow(i) * subtree(D);
        }

        // 登って降りる
        // N-1 - (i-j) >= D-j
        // 2j >= D-N+i+1
//        REPN(j, max(1, (D-N+i+2)/2), min(D, i+1)){
//            tmp += mint(2).pow(i) * mint(2).pow(D-j-1);
//        }
        int a = max(1, (D-N+i+2)/2);
        int x = min(D-1, i);
        if (x >= a){
            tmp += mint(2).pow(i) * mint(2).pow(D-x-1) * (mint(2).pow(x-a+1) - 1);
        }

        // 登るだけ
        if (i >= D){
            tmp += mint(2).pow(i);
        }

//        print(i, tmp);

        ans += tmp;
    }
    print(ans);


//    {
//        mint ans = 0;
//        REP(i, N){
//
//            mint tmp = 0;
//            // その頂点より下側
//            if (N - i - 1 >= D) {
//                tmp += mint(2).pow(i) * subtree(D);
//            }
//
//            // 登って降りる
//        REPN(j, 1, min(D, i+1)){
//            tmp += mint(2).pow(i) * mint(2).pow(D-j-1);
//        }
////            int x = min(D-1, i);
////            if (x >= 1){
////                tmp += mint(2).pow(i) * mint(2).pow(D-x-1) * (mint(2).pow(x) - 1);
////            }
//
//            // 登るだけ
//            if (i >= D){
//                tmp += mint(2).pow(i);
//            }
//
////        print(i, tmp);
//
//            ans += tmp;
//        }
//        print(ans);
//    }


    return 0;
}
