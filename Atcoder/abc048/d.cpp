// abc048_d
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
#define print_line(vec, n) {for(int i=0;i<(n-1);i++) cout << (vec)[i] << " "; cout << (vec)[(n)-1] << endl;}
template<class T> void print(const T& x){cout << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    string s;
    cin >> s;

    int n = s.size();

    // 最終状態で残る文字列の数の遇奇は、先頭と末尾が同じかどうかのみで決まる
    int end_num = (s[0] == s.back()) ? 1 : 2;

    // 消せる文字の数が奇数だったら、先手の勝ち
    if ((n - end_num) % 2 == 1){
        print("First");
    } else {
        print("Second");
    }

//    s = "";
//    random_device rd;
//    mt19937 mt(rd());
//
//    char p = '?';
//    REP(i, 4){
//        char c;
//        do {
//            c = mt() % 3 + 'a';
//        } while(c == p);
//        p = c;
//        s += c;
//        s += ' ';
//    }
//    print(s);



    return 0;
}
