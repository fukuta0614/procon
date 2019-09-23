// abc138_f
#define _USE_MATH_DEFINES
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
#define EPS (1e-9)

#define print2D(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }
template<class T> void print(const T& x){cout << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    struct Vec {
        int x, y;
        double angle;
        bool operator<(const Vec& v){ return angle < v.angle;}
        bool operator<(const double& angle_){ return angle < angle_;}
    };

    int N;
    cin >> N;
    vector<Vec> vecs(N);
    REP(i, N) {
        cin >> vecs[i].x >> vecs[i].y;
        vecs[i].angle = atan2(vecs[i].y, vecs[i].x);
        if (vecs[i].angle < 0) vecs[i].angle += 2 * M_PI;

//        if (vecs[i].x == 0 && vecs[i].y == )

    }
    sort(ALL(vecs));

    REP(i, N) {
        auto tmp = vecs[i];
        tmp.angle += 2 * M_PI;
        vecs.emplace_back(tmp);
    }

    double ans = 0;
    REP(i, N) {
        double angle = vecs[i].angle;
        int j = lower_bound(ALL(vecs), angle + M_PI - EPS) - vecs.begin();

        double x = 0, y = 0;
        REPN(k, i, j) {
            x += vecs[k].x;
            y += vecs[k].y;
        }
        ans = max(ans, sqrt(x * x + y * y));

    }

    print(ans);

    return 0;
}
