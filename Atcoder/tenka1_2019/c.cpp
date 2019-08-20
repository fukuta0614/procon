// tenka1_2019_c
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
    string S;
    cin >> S;
    vector<int> stone(N), cumsum0(N+1,0), cumsum1(N+1,0);
    REP(i, N) {
        stone[i] = (S[i] == '#' ? 1 : 0);
        cumsum0[i+1] = cumsum0[i] + (S[i] == '#' ? 0 : 1);
        cumsum1[i+1] = cumsum1[i] + (S[i] == '#' ? 1 : 0);
    }

    int ans = INF;
    REP(i, N){
        ans = min(ans, cumsum1[i] + cumsum0[N] - cumsum0[i]);
    }

    ans = min(ans, cumsum0[N]);
    ans = min(ans, cumsum1[N]);

    print(ans);

    return 0;
}
