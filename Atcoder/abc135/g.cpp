// abc135_f
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

    string S;
    cin >> S;

    deque<char> tmp(ALL(S));
    tmp.push_front(' ');
    print(tmp);

    {
        vector<int> A(S.size()+1, 0);
        A[0] = -1;
        int j = -1;
        for (int i = 0; i < S.size(); i++) {
            while (j >= 0 && S[i] != S[j]) j = A[j];

            j++;
            A[i+1] = j;
        }
        print(A);
    }

    {
        vector<int> A(S.size()+1, 0);
        A[0] = -1;
        int j = -1;
        for (int i = 0; i < S.size(); i++) {
            while (j >= 0 && S[i] != S[j]) j = A[j];

            j++;
            // 元のコードでは A[i+1] = j;
            if (S[i + 1] == S[j]) A[i + 1] = A[j];
            else A[i + 1] = j;
        }
        print(A);
    }

    {
        vector<int> A(S.size()+1, 0);
        A[0] = 0;

        int j = 0;
        for (int i = 1; i < S.size()+1; i++)
        {
            if (S[i] == S[j])
            {
                A[i] = j++;
            }
            else
            {
                A[i] = j;
                j = 0;
            }
        }
        print(A);
    }



    return 0;
}
