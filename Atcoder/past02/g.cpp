// past02_g
#include <bits/stdc++.h>
#ifdef LOCAL
#include "../cxx-prettyprint/prettyprint.hpp"
#endif
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<char, ll> P;

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

    int Q;
    cin >> Q;

    deque<P> s;

    REP(_, Q){

        int t;
        cin >> t;

        if (t == 1){
            char c;
            ll x;
            cin >> c >> x;
            s.emplace_back(c, x);

        } else {
            ll d;
            cin >> d;

            map<char, ll> mp;
            ll cnt = 0;
            while (not s.empty()){
                P p = s.front();
                if (cnt + p.second <= d){
                    mp[p.first] += p.second;
                    cnt += p.second;
                    s.pop_front();
                } else {
                    mp[p.first] += (d - cnt);
                    s[0].second -= (d - cnt);
                    break;
                }
            }
//            print(mp);

            ll ans = 0;
            for (auto e: mp){
                ans += e.second * e.second;
            }
            print(ans);

        }

//        print(_, s);

    }

    return 0;
}
