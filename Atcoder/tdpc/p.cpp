// tdpc_p

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i, n) for (int i = 0 ; i < n ; i++)
#define INF (1 << 31)-1
#define MOD 
int main() {
    std::ifstream in("../arg.txt");
    std::cin.rdbuf(in.rdbuf());

    int k;
    cin >> k;
    cout << (k / 2) * (k / 2 + k % 2) << endl;
    return 0;
}

