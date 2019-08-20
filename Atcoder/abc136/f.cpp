// abc136_f
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

#define print2D(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }
template<class T> void print(const T& x){cout << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

const int mod = 998244353;
struct mint {
    ll x;
    mint(ll x=0):x(x%mod){}
    mint(const mint& m):x(m.x){}
    mint& operator+=(const mint a) { if ((x += a.x) >= mod) x -= mod; return *this; }
    mint& operator+=(const int a) { if ((x += a) >= mod) x -= mod; return *this; }
    mint& operator-=(const mint a) { if ((x += mod-a.x) >= mod) x -= mod; return *this; }
    mint& operator-=(const int a) { if ((x += mod-a) >= mod) x -= mod; return *this; }
    mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this; }
    mint& operator*=(const int a) { (x *= a) %= mod; return *this; }
    mint operator+(const mint a) const { mint res(*this); return res+=a; }
    mint operator+(const int a) const { mint res(*this); return res+=a; }
    mint operator-(const mint a) const { mint res(*this); return res-=a; }
    mint operator-(const int a) const { mint res(*this); return res-=a; }
    mint operator*(const mint a) const { mint res(*this); return res*=a; }
    mint operator*(const int a) const { mint res(*this); return res*=a; }
    bool operator==(const mint a) const { return x == a.x;}
    bool operator==(const int a) const { return x == a;}
    bool operator!=(const mint a) const { return x != a.x;}
    bool operator!=(const int a) const { return x != a;}
    operator bool() const {return x>0;}

    mint pow(ll t) const {mint r=1,a=*this; do{if(t&1)r*=a;a*=a;}while(t>>=1);return r;}
    mint inv() const { return pow(mod-2); }
    mint& operator/=(const mint a) { return (*this) *= a.inv(); }
    mint operator/(const mint a) const { mint res(*this); return res/=a; }
};
ostream& operator<<(ostream& os, const mint& m) {cout << m.x; return os;}


template <typename T>
struct RangeTree {
    int n;
    vector<vector<T>> dat;
    vector<T> val;

    explicit RangeTree(vector<T>& val_): val(val_) {
        n = 1;
        while (n < val.size()) n <<= 1;
        dat.assign(n << 1, vector<T>());

        build(0, 0, val.size());
    }

    void build(int k, int l, int r) {
        if (r-l == 1) {
            dat[k].emplace_back(val[l]);
        } else {
            int lch = 2*k+1, rch = 2*k+2;
            build(lch, l, (l+r)/2);
            build(rch, (l+r)/2, r);
            dat[k].resize(r-l);
            merge(dat[lch].begin(), dat[lch].end(), dat[rch].begin(), dat[rch].end(), dat[k].begin());
        }
    }

    int query(int i, int j, T x) {
        return query(i, j, x, 0, 0, val.size());
    }

    int query(int i, int j, T x, int k, int l, int r) {
        if (j <= l || r <= i) return 0;
        if (i <= l && r <= j) return upper_bound(dat[k].begin(), dat[k].end(), x) - dat[k].begin();
        int lch = query(i, j, x, 2*k+1, l, (l+r)/2);
        int rch = query(i, j, x, 2*k+2, (l+r)/2, r);
        return lch+rch;
    }
};

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N;
    cin >> N;
    vector<P> ps(N);
    REP(i, N) cin >> ps[i].first >> ps[i].second;
    sort(ALL(ps));

    vector<ll> val(N);
    REP(i, N){ val[i] = ps[i].second; }

    RangeTree<ll> rtree(val);

    vector<mint> pow2(N+1, 1);
    REP(i, N) pow2[i+1] = pow2[i] * 2;

    mint ans = 0;
    REP(i, N){

        int ld = rtree.query(0, i, val[i]);
        int lu = i - ld;
        int rd = rtree.query(i+1, N, val[i]);
        int ru = N-i-1 - rd;

        ans += pow2[N-1];
        ans += (pow2[ld] - 1) * (pow2[ru] - 1) * pow2[lu] * pow2[rd];
        ans += (pow2[lu] - 1) * (pow2[rd] - 1) * pow2[ld] * pow2[ru];
        ans -= (pow2[ld] - 1) * (pow2[ru] - 1) * (pow2[lu] - 1) * (pow2[rd] - 1);
    }

    print(ans);


    return 0;
}
