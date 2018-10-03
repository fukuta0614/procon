#include "lib.h"

//  +演算子のオーバーロード
Vector2 operator+(const Vector2& v1,const Vector2& v2)
{
    Vector2 v;
    v.x = v1.x + v2.x;
    v.y = v1.y + v2.y;
    return v;
}
//  -演算子のオーバーロード
Vector2 operator-(const Vector2& v1,const Vector2& v2)
{
    Vector2 v;
    v.x = v1.x - v2.x;
    v.y = v1.y - v2.y;
    return v;
}
//  スカラー倍
Vector2 operator*(const double d, const Vector2& v)
{
    Vector2 r;
    r.x = d * v.x;
    r.y = d * v.y;
    return r;
}
//  =演算子のオーバーロード
Vector2& Vector2::operator=(const Vector2& v)
{
    x = v.x;
    y = v.y;
    return *this;
}
//  +=演算子のオーバーロード
Vector2& Vector2::operator+=(const Vector2& v)
{
    x += v.x;
    y += v.y;
    return *this;
}
//  -=演算子のオーバーロード
Vector2& Vector2::operator-=(const Vector2& v)
{
    x -= v.x;
    y -= v.y;
    return *this;
}