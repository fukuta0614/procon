//
// Created by 福田圭佑 on 2021/02/03.
//

#ifndef EFFECTIVEC_TEST_HPP
#define EFFECTIVEC_TEST_HPP

class GamePlayer {

public:
    GamePlayer();

    explicit GamePlayer(int numTurns);

    int getNumTurns() const;

    int& operator[](int i);
    const int& operator[](int i) const;

//    static const double eps = 1e-5;
//    static const int eps = 0;

private:
//    static const int NumTurns = 5;
//    int scores[NumTurns];

//    const int NumTurns = 5;
    const int NumTurns;
    int scores[5];

    mutable int parity;

};

#endif //EFFECTIVEC_TEST_HPP
