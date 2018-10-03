//
// Created by Fukuta Keisuke on 1/21/18.
//

#include <bits/stdc++.h>

using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define SHOW_ALL_VALUABLES() cout << "a = " << a << endl << "b = " << b << endl << "c = " << c << endl

int main() {
    ifstream cin("robert/args.txt");

    int a, b;
    cin>>a>>b;
    cout << a - b << endl;
}