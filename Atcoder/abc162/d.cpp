// abc162_d
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

    int N;
    cin >> N;
    string S;
    cin >> S;

    int r = 0;
    int g = 0;
    int b = 0;
    vector<vector<int>> cnt(N, vector<int>(3, 0));
    vector<int> Color(N);
    REP(i, N) {
        if (S[i] == 'R') {r++; Color[i] = 0;}
        if (S[i] == 'G') {g++; Color[i] = 1;}
        if (S[i] == 'B') {b++; Color[i] = 2;}
        cnt[i][0] = r;
        cnt[i][1] = g;
        cnt[i][2] = b;
    }

    auto rest_color = [] (int a, int b){
        return 3 - a - b;
    };

    ll ans = 0;
    REP(i, N) {
        int a = Color[i];
        REP(j, i){
            int b = Color[j];
            // i, jが違うときだけ
            if (a == b) continue;

            // kは3-i-jでいける
            int c = rest_color(a, b);
            ans += cnt[j][c];
            int k = j - (i - j);
            if (k >= 0 && Color[k] == c) ans--;
        }
    }

    print(ans);


    return 0;
}
