// tdpc_k

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

#define MOD (1000000007)
#define INF (MOD)

#define print2D(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }
template<class T> void print(const T& x){cout << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt");
    cin.rdbuf(in.rdbuf());
#endif

    // x - r を大きい順に見ていくと（降順）、
    // x + r が前のより大きければ円内部になる
    int N;
    cin >> N;
    vector<P> C(N);
    int x, r;
    REP(i, N) {
        cin >> x >> r;
        C[i].first = - (x - r); // 昇順なので負にする
        C[i].second = - (x + r); // 左側が一致してる場合は円内部にできないので、予めそうならないようにソート
    }
    sort(ALL(C));

    vector<int> lis;
    REP(i, N){
        const int right = - C[i].second;
        auto it = lower_bound(ALL(lis), right);
        if (it == lis.end()){
            lis.emplace_back(right);
        } else {
            *it = right;
        }
    }

    int ans = lis.size();
    print(ans);

    return 0;
}


