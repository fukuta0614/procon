//
// Created by Fukuta Keisuke on 1/22/18.
//

#include <iostream>
#include "lib.h"

using namespace std;

void vec(string vecname, Vector2& v);

int main(){
    Vector2 v1,v2,v3;
    //  ベクトルに値を代入
    v1.x = 1.0;
    v1.y = 2.0;
    v2 = v1;            //  値を代入
    v3 = 4.0 * v1;      //  ベクトルのスカラー倍
    vec("v1=", v1);
    vec("v2=", v2);
    Vector2 v4 = v1 + v2;
    vec("v4=", v4);
    vec("v1 + v2=", v1 + v2);
    vec("v1 - v2=", v1 - v2);
    vec("v3=", v3);
    v3 += v1;           //  代入演算子（+=）
    vec("v3=",v3);
    v1 -= v2;           //  代入演算子（-=）
    vec("v1=", v1);
    return 0;
}

void vec(string vecname, Vector2&& v)
{
    cout << vecname << "(" << v.x << "," << v.y << ")" << endl;
}