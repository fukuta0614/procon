// aribon2-6-4_d
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
template<class T> void print(const T& x){cout << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

int euler_totient(int n){
    int sqrt_n = (int) sqrt(n);
    int ret = n;
    REPN(p, 2, sqrt_n+1){
        if (n % p == 0){
            ret = (ret / p) * (p-1);
            while (n % p == 0) n /= p;
        }
    }
    if (n > 1) {
        ret = (ret / n) * (n-1);
    }

    return ret;
}

int euler(int num){

    int ret = num;

    for(int i = 2; i*i <= num;  i++){
        if(num%i == 0) {
            ret  = ret/i*(i-1);
            while(num%i == 0)num /= i;
        }
    }
    if(num != 1) ret = ret/num*(num-1);
    return ret;
}

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt");
    cin.rdbuf(in.rdbuf());
#endif

    int t;
    cin >> t;
    vector<ll> farey(1000001);
    farey[0] = 1;
    REPN(i, 1, 1000001) {
        farey[i] = farey[i-1] + (ll)euler(i);
    }

    REP(i, t){
        int n;
        cin >> n;
        print(farey[n]);
    }

    return 0;
}
