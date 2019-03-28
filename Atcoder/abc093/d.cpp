//
// Created by P218024 on 2018/04/20.
//
//
// Created by P218024 on 2018/04/20.
//

#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;

#define REP(i, n) for(int (i)=0; (i)<(int)(n); (i)++)
#define REPN(i, m, n) for(int (i)=(int)(m); (i)<(int)(n); (i)++)

ull pow(ull x, ull a, ull p) {
    ull ret = 1;
    while (a) {
        if (a & 1ull) ret = (ret * x) % p;
        a >>= 1;
        x = x * x % p;
    }
    return ret;
}

int main(int argc, char *argv[]) {

    ifstream in("C:\\Users\\P218024\\workspace\\cpp_works\\abc093\\sample.txt");
    cin.rdbuf(in.rdbuf());

    ull x, p, a, b;
    cin >> x >> p >> a >> b;

    ull n = pow(x, a, p);
    ull mn = n;

//    cout << n << endl;
    for (ull i = 0; i < b - a; i++) {
        n = n * x % p;
//        cout << n << endl;

        mn = min(n, mn);
    }
    cout << mn << endl;

}