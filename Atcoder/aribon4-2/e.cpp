// aribon4-2_e
// yukicoder No.153 石の山
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


vector<int> grundy;

int rec(int n){

    if (grundy[n] != -1) return grundy[n];

    set<int> s;

    int g;
    if (n % 2 == 0){
        g = 0;
    } else {
        g = rec(n/2) ^ rec(n/2 + 1);
    }
    s.insert(g);

    int g2;
    if (n % 3 == 0){
        g2 = rec(n/3);
    } else if (n % 3 == 1){
        g2 = rec(n/3 + 1);
    } else {
        g2 = rec(n/3);
    }
    s.insert(g2);

    int res = 0;
    while(s.count(res)) res++;
    return grundy[n] = res;
}

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N;
    cin >> N;

    grundy.assign(N+1, -1);

    grundy[0] = 0;
    grundy[1] = 0;

    if (rec(N) == 0) {
        print("B");
    } else {
        print("A");
    }


    return 0;
}
