// agc039_a
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

    string S;
    cin >> S;
    ll K;
    cin >> K;
    ll n = S.size();

    ll ans = 0;
    if (S[0] == S[n-1]){

        ll tmp1=1, tmp2=1;
        {
            int i = 0;
            while(i < n-1 && S[i] == S[i+1]){
                tmp1++;
                i++;
            }

            if (i == n - 1) {
                print((n * K) / 2);
                return 0;
            }

            i = n-1;
            while(i > 0 && S[i] == S[i-1]){
                tmp2++;
                i--;
            }

            ans += ((tmp1 + tmp2) / 2) * (K-1);
            ans += tmp1 / 2;
            ans += tmp2 / 2;
        }

        REPN(i, tmp1, n-tmp2){
            if (S[i] == S[i+1]){
                ll tmp = 1;
                while(S[i] == S[i+1] && i < n){
                    tmp++;
                    i++;
                }
                ans += (tmp / 2) * K;
            }
        }

    } else {
        REP(i, n){
            if (S[i] == S[i+1]){
                ll tmp = 1;
                while(S[i] == S[i+1] && i < n){
                    tmp++;
                    i++;
                }
                ans += (tmp / 2) * K;
            }
        }
    }

    print(ans);

    return 0;
}
