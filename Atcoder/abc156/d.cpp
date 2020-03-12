// abc156_d
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


// 階乗
//struct Factorial {
//    vector<mint> values;
//    explicit Factorial(int n): values(n+1, 0) { values[0] = 1; for (int i = 1; i <= n; ++i) { values[i] = values[i-1] * i;}}
//    mint operator()(int n){ return n >= 0 ? values[n] : mint(0);}
//};

// 組み合わせ
//mint nCk(int n, int k, Factorial& f){ return f(n) / (f(n-k) * f(k));}


//ll arr[] = {
//    1, 682498929, 491101308, 76479948, 723816384, 67347853, 27368307, 625544428, 199888908, 888050723, 927880474, 281863274, 661224977, 623534362, 970055531, 261384175, 195888993, 66404266, 547665832, 109838563, 933245637, 724691727, 368925948, 268838846, 136026497, 112390913, 135498044, 217544623, 419363534, 500780548, 668123525, 128487469, 30977140, 522049725, 309058615, 386027524, 189239124, 148528617, 940567523, 917084264, 429277690, 996164327, 358655417, 568392357, 780072518, 462639908, 275105629, 909210595, 99199382, 703397904, 733333339, 97830135, 608823837, 256141983, 141827977, 696628828, 637939935, 811575797, 848924691, 131772368, 724464507, 272814771, 326159309, 456152084, 903466878, 92255682, 769795511, 373745190, 606241871, 825871994, 957939114, 435887178, 852304035, 663307737, 375297772, 217598709, 624148346, 671734977, 624500515, 748510389, 203191898, 423951674, 629786193, 672850561, 814362881, 823845496, 116667533, 256473217, 627655552, 245795606, 586445753, 172114298, 193781724, 778983779, 83868974, 315103615, 965785236, 492741665, 377329025, 847549272, 698611116
//};
//
//
//mint func(ll n){
//
//    constexpr ll thr = 10000000;
//    std::cin >> n;
//    ll ret = arr[n / thr];
//    for (ll i = n / thr * thr + 1; i <= n; i++) {
//        ret = ret * i % mod;
//    }
//    return mint(ret);
//}
//
//mint nCk(int n, int k){
//    return func(n) / (func(n-k) * func(k));
//}

mint nCk(ll n, ll k) {
    mint denominator = 1;
    mint numerator = 1;
    REP(i, k) {
        numerator *= (n - i);
        denominator *= (i + 1);
    }
    mint ret = numerator / denominator;
    return ret;
}


int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int n, a, b;
    cin >> n >> a >> b;

//    Factorial f(2*1e5+1);

    mint ans = mint(2).pow(n) - mint(1) - nCk(n, a) - nCk(n, b);
    print(ans);

    return 0;
}
