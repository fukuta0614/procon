// ddcc_c
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

    int H, W, K;
    cin >> H >> W >> K;

    vector<vector<bool>> S;
    S.assign(H, vector<bool>(W, false));

    REP(i, H) {
        string s;
        cin >> s;
        REP(j, W){
            if (s[j] == '#') S[i][j] = true;
        }
    }

//    print(S);

    vector<bool> exists(H);
    REP(i, H) {
        REP(j, W){
            if (S[i][j]) exists[i] = true;
        }
    }

//    print(exists);

    int first=0;
    REP(i, H){
        if (exists[i]){
            first = i;
            break;
        }
    }

    vector<vector<int>> ans;
    ans.assign(H, vector<int>(W, -1));


    int tmp = 0;
    REPN(i, first, H){
        if (exists[i]){
            tmp++;
            bool mada = true;
            REP(j, W){
                if (mada){
                    if (S[i][j]) mada = false;
                    ans[i][j] = tmp;
                } else{
                    if (S[i][j]) tmp++;
                    ans[i][j] = tmp;
                }
            }
        } else {
            ans[i] = ans[i-1];
        }
    }

    REP(i, first){
        ans[i] = ans[first];

    }

    REP(i, H){
        for(int j=0;j<(W-1);j++) cout << ans[i][j] << " "; cout << ans[i][W-1] << endl;
    }

    return 0;
}
