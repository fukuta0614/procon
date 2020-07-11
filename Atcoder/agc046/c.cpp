// agc046_c
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
    mint pow(mint t) const {mint r=1,a=*this; do{if(t.x&1)r*=a;a*=a;}while(t.x>>=1);return r;}
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

    string S;
    int K;
    cin >> S >> K;
    vector<int> ones;
    int num = 0;
    REP(i, S.size()){
        if (S[i] == '0'){
            ones.emplace_back(num);
            num = 0;
        } else {
            num++;
        }
    }
    ones.emplace_back(num);
    reverse(ALL(ones));

    int N = ones.size();
    int sm = accumulate(ALL(ones), 0);
    K = min(sm, K);

    // dp[i][j][k]:
    // i番目まで見て
    // j回操作してて、
    // k個右に来てるような場合の数

    vector<vector<vector<mint>>> dp(N+1, vector<vector<mint>>(K+1, vector<mint>(K+1)));
    dp[0][0][0] = 1;

    REP(i, N){
        // i個目が増えるパターン (Kより多い状態から、iに落とす。)
        // dp[i+1][j][k] = dp[i][j][k] + dp[i][j][k+1] + .. + dp[i][j][K]
        REP(j, K+1) {
            mint cumsum = 0;
            REP_REV(k, K + 1) {
                cumsum += dp[i][j][k];
                dp[i + 1][j][k] = cumsum;
            }
        }

        // i個目が減るパターン (Kより少ない状態から、i個目を右に持っていってKになる
        // dp[i+1][j][k] = dp[i][j-1][k-1] + dp[i][j-2][k-2] + .. + dp[i][j-ones[i]][k-ones[i]]]
        vector<vector<mint>> cumsum(K+1, vector<mint>(K+1));
        REP(j, K+1) {
            REP(k, j+1) {
                if (k == 0) continue;
                cumsum[j][k] += cumsum[j-1][k-1] + dp[i][j-1][k-1];
                if (k <= ones[i]){
                    dp[i+1][j][k] += cumsum[j][k];
                } else {
                    dp[i+1][j][k] += cumsum[j][k] - cumsum[j-ones[i]][k-ones[i]];
                }
            }
        }
    }

//    // O(N^4)解
//    REP(i, N){
//        REP(j, K+1){
//            REP(k, K+1){
//                // i個目が増えるパターン
//                REP(l, k+1){
//                    dp[i+1][j][k-l] += dp[i][j][k];
//                }
//                // i個目が減るパターン
//                REPN(l, 1, ones[i]+1) if (j+l<=K and k+l<=K){
//                    dp[i+1][j+l][k+l] += dp[i][j][k];
//                }
//            }
//        }
//    }

    mint ans = 0;
    REP(j, K+1){
        ans += dp[N][j][0];
    }
    print(ans);





    // ↓ 組み合わせで行けるかと思ってしまった。
//    Factorial f(1e4);
//
//    int cumsum = 0;
//    mint ans = 0;
//    REP(i, N-1){
//        int d = ones[N - i - 1];
//        if (d == 0) continue;
//        cumsum += d;
//
//        REP(k, min(K, cumsum)){
//            ans += nCk(cumsum-1, k, f) * nCk(N-i-1 + k+1 - 1, k+1, f);
//            print(i, k, nCk(cumsum-1, k, f) * nCk(N-i-1 + k+1 - 1, k+1, f));
//        }
//    }
//    print(ans);

    return 0;
}
