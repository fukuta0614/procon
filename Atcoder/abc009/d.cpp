// abc147_f
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

struct SemiRing{
    ll x;
    SemiRing(ll x=0): x(x) {};
    SemiRing& operator+=(const SemiRing& a) { x ^= a.x; return *this;}
    SemiRing& operator*=(const SemiRing& a) { x &= a.x; return *this; }
    SemiRing operator+(const SemiRing& a) const { SemiRing res(*this); return res+=a; }
    SemiRing operator*(const SemiRing& a) const { SemiRing res(*this); return res*=a; }

    friend ostream& operator<<(ostream& os, const SemiRing& m) {cout << m.x; return os;}
    friend istream& operator>>(istream& is, SemiRing& m) { return is >> m.x; }
};

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
        REP(i, m) R[i][i] = (1ll<<32)-1; // 改変
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

    friend ostream& operator<<(ostream& os, const Mat<T>& mat) {cout << mat.val; return os;}
};


int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int K, M;
    cin >> K >> M;
    vector<ll> A(K);
    REP(i, K) cin >> A[i];
    vector<ll> C(K);
    REP(i, K) cin >> C[i];

    Mat<SemiRing> D(K, K);
    REP(i, K) D[0][i] = C[i];
    REP(i, K-1) D[i+1][i] = (1ll<<32)-1;

    vector<SemiRing> A_s(K);
    REP(i, K) A_s[i] = A[K-i-1];

//    print(D);
//    print(A_s);

    ll ans;
    if (M <= K){
        ans = A[M-1];
    } else {
        auto D_m = D.pow(M-K);
        ans = (D_m.dot(A_s))[0].x;
    }

    print(ans);

    return 0;
}
