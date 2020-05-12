// abc159_e
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
    vector<string> S(H);
    REP(i, H) cin >> S[i];

    vector<vector<int>> cumsum(H+1, vector<int>(W+1, 0));

    REPN(i, 1, H + 1) {
        REPN(j, 1, W + 1) {
            cumsum[i][j] = int(S[i-1][j-1] == '1') + cumsum[i][j - 1] + cumsum[i - 1][j] - cumsum[i - 1][j - 1];
        }
    }
//    print2D(H, W, S);
//    print2D(H+1, W+1, cumsum);

    auto func = [&](int l, int r, int u, int d){
        return cumsum[r][d] - cumsum[l][d] - cumsum[r][u] + cumsum[l][u];
    };

//    REP(i, H) {
//        REP(j, W){
//            int x = func(i, i+1, j, j+1);
//            cout << x << " " ;
//        }
//        print("");
//    }


    int ans = INF;
    REP(p, 1 << (H-1)){
        vector<P> sector;
        int a = 0;
        REP(i, H-1){
            if ((p >> i) & 1) {
                sector.emplace_back(a, i+1);
                a = i+1;
            }
        }
        if (p == 0){
            sector.emplace_back(a, H);
        } else {
            sector.emplace_back(sector.back().second, H);
        }
        int n = sector.size();

        // そもそも一列でアウトがないか確認
        bool ng = false;
        REP(x, W){
            REP(i, n){
                int a = sector[i].first;
                int b = sector[i].second;

                int num = func(a, b, x, x+1);
                if (num > K){
                    ng = true;
                    break;
                }
            }
            if (ng) break;
        }
        if (ng) continue;

        int tmp = n - 1;
        int l = 0;
        REPN(r, 2, W+1){ // l=0, r=1はOKだからr=2から

            bool need = false;
            REP(i, n){
                int a = sector[i].first;
                int b = sector[i].second;

                int num = func(a, b, l, r);
                if (num > K){
                    need = true;
                    break;
                }
            }

            if (need){
                l = r-1;
                tmp++;
            }
        }
        ans = min(ans, tmp);
    }

    print(ans);


    return 0;
}
