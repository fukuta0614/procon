// abc056_d
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

    int N, K;
    cin >> N >> K;
    vector<ll> A(N);
    REP(i, N) cin >> A[i];
    sort(ALL(A));

    auto check = [&](int x){

        vector<bool> dp(K);

        dp[0] = true;
        REP(i, N){
            if (i == x) continue;
            REP_REV(j, K-A[i]){
                dp[j + A[i]] = dp[j + A[i]] | dp[j];
            }
//            print(x, A[x], i, A[i], dp);

        }

        bool noneed = true;
        REPN(j, 1, A[x]+1){
            if (dp[K - j]){
                noneed = false;
                break;
            }
        }
        return noneed;
    };

    int inf = -1;
    int sup = N;
    while (sup - inf > 1){
        int x = (sup + inf) / 2;
        if (check(x)){
            inf = x;
        } else {
            sup = x;
        }
    }

    print(inf+1);


    return 0;
}
