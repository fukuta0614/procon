//
// Created by 福田圭佑 on 2021/02/07.
//

struct Rational {

    ll p, q;
    Rational() : p(0), q(1) {};
    Rational(ll p) : p(p), q(1) {};
    Rational(ll p, ll q) : p(p), q(q) {};

    void reduction(){ ll d = gcd(p, q); if (q < 0 && d > 0) d *= -1; p /= d; q /= d;}

    Rational& operator+=(const Rational& a) { p = p * a.q + a.p * q; q = q * a.q; reduction(); return *this; }
    Rational& operator-=(const Rational& a) { p = p * a.q - a.p * q; q = q * a.q; reduction(); return *this; }
    Rational& operator*=(const Rational& a) { p *= a.p; q *= a.q; reduction(); return *this; }
    Rational& operator/=(const Rational& a) { p *= a.q; q *= a.p; reduction(); return *this; }
    Rational operator+(const Rational& a) {Rational res(*this); return res+=a;}
    Rational operator-(const Rational& a) {Rational res(*this); return res-=a;}
    Rational operator*(const Rational& a) {Rational res(*this); return res*=a;}
    Rational operator/(const Rational& a) {Rational res(*this); return res/=a;}
    Rational operator-() const {Rational res(*this); res.p *= -1; return res;}
    bool operator==(const Rational& a) const { return p == a.p && q == a.q;}
    bool operator!=(const Rational& a) const { return p != a.p || q != a.q;}

    Rational& operator+=(const ll& a) { p = p + a * q; reduction(); return *this; }
    Rational& operator-=(const ll& a) { p = p - a * q; reduction(); return *this; }
    Rational& operator*=(const ll& a) { p *= a; reduction(); return *this; }
    Rational& operator/=(const ll& a) { q *= a; reduction(); return *this; }
    Rational operator+(const ll& a) {Rational res(*this); return res+=a;}
    Rational operator-(const ll& a) {Rational res(*this); return res-=a;}
    Rational operator*(const ll& a) {Rational res(*this); return res*=a;}
    Rational operator/(const ll& a) {Rational res(*this); return res/=a;}
    bool operator==(const ll& a) const { return p == a && q == 1;}
    bool operator!=(const ll& a) const { return p != a || q != 1;}
    bool operator==(const int& a) const { return p == a && q == 1;}
    bool operator!=(const int& a) const { return p != a || q != 1;}

    operator bool() const {return p != 0;}

    friend ostream& operator<<(ostream& os, const Rational& a) {if (a.q == 1) {cout << (long long)a.p;} else {cout << (long long)a.p << "/" << (long long)a.q;}; return os;}
};
