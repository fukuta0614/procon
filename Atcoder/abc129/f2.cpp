// abc129_f
#include <bits/stdc++.h>
#ifdef LOCAL
#include "../cxx-prettyprint/prettyprint.hpp"
#endif
using namespace std;

typedef long long ll;

#define REP(i, n) for (int (i) = 0 ; (i) < (int)(n) ; ++(i))
#define REPN(i, m, n) for (int (i) = m ; (i) < (int)(n) ; ++(i))
#define ALL(x) x.begin(), x.end()

template<class T> void print(const T& x){cout << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }


int mod;
struct mint {
    ll x;
    mint(ll x=0):x(x%mod){}
    mint(const mint& m):x(m.x){}
    mint& operator+=(const mint a) { if ((x += a.x) >= mod) x -= mod; return *this; }
    mint& operator-=(const mint a) { if ((x += mod-a.x) >= mod) x -= mod; return *this; }
    mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this; }
    mint operator+(const mint a) const { mint res(*this); return res+=a; }
    mint operator-(const mint a) const { mint res(*this); return res-=a; }
    mint operator*(const mint a) const { mint res(*this); return res*=a; }

    mint pow(ll t) const {mint r=1,a=*this; do{if(t&1)r*=a;a*=a;}while(t>>=1);return r;}
    mint inv() const { return pow(mod-2); }
    mint& operator/=(const mint a) { return (*this) *= a.inv(); }
    mint operator/(const mint a) const { mint res(*this); return res/=a; }
};
ostream& operator<<(ostream& os, const mint& m) {cout << m.x; return os;}


// m行n列
template <typename T> struct Mat {
    int m, n;
    vector<vector<T>> val;
    Mat(int m, int n, T x=0) : m(m),n(n),val(m, vector<T>(n, x)) {};
    void assign(initializer_list<vector<T>> X){ val.assign(X); }
    inline vector<T>& operator [] (int i) {return val[i];}

    Mat<T> operator*(Mat<T> B) const{
        assert(n == B.m);
        Mat<T> R(m, B.n);
        REP(i, m) REP(j, B.n) REP(k, n) { R[i][j] += val[i][k] * B[k][j]; }
        return R;
    }
    Mat<T>& operator*=(Mat<T> B) { return *this=*this*B; }

    Mat<T> pow(int t) const {
        assert(m == n);
        Mat<T> A(*this);
        Mat<T> R(m, m);
        REP(i, m) R[i][i] = 1;
        while(t > 0) {
            if (t & 1) R *= A;
            A *= A;
            t >>= 1;
        }
        return R;
    }

    vector<T> dot(vector<T> x) const {
        assert(n == x.size());
        vector<T> y(m, 0);
        REP(i, m) REP(j, n) y[i] += val[i][j] * x[j];
        return y;
    }
};
template <typename T> ostream& operator<<(ostream& os, const Mat<T>& mat) {cout << mat.val; return os;}


ll d_10[37];

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt");
    cin.rdbuf(in.rdbuf());
#endif
    ll L, A, B, M;
    cin >> L >> A >> B >> M;
    mod = (int)M;

    d_10[0] = 1;
    REP(i, 18){ d_10[i+1] = (d_10[i] * 10);}

    ll now_l = 0;
    mint s(A);
    mint ans(A);

    Mat<mint> mat(3, 3);
    vector<mint> x{ans, s, B%M};

    for (int d = 1; d < 20 && now_l < L-1; d++) {
        if (d_10[d] - A - 1 < 0) continue;

        ll next_l = (d_10[d] - A - 1) / B;

        mat.assign({
           {d_10[d], 1, 1},
           {0,           1, 1},
           {0,           0, 1}
        });

        ll l_cnt = min(next_l, L-1) - now_l;
        auto mat_l = mat.pow(l_cnt);
        x = mat_l.dot(x);
        now_l = next_l;
    }

    print(x[0]);

    return 0;
}
