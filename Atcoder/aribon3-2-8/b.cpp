// aribon3-2-8_b
#include <bits/stdc++.h>
#ifdef LOCAL
#include "../cxx-prettyprint/prettyprint.hpp"
#endif
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;

#define REP(i, n) for (ll (i) = 0 ; (i) < (ll)(n) ; ++(i))
#define REPN(i, m, n) for (ll (i) = m ; (i) < (ll)(n) ; ++(i))
#define REP_REV(i, n) for (int (i) = (int)(n) - 1 ; (i) >= 0 ; --(i))
#define REPN_REV(i, m, n) for (int (i) = (int)(n) - 1 ; (i) >= m ; --(i))
#define ALL(x) x.begin(), x.end()

#define INF ((1 << 29)-1)
#define MOD (1000000007)

#define print2D(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }
template<class T> void print(const T& x){cout << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

std::ostream &operator<<(std::ostream &dest, __int128_t value) {
    std::ostream::sentry s(dest);
    if (s) {
        __uint128_t tmp = value < 0 ? -value : value;
        char buffer[128];
        char *d = std::end(buffer);
        do {
            --d;
            *d = "0123456789"[tmp % 10];
            tmp /= 10;
        } while (tmp != 0);
        if (value < 0) {
            --d;
            *d = '-';
        }
        int len = std::end(buffer) - d;
        if (dest.rdbuf()->sputn(d, len) != len) {
            dest.setstate(std::ios_base::badbit);
        }
    }
    return dest;
}
__int128 parse(string &s) {
    __int128 ret = 0;
    for (int i = 0; i < s.length(); i++)
        if ('0' <= s[i] && s[i] <= '9')
            ret = 10 * ret + s[i] - '0';
    return ret;
}


map<ll, int> factorize(ll n){
    map<ll, int> res;
    ll a = n;
    for (ll i = 2; i * i < a; i++){
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

    return res;
}


void brute_force(){
    int N = 1e8;
    unordered_map<int, int> memo;
    REP(i, 10){
        memo[i] = 0;
    }

    int mx = 0;
    ll mx_int = 0;
    REPN(i, 10, N) {
        ll tmp = 1;
        ll n = i;
        while (n > 0){
            tmp *= n % 10;
            n /= 10;
        }

        memo[i] = memo[tmp] + 1;
        if (memo[i] > mx){
            mx = memo[i];
            mx_int = i;
        }
    }

    print(mx, mx_int);

    while (mx_int > 0){
        ll n = mx_int;
        ll tmp = 1;
        while (n > 0){
            tmp *= n % 10;
            n /= 10;
        }

        mx_int = tmp;
        print(mx_int, memo[mx_int]);
    }
}

void print_sequence(ll mx_num){
    int cnt=0;
    while (mx_num > 9) {
        ll n = mx_num;
        ll tmp = 1;
        while (n > 0) {
            tmp *= n % 10;
            n /= 10;
        }
        print(mx_num, tmp);
        mx_num = tmp;
        cnt++;
    }
    print(cnt);
}

int mx_cnt = 0;
ll mx_num = 0;

int asdf = 0;
vector<int> vec;

int calc(ll x){
    int cnt=0;
    while (x > 9){
        ll n = x;
        ll tmp = 1;
        while (n > 0){
            tmp *= n % 10;
            n /= 10;
        }
        x = tmp;
        cnt++;
    }
    return cnt;
}

void traverse(ll d, ll prev = 1, ll res = 1) {
    REPN(n, prev, 10){
        if (d - 1 == 0) {
            int cnt = calc(res * n) + 1;
            if (cnt > mx_cnt){
                vec.emplace_back(n);
                mx_cnt = cnt;
                mx_num = 0;
                for (auto x: vec){
                    mx_num = mx_num * 10 + x;
                }
                vec.pop_back();
                asdf++;
            }

        }
        else {
            vec.emplace_back(n);
            traverse(d-1, n, res*n);
            vec.pop_back();
        }
    }
}

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    traverse(15);
    print(mx_cnt, mx_num);

//    print_sequence(26888999);
//    print_sequence(3778888999);
//    print_sequence(277777788888899);
//    string s = "22222222222222222223333777777";
//    __int128 x = parse(s);
//    print_sequence(x);

    return 0;
}
