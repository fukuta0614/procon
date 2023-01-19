// test_a
#pragma GCC optimize ("O3")

#include <bits/stdc++.h>
#ifdef LOCAL
#include "../../debug_util/cxx-prettyprint/prettyprint.hpp"
#include "../../debug_util/rng.hpp"
#include "../../debug_util/timer.hpp"
#endif
using namespace std;

using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

#define REP(i, n) for (int i = 0 ; i < (int)(n) ; ++i)
#define REPN(i, m, n) for (int i = m ; i < (int)(n) ; ++i)
#define REP_REV(i, n) for (int i = (int)(n) - 1 ; i >= 0 ; --i)
#define REPN_REV(i, m, n) for (int i = (int)(n) - 1 ; i >= m ; --i)
#define ALL(x) x.begin(), x.end()

#define INF (ll)(1e15)
#define MOD (1000000007)

#define print2D(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }
#define print_line(vec, n) {for(int idx=0;idx<(n-1);idx++) cout << (vec)[idx] << " "; cout << (vec)[(n)-1] << endl;}
template<class T> void print(const T& x){cout << x << "\n";}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;



enum teUnscopedColor {
    eUNSCOPED_COLOR_BLACK,
    eUNSCOPED_COLOR_WHITE,
    eUNSCOPED_COLOR_RED,
    eUNSCOPED_COLOR_MAX,
};

//enum Color { black, white, red };

template<typename E>
constexpr auto toUType(E enumerator)
{
    return static_cast<std::underlying_type_t<E>>(enumerator);
}

enum class ScopedColor {
    black,
    white,
    red,
    max
};

int main() {

    print(toUType(ScopedColor::black)); // -> 0
    print(toUType(ScopedColor::white)); // -> 1
    print(toUType(ScopedColor::red));   // -> 2
    print(toUType(ScopedColor::max));   // -> 3

    // 従来のenumを使う場合
    int arr1[eUNSCOPED_COLOR_MAX] = {1, 2, 3};

    int x = arr1[eUNSCOPED_COLOR_WHITE];

    // enum classを使う場合
    int arr2[toUType(ScopedColor::max)] = {1, 2, 3};

    int y = arr2[toUType(ScopedColor::black)];


    // 従来のenumを使う場合
    for (int i = eUNSCOPED_COLOR_BLACK; i < eUNSCOPED_COLOR_MAX; ++i) {
        print(i);
    }

    // enum classを使う場合
    for (int i = toUType(ScopedColor::black); i < toUType(ScopedColor::max); ++i) {
        print(i);
    }

    print(x, y);

//    enum class Color { black, white, red };
//    auto white = Color::white;
//    print(static_cast<int>(white));

    return 0;
}
