// aribon3-6_e
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
    friend double calc_distance_between_segments(Point a, Point b, Point c, Point d) {
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
    ifstream in("../in.txt"); cin.rdbuf(in.rdbuf());
#endif

    while (true) {
        int N, M;
        cin >> N >> M;
        if (N == 0 && M == 0) break;

        vector<Point> dog_pos(N);
        vector<double> dog_speed(N);
        vector<Point> frisbee_pos(M);
        vector<Point> frisbee_V(M);

        REP(i, N) cin >> dog_pos[i] >> dog_speed[i];
        REP(i, M) cin >> frisbee_pos[i] >> frisbee_V[i];

        vector<int> dog_score(N);
        REP(fid, M) {

            vector<Point> dog_V(N);
            double min_t = numeric_limits<double>::max();
            int min_did = 0;
            REP(did, N) {

                double r_2 = (dog_pos[did] - frisbee_pos[fid]).norm2();
                double y_2 = calc_distance_between_point_and_line(frisbee_pos[fid], frisbee_pos[fid]+frisbee_V[fid], dog_pos[did]);
                double x_2 = r_2 - y_2;
                double x = sqrt(x_2);

                double Vf_2 = frisbee_V[fid].norm2();
                double Vf = sqrt(Vf_2);
                double Vd_2 = dog_speed[did] * dog_speed[did];

                double a = Vf_2 - Vd_2;
                double b = - 2 * Vf * x;
                double c = r_2;

                double t;
                if (a == 0) {
                    t = - c / b;
                } else {
                    double D = sqrt(b * b - 4 * a * c);
                    double t1 = (-b - D) / (2 * a);
                    double t2 = (-b + D) / (2 * a);
                    t = min(t1, t2) > Point::eps ? min(t1, t2) : max(t1, t2);
                }

                if (t < min_t) {
                    min_t = t;
                    min_did = did;
                }

                Point intersection = frisbee_pos[fid] + frisbee_V[fid] * t;
                dog_V[did] = (intersection - dog_pos[did]) / t;
            }

            dog_score[min_did]++;

            REP(did, N){
                dog_pos[did] += dog_V[did] * min_t;
            }
        }

        REP(did, N-1) {
            cout << dog_score[did] << " ";
        }
        print(dog_score[N-1]);

    }


    return 0;
}
