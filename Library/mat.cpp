//
// Created by 福田圭佑 on 2019/07/27.
//
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef pair<int, P> PP;

#define REP(i, n) for (int (i) = 0 ; (i) < (int)(n) ; ++(i))
#define REPN(i, m, n) for (int (i) = m ; (i) < (int)(n) ; ++(i))

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