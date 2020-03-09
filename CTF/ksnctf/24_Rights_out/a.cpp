// aribon3-2-3_4_f Awkward Lights
#include <bits/stdc++.h>
#ifdef LOCAL
#include "../../../Atcoder/cxx-prettyprint/prettyprint.hpp"
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

template <int mod>
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
    bool operator==(const mint a) const { return x == a.x;}
    bool operator==(const ll a) const { return x == a;}
    bool operator==(const int a) const { return x == a;}
    bool operator!=(const mint a) const { return x != a.x;}
    bool operator!=(const ll a) const { return x != a;}
    bool operator!=(const int a) const { return x != a;}
    operator bool() const {return x>0;}

    mint pow(ll t) const {mint r=1,a=*this; do{if(t&1)r*=a;a*=a;}while(t>>=1);return r;}
    mint inv() const { return pow(mod-2); }
    mint& operator/=(const mint a) { return (*this) *= a.inv(); }
    mint operator/(const mint a) const { mint res(*this); return res/=a; }
};
template <int mod> ostream& operator<<(ostream& os, const mint<mod>& m) {cout << m.x; return os;}

int M, N, D;
vector<vector<int>> S;

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
        REP(c, A.n) A[rank][c] /= A[rank][col];

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



int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    cin >> M >> N >> D;

    S.assign(N, vector<int>(M, 0));
    REP(i, N) REP(j, M) cin >> S[i][j];

    Mat<mint<2>> A(N*M, N*M);
    vector<mint<2>> b(N*M);

    REP(i, N) REP(j, M){
        REP(i2, N) REP(j2, M){
            int d = abs(i - i2) + abs(j - j2);
            if (d == D || (i==i2 && j==j2)){
                A[i2*M+j2][i*M+j] = 1;
            }
        }
        b[i*M+j] = S[i][j];
    }

    vector<mint<2>> res;
    int rank = linear_equation(A, b, res);
    REP(i, 5){
        REP(j, 5){
            cout << res[i*5+j] << " ";
        }
        print("");
    }



    return 0;
}