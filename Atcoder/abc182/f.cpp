// abc182_f
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
#define print_line(vec, n) {for(int idx=0;idx<(n-1);idx++) cout << (vec)[idx] << " "; cout << (vec)[(n)-1] << endl;}
template<class T> void print(const T& x){cout << x << "\n";}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    ll N, X;
    cin >> N >> X;
    vector<ll> A(N);
    REP(i, N) cin >> A[i];

    vector<ll> B(N-1);
    REP(i, N-1){
        B[i] = A[i+1] / A[i];
    }

    vector<map<ll, ll>> dp(N, map<ll, ll>());
    REP_REV(i, N){

        ll res = X % A[i];

        if (i == N-1){
            dp[i][res] += 1;
            dp[i][res - A[i]] += 1;
        } else {
            for (auto [d, cnt]: dp[i+1]) {
                if (abs(d - res) % A[i] == 0 && (abs(d - res) / A[i]) < B[i]) {
                    dp[i][res] += cnt;
                }
                if (res == 0) continue;

                if (abs(d - res + A[i]) % A[i] == 0 && (abs(d - res + A[i]) / A[i]) < B[i]) {
                    dp[i][res - A[i]] += cnt;
                }
            }
        }
//        print(dp[i]);
    }

    ll ans = dp[0][0];

    print(ans);

//    vector<int> ans2;
//    REPN(y, X, X+A.back()+1){
//
//        bool valid = true;
//        ll yy = y;
//        vector<int> C(N);
//        REP_REV(i, N){
//            C[i] = yy / A[i];
//            yy %= A[i];
//        }
//
//        yy = y - X;
//        REP_REV(i, N){
//            if (C[i] > 0 && yy / A[i]){
//                valid = false;
//                break;
//            }
//            yy %= A[i];
//        }
//
//        if (valid){
//            ans2.emplace_back(y);
//        }
//
//    }
//
//    print(ans2.size());
//    print(ans2);

    return 0;
}
