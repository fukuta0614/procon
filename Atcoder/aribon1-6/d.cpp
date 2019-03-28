// aribon1-6_d
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

int main() {
#ifdef LOCAL
    std::ifstream in("../arg.txt");
    std::cin.rdbuf(in.rdbuf());
#endif

    int N,Y;
    cin >> N >> Y;
    Y /= 1000;

    REP(x, N+1){
        int y = Y - N - 9 * x;
        if (y % 4 != 0 || y / 4  > N || y < 0) continue;
        int z = -Y + 5 * N + 5 * x;
        if (z % 4 != 0 || z / 4  > N || z < 0) continue;
        cout << x << " " << (y / 4) << " " << (z / 4) << endl;
        exit(0);
    }
    cout << -1 << " " << -1 << " " << -1 << endl;

    return 0;
}


