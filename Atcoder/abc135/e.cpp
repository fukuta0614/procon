// abc135_e
#include <bits/stdc++.h>
#ifdef LOCAL
#include "../cxx-prettyprint/prettyprint.hpp"
#endif
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

#define REP(i, n) for (int (i) = 0 ; (i) < (int)(n) ; ++(i))
#define REPN(i, m, n) for (int (i) = m ; (i) < (int)(n) ; ++(i))
#define REP_REV(i, n) for (int (i) = (int)(n) - 1 ; (i) >= 0 ; --(i))
#define REPN_REV(i, m, n) for (int (i) = (int)(n) - 1 ; (i) >= m ; --(i))
#define ALL(x) x.begin(), x.end()

#define INF ((1 << 29)-1)
#define MOD (1000000007)

#define print2D(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }
template<class T> void print(const T& x){cout << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    ll K;
    ll X, Y;
    cin >> K;
    cin >> X >> Y;

    ll x = abs(X);
    ll y = abs(Y);
    if (x < y) swap(x, y);

    if ((x + y) % 2 == 1 && K % 2 == 0){
        print(-1);
        return 0;
    }

    vector<P> ans;

    ll a=0, b=0;

    // 距離が2K以下になるまで進む
    while((abs(x - a) + abs(y - b)) > 2 * K){
        if(a + K <= x){
            a += K;
        } else {
            b += (K + a - x);
            a = x;
        }
        ans.emplace_back(a, b);
    }

    // 残りが奇数だといけないので調整が必要
    if ((abs(x - a) + abs(y - b)) % 2 == 1){
        if(a + K <= x){
            a += K;
        } else {
            b += (K + a - x);
            a = x;
        }
        ans.emplace_back(a, b);
    }

    // この時点でたどり着いている可能性も
    if (abs(x - a) + abs(y - b) != 0){

        // 半分まで行って、そこから寄り道
        // 寄り道から帰ってきて半分進む
        ll half = (abs(x - a) + abs(y - b)) / 2;

        if (b > y) // y方向に行き過ぎてしまったら、（正負の管理が面倒なので分岐）
        {
            b -= half;
            a += K - half;
            ans.emplace_back(a, b);
            a -= K - half;
            b -= half;
            ans.emplace_back(a, b);
        }
        else {
            bool y_flag;
            if (a + half <= x) {
                a += half;
                b -= K - half;
                y_flag = true;
            } else {
                b += (half + a - x);
                a = x;
                a += K - half;
                y_flag = false;
            }
            ans.emplace_back(a, b);

            if (y_flag) {
                b += K - half;
            } else {
                a -= K - half;
            }

            if (a + half <= x) {
                a += half;
            } else {
                b += (half + a - x);
                a = x;
            }
            ans.emplace_back(a, b);
        }
    }

    print(ans.size());
    for (auto p: ans){
        ll a = p.first;
        ll b = p.second;

        if (abs(X) < abs(Y)) swap(a, b);
        if (X < 0) a *= -1;
        if (Y < 0) b *= -1;

        print(a, b);
    }

    return 0;
}


