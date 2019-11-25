// abc118_d
#include <bits/stdc++.h>
#ifdef LOCAL
#include "../cxx-prettyprint/prettyprint.hpp"
#endif
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;

#define REP(i, n) for (ll (i) = 0 ; (i) < (ll)(n) ; ++(i))
#define REPN(i, m, n) for (ll (i) = m ; (i) < (ll)(n) ; ++(i))
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

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N, M;
    cin >> N >> M;
    vector<int> A(M);
    REP(i, M) cin >> A[i];
    sort(ALL(A));

    vector<int> num{2, 5, 5, 4, 5, 6, 3, 7, 6};
    vector<P> candidates;
    REP(i, M){
        bool flag = true;
        for (auto &p: candidates){
            if (num[A[i]-1] == p.first){
                p.second = A[i];
                flag = false;
                break;
            }
        }
        if (flag){
            candidates.emplace_back(num[A[i]-1], A[i]);
        }
    }
    sort(ALL(candidates));

    vector<string> dp(100);
    dp[0] = "0";
    REPN(i, 1, candidates.size()){
        ll cnt = candidates[i].first;
        string n = to_string(candidates[i].second);
        REPN(j, cnt, 100){
            if (dp[j - cnt] == ""){
                continue;
            } else if (dp[j - cnt] == "0"){
                dp[j] = n;
            } else {
                dp[j] = dp[j - cnt] + n;
                sort(ALL(dp[j]), greater<char>());
            }
        }
    }
    dp[0] = "";


    string s = "";
    int tmp = N;
    int n = candidates[0].first;
    while (tmp - n >= 0){
        s += to_string(candidates[0].second);
        tmp -= n;
    }

    string ans = "";
    if (tmp == 0) {
        ans = s;
    } else{
        while (s != "" && tmp < 100) {
            if (dp[tmp] != ""){
                string t = dp[tmp] + s;
                sort(ALL(t), greater<char>());
                if (t.size() >= ans.size() && t >= ans){
                    ans = t;
                }
            }
            tmp += n;
            s = s.substr(1);
        }
    }

    sort(ALL(ans), greater<char>());
    print(ans);

    return 0;
}
