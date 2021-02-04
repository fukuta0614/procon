// arc012_c
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

#define INF (ll)(1e9)
#define MOD (1000000007)

#define print2D(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }
#define print_line(vec, n) {for(int idx=0;idx<(n-1);idx++) cout << (vec)[idx] << " "; cout << (vec)[(n)-1] << endl;}
template<class T> void print(const T& x){cout << x << "\n";}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

bool tate(vector<string>& S, char c){
    int mx = 0;
    REP(j, 19){
        int tmp = 0;
        REP(i, 19){
            if (S[i][j] == c){
                tmp++;
                mx = max(mx, tmp);
            } else {
                tmp = 0;
            }
        }
    }
    return mx >= 5;
}

bool yoko(vector<string>& S, char c){
    int mx = 0;
    REP(i, 19){
        int tmp = 0;
        REP(j, 19){
            if (S[i][j] == c){
                tmp++;
                mx = max(mx, tmp);
            } else {
                tmp = 0;
            }
        }
    }
    return mx >= 5;
}

int naname(vector<string>& S, char c){

    int mx = 0;

    REPN(i, -19, 19){
        int tmp = 0;
        REP(k, 19) {
            int ni = i + k;
            int nj = k;
            if (not (0 <= ni && ni < 19)) continue;
            if (S[ni][nj] == c){
                tmp++;
                mx = max(mx, tmp);
            } else {
                tmp = 0;
            }
        }
    }

    REPN(i, 0, 38){
        int tmp = 0;
        REP(k, 19) {
            int ni = i - k;
            int nj = k;
            if (not (0 <= ni && ni < 19)) continue;
            if (S[ni][nj] == c){
                tmp++;
                mx = max(mx, tmp);
            } else {
                tmp = 0;
            }
        }
    }

    return mx >= 5;
}

int count(vector<string>& S, char c){

    int cnt = 0;
    REP(i, 19) REP(j, 19){
        if (S[i][j] == c){
            cnt++;
        }
    }
    return cnt;
}

bool is_valid(vector<string>& S){

    bool win = false;

    win |= tate(S, 'o');
    win |= yoko(S, 'o');
    win |= naname(S, 'o');
    win |= tate(S, 'x');
    win |= yoko(S, 'x');
    win |= naname(S, 'x');

    return not win;
}

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    vector<string> S(19);
    REP(i, 19) cin >> S[i];

    int b = count(S, 'o');
    int w = count(S, 'x');

    bool valid = false;
    if (b == 0 && w == 0){
        valid = true;
    } else if (b == w){
        // 最後が白
        REP(i, 19) REP(j, 19){
            if (S[i][j] != 'x') continue;

            S[i][j] = '.';
            valid |= is_valid(S);
            S[i][j] = 'x';
        }

    } else if (b == w + 1){
        // 最後が黒
        REP(i, 19) REP(j, 19) {
            if (S[i][j] != 'o') continue;

            S[i][j] = '.';
            valid |= is_valid(S);
            S[i][j] = 'o';
        }
    } else {
        valid = false;
    }

    if (valid){
        print("YES");
    } else {
        print("NO");
    }

    return 0;
}
