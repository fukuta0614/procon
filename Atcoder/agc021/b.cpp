// agc021_b
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


// 幾何ライブラリ
namespace Geom {
#define _USE_MATH_DEFINES

    const double eps = 1e-9;

    struct Point {
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
        Point rot(double theta) {return Point(cos(theta) * x - sin(theta) * y, sin(theta) * x + cos(theta) * y);} // 回転
        Point rot90() {return Point(-y, x);} // 90度回転
    };

    // 比較関数はとりあえずyの昇順
    bool operator<(const Point& a, const Point& b) { return a.y!=b.y ? a.y<b.y : a.x<b.x; }

    ostream& operator<<(ostream& os, const Point& v) {os<<"("<<v.x<<","<<v.y<<")"; return os;}
    istream& operator>>(istream& is, Point& v){ is >> v.x >> v.y; return is;}

    // 点a, b, cからなる三角形の面積
    double calc_triangle_area(Point a, Point b, Point c) {
        Point v1 = b - a;
        Point v2 = c - a;
        return abs(v1.cross(v2)) / 2;
    }

    // 点a, bを通る直線と点cとの距離
    double calc_distance_between_point_and_line(Point a, Point b, Point c) {
        return abs((b-a).cross(c-a)) / (b-a).norm();
    }

    // 点a, bを端点とする線分と点cとの距離
    double calc_distance_between_point_and_segment(Point a, Point b, Point c) {
        if ((b-a).dot(c-a) < eps) return (c-a).norm();
        if ((a-b).dot(c-b) < eps) return (c-b).norm();
        return calc_distance_between_point_and_line(a, b, c);
    }

    // 点a, bを端点とする線分と点cと点dを端点とする線分の距離
    double calc_distance_between_segments(Point a, Point b, Point c, Point d) {
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
    RELATION_BETWEEN_SEGMENT_AND_POINT ccw_ex(Point p0, Point p1, Point p2) {
        Point v1 = p1 - p0;
        Point v2 = p2 - p0;
        if(v1.cross(v2) > eps) return COUNTER_CLOCKWISE;    // 1
        if(v1.cross(v2) < -eps) return CLOCKWISE;           // -1
        if(v1.dot(v2) < -eps) return ONLINE_BACK;           // 2
        if(v1.norm() < v2.norm()) return ONLINE_FRONT;      // -2
        return ON_SEGMENT;                                  // 0
    }

    // 点cが点a, bを端点とする線分のどちら側にあるか
    int ccw(Point p0, Point p1, Point p2) {
        Point v1 = p1 - p0;
        Point v2 = p2 - p0;
        if(v1.cross(v2) > eps) return 1;
        if(v1.cross(v2) < -eps) return -1;
        return 0;
    }

    // p1,p2を端点とする線分Aとp3,p4を端点とする線分Bの交差判定
    // include_end=trueなら端点が重なっていても交差しているとみなす
    bool intersect(Point p1, Point p2, Point p3, Point p4, bool include_end=true) {

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

    // 凸包
    vector<Point> convex_hull(vector<Point> ps) {
        int n = ps.size(), k = 0;
        sort(ps.begin(), ps.end(),
             [](const Point& a, const Point& b){return a.y!=b.y?a.y<b.y:a.x<b.x;}
        );
        vector<Point> ch(2*n);
        for (int i = 0; i < n; ch[k++] = ps[i++]){  // lower-hull
            while (k >= 2 && ccw(ch[k-2], ch[k-1], ps[i]) <= 0) --k;
        }
        for (int i = n-2, t = k+1; i >= 0; ch[k++] = ps[i--]) { // upper-hull
            while (k >= t && ccw(ch[k-2], ch[k-1], ps[i]) <= 0) --k;
        }
        ch.resize(k-1);
        return ch;
    }

    // 円
    struct Circle {
        Point c;
        double r;
        Circle(){}
        Circle(Point c, double r):c(c),r(r){}

        // 円が点pを含むかどうか　include_circumは円周上を含むとするかどうか
        bool does_include_point(Point p, bool include_circum = true){
            double d = (p - c).norm();
            if (include_circum){
                return d < r + eps;
            } else {
                return d < r - eps;
            }
        }
    };
    ostream& operator<<(ostream& os, const Circle& c) {os<<"("<<c.c<<","<<c.r<<")"; return os;}
    istream& operator>>(istream& is, Circle& c){ is >> c.c >> c.r; return is;}

    // 点p1, p2を通る半径rの円を返す
    vector<Circle> calc_circle_on_two_points(Point p1, Point p2, double r){

        Point p12_half = (p2 - p1) / 2.0;

        double n_vec_norm2 = r*r - p12_half.norm2();
        if (n_vec_norm2 < 0) return vector<Circle>();

        double n_vec_norm = sqrt(n_vec_norm2);
        Point n_vec = p12_half.rot90() * n_vec_norm / p12_half.norm();

        vector<Circle> ret;
        ret.emplace_back(p1 + p12_half + n_vec, 1.0);
        ret.emplace_back(p1 + p12_half - n_vec, 1.0);
        return ret;
    }

    // 点pを通る、円Cの２つの接線の傾きの角度を返す [0, 2π]で返す
    pair<double, double> calc_tangent_line_on_circle(Circle c, Point p){
        Point pc = c.c - p;
        double angle0 = atan2(pc.y, pc.x);
        double l2 = pc.norm2() - c.r*c.r;
        if (l2 < 0) {
            return {0, 2*M_PI};
        }
        double l = sqrt(l2);
        double angle1 = angle0 - atan2(c.r, l);
        double angle2 = angle0 + atan2(c.r, l);
        angle1 = angle1 >= 0 ? angle1 : angle1 + 2*M_PI;
        angle2 = angle2 >= 0 ? angle2 : angle2 + 2*M_PI;

        return {angle1, angle2};
    }

    // 反時計回り方向の角度 (rad) の差 (angle2 - angle1)
    double calc_ccw_angle_diff(double angle1, double angle2) {
        double diff = angle2 - angle1;
        if (diff < 0) diff += 2 * M_PI;
        return diff;
    }

}

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    using namespace Geom;

    int N;
    cin >> N;
    vector<Point> ps(N);
    REP(i, N) cin >> ps[i];

    auto ch = convex_hull(ps);
    int n = ch.size();
    ch.emplace_back(ch[0]);

    vector<double> n_vec_angle(n);
    REP(i, n){
        Point n_vec = (ch[i+1] - ch[i]).rot90() * -1;
        double angle = atan2(n_vec.y, n_vec.x);
        n_vec_angle[i] =  angle >= 0 ? angle : angle + 2*M_PI;
    }
//    print(ch);
//    print(n_vec_angle);

    map<Point, double> ans_map;
    REP(i, n){
        double range;
        if (i == 0){
            range = calc_ccw_angle_diff(n_vec_angle[n-1], n_vec_angle[0]);
        } else{
            range = calc_ccw_angle_diff(n_vec_angle[i-1], n_vec_angle[i]);
        }

        ans_map[ch[i]] = range / M_PI / 2;
    }

//    print(ans_map);

    REP(i, N){
        print(ans_map[ps[i]]);
    }

    return 0;
}
