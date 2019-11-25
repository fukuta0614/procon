// ddcc_d
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


int func(string n){

    int cnt = 0;
    while (n.size() > 1){
        int sm = ((n[0] - '0') + (n[1] - '0'));
        n = to_string(sm) + n.substr(2, n.size()-2);
        cnt++;
    }

    return cnt;

}


int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    ll M;
    cin >> M;

    vector<ll> A(10, 0);
    REP(i, M){
        ll d, c;
        cin >> d >> c;
        A[d] += c;
    }

    ll ans = 0;

    bool update = true;
    while (update){
        update = false;

        ans += A[0];
        A[0] = 0;

        REPN(d, 1, 10){
            if (A[d] < 2) continue;
            update = true;
            int x = d * 2;
            ans += A[d] / 2;
            if (x < 10){
                A[x] += A[d] / 2;
                A[d] = A[d] % 2;
            } else {
                A[1] += A[d] / 2;
                A[x % 10] += A[d] / 2;
                A[d] = A[d] % 2;
            }
        }
    }


    string n;
    REP(d, 10){
        if (A[d] == 1) {
            n += to_string(d);
        }
    }


    ans += func(n);

    print(ans);


    return 0;
}
