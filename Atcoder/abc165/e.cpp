// abc165_e
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

    int N, M;
    cin >> N >> M;

    if (N % 2 == 0) N--;

    vector<P> ans;

    int odd = ((N/2 + 1) / 2) * 2 - 1; // 奇->そのまま、遇->遇-1
    int idx = 1;
    for (int i = odd; i >= 1; i -= 2) {
        ans.emplace_back(idx, idx + i);
        idx++;
    }

    int even = ((N/2) / 2) * 2; // 奇->奇-1、遇->そのまま
    idx = odd + 2;
    for (int i = even; i >= 2; i -= 2) {
        ans.emplace_back(idx, idx + i);
        idx++;
    }

    REP(i, M){
        print(ans[i].first, ans[i].second);
    }

    return 0;
}
