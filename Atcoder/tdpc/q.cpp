// tdpc_q
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

    int N, L;
    cin >> N >> L;

    vector<P> W; // (文字数, 2進数として読んだときの数)
    REP(i, N) {
        string s; cin >> s;
        int w = 0;
        REP(k, s.size()) w |= (s[s.size()-1-k] == '1') << k;
        W.emplace_back(s.size(), w);
    }

    // dp[i][j][k]
    // i文字まで伸ばしたときの
    // 直近7文字がjで、
    // 直近8文字のなかで文字列の切れ目となるような場所にはbitがたつような数を作るとk となるような数
    mint dp[L+1][1 << 7][1 << 8];

    dp[0][0][1] = 1;
    REP(i, L) REP(j, 1 << 7) REP(k, 1 << 8){

        if (dp[i][j][k] == 0) continue;

        if (i == L-1 && j == 1){
            print(i, j, bitset<4>(k));
        }
        if (i == L-2 && j == 0){
            print(i, j, bitset<4>(k));

        }
        REP(d, 2){
            int is_valid = 0;
            REP(n, N){
                int sz = W[n].first - 1; // n番目の文字列が使えるのは、文字数-1の場所に切れ目があって、文字列が一致するとき
                int w1 = W[n].second;
                int w2 = ((((1 << sz) - 1) & j) << 1) | d;

                if ( (k >> sz) & 1 && w1 == w2 ){
                    is_valid = 1;
                    break;
                }
            }

            int nj = ((j << 1) | d) & ((1 << 7) - 1);
            int nk = ((k << 1) | is_valid) & ((1 << 8) - 1);
            dp[i+1][nj][nk] += dp[i][j][k];
        }
    }

    mint ans = 0;
    REP(j, 1 << 7) REP(k, 1 << 7) {
        ans += dp[L][j][(k << 1) | 1];
    }
    print(ans);


    return 0;
}
