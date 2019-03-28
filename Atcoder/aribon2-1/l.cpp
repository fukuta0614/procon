// asdf_l
#include <bits/stdc++.h>
#ifdef LOCAL
#include "../cxx-prettyprint/prettyprint.hpp"
#endif
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ull, int> P;

#define REP(i, n) for (int (i) = 0 ; (i) < (int)(n) ; ++(i))
#define REPN(i, m, n) for (int (i) = m ; (i) < (int)(n) ; ++(i))
#define REP_REV(i, n) for (int (i) = (int)(n) - 1 ; (i) >= 0 ; --(i))
#define INF ((1 << 31)-1)
#define MOD (1000000007)

#define ALL(x) x.begin(), x.end()
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );
#define CHAR2INT(c) (c - '0')
#define COUT(x) cout << x << endl
#define COUT_2DARR(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }

int main() {
#ifdef LOCAL
    std::ifstream in("../arg.txt");
    std::cin.rdbuf(in.rdbuf());
#endif

    ull pow3[16];
    pow3[0] = 1;
    REP(i, 15) pow3[i + 1] = pow3[i] * 3;

    int arr[4][2] = {{0, 1}, {1,2}, {2,1}, {1,0}};

    while(true){
        int N, M;
        cin >> N >> M;
        if (N == 0) return 0;

        ull init_state = 0;
        REP(i, 3){
            int k;
            cin >> k;
            REP(j, k){
                int n;
                cin >> n;
                init_state += i * pow3[--n];
            }
        }
        ull final_state1 = 0;
        ull final_state2 = pow3[N] - 1;

        vector<bool> visited(pow3[N], false);
        queue<P> Q;
        Q.push(P(init_state, 0));
        int max_cup[3];
        while (!Q.empty()){
            P p = Q.front(); Q.pop();

            ull state = p.first;
            int count = p.second;

            if (count >= M) {
                COUT(-1);
                break;
            }

            if (state == final_state1 || state == final_state2) {
                COUT(count);
                break;
            }

            visited[state] = true;

            memset(max_cup, -1, sizeof(max_cup));
            ull tmp = state;

            vector<vector<ull>> vec(3, vector<ull>{});
            REP(i, N){
                ull res = tmp % 3;
                max_cup[res] = max(max_cup[res], i);
                tmp /= 3;
            }

            REP(i, 4){
                int src = arr[i][0];
                int dst = arr[i][1];
                if (max_cup[src] > max_cup[dst]){
                    ull next_state = src < dst ? state + pow3[max_cup[src]] : state - pow3[max_cup[src]];
                    if (visited[next_state]) continue;
                    Q.push(P(next_state, count + 1));
                }
            }

        }

    }
}
