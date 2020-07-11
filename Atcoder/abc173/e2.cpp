// abc173_e
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

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    REP(i, N) cin >> A[i];

    sort(ALL(A), [](int a, int b){ return abs(a) < abs(b);});

    vector<int> pos;
    vector<int> neg;
    REP(i, N){
        if (A[i] >= 0) pos.emplace_back(A[i]);
        else neg.emplace_back(A[i]);
    }

    mint ans = 1;

    if (N == K){
        // 全部選ぶしか無い
        REP(i, K) ans *= mint(A[i]);

    } else if (pos.empty()){
        // 全部負なら、Kが偶数なら大きくなるように、Kが奇数なら小さくなるように
        if (K % 2 == 1){
            REP(i, K) ans *= mint(neg[i]);
        } else {
            REP(i, K) ans *= mint(neg[N-1-i]);
        }
    } else {
        // 上記以外なら、絶対正にできる

        // Kが奇数なら、1個正を選ぶ必要があるので最初に一番大きいのを選んどく
        if (K % 2 == 1){
            ans *= pos.back();
            pos.pop_back();
            K--;
        }

        // m, nのどちらかは必ず2以上である。
        // なぜなら、m=1,n=1で残るならそれはN=Kだから
        REP(i, K/2){
            int m = pos.size();
            int n = neg.size();
            ll x = 0, y = 0;
            if (m >= 2) x = (ll)pos[m-1] * pos[m-2];
            if (n >= 2) y = (ll)neg[n-1] * neg[n-2];

            if (x >= y){
                ans *= pos[m-1];
                ans *= pos[m-2];
                pos.pop_back(); pos.pop_back();
            } else {
                ans *= -neg[n-1];
                ans *= -neg[n-2];
                neg.pop_back(); neg.pop_back();
            }
        }
    }
    print(ans);


    return 0;
}
