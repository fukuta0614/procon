// aribon3-2-1_2_c
#include <bits/stdc++.h>
#ifdef LOCAL
#include "../cxx-prettyprint/prettyprint.hpp"
#endif
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;

#define REP(i, n) for (int (i) = 0 ; (i) < (int)(n) ; ++(i))
#define ITR(e, v) for (auto e: v)
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
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(5);}} premain;


#define _USE_MATH_DEFINES


struct Point{
    int x,y;
    Point(int x, int y): x(x), y(y){}
};

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    ll N;
    cin >> N;
    vector<Point> points;

    int x, y;
    REP(i, N){
        cin >> x >> y;
        points.emplace_back(x, y);
    }

    REP(i, N){
        points.emplace_back(points[i]);
    }

    ll ans_90 = 0;
    ll ans_obtuse = 0;

    REP(i, N){
        Point c = points[i];
        vector<double> angles;
        REP(j, N){
            if (i == j) continue;
            double angle = atan2(points[j].y - c.y, points[j].x - c.x);
            angles.emplace_back(angle);
        }

        sort(ALL(angles));
        REP(j, N-1) {
            angles.emplace_back(angles[j] + 2 * M_PI); // 2周分
        }

        REP(j, N-1) {
            double th = angles[j];

            ans_90 += upper_bound(ALL(angles), th + M_PI_2 + EPS) - lower_bound(ALL(angles), th + M_PI_2 - EPS);
            ans_obtuse += lower_bound(ALL(angles), th + M_PI - EPS) - upper_bound(ALL(angles), th + M_PI_2 + EPS);
        }
    }

    ll ans_acute = N * (N - 1) * (N - 2) / 6 - ans_90 - ans_obtuse;

    print(ans_acute, ans_90, ans_obtuse);


    return 0;
}
