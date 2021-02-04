// abc184_e
#include <bits/stdc++.h>
#ifdef LOCAL
#include "../cxx-prettyprint/prettyprint.hpp"
#endif
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

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

typedef pair<int, int> P;

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    REP(i, H) cin >> S[i];

    int s = 0;
    int t = 0;
    vector<vector<int>> warp(26);
    vector<bool> used(26, false);
    REP(i, H) REP(j, W){
        if (S[i][j] == 'S') s = i * W + j;
        else if (S[i][j] == 'G') t = i * W + j;
        else if (S[i][j] != '.' && S[i][j] != '#') warp[S[i][j]-'a'].emplace_back(i*W+j);
    }

    priority_queue<P, vector<P>, greater<P> > pq;
    pq.push(P(0, s));

    vector<ll> dist(H * W, INF);
    dist[s] = 0;

    while (!pq.empty()){
        P p = pq.top(); pq.pop();

        ll cost = p.first;
        int node = p.second;

        if (node == t) {
            print(cost);
            return 0;
        }

        int i = node / W;
        int j = node % W;

        ll ncost = cost + 1;

        REP(k, 4) {
            int ni = i + dx[k];
            int nj = j + dy[k];
            if (not bound_check(ni, nj, H, W)) continue;
            if (S[i][j] == '#') continue;

            int nnode = ni * W + nj;
            if (ncost < dist[nnode]){
                dist[nnode] = ncost;
                pq.emplace(ncost, nnode);
            }
        }

        if ('a' <= S[i][j] && S[i][j] <= 'z' && not used[S[i][j] - 'a']){
            for (auto nnode: warp[S[i][j] - 'a']){
                if (ncost < dist[nnode]){
                    dist[nnode] = ncost;
                    pq.emplace(ncost, nnode);
                }
            }
            used[S[i][j] - 'a'] = true;
        }
//        print(i, j);
//        REP(i, H){
//            REP(j, W){
//                cout << dist[i*W+j] << " ";
//            }
//            cout << endl;
//        }
    }

    print(-1);

    return 0;
}
