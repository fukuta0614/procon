// aribon3-6_d
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
    constexpr static double eps = 1e-9;
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

    // 点a, b, cからなる三角形の面積
    friend double calc_triangle_area(Point a, Point b, Point c) {
        Point v1 = b - a;
        Point v2 = c - a;
        return abs(v1.cross(v2)) / 2;
    }

    // 点a, bを通る直線と点cとの距離
    friend double calc_distance_between_point_and_line(Point a, Point b, Point c) {
        return abs((b-a).cross(c-a)) / (b-a).norm();
    }

    // 点a, bを端点とする線分と点cとの距離
    friend double calc_distance_between_point_and_segment(Point a, Point b, Point c) {
        if ((b-a).dot(c-a) < eps) return (c-a).norm();
        if ((a-b).dot(c-b) < eps) return (c-b).norm();
        return calc_distance_between_point_and_line(a, b, c);
    }

    // 点a, bを端点とする線分と点cと点dを端点とする線分の距離
    friend double calc_distance_between_segment_and_segment(Point a, Point b, Point c, Point d) {
        double d0 = calc_distance_between_point_and_segment(a, b, c);
        double d1 = calc_distance_between_point_and_segment(a, b, d);
        double d2 = calc_distance_between_point_and_segment(c, d, a);
        double d3 = calc_distance_between_point_and_segment(c, d, b);
        return min(min(d0, d1), min(d2, d3));
    }

    enum RELATION_BETWEEN_SEGMENT_AND_POINT {
        COUNTER_CLOCKWISE = 1,     // p1とp2のp0を挟んだ位置関係が反時計回り
        CLOCKWISE = -1,            // 時計回り
        ONLINE_BACK = 2,           // p1とp2がp0を挟んで直線状にある
        ONLINE_FRONT = -2,         // p0とp2の間にp1がある
        ON_SEGMENT = 0,            // p0とp1の間にp2がある
    };

    // 点cが点a, bを端点とする線分のどちら側にあるか、enumで返す
    friend RELATION_BETWEEN_SEGMENT_AND_POINT ccw_ex(Point p0, Point p1, Point p2) {
        Point v1 = p1 - p0;
        Point v2 = p2 - p0;
        if(v1.cross(v2) > eps) return COUNTER_CLOCKWISE;    // 1
        if(v1.cross(v2) < -eps) return CLOCKWISE;           // -1
        if(v1.dot(v2) < -eps) return ONLINE_BACK;           // 2
        if(v1.norm() < v2.norm()) return ONLINE_FRONT;      // -2
        return ON_SEGMENT;                                  // 0
    }

    // 点cが点a, bを端点とする線分のどちら側にあるか
    friend int ccw(Point p0, Point p1, Point p2) {
        Point v1 = p1 - p0;
        Point v2 = p2 - p0;
        if(v1.cross(v2) > eps) return 1;
        if(v1.cross(v2) < -eps) return -1;
        return 0;
    }

    // p1,p2を端点とする線分Aとp3,p4を端点とする線分Bの交差判定
    // include_end=trueなら端点が重なっていても交差しているとみなす
    friend bool intersect(Point p1, Point p2, Point p3, Point p4, bool include_end=true) {

        bool is_otherside;
        bool is_inside;

        if (include_end){
            is_otherside = ccw(p1,p2,p3) * ccw(p1,p2,p4) <= 0; // Aの両側にBの端点があるかどうか。どちらかがAの直線状にいてもOK
            is_inside = ccw(p3,p4,p1) * ccw(p3,p4,p2) <= 0;    // Aの端点の内側にBがいるかどうか。
        } else {
            is_otherside = ccw(p1,p2,p3) * ccw(p1,p2,p4) < 0; // Aの両側にBの端点があるかどうか
            is_inside = ccw(p3,p4,p1) * ccw(p3,p4,p2) < 0;    // Aの端点の内側にBがいるかどうか
        }
        return is_otherside && is_inside;
    }

};

// 円
struct Circle {
    Point c;
    double r;
    Circle(){}
    Circle(Point c, double r):c(c),r(r){}
};


int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N1; cin >> N1;
    vector<Point> polyline1(N1+2);
    polyline1[0] = Point(0, 0);
    REPN(i, 1, N1+1) cin >> polyline1[i];
    polyline1[N1+1] = Point(1000, 0);

    int N2; cin >> N2;
    vector<Point> polyline2(N2+2);
    polyline2[0] = Point(0, 1000);
    REPN(i, 1, N2+1) cin >> polyline2[i];
    polyline2[N2+1] = Point(1000, 1000);

    double ans = numeric_limits<double>::max();
    REP(i, N1+1) REP(j, N2+1){
        double d = calc_distance_between_segment_and_segment(polyline1[i],polyline1[i+1],polyline2[j],polyline2[j+1]);
        ans = min(ans, d);
    }
    print(ans);

    return 0;
}
