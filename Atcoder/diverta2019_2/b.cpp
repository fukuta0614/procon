// diverta2019_2_b
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

    vector<P> points(N);
    REP(i, N) cin >> points[i].first >> points[i].second;
    sort(ALL(points));

    int ans = INF;
    REP(i, N) REP(j, N){

        int p = points[j].first - points[i].first;
        int q = points[j].second - points[i].second;

        vector<bool> used(N, false);

        int count = 0;
        REP(k, N){
            if (used[k]) continue;
            count++;

            int a = points[k].first;
            int b = points[k].second;
            used[k] = true;

            REP(l, N){
                if (points[l].first == a + p && points[l].second == b + q) {
                    used[l] = true;
                    a += p;
                    b += q;
                }
            }
        }
        ans = min(ans, count);
    }

    print(ans);

    return 0;
}
