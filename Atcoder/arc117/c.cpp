// arc117_c
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
using P = pair<int, int>;

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

void solve() {

    int N;
    cin >> N;
    string C;
    cin >> C;

    map<char, int> mp{{'B', 0}, {'W', 1}, {'R', 2}};
    vector<char> rev{'B', 'W', 'R'};

    vector<int> color(N);
    REP(i, N) color[i] = mp[C[i]];

//    N = 9;
//    color = random_vector(3, N);

    ll x = 0;
    ll nCk = 1;
    ll n3 = 0;
    REP(i, N){
        print(i, n3, nCk);

        x += nCk * color[i];
        x %= 3;

        int a = (N - 1 - i);
        if (a % 3 == 0){
            while (a > 0 && a % 3 == 0){
                n3++;
                a /= 3;
            }
        }
        nCk *= a;

        int b = i+1;
        if (b % 3 == 0){
            while (b > 0 && b % 3 == 0){
                n3--;
                b /= 3;
            }
        }
        nCk /= b;

        nCk %= 3;
    }

    if (N % 2 == 0){
        x = (3 - (x%3));
    }

    char ans = rev[x];
    print(ans);

    auto func = [](vector<int>& v){
        int n = v.size();
        REPN_REV(l, 1, n){
            auto prev = v;
            v.clear();
            REP(i, l){
                v.emplace_back((6 - prev[i] - prev[i+1]) % 3);
            }
        }
        return v[0];
    };

    char ans2 = rev[func(color)];
    print(ans2);

}


int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    solve();

    return 0;
}
