// abc189_e
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
#define print_line(vec, n) {for(int idx=0;idx<(n-1);idx++) cout << (vec)[idx] << " "; cout << (vec)[(n)-1] << endl;}
template<class T> void print(const T& x){cout << x << "\n";}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

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

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    ll N;
    cin >> N;
    vector<ll> X(N), Y(N);
    REP(i, N) cin >> X[i] >> Y[i];

    ll M;
    cin >> M;
    vector<ll> OP1(M), OP2(M);
    REP(i, M) {
        cin >> OP1[i];
        if (OP1[i] >= 3) cin >> OP2[i];
    }

    ll Q;
    cin >> Q;
    vector<ll> A(Q), B(Q);
    REP(i, Q) cin >> A[i] >> B[i];

    vector<Mat<ll>> ops;

    Mat<ll> prev(3, 3);
    prev.assign({{1, 0, 0},{0, 1, 0}, {0, 0, 1}});
    ops.emplace_back(prev);

    REP(i, M){
        Mat<ll> op(3, 3);
        if (OP1[i] == 1){
            op.assign({{0,  1, 0},
                       {-1, 0, 0},
                       {0,  0, 1}});
        } else if (OP1[i] == 2){
            op.assign({{0,  -1, 0},
                       {1, 0, 0},
                       {0,  0, 1}});
        } else if (OP1[i] == 3){
            ll p = OP2[i];
            op.assign({{-1,  0, 2*p},
                       {0, 1, 0},
                       {0,  0, 1}});
        } else {
            ll p = OP2[i];
            op.assign({{1,  0, 0},
                       {0, -1, 2*p},
                       {0,  0, 1}});
        }

        prev = op * prev;
        ops.emplace_back(prev);
    }

    REP(i, Q){
        int idx = B[i] - 1;
        vector<ll> v{X[idx], Y[idx], 1};
        auto ans = ops[A[i]].dot(v);
        print(ans[0], ans[1]);
    }


    return 0;
}
