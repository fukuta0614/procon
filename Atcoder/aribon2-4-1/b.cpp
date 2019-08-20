// aribon2-3-3_b
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

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt");
    cin.rdbuf(in.rdbuf());
#endif

    int N;
    cin >> N;
    vector<int> A(3 * N);
    REP(i, 3*N) cin >> A[i];

    priority_queue<int, vector<int>, greater<int>>  pq1;
    priority_queue<int, vector<int>, less<int>>  pq2;

    int sm1=0, sm2=0;
    REP(i, N) {
        pq1.push(A[i]);
        sm1 += A[i];
        pq2.push(A[3 * N - i - 1]);
        sm2 += A[3 * N - i - i];
    }

    vector<int> p(N+1), q(N+1);

    p[0] = sm1;
    q[N+1] = sm2;

    REP(i, N){
        p[i+1] = p[i] + A[N+i] - pq1.top();
        pq1.push(A[N+i]);
        pq1.pop();

        q[N-i-1] = q[N-i] + A[2*N-i-1] - pq2.top();
        pq2.push(A[2*N-i-1]);
        pq2.pop();
    }

    int ans = 0;
    REP(i, N){
        ans = max(p[0] - q[0], ans);
    }

    print(ans);

    return 0;
}
