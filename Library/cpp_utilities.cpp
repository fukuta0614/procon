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
        if (i * i == n){
            res.emplace_back(i);
            break;
        }
        if (n % i == 0){
            res.emplace_back(i);
            res.emplace_back(n / i);
        }
    }
    sort(ALL(res));
    return res;
}

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}

ll lcm(ll a, ll b) { return a * b / gcd(a, b);}

int bit_count(unsigned int bits) { int cnt = 0; for(unsigned int mask=1;mask!=0;mask<<=1){if((bits&mask)!=0) ++cnt; }return cnt; }

string to_hex(int n){ std::stringstream ss; ss << std::hex << n; return ss.str(); }
string to_oct(int n){ std::stringstream ss; ss << std::oct << n; return ss.str(); }
string to_bin(int n){ std::stringstream ss; ss << std::bitset<8>(n); return ss.str(); }

int dx[8]={ 1, 0, -1, 0, -1, 1, -1, 1};
int dy[8]={ 0, 1, 0, -1, -1, -1, 1, 1};

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
