// agc039_c
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
#define MOD (998244353)

#define print2D(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }
template<class T> void print(const T& x){cout << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;


const int mod = 998244353;
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

    int N;
    cin >> N;
    string S;
    cin >> S;

//    int X = 0;
//    REP(i, S.size()){
//        if (S[S.size()-1-i] == '1') X += (1 << i);
//    }
//
//    print(X);
//
//    int sm = 0;
//    REPN(orig, 0, X+1){
//        int n = orig;
//        int cnt = 0;
////        print(bitset<6>(n));
//        while (true){
//            if (n & 1) n >>= 1;
//            else n = (n >> 1) + (1 << (N-1));
//            cnt++;
////            print(bitset<6>(n));
//            if (n == orig) break;
//        }
//        print(orig, cnt);
//        sm += cnt;
//    }
//    print(sm);


    REPN(N, 2, 12){
        print("---------");
        print(N);

        int sm = 0;
        REPN(orig, 0, 1<<N){
            int n = orig;
            int cnt = 0;
//        print(bitset<6>(n));
            while (true){
                if (n & 1) n >>= 1;
                else n = (n >> 1) + (1 << (N-1));
                cnt++;
//            print(bitset<6>(n));
                if (n == orig) break;
            }
//            print(orig, bitset<12>(orig), cnt);
            sm += cnt;
        }
        print(N, sm);

        int x = 1 << N;

        int tmp;
        int tmp_cnt;
        if (N == 5 || N == 3 || N == 7) {
            tmp = 2;
            tmp_cnt = 2;
        } else {
            tmp = 1;
            tmp_cnt = 0;
        }
        int ans = 2 * N * (x-tmp_cnt);
        ans += tmp * tmp_cnt;
        print(ans);
    }





    return 0;
}
