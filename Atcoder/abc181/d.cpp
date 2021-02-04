// abc181_d
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
#define CHAR2INT(c) (c - '0')


int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    string S;
    cin >> S;

    if (S.size() == 1){
        int a = CHAR2INT(S[0]);
        print((a % 8 == 0) ? "Yes" : "No");
        return 0;
    }

    if (S.size() == 2){
        int a = CHAR2INT(S[0]) * 10 + CHAR2INT(S[1]);
        int b = CHAR2INT(S[1]) * 10 + CHAR2INT(S[0]);
        print((a % 8 == 0) || (b % 8 == 0) ? "Yes" : "No");
        return 0;
    }

    map<int, int> count;
    REP(i, S.size()){
        int a = CHAR2INT(S[i]);
        count[a]++;
    }

    REP(i, 1000){
        if (i % 8 != 0) continue;

        int n = i;

        std::ostringstream ss;
        ss << std::setw(3) << std::setfill('0') << n;
        std::string s(ss.str());

        map<int, int> x;
        REP(j, 3){
            x[s[j] - '0']++;
        }
//        print(n, s, x);

        bool ok = true;
        for (auto e: x){
            if (count[e.first] < e.second) ok = false;
        }

        if (ok){
            print("Yes");
            return 0;
        }

    }

    print("No");


    return 0;
}
