#include <bits/stdc++.h>
#ifdef LOCAL
#include "cxx-prettyprint/prettyprint.hpp"
#endif
using namespace std;

typedef __int128 ll;
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
#define print_line(vec, n) {for(int idx=0;idx<(n-1);idx++) cout << (vec)[idx] << " "; cout << (vec)[(n)-1] << endl;}
template<class T> void print(const T& x){cout << x << "\n";}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
//struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}

struct Rational {

    ll p, q;
    Rational() : p(0), q(1) {};
    Rational(ll p) : p(p), q(1) {};
    Rational(ll p, ll q) : p(p), q(q) {};

    void reduction(){ ll d = gcd(p, q); if (q < 0 && d > 0) d *= -1; p /= d; q /= d;}

    Rational& operator+=(const Rational& a) { p = p * a.q + a.p * q; q = q * a.q; reduction(); return *this; }
    Rational& operator-=(const Rational& a) { p = p * a.q - a.p * q; q = q * a.q; reduction(); return *this; }
    Rational& operator*=(const Rational& a) { p *= a.p; q *= a.q; reduction(); return *this; }
    Rational& operator/=(const Rational& a) { p *= a.q; q *= a.p; reduction(); return *this; }
    Rational operator+(const Rational& a) {Rational res(*this); return res+=a;}
    Rational operator-(const Rational& a) {Rational res(*this); return res-=a;}
    Rational operator*(const Rational& a) {Rational res(*this); return res*=a;}
    Rational operator/(const Rational& a) {Rational res(*this); return res/=a;}
    Rational operator-() const {Rational res(*this); res.p *= -1; return res;}
    bool operator==(const Rational& a) const { return p == a.p && q == a.q;}
    bool operator!=(const Rational& a) const { return p != a.p || q != a.q;}

    Rational& operator+=(const ll& a) { p = p + a * q; reduction(); return *this; }
    Rational& operator-=(const ll& a) { p = p - a * q; reduction(); return *this; }
    Rational& operator*=(const ll& a) { p *= a; reduction(); return *this; }
    Rational& operator/=(const ll& a) { q *= a; reduction(); return *this; }
    Rational operator+(const ll& a) {Rational res(*this); return res+=a;}
    Rational operator-(const ll& a) {Rational res(*this); return res-=a;}
    Rational operator*(const ll& a) {Rational res(*this); return res*=a;}
    Rational operator/(const ll& a) {Rational res(*this); return res/=a;}
    bool operator==(const ll& a) const { return p == a && q == 1;}
    bool operator!=(const ll& a) const { return p != a || q != 1;}
    bool operator==(const int& a) const { return p == a && q == 1;}
    bool operator!=(const int& a) const { return p != a || q != 1;}

    operator bool() const {return p != 0;}

    friend ostream& operator<<(ostream& os, const Rational& a) {if (a.q == 1) {cout << (long long)a.p;} else {cout << (long long)a.p << "/" << (long long)a.q;}; return os;}
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

    friend ostream& operator<<(ostream& os, const Mat<T>& mat) {cout << mat.val; return os;}
};

// is_extended: Aが拡大係数だったとき、最終列は掃き出さない
template <typename T>
int gauss_jordan(Mat<T>& A, bool is_extended=true){

    int rank = 0;
    REP(col, A.n){
        if (is_extended && col == A.n-1) break;

        // 非ゼロをさがす
        int pivot = -1;
        REPN(row, rank, A.m) {
            if (A[row][col] != 0) {
                pivot = row;
                break;
            }
        }
        if (pivot == -1) continue;

        // 対象行を1にする
        swap(A[pivot], A[rank]);
        T x = A[rank][col];
        REP(c, A.n) A[rank][c] /= x;

        // 対象行以外を0にする
        REP(row, A.m) if (row != rank && A[row][col]){
                auto coeff = A[row][col];
                REP(c, A.n) A[row][c] -= coeff * A[rank][c];
            }
        ++rank;
    }
    return rank;
}

template <typename T>
int linear_equation(Mat<T> A, vector<T> b, vector<T> &res) {

    // 拡大係数行列
    Mat<T> M(A.m, A.n + 1);
    REP(i, A.m) {
        REP(j, A.n) M[i][j] = A[i][j];
        M[i][A.n] = b[i];
    }

    // ジョルダン変形
    int rank = gauss_jordan(M);

    // ランクを超えた部分に非ゼロがあるとアウト
    REPN(row, rank, A.n) {
        if (M[row][A.n]) return -1;
    }

    // answer
    res.assign(A.n, 0);
    REP(i, A.n) res[i] = M[i][A.n];
    return rank;
}

ll func(int n){
    return 1 - n + pow(n, 2) - pow(n,3) + pow(n,4) - pow(n,5) + pow(n,6) - pow(n,7) + pow(n,8) - pow(n,9) + pow(n,10);
//    return pow(n, 3);
}


int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    ll ans = 0;
    REPN(n, 1, 11){

        Mat<Rational> A(n, n);
        REP(i, n) REP(j, n){
            A[i][j] = pow(i+1, n-j-1);
        }
        vector<Rational> b(n);
        REP(i, n) {
            b[i] = func(i+1);
        }
//        REP(i, n) print(A[i]);
//        print("b", b);

        vector<Rational> res;
        linear_equation(A, b, res);
//        print("res", res);

        Rational x = 0;
        REP(j, n){
            x += res[j] * (ll)pow(n+1, n-j-1);
        }
        ans += x.p;
    }

    print((long long)ans);

    return 0;
}