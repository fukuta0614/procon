// abc168_e
#include <bits/stdc++.h>
#ifdef LOCAL
#include "../cxx-prettyprint/prettyprint.hpp"
#endif
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

#define REP(i, n) for (int (i) = 0 ; (i) < (int)(n) ; ++(i))
#define REPN(i, m, n) for (int (i) = m ; (i) < (int)(n) ; ++(i))
#define REP_REV(i, n) for (int (i) = (int)(n) - 1 ; (i) >= 0 ; --(i))
#define REPN_REV(i, m, n) for (int (i) = (int)(n) - 1 ; (i) >= m ; --(i))
#define ALL(x) x.begin(), x.end()

#define INF ((1 << 29)-1)
#define EPS (1e-12)
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

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N;
    cin >> N;

    vector<ll> A(N), B(N);
    REP(i, N) {
        cin >> A[i] >> B[i];
        if (A[i] == 0 && B[i] == 0){
            ;
        } else if (A[i] == 0){
            B[i] = 1;
        } else if (B[i] == 0){
            A[i] = 1;
        } else {
            ll d = gcd(abs(A[i]), abs(B[i]));
            A[i] /= d; B[i] /= d;

            if (A[i] <= 0 && B[i] >= 0){
                A[i] *= -1; B[i] *= -1;
            }
            if (A[i] <= 0 && B[i] <= 0){
                A[i] *= -1; B[i] *= -1;
            }
        }
    }

    map<P, int> mp;
    REP(i, N){
        mp[P(A[i], B[i])]++;
    }
    vector<P> vec;
    for (auto e: mp){
        vec.emplace_back(e.first);
    }

//    print(mp);
//    print(vec);

    mint ans = 1;
    for (auto ab: vec) {
        ll a = ab.first;
        ll b = ab.second;
        int cnt = mp[ab];

        P ba = P(0, 0);
        if (a == 0 && b == 0){
            continue;
        } else if (a == 0){
            ba = P(1, 0);
        } else if (b == 0){
            ba = P(0, 1);
        } else {
            ba = (b > 0) ? P(b, -a) : P(-b, a);
        }

        int cnt2 = mp[ba];
        if (cnt2 > 0){
            ans *= (mint(2).pow(cnt) + mint(2).pow(cnt2) - mint(1));
            mp[ba] = 0;
            mp[ab] = 0;
        } else {
            ans *= mint(2).pow(cnt);
        }
    }

    if (mp[P(0, 0)] > 0){
        int cnt = mp[P(0, 0)];
        ans += cnt;
    }

    ans -= mint(1);
    print(ans);


//    set<double> st;
//    REP(i, N){
//        double th1 = A[i] / B[i];
//        double th2 = B[i] / A[i];
//
//        auto it = st.lower_bound(th1);
//
//        bool exist = false;
//        if (it == st.begin()){
//            if (abs(*it - th1) < EPS) {
//                exist = true;
//            }
//        } else if (it == st.end()){
//            it--;
//            if (abs(*it - th1) < EPS) {
//                exist = true;
//            }
//        } else {
//            if (abs(*it - th1) < EPS) {
//                exist = true;
//            }
//            it++;
//            if (abs(*it - th1) < EPS) {
//                exist = true;
//            }
//        }
//
//    }

    return 0;
}
