// abc102_d
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
#define print_line(vec, n) {for(int i=0;i<(n-1);i++) cout << (vec)[i] << " "; cout << (vec)[(n)-1] << endl;}
template<class T> void print(const T& x){cout << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N;
    cin >> N;
    vector<ll> A(N);
    REP(i, N) cin >> A[i];

    vector<ll> cumsum(N+1);
    REP(i, N){
        cumsum[i+1] = cumsum[i] + A[i];
    }

    print(A);
    print(cumsum);

    ll ans = 1e15;
    REPN(m, 1, N-2){ // 0-m, m+1-N
        print(m);
        ll l_sum = cumsum[m+1] - cumsum[0];
        auto l_it = lower_bound(cumsum.begin(), cumsum.begin() + m + 1 + 1, l_sum/2);
        ll p = *l_it - cumsum[0];
        ll q = l_sum - p;
        if (l_it != cumsum.begin()){
            ll p2 = *(--l_it) - cumsum[0];
            ll q2 = l_sum - p2;
            if (abs(p2-q2) < abs(p-q)) p=p2,q=q2;
        }

        print("l", l_sum, l_it-cumsum.begin(), p, q);

        ll r_sum = cumsum[N] - cumsum[m+1];
        auto r_it = lower_bound(cumsum.begin()+m+1+1, cumsum.end(), l_sum + r_sum/2);
        ll s = *r_it - cumsum[m+1];
        ll t = r_sum - s;
        if (r_it != cumsum.begin()+m+1+1){
            ll s2 = *(--r_it) - cumsum[m+1];
            ll t2 = r_sum - s2;
            if (abs(s2-t2) < abs(s-t)) s=s2,t=t2;
        }

        print("r", r_sum, r_it-cumsum.begin(), s, t);

        ll mn = min(min(p, q), min(s, t));
        ll mx = max(max(p, q), max(s, t));
        ans = min(ans, mx-mn);
    }

    print(ans);

    return 0;
}
