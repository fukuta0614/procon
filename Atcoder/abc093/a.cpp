//
// Created by P218024 on 2018/04/20.
//
//
// Created by P218024 on 2018/04/20.
//

#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int (i)=0; (i)<(int)(n); (i)++)
#define REPN(i, m, n) for(int (i)=(int)(m); (i)<(int)(n); (i)++)
#define REP_REV(i, n) for(int (i)=(int)(n)-1; (i)>=0; (i)--)
#define debug(x) cout << #x << ": " << (x) << endl;


int main() {
    ifstream in("C:\\Users\\P218024\\Documents\\Cpp Projects\\abc093\\sample.txt");
    cin.rdbuf(in.rdbuf());

    char a, b, c;
    cin >> a >> b >> c;

    cout << ((a == b || b == c || c == a) ? "NO" : "YES");

    return 0;
}