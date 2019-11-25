// abc145_c
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
ostream& operator<<(ostream& os, const Point& v) {os<<"("<<v.x<<","<<v.y<<")"; return os;}
istream& operator>>(istream& is, Point& v){ is >> v.x >> v.y; return is;}


int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N;
    cin >> N;
    vector<Point> points(N);
    REP(i, N){
        cin >> points[i];
    }

    vector<int> factorial(N+1);
    factorial[0] = 1;
    for (int i = 1; i <= N; ++i) { factorial[i] = factorial[i-1] * i;}

    double ans = 0;
    REP(i, N) REPN(j, i+1, N){
        ans += (points[i] - points[j]).norm();
    }
    ans = ans * 2 * (N - 1) * factorial[N-2] / factorial[N];
    print(ans);


    return 0;
}
