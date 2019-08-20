// abc134_d
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
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N;
    cin >> N;
    vector<int> A(N+1);
    REPN(i, 1, N+1) cin >> A[i];

    vector<int> x(N+1);
    REPN_REV(n, 1, N+1){

        int tmp = 0;
        for (int i=2*n; i <= N; i+=n){
            tmp = (tmp + x[i]) % 2;
        }
        x[n] = A[n] ^ tmp;
    }

    vector<int> ans;
    REPN(i, 1, N+1){
        if (x[i]) {
            ans.emplace_back(i);
        }
    }

    int m = ans.size();
    print(m);
    if (m == 0) return 0;

    REP(i, m-1){
        cout << ans[i] << " ";
    }
    cout << ans[m-1] << endl;


    return 0;
}
