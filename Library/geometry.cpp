//
// Created by fukut on 2019/09/09.
//

/* ベクトル型 */
struct Point {
    const double eps = 1e-9;
    double x, y;
    Point(double x=0, double y=0): x(x), y(y) {}
    Point& operator+=(const Point& v){ x += v.x; y+= v.y; return *this;}
    Point operator+(const Point& v) const{return Point(*this) += v;}
    Point& operator-=(const Point& v){x -= v.x; y-= v.y; return *this;}
    Point operator-(const Point& v) const{return Point(*this) -= v;}
    Point& operator*=(double s){x *= s; y*=s; return *this;}
    Point operator*(double s) const{return Point(*this) *= s;}
    Point& operator/=(double s){x /= s; y/=s; return *this;}
    Point operator/(double s) const{return Point(*this) /= s;}
    double dot(const Point& v) const {return x*v.x + y*v.y;}     /* 内積 */
    double cross(const Point& v) const {return x*v.y - v.x*y;}    /* 外積 */
    double norm2() const {return x*x + y*y;}    /*ノルムの二乗*/
    double norm() const {return sqrt(norm2());}    /* ノルム */
    int ort() const {    /* 象限判定 */
        if(y > 0) return x>0 ? 1:2;
        else return x>0 ? 4:3;
    }
    bool operator<(const Point& v) const{
        int o = ort(), vo = v.ort();
        if(o!=vo) return o<vo;
        return cross(v) > 0;
    }
    friend ostream& operator<<(ostream& os, const Point& v) {os<<"("<<v.x<<","<<v.y<<")"; return os;}
    friend istream& operator>>(istream& is, Point& v){ is >> v.x >> v.y; return is;}
};

// 円
struct Circle {
    Point c;
    double r;
    Circle(){}
    Circle(Point c, double r):c(c),r(r){}
};