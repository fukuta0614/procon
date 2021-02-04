// abc188_d
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

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    ll N, D;
    cin >> N >> D;

    vector<ll> A(N), B(N), C(N);
    REP(i, N) cin >> A[i] >> B[i] >> C[i];

    vector<pair<ll, ll>> d;
    REP(i, N) {
        d.emplace_back(A[i], i);
        d.emplace_back(B[i]+1, i+N);
    }
    sort(ALL(d));

    ll sm = 0;
    ll prev = 0;

    ll ans = 0;
    REP(i, 2*N){
        ll s;
        int x;
        tie(s, x) = d[i];

        ans += (s - prev) * min(D, sm);

        if (x < N){
            sm += C[x];
        } else {
            sm -= C[x-N];
        }
        prev = s;
    }

    print(ans);


    return 0;
}
