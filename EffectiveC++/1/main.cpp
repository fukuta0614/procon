
#include "common.hpp"
#include "GamePlayer.hpp"



int main() {
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());

    GamePlayer a;
    const GamePlayer b;

    REP(i, a.getNumTurns()){
        print(a[i]);
    }

    REP(i, b.getNumTurns()){
        print(b[i]);
    }

    GamePlayer c(10);
    print(c.getNumTurns());

//    print(GamePlayer::eps);

    return 0;
}
