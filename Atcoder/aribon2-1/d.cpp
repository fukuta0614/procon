// aribon2-1_d
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define debug(x) cout << #x << ": " << (x) << endl
#define REP(i, n) for (int (i) = 0 ; (i) < (int)(n) ; ++(i))
#define REPN(i, m, n) for (int (i) = m ; (i) < (int)(n) ; ++(i))
#define REP_REV(i, n) for (int (i) = (int)(n) - 1 ; (i) >= 0 ; --(i))
#define all(x) x.begin(), x.end()
#define INF ((1 << 16)-1)
#define MOD (1000000007)
#define print(arr, n) REP(i, n) cout << arr[i] << " ";

struct PreMain {PreMain(){std::cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

int bitCount(unsigned int bits) {
    int cnt = 0;
    for(unsigned int mask = 1; mask != 0; mask<<=1) {
        if( (bits & mask) != 0 )
            ++cnt;
    }
    return cnt;
}

int main() {
#ifdef LOCAL
    std::ifstream in("../arg.txt");
    std::cin.rdbuf(in.rdbuf());
#endif

    int N, M;
    cin >> N >> M;
    bool R[N][N] = {};

    REP(i, M){
        int x, y;
        cin >> x >> y;x--;y--;
        R[x][y] = true;
        R[y][x] = true;
    }

    int max_n = 1 << N;
    int ans = 0;
    REP(n, max_n){
        int tmp = bitCount(n);
        if (tmp <= ans) continue;

        bool flag = true;
        REP(i, N) {
            REPN(j, i+1, N){
                if (((n >> i) & 1) && ((n >> j) & 1) && !R[i][j]) {
                    flag = false;
                    break;
                }
            }
            if (!flag) break;
        }

        if (flag) ans = tmp;
    }
    cout << ans << endl;

    return 0;
}


