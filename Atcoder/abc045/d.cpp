// abc045_d
#include <bits/stdc++.h>
#ifdef LOCAL
#include "../cxx-prettyprint/prettyprint.hpp"
#endif
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

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

int dx[9]={ 0, 1, 0, -1, 0, -1, 1, -1, 1};
int dy[9]={ 0, 0, 1, 0, -1, -1, -1, 1, 1};

int main() {
#ifdef LOCAL
    ifstream in("../05.txt"); cin.rdbuf(in.rdbuf());
#endif

    ll H, W, N;
    cin >> H >> W >> N;

    if (N == 0){
        print((H-2)*(W-2));
        REP(i, 9) print(0);
        return 0;
    }

    vector<P> AB(N);
    REP(i, N) {
        cin >> AB[i].first >> AB[i].second;
        AB[i].first--; AB[i].second--;
    }

    // ここ座標圧縮したけど、x, y両方10^5になりうるのでだめだった。
    sort(ALL(AB));
    ll h_margin = min(3ll, H-1 - AB[N-1].first);

    ll prev_x = 0;
    ll prev_origin_x = 0;
    REP(i, N){
        ll tmp = AB[i].first;
        AB[i].first = prev_x + min(3ll, AB[i].first - prev_origin_x);
        prev_x = AB[i].first;
        prev_origin_x = tmp;
    }
    ll h = AB[N-1].first + 1 + h_margin;

    sort(ALL(AB), [](const P& a, const P& b) {return a.second < b.second;});
    ll w_margin = min(3ll, W-1 - AB[N-1].second);

    ll prev_y = 0;
    ll prev_origin_y = 0;
    REP(i, N){
        ll tmp = AB[i].second;
        AB[i].second = prev_y + min(3ll, AB[i].second - prev_origin_y);
        prev_y = AB[i].second;
        prev_origin_y = tmp;
    }
    ll w = AB[N-1].second + 1 + w_margin;
    // ここまでいらんかった。

    set<P> st(ALL(AB));
    set<P> used;
    vector<ll> ans(10);
    for (auto p: st){
        ll i = p.first;
        ll j = p.second;
        REP(k, 9) {
            ll ni = i+dx[k];
            ll nj = j+dy[k];

            P nx = {ni, nj};
            if (used.find(nx) != used.end()) continue;
            used.insert(nx);

            if (ni >= 1 && ni < h-1 && nj >= 1 && nj < w-1) {
                int cnt = 0;
                REP(l, 9) {
                    P x = {ni+dx[l], nj+dy[l]};
                    if (st.find(x) != st.end()) cnt++;
                }
                ans[cnt]++;
                assert(cnt>0);
            }

        }
    }
    ans[0] = (H-2)*(W-2) - accumulate(ALL(ans), 0ll);
    REP(i, 10) print(ans[i]);

//    print(h, w);
//    print(AB);

//    vector<vector<int>> S(h, vector<int>(w, 0));
//    REP(i, N){
//        ll a = AB[i].first;
//        ll b = AB[i].second;
//        S[a][b] = 1;
//    }

//    REP(i, h) print(S[i]);

//    vector<ll> ans(10);
//    REPN(i, 1, h-1) REPN(j, 1, w-1){
//
//        int cnt=0;
//        REP(k, 9) cnt += S[i+dx[k]][j+dy[k]];
//
//        if (cnt > 0) ans[cnt]++;
//    }
//
//    ans[0] = (H-2)*(W-2) - accumulate(ALL(ans), 0ll);
//
//    REP(i, 10) print(ans[i]);


    return 0;
}
