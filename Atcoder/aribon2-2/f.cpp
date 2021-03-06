// aribon2-2_f
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

int main() {
#ifdef LOCAL
    std::ifstream in("../arg.txt");
    std::cin.rdbuf(in.rdbuf());
#endif

    ull N;
    cin >> N;
    vector<P> boxes(N);
    REP(i, N){cin >> boxes[i].first >> boxes[i].second;}
    sort(ALL(boxes), [](const P& x, const P& y) {
        return x.first != y.first ? x.first < y.first : x.second > y.second;
    });

    vector<int> lis(N+1, INF);
    REP(i, N){
        auto it = lower_bound(ALL(lis), boxes[i].second);
        (*it) = boxes[i].second;
    }

    REP(i, N+1) {
        if (lis[i] == INF) { COUT(i); return 0;}
    }

    return 0;
}
