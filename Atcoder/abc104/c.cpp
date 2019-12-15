// abc104_c
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
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(3);}} premain;


int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    ll D, G;
    cin >> D >> G;

    vector<ll> p(D), c(D);
    REP(i, D) cin >> p[i] >> c[i];

    int ans = INF;
    REP(pattern, 1 << D){

        int score = 0;
        int cnt = 0;
        REP(i, D){
            if ((pattern >> i)&1){
                score += (i+1)*100*p[i] + c[i];
                cnt += p[i];
            }
        }

        if (score >= G){
            ans = min(ans, cnt);
            continue;
        }

        REP_REV(i, D){
            if (((pattern >> i)&1) == 0){
                int n = (G - score + ((i+1)*100)-1) / ((i+1)*100);
                if (n <= p[i]){
                    cnt += n;
                    score += n * (i+1) * 100;
                } else {
                    score += p[i] * (i+1) * 100;
                }
                break;
            }
        }

        if (score >= G){
            ans = min(ans, cnt);
        }
    }

    print(ans);

    return 0;
}



