// aising2020_e
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
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int T;
    cin >> T;
    while (T--){
        int N;
        cin >> N;

        vector<vector<int>> left(N+1);
        vector<vector<int>> right(N+1);
        ll ans = 0;
        REP(i, N){
            int k, l, r;
            cin >> k >> l >> r;
            if (l > r){
                left[k].emplace_back(l-r);
                ans += r;
            } else {
                right[N-k].emplace_back(r-l);
                ans += l;
            }
        }

        priority_queue<int, vector<int>, greater<int>> pq_l, pq_r;

        REP(k, N+1){
            for (auto x: left[k]){
                pq_l.emplace(x);
                ans += x;
            }

            while (pq_l.size() > k){
                ll x = pq_l.top(); pq_l.pop();
                ans -= x;
            }
        }

        REP(k, N+1){
            for (auto x: right[k]){
                pq_r.emplace(x);
                ans += x;
            }

            while (pq_r.size() > k){
                ll x = pq_r.top(); pq_r.pop();
                ans -= x;
            }
        }

        print(ans);
    }


    return 0;
}
