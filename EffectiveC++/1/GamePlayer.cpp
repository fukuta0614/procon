//
// Created by 福田圭佑 on 2021/02/03.
//

#include "common.hpp"
#include "GamePlayer.hpp"

GamePlayer::GamePlayer() : scores{1,2,3,4,5}, NumTurns(5), parity(0) {

}

GamePlayer::GamePlayer(int numTurns) : scores{1,2,3,4,5}, NumTurns(numTurns), parity(0) {

}

int GamePlayer::getNumTurns() const {
    return NumTurns;
}

int& GamePlayer::operator[](int i) {
    parity = 1 - parity;

    print("non-const");
    return scores[i];
}

const int& GamePlayer::operator[](int i) const{
    parity = 1 - parity;

    print("const");
    return scores[i];
}



