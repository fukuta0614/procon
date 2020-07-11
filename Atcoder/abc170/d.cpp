// abc170_d
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



int main() {
#ifdef LOCAL
    ifstream in("../arg.txt");
    cin.rdbuf(in.rdbuf());
#endif

    int N;
    cin >> N;
    vector<int> nums(1e6+1);
    REP(i, N) {
        int a;
        cin >> a;
        nums[a]++;
    }

    if (nums[1] > 0){
        if (nums[1] == 1){
            print(1);
        } else {
            print(0);
        }
        return 0;
    }

    int ans = 0;
    for (int i = 2; i < 1e6+1; i++) {
        if (nums[i] > 0) {

            if (nums[i] == 1) ans++;

            for (int j = i; j < 1e6 + 1; j += i) {
                nums[j] = 0;
            }
        }
    }

    print(ans);

    return 0;
}
