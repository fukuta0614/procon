// aribon3-6_a
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


// ベクトル
struct Point {
    const double eps = 1e-9;
    double x, y;
    explicit Point(double x=0, double y=0): x(x), y(y) {}
    Point& operator+=(const Point& v){ x += v.x; y+= v.y; return *this;}
    Point operator+(const Point& v) const{return Point(*this) += v;}
    Point& operator-=(const Point& v){x -= v.x; y-= v.y; return *this;}
    Point operator-(const Point& v) const{return Point(*this) -= v;}
    Point& operator*=(double s){x *= s; y *= s; return *this;}
    Point operator*(double s) const{return Point(*this) *= s;}
    Point& operator/=(double s){x /= s; y /= s; return *this;}
    Point operator/(double s) const{return Point(*this) /= s;}
    double dot(const Point& v) const {return x*v.x + y*v.y;}        /* 内積 */
    double cross(const Point& v) const {return x*v.y - v.x*y;}      /* 外積 */
    double norm2() const {return x*x + y*y;}                        /* ノルムの二乗*/
    double norm() const {return sqrt(norm2());}                     /* ノルム */
    int quadrant() const { if(y > 0) return x>0 ? 1:2; else return x>0 ? 4:3;} /* 象限判定 */

    friend ostream& operator<<(ostream& os, const Point& v) {os<<"("<<v.x<<","<<v.y<<")"; return os;}
    friend istream& operator>>(istream& is, Point& v){ is >> v.x >> v.y; return is;}

    friend double calc_triangle_area(Point a, Point b, Point c) {
        Point v1 = b - a;
        Point v2 = c - a;
        return abs(v1.cross(v2)) / 2;
    }
};

using V = Point;
using Polygon = vector<Point>;

// 円
struct Circle {
    Point c;
    double r;
    Circle(){}
    Circle(Point c, double r):c(c),r(r){}
};

// 線分
struct Segment {
    Point p1,p2;
    Segment(){}
    Segment(Point p1, Point p2):p1(p1),p2(p2){}
};


int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    Point a, b, c;
    cin >> a >> b >> c;
    double area = calc_triangle_area(a, b, c);
    print(area);

    return 0;
}
