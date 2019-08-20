#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef pair<int, P> PP;

#define REP(i, n) for (int (i) = 0 ; (i) < (int)(n) ; ++(i))
#define REPN(i, m, n) for (int (i) = m ; (i) < (int)(n) ; ++(i))
#define REP_REV(i, n) for (int (i) = (int)(n) - 1 ; (i) >= 0 ; --(i))
#define REPN_REV(i, m, n) for (int (i) = (int)(n) - 1 ; (i) >= m ; --(i))
#define ALL(x) x.begin(), x.end()
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );
#define CHAR2INT(c) (c - '0')

#define INF ((1 << 29)-1)
#define MOD (1000000007)

int mod_pow(ll a,ll b,int mo){int ans=1;do{if(b&1)ans=1ll*ans*a%mo;a=1ll*a*a%mo;}while(b>>=1);return ans;}


ll factorial[200001];
void make_factorial(int mo){ factorial[0] = 1; REPN(i, 1, 200001) factorial[i] = (i * factorial[i-1]) % mo; }

ll get_factorial(int n){ return n >= 0 ? factorial[n] : 0; }

ll nCk(int n, int k, int mo){
    ll a = get_factorial(n);
    ll b = get_factorial(n-k) * get_factorial(k) % mo;
    ll b_inv = mod_pow(b, mo-2, mo);
    return a * b_inv % mo;
}

void factorize(int n, map<int, int> &res){
    int sqrt_n = (int) sqrt(n);
    REPN(i, 2, sqrt_n+1){
        int cnt = 0;
        while (n % i == 0){
            cnt++;
            n /= i;
        }
        if (cnt > 0){
            res[i] = cnt;
        }
    }

    if (n > 1){
        res[n] = 1;
    }
}

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

int gcd(int a,int b){return b?gcd(b,a%b):a;}
int dx[8]={ 1, 0, -1, 0, -1, 1, -1, 1};
int dy[8]={ 0, 1, 0, -1, -1, -1, 1, 1};

#define print2D(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }
template<class T> void print(const T& x){cout << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

random_device rd;
mt19937 mt(rd());

ll N = mt() % 10 + 1;
ll K = mt() % N + 1;

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt");
    cin.rdbuf(in.rdbuf());
#endif

    int N;
    cin >> N;

    return 0;
}
