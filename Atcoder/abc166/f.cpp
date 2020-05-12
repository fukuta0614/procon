// abc166_f
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
#define print_line(vec, n) {for(int i=0;i<(n-1);i++) cout << (vec)[i] << " "; cout << (vec)[(n)-1] << endl;}
template<class T> void print(const T& x){cout << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N, A, B, C;
    cin >> N >> A >> B >> C;

    map<string, int> mp;
    mp["AB"] = 0;
    mp["BC"] = 1;
    mp["AC"] = 2;

    vector<int> Q(N);
    REP(i, N) {
        string S;
        cin >> S;
        Q[i] = mp[S];
    }

    vector<int> card{A, B, C};
    string abc = "ABC";
    vector<char> ans;

    REP(i, N){
        int x = Q[i];
        int y = (Q[i] + 1) % 3;

        if (card[x] == 0 && card[y] == 0){
            print("No");
            return 0;
        } else if (card[x] == 0){
            card[x]++; card[y]--;
            ans.emplace_back(abc[x]);
        } else if (card[y] == 0){
            card[y]++; card[x]--;
            ans.emplace_back(abc[y]);
        } else {
            if (i == N-1){
                card[x]++; card[y]--;
                ans.emplace_back(abc[x]);
            } else {
                int nx = Q[i+1];
                if ((3 + nx - x) % 3 == 2){
                    card[x]++; card[y]--;
                    ans.emplace_back(abc[x]);
                } else {
                    card[y]++; card[x]--;
                    ans.emplace_back(abc[y]);
                }
            }
        }
    }

    print("Yes");
    REP(i, N){
        print(ans[i]);
    }

    return 0;
}
