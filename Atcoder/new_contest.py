import sys, os


contest_name = sys.argv[1]
if len(sys.argv) == 3:
    alphabets = "abcdefghijklmnopqrstuvwxyz"
    questions = [ alphabets[i] for i in range(int(sys.argv[2]))]
else:
    questions = ['a', 'b', 'c', 'd']

os.mkdir(contest_name)


# input file
with open(os.path.join(contest_name, 'arg.txt'), 'w') as f:
    f.write('')

# python script
content = '''
from itertools import combinations
from itertools import product
import bisect
import math

N = int(input())
N, K = [int(_) for _ in input().split()]
T = [[int(_) for _ in input().split()] for i in range(N)]
'''

for q in questions:
    with open(os.path.join(contest_name, '{}.py'.format(q)), 'w') as f:
        f.write(content)


# make CmakeLists.txt
version = 3.10
head = ["cmake_minimum_required(VERSION {})\n".format(version),
        "project({})\n".format(contest_name),
        "set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -std=c++11)\n",
        "\n"]

executable = ["{}_{}".format(contest_name, q) for q in questions]  # ex) ABC104_C

text_list = ["add_executable({} {}.cpp)\n".format(exe, exe.split('_')[-1]) for exe in executable]
output = head + text_list  # CMakeLists.txt に書き込むリスト

with open(os.path.join(contest_name, "CMakeLists.txt"), "w") as file:
    file.writelines(output)  # リスト型変数を改行なしでファイルに書き込む


content = '''
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define debug(x) cout << #x << ": " << (x) << endl
#define REP(i, n) for (int (i) = 0 ; (i) < (int)(n) ; ++(i))
#define REPN(i, m, n) for (int (i) = m ; (i) < (int)(n) ; ++(i))
#define REP_REV(i, n) for (int (i) = (int)(n) - 1 ; (i) >= 0 ; --(i))
#define INF ((1 << 16)-1)
#define MOD (1000000007)
#define print(arr, n) REP(i, n) cout << arr[i] << " ";

int main() {
    std::ifstream in("../arg.txt");
    std::cin.rdbuf(in.rdbuf());

    int N;
    cin >> N;

    return 0;
}


'''
# make .cpp
for exe in executable:
    with open(os.path.join(contest_name, "{}.cpp".format(exe.split('_')[-1])), "w") as cpp_file:
        cpp_file.write("// {}".format(exe))
        cpp_file.write(content)


