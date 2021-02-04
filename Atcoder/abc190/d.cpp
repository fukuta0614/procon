// abc190_d
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

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    ll N;
    cin >> N;

    auto res = get_divisors(2 * N);

    int ans = 0;
    for (auto d: res){
        ll x = d, y = 2*N/d;

        if ((x + y - 1) % 2 == 0 || (x - y + 1) % 2 == 0){
            ll a = (x - y + 1) / 2;
            ll b = (x + y - 1) / 2;
            if (b >= a){
//                print(d, x, y, a, b);
                ans++;
            }
        }

        x *= -1, y *= -1;
        if ((x + y - 1) % 2 == 0 || (x - y + 1) % 2 == 0){
            ll a = (x - y + 1) / 2;
            ll b = (x + y - 1) / 2;
            if (b >= a){
//                print(d, x, y, a, b);
                ans++;
            }
        }
    }

    print(ans);


    return 0;
}
