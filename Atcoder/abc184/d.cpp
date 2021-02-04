// abc184_d
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


unordered_map<int, double> memo;

int func(int a, int b, int c){
    return 40000 * a + 200 * b + c;
}

double rec(int a, int b, int c){

    int h = func(a, b, c);
    if (memo.find(h) != memo.end()) return memo[h];

    if (a == 100 || b == 100 || c == 100){
        return memo[h] = 0;
    }

    double ret = 1;
    ret += rec(a+1, b, c) * a / (a + b + c);
    ret += rec(a, b+1, c) * b / (a + b + c);
    ret += rec(a, b, c+1) * c / (a + b + c);
    return memo[h] = ret;
}

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int A, B, C;
    cin >> A >> B >> C;

    double ans = rec(A,B,C);
    print(ans);

    return 0;
}
