// httf2020_a
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

int dx[4]={ 1, 0, -1, 0 };
int dy[4]={ 0, 1, 0, -1 };

enum{
    NOTHING = 0,
    BLOCK,
    ARROW_D,
    ARROW_U,
    ARROW_L,
    ARROW_R,
};


int N, M, B;
int gy, gx;
vector<int> ry, rx, rc;
vector<vector<int>> S;


vector<vector<int>> bfs(vector<vector<int>>& S){

    auto S2 = S;

    queue<P> q;
    q.push(P(gy, gx));

    vector<int> rev{ARROW_L, ARROW_U, ARROW_R, ARROW_D};

    while(!q.empty()){

        P p = q.front(); q.pop();
        int y = p.first;
        int x = p.second;

        REP(i, 4){
            int nx = x + dx[i];
            int ny = y + dy[i];
            nx = nx < 0 ? nx + N : (nx >= N ? nx - N : nx);
            ny = ny < 0 ? ny + N : (ny >= N ? ny - N : ny);

            if (S2[ny][nx] == NOTHING){
                S2[ny][nx] = rev[i];
                q.push(P(ny, nx));
            }
        }
    }

    return S2;

}


vector<vector<int>> prune(vector<vector<int>>& S){

    vector<vector<bool>> used;
    used.assign(N, vector<bool>(N, false));

    vector<int> forward_dir{-1, -1, 1, 3, 2, 0};

    auto S2 = S;

    REP(k, M){

        int y = ry[k];
        int x = rx[k];
        int c = rc[k];
        while (not (x == gx && y == gy)){

            if (c != S[y][x]) {
                used[y][x] = true;
            }
            c = S[y][x];

            x += dx[forward_dir[c]];
            y += dy[forward_dir[c]];
            x = x < 0 ? x + N : (x >= N ? x - N : x);
            y = y < 0 ? y + N : (y >= N ? y - N : y);
        }
    }

    REP(i, N) REP(j, N){
        if (not used[i][j]) {
            S2[i][j] = NOTHING;
        }
    }

    return S2;
}


vector<vector<int>> prune2(vector<vector<int>>& S){

    vector<vector<bool>> used;

    vector<int> forward_dir{-1, -1, 1, 3, 2, 0};

    auto S2 = S;

    REP(i, N) REP(j, N){
        if (S2[i][j] == NOTHING || S2[i][j] == BLOCK) continue;

        auto tmp = S2;
        tmp[i][j] = NOTHING;

        bool flag = true;
        REP(k, M){
            used.assign(N, vector<bool>(N, false));

            int y = ry[k];
            int x = rx[k];
            int c = rc[k];
            while (not (x == gx && y == gy)){
                if (used[y][x] || tmp[y][x] == BLOCK) {
                    flag = false;
                    break;
                }
                used[y][x] = true;
                c = tmp[y][x] == NOTHING ? c : tmp[y][x];

                x += dx[forward_dir[c]];
                y += dy[forward_dir[c]];
                x = x < 0 ? x + N : (x >= N ? x - N : x);
                y = y < 0 ? y + N : (y >= N ? y - N : y);
            }

            if (not flag) break;
        }

        if (flag){
            S2 = tmp;
        }

    }

    return S2;
}

void print_ans(vector<vector<int>>& state){
    vector<tuple<int, int, char>> ans;

    REP(i, N) REP(j, N){
            switch (state[i][j]){
                case NOTHING:
                    continue;
                case BLOCK:
                    continue;
                case ARROW_D:
                    ans.emplace_back(i, j, 'D');
                    break;
                case ARROW_L:
                    ans.emplace_back(i, j, 'L');
                    break;
                case ARROW_R:
                    ans.emplace_back(i, j, 'R');
                    break;
                case ARROW_U:
                    ans.emplace_back(i, j, 'U');
                    break;
                default:
                    continue;
            }
        }

    print(ans.size());
    for (auto t: ans){
        print(get<0>(t), get<1>(t), get<2>(t));
    }
}
int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif


    cin >> N >> M >> B;
    cin >> gy >> gx;
    ry.assign(M, 0); rx.assign(M, 0); rc.assign(M, 0);

    map<char, int> char2enum{{'D', ARROW_D}, {'U', ARROW_U}, {'L', ARROW_L}, {'R', ARROW_R}};
    REP(i, M) {
        char c;
        cin >> ry[i] >> rx[i] >> c;
        rc[i] = char2enum[c];
    }

    S.assign(N, vector<int>(N));
    REP(i, B){
        int by, bx;
        cin >> by >> bx;
        S[by][bx] = BLOCK;
    }

    auto S2 = bfs(S);
    auto S3 = prune(S2);
    auto S4 = prune2(S3);

    print_ans(S4);

    return 0;
}
