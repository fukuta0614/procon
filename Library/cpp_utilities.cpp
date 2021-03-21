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

// int128のprint
ostream& operator<<(ostream& os, const __int128& x) {
    ll a = (ll) (x / 1000000000000000000ll);
    ll b = (ll) (x % 1000000000000000000ll);
    if (a != 0){
        os << a << b;
    } else {
        os << b;
    }
    return os;
}

map<ll, int> factorize(ll n){
    ll tmp = n;
    map<ll, int> res;
    for (ll a = 2; a * a <= n; a++) { int cnt = 0; while (tmp % a == 0){ cnt++; tmp /= a; } if (cnt > 0) res[a] = cnt; }
    if (tmp > 1) res[tmp] = 1;
    return res;
}

vector<ll> get_divisors(ll n){
    vector<ll> res;
    for (ll i = 1; i * i <= n; i++){
        if (n % i != 0) continue;
        res.emplace_back(i);
        if (n / i == i) continue;
        res.emplace_back(n / i);
    }
    sort(ALL(res));
    return res;
}

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}

ll lcm(ll a, ll b) { return a * b / gcd(a, b);}

ll extgcd(ll a, ll b, ll& x, ll& y) { ll d = a; if(b != 0){ d = extgcd(b, a%b, y, x); y -= (a/b) * x; } else{ x = 1; y = 0; } return d; }

int bit_count(unsigned int bits) { int cnt = 0; for(unsigned int mask=1;mask!=0;mask<<=1){if((bits&mask)!=0) ++cnt; }return cnt; }

string to_hex(int n){ std::stringstream ss; ss << std::hex << n; return ss.str(); }
string to_oct(int n){ std::stringstream ss; ss << std::oct << n; return ss.str(); }
string to_bin(int n){ std::stringstream ss; ss << std::bitset<8>(n); return ss.str(); }

int dx[8]={ 1, 0, -1, 0, -1, 1, -1, 1};
int dy[8]={ 0, 1, 0, -1, -1, -1, 1, 1};
bool bound_check(int i, int j, int N, int M) {return (0 <= i) && (i < N) && (0 <= j) && (j < M);}

struct EratosthenesSieve{
    vector<bool> is_prime;
    EratosthenesSieve(int N): is_prime(N+1, true){
        is_prime[0] = is_prime[1] = false;
        for (int n=2; n<=N; n++){
            if (not is_prime[n]) continue;
            for (int i = 2; n * i <= N; i++) is_prime[n * i] = false;
        }
    }
};

// 何度も素因数分解を行う場合の高速版
// エラトステネスの篩っぽく、その整数を割る最小の整数を配列として格納する
struct FastFactorization{
    vector<int> smallest_divisor;

    FastFactorization(int N): smallest_divisor(N+1, -1){
        smallest_divisor[1] = 1;
        for (int n=2; n<=N; n++){
            if (smallest_divisor[n] != -1) continue;
            for (int x = n; x <= N; x+=n) smallest_divisor[x] = n;
        }
    }

    map<int, int> operator()(int N){
        map<int, int> res;
        int n = N;
        while (n > 1) {
            int d = smallest_divisor[n];
            res[d]++;
            n /= d;
        }
        return res;
    };
};

bool is_prime(int n){
    if (n == 1) return false;
    for (int a=2; a*a <= n; a++) if (n % a == 0) return false;
    return true;
}

int euler_phi(int n){
    int res = n;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0){
            res = res / i * (i-1);
            for (; n % i == 0; n /= i);
        }
    }
    if (n != 1) res = res / n * (n - 1);
    return res;
}

struct CombinationGenerator {
    ll sup, ret;
    bool first;
    CombinationGenerator(int n, int k): sup(1ll<<n), ret((1ll<<k)-1) {first = true;}
    ll operator()(){
        if (first) {first = false; return ret;}
        if (ret == 0) return -1;
        ll x = ret & -ret, y = ret + x;
        ret = ((ret & ~y) / x >> 1) | y;
        return ret < sup ? ret : -1;
    }
};

//    CombinationGenerator g(n, r);
//    ll mask;
//    while ((mask = g()) >= 0){
//        ll tmp = 1;
//        REP(i, n) if (mask & (1 << i)) {
//            tmp *= cnt[i];
//        }
//        ans += tmp;
//    }


// 負の数にも対応した mod
// 例えば -17 を 5 で割った余りは本当は 3 (-17 ≡ 3 (mod. 5))
// しかし単に -17 % 5 では -2 になってしまう
inline long long mod(long long a, long long m) {
    return (a % m + m) % m;
}

// 拡張 Euclid の互除法
// ap + bq = gcd(a, b) となる (p, q) を求め、d = gcd(a, b) をリターンします
long long extGcd(long long a, long long b, long long &p, long long &q) {
    if (b == 0) { p = 1; q = 0; return a; }
    long long d = extGcd(b, a%b, q, p);
    q -= a/b * p;
    return d;
}

// 中国剰余定理
// リターン値を (r, m) とすると解は x ≡ r (mod. m)
// 解なしの場合は (0, -1) をリターン
pair<long long, long long> ChineseRem(const vector<long long> &b, const vector<long long> &m) {
    long long r = 0, M = 1;
    for (int i = 0; i < (int)b.size(); ++i) {
        long long p, q;
        long long d = extGcd(M, m[i], p, q); // p is inv of M/d (mod. m[i]/d)
        if ((b[i] - r) % d != 0) return make_pair(0, -1);
        long long tmp = (b[i] - r) / d * p % (m[i]/d);
        r += M * tmp;
        M *= m[i]/d;
    }
    return make_pair(mod(r, M), M);
}

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
