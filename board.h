#ifndef __BOARD_H__
#define __BOARD_H__

#include <bitset>
#include "common.h"
using namespace std;

class Board {
   
private:
    bitset<64> black;
    bitset<64> taken;    
       
    bool get(Side side, int x, int y);
    void set(Side side, int x, int y);
      
public:
    Board();
    ~Board();
    Board *copy();
        
    bool isDone();
    bool hasMoves(Side side);
    bool checkMove(Move *m, Side side);
    bool onBoard(int x, int y);
    bool occupied(int x, int y);
    void doMove(Move *m, Side side);
    int count(Side side);
    int countBlack();
    int countWhite();

    void setBoard(char data[]);

    int scores[8][8];
};

#endif
