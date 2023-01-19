// abc203_e
#pragma GCC optimize ("O3")

#include <bits/stdc++.h>
#ifdef LOCAL
#include "../../debug_util/cxx-prettyprint/prettyprint.hpp"
#include "../../debug_util/rng.hpp"
#include "../../debug_util/timer.hpp"
#endif
using namespace std;

using ll = long long;
using ull = unsigned long long;
using P = pair<ll, ll>;

#define REP(i, n) for (int i = 0 ; i < (int)(n) ; ++i)
#define REPN(i, m, n) for (int i = m ; i < (int)(n) ; ++i)
#define REP_REV(i, n) for (int i = (int)(n) - 1 ; i >= 0 ; --i)
#define REPN_REV(i, m, n) for (int i = (int)(n) - 1 ; i >= m ; --i)
#define ALL(x) x.begin(), x.end()

#define INF (ll)(1e15)
#define MOD (1000000007)

#define print2D(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }
#define print_line(vec, n) {for(int idx=0;idx<(n-1);idx++) cout << (vec)[idx] << " "; cout << (vec)[(n)-1] << endl;}
template<class T> void print(const T& x){cout << x << "\n";}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
//struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

const int SQUARE = 0;
const int CIRCLE = 1;
struct Shape {
    int itsType;
    virtual void Draw();
};

class Square : public Shape {
    void Draw() override;
};

class Circle : public Shape {
    void Draw() override;
};

void DrawAllShapes(vector<Shape*>& shape_list){
    for (auto p: shape_list){
        p->Draw();
    }
}

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    ll N, M;
    cin >> N >> M;
    map<ll, set<ll>> mp;
    REP(i, M){
        ll x, y; cin >> x >> y;
        mp[x].emplace(y);
    }
//    print(mp);

    vector<P> range_list{{N, N+1}};
    for (auto& [i, st]: mp){

        vector<P> tmp;
//        print(i, range_list);
        for (auto r: range_list){

            if (r.second - r.first > 2 || st.find(r.first) == st.end()){

                if (st.find(r.first-1) != st.end()){
                    r.first -= 1;
                }
                if (st.find(r.second) != st.end()){
                    r.second += 1;
                }

                if (not tmp.empty() && r.first <= tmp.back().second){
                    tmp.back().second = r.second;
                } else {
                    tmp.emplace_back(r);
                }

            } else {

                if (st.find(r.first-1) != st.end()){
                    if (not tmp.empty() && r.first-1 <= tmp.back().second){
                        tmp.back().second = r.first;
                    } else {
                        tmp.emplace_back(r.first-1, r.first);
                    }
                }

                if (st.find(r.second) != st.end()){
                    tmp.emplace_back(r.second, r.second+1);
                }

            }
        }
        range_list = tmp;

//        print(i, range_list);
    }

    ll ans = 0;
    for (auto r: range_list){
        assert(r.first >= 0);
        assert(r.second <= 2*N+1);
        ans += r.second - r.first;
    }

    print(ans);



    return 0;
}
