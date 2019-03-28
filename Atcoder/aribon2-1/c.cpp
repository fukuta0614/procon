// aribon2-1_c
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

    int N;
    cin >> N;

    vector<int> T;
    int t;
    REP(i, N) {cin >> t; T.emplace_back(t);}
    int S = accumulate(all(T), 0);

    int max_n = 1 << N;
    int ans = 200;
    REP(x, max_n){
        int n = x;
        int s = 0;
        REP(i, N) {
            if (n & 1) s += T[i];
            n >>= 1;
        }
        ans = min(ans,  max(s, S - s));
    }

    cout << ans << endl;
    
    return 0;
}


