//
// Created by fukut on 2019/09/09.
//

/* ベクトル型 */
struct V {
    double x, y;
    V(double x=0, double y=0): x(x), y(y) {}
    V& operator+=(const V& v){ x += v.x; y+= v.y; return *this;}
    V operator+(const V& v) const{return V(*this) += v;}
    V& operator-=(const V& v){x -= v.x; y-= v.y; return *this;}
    V operator-(const V& v) const{return V(*this) -= v;}
    V& operator*=(double s){x *= s; y*=s; return *this;}
    V operator*(double s) const{return V(*this) *= s;}
    V& operator/=(double s){x /= s; y/=s; return *this;}
    V operator/(double s) const{return V(*this) /= s;}
    /* 内積 */
    double dot(const V& v) const {return x*v.x + y*v.y;}
    /* 外積 */
    double cross(const V& v) const {return x*v.y - v.x*y;}
    /*ノルムの二乗*/
    double norm2() const {return x*x + y*y;}
    /* ノルム */
    double norm() const {return sqrt(norm2());}
    /* 象限判定 */
    int ort() const {
        if(y > 0) return x>0 ? 1:2;
        else return x>0 ? 4:3;
    }
    bool operator<(const V& v) const{
        int o = ort(), vo = v.ort();
        if(o!=vo) return o<vo;
        return cross(v) > 0;
    }
    friend istream& operator>>(istream& i, V& v){
        i >> v.x >> v.y;
        return i;
    }
};
