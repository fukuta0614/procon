// abc182_e
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

int dx[8]={ 1, 0, -1, 0, -1, 1, -1, 1};
int dy[8]={ 0, 1, 0, -1, -1, -1, 1, 1};
bool bound_check(int i, int j, int N, int M) {return (0 <= i) && (i < N) && (0 <= j) && (j < M);}

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int H, W, N, M;
    cin >> H >> W >> N >> M;

    vector<P> light(N);
    vector<P> block(M);

    REP(i, N) {cin >> light[i].first >> light[i].second; light[i].first--; light[i].second--;}
    REP(i, M) {cin >> block[i].first >> block[i].second; block[i].first--; block[i].second--;}

    vector<vector<int>> map(H, vector<int>(W, 0));
    REP(i, M) {
        map[block[i].first][block[i].second] = 1;
    }

    vector<vector<vector<int>>> dir(H, vector<vector<int>>(W, vector<int>(4, 0)));
    REP(i, M) {
        map[block[i].first][block[i].second] = 1;
    }

    REP(i, N){

        int y = light[i].first;
        int x = light[i].second;

        map[y][x] = 2;

        REP(k, 4){

            y = light[i].first;
            x = light[i].second;

            while (true){
                int ny = y+dy[k];
                int nx = x+dx[k];

                if (not bound_check(ny, nx, H, W)) break;
                if (map[ny][nx] == 1) break;
                if (dir[ny][nx][k] == 1 || dir[ny][nx][(k+2)%4] == 1) break;

//                print(ny, nx);

                map[ny][nx] = 2;
                dir[ny][nx][k] = 1;

                y = ny;
                x = nx;
            }
        }
    }

    int ans = 0;
    REP(i, H) REP(j, W){
        if (map[i][j] == 2) ans++;
    }

    print(ans);

    return 0;
}
