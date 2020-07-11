// heuristics01_b
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
#define print_line(vec, n) {for(int i=0;i<(n-1);i++) cout << (vec)[i] << " "; cout << (vec)[(n)-1] << endl;}
template<class T> void print(const T& x){cout << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

ll eval_func(int D, vector<ll>& C, vector<vector<ll>>& S, vector<int>& T){

    ll score = 0;
    vector<int> last(26, 0);
    REP(i, D){
        int x = T[i];
        score += S[i][x];
        last[x] = i+1;

        REP(j, 26){
            score -= C[j] * (i+1 - last[j]);
        }
        print(score);
    }
    return score;
}

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int D;
    cin >> D;
    vector<ll> C(26);
    REP(i, 26) cin >> C[i];
    vector<vector<ll>> S(D, vector<ll>(26, 0));
    REP(i, D) REP(j, 26) cin >> S[i][j];

    vector<int> T(D);
    REP(i, D) {cin >> T[i]; T[i]--;}

    ll score = eval_func(D, C, S, T);
//    print(score);


    return 0;
}
