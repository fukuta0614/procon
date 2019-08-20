// abc136_e
#include <bits/stdc++.h>
#ifdef LOCAL
#include "../cxx-prettyprint/prettyprint.hpp"
#endif
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

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

int N, K;
vector<int> A;

bool check(int x){

    vector<P> nums(N);
    REP(i, N){
        nums[i].first = A[i] % x;
        nums[i].second = x - nums[i].first;
    }
    sort(ALL(nums));

    vector<ll> cumsum1(N+1), cumsum2(N+1);

    REP(i, N){
        cumsum1[i+1] = cumsum1[i] + nums[i].first;
        cumsum2[i+1] = cumsum2[i] + nums[i].second;
    }

    ll mn = INF;
    REP(i, N){
        if (cumsum1[i+1] == cumsum2[N] - cumsum2[i+1]) {
            mn = min(mn, cumsum1[i+1]);
        }
    }

    return mn <= K;
}

vector<ll> get_divisors(ll n){
    vector<ll> res;
    for (int i = 1; i * i < n; i++){
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

    cin >> N >> K;
    A = vector<int>(N);
    REP(i, N) cin >> A[i];

    ll sm = accumulate(ALL(A), 0);
    auto divisors = get_divisors(sm);

    REP_REV(i, divisors.size()){
        ll d = divisors[i];

        if (check(d)){
            print(d);
            return 0;
        }
    }

    return 0;
}
