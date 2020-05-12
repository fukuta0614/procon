#include <bits/stdc++.h>
#define WHOLE(v) (v).begin(), (v).end()
#define REV_WHOLE(v) (v).rbegin(), (v).rend()
using i64 = int64_t;
using namespace std;
template<class F>auto recursive(F f){return[f](auto...a){return f(f,a...);};}
template<class T>using rev_priority_queue=priority_queue<T,vector<T>,greater<T>>;
template<class T>using vector2d=vector<vector<T>>;
struct fixprec{int p;fixprec(int p):p(p){}};
ostream&operator<<(ostream&o,fixprec f){return o<<fixed<<setprecision(f.p);}

struct Point {
    double x, y;
};

const double eps = 1e-10;

pair<Point, double> get_circle(Point p, Point q, Point r) {
    double a = p.x - q.x,
            b = p.y - q.y,
            c = q.x - r.x,
            d = q.y - r.y;
    double det = a * d - b * c;
    if(det == 0.0) return {{0,0},-1};
    double x = p.x * p.x + p.y * p.y - q.x * q.x - q.y * q.y,
            y = q.x * q.x + q.y * q.y - r.x * r.x - r.y * r.y;
    Point center = {
            (d * x - b * y) / (2.0 * det),
            (a * y - c * x) / (2.0 * det)
    };
    double radius = hypot(p.x - center.x, p.y - center.y);
    print(radious, center.x, center.y);
    return make_pair(center, radius);
}

int main() {
    int N;
    cin >> N;
    vector<Point> p(N);
    auto judge = [&p](Point c, double r) -> bool {
        bool ans = true;
        for(Point a : p) {
            ans &= hypot(c.x - a.x, c.y - a.y) <= r + eps;
        }
        return ans;
    };
    for(Point &a : p) {
        cin >> a.x >> a.y;
    }
    double ans = 1e7;
    for(int i = 0; i < N; i++) {
        Point center;
        double radius;
        for(int j = i + 1; j < N; j++) {
            for(int k = j + 1; k < N; k++) {
                tie(center, radius) = get_circle(p[i], p[j], p[k]);
                if(radius < 0) continue;
                if(judge(center, radius)) ans = min(ans, radius);
            }
            center = {
                    (p[i].x + p[j].x) / 2.0,
                    (p[i].y + p[j].y) / 2.0
            };
            radius = hypot(center.x - p[i].x, center.y - p[i].y);
            if(judge(center, radius)) ans = min(ans, radius);
        }
    }
    cout << fixprec(15) << ans << endl;
    return 0;
}

