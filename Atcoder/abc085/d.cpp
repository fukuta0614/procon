// abc085_d
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

#define INF (1e9)
#define MOD (1000000007)

#define print2D(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }
#define print_line(vec, n) {for(int i=0;i<(n-1);i++) cout << (vec)[i] << " "; cout << (vec)[(n)-1] << endl;}
template<class T> void print(const T& x){cout << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N, H;
    cin >> N >> H;
    vector<pair<ll, int>> A(N), B(N);
    REP(i, N){
        int a, b; cin >> a >> b;
        A[i] = {a, i};
        B[i] = {b, i};
    }
    sort(ALL(A), greater<P>());
    sort(ALL(B), greater<P>());
    ll a0 = A[0].first;

    ll cumsum = 0;
    ll ans = INF;
    REP(i, N){
        cumsum += B[i].first;
        if (cumsum < H){
            ans = min(ans, (i+1 + (H-cumsum+a0-1)/a0));
        } else {
            ans = min(ans, (ll)(i+1));
        }
    }

    print(ans);
    return 0;

    // ↓ なんとなくにぶたんしちゃったやつ。一応これもAC
    auto func = [&](int n){

        int cnt = 0;
        ll damage = 0;
        REP(i, N){
            if (B[i].first > A[0].first){
                damage += B[i].first;
                cnt++;
                if (cnt >= n) break;
            }
        }

        if (cnt < n){
            damage += A[0].first * (n - cnt);
        }

        return damage;
    };

    int ok = 1e9;
    int ng = 0;
    while (ok - ng > 1){
        int mid = (ok + ng) / 2;
        if (func(mid) >= H){
            ok = mid;
        } else {
            ng = mid;
        }
    }

    print(ok);



    return 0;
}
