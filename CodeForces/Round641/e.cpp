// Round641_e
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

#define INF (ll)(2e18)
#define MOD (1000000007)

#define print2D(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }
#define print_line(vec, n) {for(int i=0;i<(n-1);i++) cout << (vec)[i] << " "; cout << (vec)[(n)-1] << endl;}
template<class T> void print(const T& x){cout << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;


int dx[8]={ 1, 0, -1, 0, -1, 1, -1, 1};
int dy[8]={ 0, 1, 0, -1, -1, -1, 1, 1};

ll N, M, T;
vector<string> S;
vector<vector<ll>> dist;

void test(){
    REP(i, N) print(S[i]);

    auto rev = [](char c){
        return (char)((1 - (c - '0')) + '0');
    };

    REP(t, 10){
        auto prev = S;
        REP(i, N) REP(j, N) {

            bool change = false;
            REP(k, 4) {
                int ni = i + dx[k];
                int nj = j + dy[k];
                if (ni < 0 || ni >= N || nj < 0 || nj >= M) continue;

                if (prev[i][j] == prev[ni][nj]) {
                    change = true;
                    break;
                }
            }
            S[i][j] = change ? rev(prev[i][j]) : prev[i][j];
        }
        print(t+1);
        REP(i, N) print(S[i]);
    }
}

void bfs(){

    queue<P> q;

    REP(i, N) REP(j, M) {
        REP(k, 4) {
            int ni = i + dx[k];
            int nj = j + dy[k];
            if (ni < 0 || ni >= N || nj < 0 || nj >= M) continue;

            if (S[i][j] == S[ni][nj]) {
                dist[i][j] = 0;
                q.push(P(i, j));
                break;
            }
        }
    }

    while (not q.empty()){

        P p = q.front(); q.pop();
        int i = p.first;
        int j = p.second;

        REP(k, 4) {
            int ni = i + dx[k];
            int nj = j + dy[k];
            if (ni < 0 || ni >= N || nj < 0 || nj >= M) continue;

            if (dist[ni][nj] == INF) {
                dist[ni][nj] = dist[i][j] + 1;
                q.push(P(ni, nj));
            }
        }
    }
}

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    cin >> N >> M >> T;
    S.assign(N, "");
    REP(i, N) cin >> S[i];

    dist.assign(N, vector<ll>(M, INF));
    bfs();

    auto rev = [](char c){ return (char)((1 - (c - '0')) + '0'); };

//    REP(i, N) print(dist[i]);

    REP(_, T){
        ll i, j, p;
        cin >> i >> j >> p;
        i--; j--;

        ll d = dist[i][j] + 1;

        char ans;
        if (p < d){
            ans = S[i][j];
        } else {
//            print(p, d, S[i][j]);
            ans = ((p - d) % 2 == 0) ? rev(S[i][j]) : S[i][j];
        }
        print(ans);
    }


    return 0;
}
