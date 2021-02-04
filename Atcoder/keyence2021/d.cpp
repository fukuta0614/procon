// keyence2021_d
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
#define print_line(vec, n) {for(int idx=0;idx<(n-1);idx++) cout << (vec)[idx] << " "; cout << (vec)[(n)-1] << endl;}
template<class T> void print(const T& x){cout << x << "\n";}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}

ll lcm(ll a, ll b) { return a * b / gcd(a, b);}
int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N;
    cin >> N;

    if (N == 1){
        print(1);
        print("AB");
        return 0;
    }

    int n = 1 << N;
    vector<string> ans;

//    int d = (int)lcm(n-1, n/2-1);
//    int x = 1;
//    REP(i, d){
//        unordered_set<int> v;
//        REP(k, n/2 - 1) {
//            v.emplace(x);
//            x = x == n-1 ? 1 : x + 1;
//        }
//
//        string s = "A";
//        REPN(k, 1, n){
//            if (v.count(k)){
//                s += "A";
//            } else {
//                s += "B";
//            }
//        }
//
//        ans.emplace_back(s);
//    }

//    REP(x, 1<<16){
//        if (__builtin_popcount(x) != 8) continue;
//
//        string s = "";
//        REP(i, 16){
//            if ((x >> i) & 1){
//                s += "A";
//            } else {
//                s += "B";
//            }
//        }
//        ans.emplace_back(s);
//    }

    int d = (int)lcm(n-1, n/2-1);
    int diff = 1;
    REP(i, d){
        unordered_set<int> v;
        int x = 1;
        REP(k, n/2 - 1) {
            v.emplace(x);
            x = (x + diff) % n;
        }
        diff++;

        string s = "A";
        REPN(k, 1, n){
            if (v.count(k)){
                s += "A";
            } else {
                s += "B";
            }
        }

        ans.emplace_back(s);
    }

    print(d);
    REP(i, d) print(ans[i]);

    REP(m, n){
        vector<int> test(n);
        REP(k, d){
            REP(i, n){
                if (i != m && ans[k][i] == ans[k][m]){
                    test[i]++;
                }
            }
        }
        print(test);
    }



    return 0;
}
