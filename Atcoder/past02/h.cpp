// past02_h
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
#define print_line(vec, n) {for(int i=0;i<(n-1);i++) cout << (vec)[i] << " "; cout << (vec)[(n)-1] << endl;}
template<class T> void print(const T& x){cout << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

int dx[8]={ 1, 0, -1, 0, -1, 1, -1, 1};
int dy[8]={ 0, 1, 0, -1, -1, -1, 1, 1};

bool bound_check(int i, int j, int N, int M) {return (0 <= i) && (i < N) && (0 <= j) && (j < M);}

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N, M;
    cin >> N >> M;
    vector<vector<int>> S(N, vector<int>(M, 0));
    int si, sj, gi, gj;
    REP(i, N) REP(j, M){
        char c;
        cin >> c;
        if (c == 'S') {
            si = i; sj = j;
            S[i][j] = 0;
        } else if (c == 'G') {
            gi = i; gj = j;
            S[i][j] = 0;
        } else {
            S[i][j] = c - '0';
        }
    }

    auto hash = [&](int i, int j, int n){
        return (N*M)*n + i * M + j;
    };

    vector<int> dist(N*M*10, INF);

    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push(P(0, hash(si, sj, 0)));
    dist[hash(si, sj, 0)] = 0;

//    print(S);

    int ans = -1;
    while (!pq.empty()){

        P p = pq.top(); pq.pop();

        int cost = p.first;
        int h = p.second;
        int n = h / (N*M);
        h %= (N*M);
        int i = h / M;
        int j = h % M;

//        print(n, i, j, cost);

        if (i == gi && j == gj && n == 9){
            ans = cost;
            break;
        }

        REP(k, 4) {
            int ni = i + dx[k];
            int nj = j + dy[k];
            if (not bound_check(ni, nj, N, M)) continue;

            int ncost = cost + 1;
            int nextn = (S[ni][nj] == n + 1) ? n+1 : n;
            int nexth = hash(ni, nj, nextn);

            if (ncost < dist[nexth]){
                dist[nexth] = ncost;
                pq.push(P(ncost, nexth));
            }
        }
    }



    print(ans);

    return 0;
}
