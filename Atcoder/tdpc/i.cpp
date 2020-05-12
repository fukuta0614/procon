// tdpc_i 区間DP
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

string S;

int memo[301][301];

int rec(int l, int r){

    if (memo[l][r] != -1) return memo[l][r];

    if (r - l <= 1) return 0;

    // 全消しできる可能性がある
    if ((r - l) % 3 == 0)
    {
        if (S[l] == 'i' && S[l+1] == 'w' && S[r-1] == 'i' &&
            rec(l+2, r-1) == (r - l - 3) / 3 )
        {
            return memo[l][r] = (r - l) / 3;
        }

        if (S[l] == 'i' && S[r-2] == 'w' && S[r-1] == 'i' &&
            rec(l+1, r-2) == (r - l - 3) / 3 )
        {
            return memo[l][r] = (r - l) / 3;
        }
    }

    int res = 0;
    REPN(mid, l+1, r){
        res = max(res, rec(l, mid) + rec(mid, r));
    }

    return memo[l][r] = res;
}

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt");
    cin.rdbuf(in.rdbuf());
#endif

    cin >> S;
    memset(memo, -1, 301 * 301 * sizeof(int));
    int res = rec(0, S.size());

    print(res);

    return 0;
}


