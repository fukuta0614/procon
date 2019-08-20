// aribon2-6-4_b
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

#define INF ((1 << 29)-1)
#define MOD (1000000007)

#define print2D(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }
template<class T> void print(const T& x){cout << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;
#define MAX_N 100001

bool is_prime[MAX_N];
int cumsum[MAX_N];

void seive(void) {
    REP(n, MAX_N) is_prime[n] = true;
    is_prime[0] = is_prime[1] = false;
    REPN(n, 2, MAX_N){
        if (!is_prime[n]) continue;

        for (int i = 2; n * i <= MAX_N;i++) {
            is_prime[n * i] = false;
        }
    }
}

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt");
    cin.rdbuf(in.rdbuf());
#endif

    int Q; cin >> Q;

    seive();

    REPN(n, 3, MAX_N) {
        bool is2017like = is_prime[n] && is_prime[(n+1)/2];
        cumsum[n] = cumsum[n-1] + is2017like;
    }

    int l,r;
    REP(i, Q){
        cin >> l >> r;
        print(cumsum[r] - cumsum[l-1]);
    }


    return 0;
}
