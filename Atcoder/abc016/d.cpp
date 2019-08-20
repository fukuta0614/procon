#include <bits/stdc++.h>
#ifdef LOCAL
#include "../cxx-prettyprint/prettyprint.hpp"
#endif
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;

#define REP(i, n) for (int (i) = 0 ; (i) < (int)(n) ; ++(i))

template<class T> void print(const T& x){cout << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

struct Vec {
    int x; int y;
    Vec() {}
    Vec(int x, int y) : x(x), y(y) {}
    Vec operator - (const Vec& v) const { return Vec(x - v.x, y - v.y); }
    ll outer(const Vec& v) const { return x * v.y - y * v.x; }
    int inner(const Vec& v) const { return x * v.x + y * v.y; }
};

ostream& operator <<(ostream& os, Vec p) { return os << "(" << p.x << ", " << p.y << ")"; }

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int x, y, N;
    cin >> x >> y; Vec A = Vec(x, y);
    cin >> x >> y; Vec B = Vec(x, y);
    Vec AB = B - A;

    cin >> N;
    vector<Vec> points(N);
    REP(i, N) cin >> points[i].x >> points[i].y;
    points.emplace_back(points[0]);

    int intersection = 0;
    REP(i, N){

        Vec AP = points[i] - A;
        Vec AQ = points[i+1] - A;
        Vec BP = points[i] - B;
        Vec BQ = points[i+1] - B;

        if (AB.outer(AP) * AB.outer(AQ) < 0 && AP.outer(AQ) * BP.outer(BQ) < 0) {
            intersection++;
        }
    }

    int ans = intersection / 2 + 1;
    print(ans);

    return 0;
}
