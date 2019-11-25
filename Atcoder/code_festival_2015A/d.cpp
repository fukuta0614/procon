// code_festival_2015A_d
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

#define MOD (1000000007)

#define print2D(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }
#define print_line(vec, n) {for(int i=0;i<(n-1);i++) cout << (vec)[i] << " "; cout << (vec)[(n)-1] << endl;}
template<class T> void print(const T& x){cout << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

ll N, M;
vector<ll> X;


bool subproblem(ll x){

    ll p = 1;
    REP(i, M){
        if (X[i] - p > x){
            return false;
        }

        ll tmp1 = x - 2*(X[i] - p);
        ll tmp2 = (x - (X[i] - p)) / 2;
        ll tmp = max(0ll, max(tmp1, tmp2));

//        print(i, p, X[i], tmp1, tmp2);

        if (i == M-1){
            return X[i] + tmp >= N;
        } else {
            p = min(X[i+1], X[i] + tmp + 1);
        }
    }

    return false;
}


int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    cin >> N >> M;
    X.resize(M);
    REP(i, M) cin >> X[i];

    ll ng = -1;
    ll ok = 1ll << 40;
    while (ok - ng > 1){
        ll x = (ok + ng) / 2;
        if (subproblem(x)){
            ok = x;
        } else {
            ng = x;
        }
    }

    print(ok);

//    print(subproblem(8));


    return 0;
}
