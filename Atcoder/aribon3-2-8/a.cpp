// aribon3-2-8_a
#include <bits/stdc++.h>
#ifdef LOCAL
#include "../cxx-prettyprint/prettyprint.hpp"
#endif
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;

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

// 座標圧縮
int comp( vector<int> &x1, vector<int> &x2, int W )
{
    const int N = x1.size();

    vector<int> xs;
    REPN( i, 0, N ){
        REPN( j, -1, 2 ) {
            // 変化のある座標の前後の座標について、有効な範囲なら追加
            int tmp1 = x1[i] + j, tmp2 = x2[i] + j;
            if ( 0 <= tmp1 && tmp1 < W ) xs.push_back( tmp1 );
            if ( 0 <= tmp2 && tmp2 < W ) xs.push_back( tmp2 );
        }
    }

    //　重複要素を消す
    sort( ALL( xs ) );
    xs.erase( unique( ALL( xs ) ), xs.end() );

    REP( i, N ){
        // 新しい座標の取得
        x1[i] = find( ALL( xs ), x1[i] ) - xs.begin();
        x2[i] = find( ALL( xs ), x2[i] ) - xs.begin();
    }

    return xs.size();
}

int field[10][10];

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

//    int N;
//    cin >> N;
    vector<int> x1{1,1,4,9,10};
    vector<int> x2{6,10,4,9,10};
    vector<int> y1{7,8,1,1,6};
    vector<int> y2{7,8,10,5,10};

    for(auto& e: x1) e--;
    for(auto& e: x2) e--;
    for(auto& e: y1) e--;
    for(auto& e: y2) e--;

    print(x1);

    REP(i, 5){
        REPN(y, y1[i], y2[i]+1){
            REPN(x, x1[i], x2[i]+1) {
                field[y][x] = 1;
            }
        }
    }
    print2D(10, 10, field);
    print("");

    int W = comp(x1, x2, 10);
    int H = comp(y1, y2, 10);

    memset(field, 0, sizeof(field));

//    print2D(H, W, field);
//    print("");

    REP(i, 5){
        REPN(y, y1[i], y2[i]+1){
            REPN(x, x1[i], x2[i]+1) {
                field[y][x] = 1;
            }
        }
    }
    print2D(H, W, field);

    return 0;
}
