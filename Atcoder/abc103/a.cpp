// abc103_a
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define REP(i, n) for (int (i) = 0 ; (i) < (int)(n) ; ++(i))

int main() {
#ifdef LOCAL
    std::ifstream in("../arg.txt");
    std::cin.rdbuf(in.rdbuf());
#endif

    ull X,Y;
    cin >> X >> Y;

    int n=0;
    ull tmp = X;
    for (n=0;tmp<=Y;tmp*=2, n++){}
    cout << n << endl;

    return 0;
}


