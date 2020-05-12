// abc062_d
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

    ll N;
    cin >> N;
    vector<ll> A(3 * N);
    REP(i, 3 * N) cin >> A[i];

    priority_queue<ll, vector<ll>, greater<ll>> pq_l;
    priority_queue<ll, vector<ll>, less<ll>> pq_r;

    ll sum_l = 0, sum_r = 0;
    REP(i, N){
        pq_l.push(A[i]);
        sum_l += A[i];

        pq_r.push(A[3*N-i-1]);
        sum_r += A[3*N-i-1];
    }

    vector<ll> p(N+1), q(N+1);

    p[0] = sum_l;
    q[N] = sum_r;
    REP(i, N) {
        pq_l.push(A[N + i]);
        sum_l += A[N + i];
        ll x = pq_l.top(); pq_l.pop();
        sum_l -= x;
        p[i+1] = sum_l;

        pq_r.push(A[2*N-i-1]);
        sum_r += A[2*N-i-1];
        ll y = pq_r.top(); pq_r.pop();
        sum_r -= y;
        q[N-i-1] = sum_r;
    }
//    print(p);
//    print(q);

    ll ans = -1e15;
    REP(i, N+1){
        ans = max(ans, p[i] - q[i]);
    }
    print(ans);

    return 0;
}
