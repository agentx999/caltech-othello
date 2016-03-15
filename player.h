#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <iostream>
#include "common.h"
#include "board.h"
using namespace std;

class Player {

public:
    Player(Side side);
    ~Player();
    
    Move *doMove(Move *opponentsMove, int msLeft);
    int minimax(Move *move, Board *current, int depth, bool player);
    double minimax2(Move *move, Board *current, int depth, int score, int ply);
    // Flag to tell if the player is running within the test_minimax context
    bool testingMinimax;
    Side side;
    Board *board;
};

#endif
