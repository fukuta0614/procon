//
// Created by fukut on 2019/09/19.
//


// p1とp2のp0を挟んだ位置関係が反時計回り
static const int COUNTER_CLOCKWISE = 1;
// 時計回り
static const int CLOCKWISE = -1;
// p1とp2がp0を挟んで直線状にある
static const int ONLINE_BACK = 2;
// p0とp2の間にp1がある
static const int ONLINE_FRONT = -2;
// p0とp1の間にp2がある
static const int ON_SEGMENT = 0;

//Intercsect Circle & Circle 共通接線の数
static const int ICC_SEPERATE = 4;
static const int ICC_CIRCUMSCRIBE = 3;
static const int ICC_INTERSECT = 2;
static const int ICC_INSCRIBE = 1;
static const int ICC_CONTAIN = 0;

// 点
struct Point {
    double x,y;
    Point(){}
    Point(double x, double y) : x(x),y(y){}
    Point operator+(Point p) {return Point(x+p.x, y+p.y);}
    Point operator-(Point p) {return Point(x-p.x, y-p.y);}
    Point operator*(double k){return Point(x*k,y*k);}
    Point operator/(double k){return Point(x/k,y/k);}
    double norm(){return x*x+y*y;}
    double abs(){sqrt(norm());}
    bool operator == (const Point &p) const {return equals(x,p.x)&&equals(y,p.y);}
    bool operator < (const Point &p) const {
        return x!=p.x?x<p.x:y<p.y;
        //grid-point only
        //return !equals(x,p.x)?x<p.x:!equals(y,p.y)?y<p.y:0;
    }
};

typedef Point P;
typedef vector<Point> Polygon;

double norm(P a){return a.x*a.x+a.y*a.y;}
double abs(P a){return sqrt(norm(a));}

// 線分
struct Segment {
    Point p1,p2;
    Segment(){}
    Segment(Point p1, Point p2):p1(p1),p2(p2){}
};

typedef Segment Line;

struct Circle {
    Point c;
    double r;
    Circle(){}
    Circle(Point c, double r):c(c),r(r){}
};

// 法線ベクトル
Point orth(Point p){return Point(-p.y,p.x);}

// 内積
double dot(Point a, Point b) {return a.x*b.x + a.y*b.y;}

// 外積
double cross(Point a, Point b) {return a.x*b.y-a.y*b.x;}
// 2直線の直行判定
bool is_orthogonal(Point a1, Point a2, Point b1, Point b2) {
    return equals(dot(a1-a2, b1-b2), 0.0);
}
// 2直線の平行判定
bool is_parallel(Point a1, Point a2, Point b1, Point b2) {
    return equals(cross(a1-a2, b1-b2), 0.0);
}
// 点cが直線ab上にあるかないか
bool is_point_on_INF_line(Point a, Point b, Point c) {
    return equals(cross(b-a,c-a), 0.0);
}
// 点cが線分ab上にあるかないか
bool is_point_on_LIMITED_line(Point a, Point b, Point c) {
    return (Point(a-c).abs()+Point(c-b).abs() < Point(a-b).abs() + EPS);
}
// 直線と点の距離
double distance_l_p(Point a, Point b, Point c) {return abs(cross(b-a, c-a)) / (b-a).abs();}

// 点a,bを端点とする線分と点cとの距離
double distance_ls_p(Point a, Point b, Point c) {
    if (dot(b-a, c-a) < EPS) return (c-a).abs();
    if (dot(a-b, c-b) < EPS) return (c-b).abs();
    return abs(cross(b-a, c-a)) / (b-a).abs();
}

// 射影
Point project(Segment s, Point p) {
    Point base = s.p2-s.p1;
    double r = dot(p-s.p1,base)/norm(base);
    return s.p1+base*r;
}

// 点が線分のどちら側にあるかを計算
int ccw(Point p0,Point p1,Point p2) {
    P a = p1-p0;
    P b = p2-p0;
    if(cross(a,b) > EPS) return COUNTER_CLOCKWISE;
    if(cross(a,b) < -EPS) return CLOCKWISE;
    if(dot(a,b) < -EPS) return ONLINE_BACK;
    if(a.norm()<b.norm()) return ONLINE_FRONT;
    return ON_SEGMENT;
}

// a1,a2を端点とする線分とb1,b2を端点とする線分の交差判定
bool intersectSS(Point p1, Point p2, Point p3, Point p4) {
    return (ccw(p1,p2,p3)*ccw(p1,p2,p4) <= 0&&ccw(p3,p4,p1)*ccw(p3,p4,p2) <= 0 );
}

// a1,a2を端点とする線分とb1,b2を端点とする線分の交差判定
bool intersectSS(Segment s1, Segment s2) {
    return intersectSS(s1.p1,s1.p2,s2.p1,s2.p2);
}

// 多角形と線分の交差判定
bool intersectPS(Polygon p,Segment l){
    int n=p.size();
    for(int i=0;i<n;i++)
        if(intersectSS(Segment(p[i],p[(i+1)%n]),l)) return 1;
    return 0;
}

// 円と円の交差判定
int intersectCC(Circle c1,Circle c2){
    if(c1.r<c2.r) swap(c1,c2);
    double d=abs(c1.c-c2.c);
    double r=c1.r+c2.r;
    if(equals(d,r)) return ICC_CIRCUMSCRIBE;
    if(d>r) return ICC_SEPERATE;
    if(equals(d+c2.r,c1.r)) return ICC_INSCRIBE;
    if(d+c2.r<c1.r) return ICC_CONTAIN;
    return ICC_INTERSECT;
}
// 直線と点の距離
double getDistanceLP(Line l, Point p) {
    return abs(cross(l.p2-l.p1,p-l.p1)/abs(l.p2-l.p1));
}

// 線分と点の距離
double getDistanceSP(Segment s,Point p){
    if(dot(s.p2-s.p1,p-s.p1) < 0.0 ) return abs(p-s.p1);
    if(dot(s.p1-s.p2,p-s.p2) < 0.0 ) return abs(p-s.p2);
    return getDistanceLP(s,p);
}

// 線分と円の交差判定
bool intersectSC(Segment s,Circle c){
    return getDistanceSP(s,c.c)<=c.r;
}

//
int intersectCS(Circle c,Segment s){
    if(norm(project(s,c.c)-c.c)-c.r*c.r>EPS) return 0;
    double d1=abs(c.c-s.p1),d2=abs(c.c-s.p2);
    if(d1<c.r+EPS&&d2<c.r+EPS) return 0;
    if((d1<c.r-EPS&&d2>c.r+EPS)||(d1>c.r+EPS&&d2<c.r-EPS)) return 1;
    Point h=project(s,c.c);
    if(dot(s.p1-h,s.p2-h)<0) return 2;
    return 0;
}




// 線分と線分の距離
double getDistanceSS(Segment s1,Segment s2){
    if(intersectSS(s1,s2)) return 0.0;
    return min(min(getDistanceSP(s1,s2.p1),getDistanceSP(s1,s2.p2)),
               min(getDistanceSP(s2,s1.p1),getDistanceSP(s2,s1.p2)));
}

// a1,a2を端点とする線分とb1,b2を端点とする線分の交点計算
// 前提として交差していることが必要
P getCrossPointSS(P a1, P a2, P b1, P b2) {
    P b = b2-b1;
    double d1 = abs(cross(b, a1-b1));
    double d2 = abs(cross(b, a2-b1));
    double t = d1/(d1+d2);
    return a1+(a2-a1)*t;
}

// a1,a2を通る直線とb1,b2を通る直線の交点計算
// 前提として平行でないことが必要
Point getCrossPointLL(Line l1,Line l2){
    double a=cross(l1.p2-l1.p1,l2.p2-l2.p1);
    double b=cross(l1.p2-l1.p1,l1.p2-l2.p1);
    if(abs(a)<EPS&&abs(b)<EPS) return l2.p1;
    return l2.p1+(l2.p2-l2.p1)*(b/a);
}

// getCrossPointCCに必要
double arg(Point p){
    return atan2(p.y,p.x);
}

// getCrossPointCCに必要
Point polar(double a,double r) {
    return Point(cos(r)*a,sin(r)*a);
}

// 円と直線の交点
Polygon getCrossPointCL(Circle c,Line l){
    Polygon ps;
    Point pr=project(l,c.c);
    Point e=(l.p2-l.p1)/abs(l.p2-l.p1);
    if(equals(getDistanceLP(l,c.c),c.r)){
        ps.emplace_back(pr);
        return ps;
    }
    double base=sqrt(c.r*c.r-norm(pr-c.c));
    ps.emplace_back(pr+e*base);
    ps.emplace_back(pr-e*base);
    return ps;
}

// 円と線分の交点
Polygon getCrossPointCS(Circle c,Segment s){
    Line l(s);
    Polygon res=getCrossPointCL(c,l);
    if(intersectCS(c,s)==2) return res;
    if(res.size()>1u){
        if(dot(l.p1-res[0],l.p2-res[0])>0) swap(res[0],res[1]);
        res.pop_back();
    }
    return res;
}

// 円と円の交点
Polygon getCrossPointCC(Circle c1,Circle c2){
    Polygon p(2);
    double d=abs(c1.c-c2.c);
    double a=acos((c1.r*c1.r+d*d-c2.r*c2.r)/(2*c1.r*d));
    double t=arg(c2.c-c1.c);
    p[0]=c1.c+polar(c1.r,t+a);
    p[1]=c1.c+polar(c1.r,t-a);
    return p;
}

// 多角形の面積
double area(Polygon s){
    double res=0;
    for(int i=0;i<(int)s.size();i++){
        res+=cross(s[i],s[(i+1)%s.size()])/2.0;
    }
    return res;
}

// 凸多角形ですか？
bool isConvex(Polygon p){
    bool f=1;
    int n=p.size();
    for(int i=0;i<n;i++){
        int t=ccw(p[(i+n-1)%n],p[i],p[(i+1)%n]);
        f&=t!=CLOCKWISE;
    }
    return f;
}

// 多角形の中に点は含まれている？
// IN:2 ON:1 OUT:0
int contains(Polygon g,Point p){
    int n=g.size();
    bool x=false;
    for(int i=0;i<n;i++){
        Point a=g[i]-p,b=g[(i+1)%n]-p;
        if(fabs(cross(a,b)) < EPS && dot(a,b) < EPS) return 1;
        if(a.y>b.y) swap(a,b);
        if(a.y < EPS && EPS < b.y && cross(a,b) > EPS ) x = !x;
    }
    return (x?2:0);
}

// 凸包に使う
bool sort_x(Point a,Point b){
    return a.x!=b.x?a.x<b.x:a.y<b.y;
}

// 凸包に使う
bool sort_y(Point a,Point b){
    return a.y!=b.y?a.y<b.y:a.x<b.x;
}

// 凸包
Polygon convex_hull(Polygon ps){
    int n=ps.size();
    sort(ps.begin(),ps.end(),sort_y);
    int k=0;
    Polygon qs(n*2);
    for(int i=0;i<n;i++){
        while(k>1&&cross(qs[k-1]-qs[k-2],ps[i]-qs[k-1])<0) k--;
        qs[k++]=ps[i];
    }
    for(int i=n-2,t=k;i>=0;i--){
        while(k>t&&cross(qs[k-1]-qs[k-2],ps[i]-qs[k-1])<0) k--;
        qs[k++]=ps[i];
    }
    qs.resize(k-1);
    return qs;
}

// 多角形の直径
double diameter(Polygon s){
    Polygon p=s;
    int n=p.size();
    if(n==2) return abs(p[0]-p[1]);
    int i=0,j=0;
    for(int k=0;k<n;k++){
        if(p[i]<p[k]) i=k;
        if(!(p[j]<p[k])) j=k;
    }
    double res=0;
    int si=i,sj=j;
    while(i!=sj||j!=si){
        res=max(res,abs(p[i]-p[j]));
        if(cross(p[(i+1)%n]-p[i],p[(j+1)%n]-p[j])<0.0){
            i=(i+1)%n;
        }else{
            j=(j+1)%n;
        }
    }
    return res;
}

// 凸多角形を直線で切った時の左側
Polygon convexCut(Polygon p,Line l){
    Polygon q;
    for(int i=0;i<(int)p.size();i++){
        Point a=p[i],b=p[(i+1)%p.size()];
        if(ccw(l.p1,l.p2,a)!=-1) q.push_back(a);
        if(ccw(l.p1,l.p2,a)*ccw(l.p1,l.p2,b)<0)
            q.push_back(getCrossPointLL(Line(a,b),l));
    }
    return q;
}

// 円と点の接線
Polygon tangent(Circle c1,Point p2){
    Circle c2=Circle(p2,sqrt(norm(c1.c-p2)-c1.r*c1.r));
    Polygon p=getCrossPointCC(c1,c2);
    sort(p.begin(),p.end());
    return p;
}

// 円と円の接線
vector<Line> tangent(Circle c1,Circle c2){
    vector<Line> ls;
    if(c1.r<c2.r) swap(c1,c2);
    double g=norm(c1.c-c2.c);
    if(equals(g,0)) return ls;
    Point u=(c2.c-c1.c)/sqrt(g);
    Point v=orth(u);

    for(int s=1;s>=-1;s-=2) {
        double h=(c1.r+s*c2.r)/sqrt(g);
        if(equals(1-h*h,0)) {
            ls.emplace_back(c1.c+u*c1.r,c1.c+(u+v)*c1.r);
        }
        else if(1-h*h>0) {
            Point uu=u*h,vv=v*sqrt(1-h*h);
            ls.emplace_back(c1.c+(uu+vv)*c1.r,c2.c-(uu+vv)*c2.r*s);
            ls.emplace_back(c1.c+(uu-vv)*c1.r,c2.c-(uu-vv)*c2.r*s);
        }
    }

    return ls;
}
