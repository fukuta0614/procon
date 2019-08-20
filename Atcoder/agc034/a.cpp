// agc034_a
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

    int N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;
    A--; B--; C--; D--;

    string S;
    cin >> S;

    REPN(i, A, C){
        if (S[i] == '#' && S[i+1] == '#') {
            print("No");
            return 0;
        }
    }

    REPN(i, B, D){
        if (S[i] == '#' && S[i+1] == '#') {
            print("No");
            return 0;
        }
    }

    if (C < D) {
        print("Yes");
        return 0;
    }

    REPN(i, B, D+1){
        if (S[i-1] == '.' && S[i] == '.' && S[i+1] == '.') {
            print("Yes");
            return 0;
        }
    }

    print("No");

    return 0;
}
