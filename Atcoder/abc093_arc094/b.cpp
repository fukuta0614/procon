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
#define REPN_REV(i, m, n) for(int (i)=(int)(n)-1; (i)>=m; (i)--)
#define debug(x) cout << #x << ": " << (x) << endl;


int main() {
    ifstream in("C:\\Users\\P218024\\Documents\\Cpp Projects\\abc093\\sample.txt");
    cin.rdbuf(in.rdbuf());

    int a, b, k;
    cin >> a >> b >> k;

    int i;
    REPN(i, a, min(a+k-1, b)+1) {
        cout << i << endl;
    }
    REPN(i, max(b-k+1, a), b+1){
        cout << i << endl;
    }

    return 0;
}