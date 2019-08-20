// abc127_f
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


int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int Q;
    cin >> Q;

    ll cumsum_l = 0;
    ll cumsum_r = 0;
    priority_queue<int> pq_l;
    priority_queue<int, vector<int>, greater<int>> pq_r;

    ll C = 0;
    ll mid = INF;

    int t;
    int a, b;
    REP(q, Q){
        cin >> t;
        int n =  pq_l.size() + pq_r.size();

        if (t == 1){
            cin >> a >> b;
            C += b; //定数

            if (a <= mid){
                pq_l.push(a);
                cumsum_l += a;
            } else {
                pq_r.push(a);
                cumsum_r += a;
            }

            if (pq_l.size() < pq_r.size()){  // 右のほうが多くなったら
                int x = pq_r.top(); pq_r.pop();
                cumsum_r -= x;
                pq_l.push(x);
                cumsum_l += x;
            } else if (pq_r.size() < pq_l.size() - 1){ // 左のほうが多くなったら
                int x = pq_l.top(); pq_l.pop();
                cumsum_l -= x;
                pq_r.push(x);
                cumsum_r += x;
            }
            mid = pq_l.top();

        } else {
            ll ans;
            if (n % 2 == 0){
                ans = cumsum_r - cumsum_l + C;
            } else {
                ans = mid + cumsum_r - cumsum_l + C;
            }

            print(mid, ans);
        }
    }



    return 0;
}
