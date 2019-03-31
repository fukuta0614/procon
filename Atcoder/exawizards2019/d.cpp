// exawizards2019_d
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
#define INF ((1 << 29)-1)
#define MOD (1000000007)

#define ALL(x) x.begin(), x.end()
#define COUT(x) cout << x << endl
#define COUT_2DARR(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }

struct PreMain {PreMain(){std::cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

int factorial[201];
void make_factorial() {
    factorial[0] = 1;
    REP(i, 200) factorial[i + 1] = (factorial[i] * (i + 1)) % MOD;
}


int N, X;
vector<bool> used;
vector<int> S;
int ans = 0;
void dfs(int x, int n){

    REP(i, N){
        if (!used[i]){
            const int res = x % S[i];
            if (res == 1){
                ans = (ans + factorial[n-1]) % MOD;
                continue;
            }
            if (n == 1){
                ans = (ans + res) % MOD;
                continue;
            }
            used[i] = true;
            dfs(res, n-1);
            used[i] = false;
        }
    }
}

int main() {
#ifdef LOCAL
    std::ifstream in("../arg.txt");
    std::cin.rdbuf(in.rdbuf());
#endif
    make_factorial();

    cin >> N >> X;

    S.assign(N, 0);
    REP(i, N) cin >> S[i];

    used.assign(N, false);
    dfs(X, N);

    COUT(ans);

    return 0;
}
