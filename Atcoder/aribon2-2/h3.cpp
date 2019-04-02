#include <bits/stdc++.h>
using namespace std;
int main() {
#ifdef LOCAL
    std::ifstream in("../arg.txt");
    std::cin.rdbuf(in.rdbuf());
#endif
    int n, k;
    string s, t, u;
    cin >> n >> k >> s;
    t = s;
    for (int i = 0; i < n; i++) {
        int x = i;
        for (int j = i+1; j < n; j++) {
            if (t[x] > t[j]) {
                u = t;
                swap(u[i], u[j]);
                int cnt = 0;
                for (int l = 0; l < n; l++) if (s[l] != u[l]) cnt++;
                if (cnt <= k) x = j;
            }
        }
        swap(t[i], t[x]);
    }
    cout << t << endl;
    return 0;
}
//5 4
//bcdba
//bcdab
