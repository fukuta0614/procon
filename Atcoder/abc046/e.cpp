// arc062_e
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

    vector<vector<int>> colors;
    colors.assign(N, vector<int>(4,0));

    using Color = pair<P, P>;
    map<Color, int> mp;

    REP(i, N){

        vector<int>& C = colors[i];
        REP(j, 4) cin >> C[j];

        // 2週にしとく
        REP(j, 4) C.emplace_back(C[j]);

        REP(j, 4) {
            Color c{{C[j], C[j+1]}, {C[j+2], C[j+3]}};
            mp[c]++;
        }

    }

    /*
     *   □
     * □ □ □ □
     *   □
     *   真ん中が一番小さい数字かつ回転なし
     *   底面とその方向を決めると、全色確定
     */

    auto rotate = [](Color& c){ c = {{c.second.second, c.first.first}, {c.first.second, c.second.first}};};

    ll ans = 0;
    REP(i, N) {

        vector<int> front = colors[i];
        int a = front[0];
        int b = front[1];
        int c = front[2];
        int d = front[3];

        Color c0{{a, b}, {c, d}};
        REP(k, 4) { mp[c0]--; rotate(c0);}

        REPN(j, i+1, N) {
            vector<int> back = colors[j];

            Color c5{{back[0], back[1]}, {back[2], back[3]}};
            REP(k, 4) { mp[c5]--; rotate(c5);}

            REP(k, 4){
                int x = back[k+0];
                int y = back[k+1];
                int z = back[k+2];
                int w = back[k+3];

                Color c1{{d, c}, {w, z}};
                Color c2{{c, b}, {x, w}};
                Color c3{{b, a}, {y, x}};
                Color c4{{a, d}, {z, y}};

                if (mp[c1] == 0 || mp[c2] == 0 || mp[c3] == 0 || mp[c4] == 0) continue;

                vector<Color> cs{c1, c2, c3, c4};

                ll tmp = 1;

                REP(m, 4){
                    tmp *= mp[cs[m]];
                    REP(n, 4) { mp[cs[m]]--; rotate(cs[m]);}
                }

                REP(m, 4){
                    REP(n, 4) { mp[cs[m]]++; rotate(cs[m]);}
                }

                ans += tmp;
            }

            REP(k, 4) { mp[c5]++; rotate(c5);}
        }
    }

    print(ans);
//    print(cnt);

    return 0;
}
