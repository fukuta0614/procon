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

template <typename T>
using Mat = vector<vector<T>>;

template <typename T>
Mat<T> calc_mat_mod(Mat<T> A, Mat<T> B, T mod){
    Mat<T> C;
    C.assign(A.size(), vector<T>(B[0].size(), 0));

    REP(i, A.size()) {
        REP(j, B[0].size()) {
            REP(k, A[0].size()){
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
            }
        }
    }
    return C;
}

template <typename T>
vector<T> calc_mat_vec_mod(Mat<T> A, vector<T> x, T mod){
    vector<T> y(x.size(), 0);

    REP(i, A.size()) {
        REP(k, A[0].size()){
            y[i] = (y[i] + A[i][k] * x[k]) % mod;
        }
    }
    return y;
}

template <typename T>
Mat<T> mat_pow_mod(Mat<T> A, ll n, T mod) {
    Mat<T> B;
    B.assign(A.size(), vector<T>(A.size(), 0));
    REP(i, A.size()) B[i][i] = 1;

    while(n > 0) {
        if (n & 1) {
            B = calc_mat_mod(A, B, mod);
        }
        A = calc_mat_mod(A, A, mod);
        n >>= 1;
    }
    return B;
}

ll d_10[37];

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt");
    cin.rdbuf(in.rdbuf());
#endif

    ll L, A, B, M;
    cin >> L >> A >> B >> M;

    d_10[0] = 1;
    REP(i, 18){ d_10[i+1] = (d_10[i] * 10); }

    ll now_l = 0;
    ll s = A % M;
    ll ans = A % M;
    Mat<ll> mat;
    vector<ll> x{ans, s, B%M};
    for (int d = 1; d < 18 && now_l < L-1; d++) {
        if (d_10[d] - A - 1 < 0) continue;

        ll next_l = (d_10[d] - A - 1) / B;

        mat.assign({
            {d_10[d]%M, 1, 1},
            {0,       1, 1},
            {0,       0, 1}
        });

        print(mat);

        ll l_cnt = min(next_l, L-1) - now_l;
        print(l_cnt);
        Mat<ll> mat_l = mat_pow_mod(mat, l_cnt, M);
        print(mat_l);
        x = calc_mat_vec_mod(mat_l, x, M);
        print(x);
        now_l = next_l;
    }

    print(x[0]);

    return 0;
}

