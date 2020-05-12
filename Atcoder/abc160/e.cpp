// abc160_e
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

#define INF (2e9)
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

    ll X, Y, A, B, C;
    cin >> X >> Y >> A >> B >> C;
    vector<ll> P(A), Q(B), R(C);
    REP(i, A) cin >> P[i];
    REP(i, B) cin >> Q[i];
    REP(i, C) cin >> R[i];

    sort(ALL(P), greater<ll>());
    sort(ALL(Q), greater<ll>());
    sort(ALL(R), greater<ll>());

    priority_queue<ll, vector<ll>, greater<ll>> P2, Q2;
    REP(i, X) P2.push(P[i]);
    REP(i, Y) Q2.push(Q[i]);

    REP(i, C){

        ll p = P2.top();
        ll q = Q2.top();

        if (R[i] > min(p, q)){
            if (p < q){
                P2.pop();
                P2.push(R[i]);
            } else {
                Q2.pop();
                Q2.push(R[i]);
            }
        }
    }

    ll ans = 0;
    REP(i, X){ ans += P2.top(); P2.pop();}
    REP(i, Y){ ans += Q2.top(); Q2.pop();}
    print(ans);


    return 0;
}
