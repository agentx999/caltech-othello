#include "player.h"
#include <vector>
#include <stdlib.h>

/*
 * Constructor for the player; initialize everything here. The side your AI is
 * on (BLACK or WHITE) is passed in as "side". The constructor must finish 
 * within 30 seconds.
 */
Player::Player(Side side) {
    // Will be set to true in test_minimax.cpp.
    testingMinimax = false;
    
    /* 
     * TODO: Do any initialization you need to do here (setting up the board,
     * precalculating things, etc.) However, remember that you will only have
     * 30 seconds.
     */

     // Stores the current side
     this->side = side;
     // Creates a board (this is what the AI tracks)
     this->board = new Board();

     // ----CODE FOR RANDOM AI----
     // Initialize random seed (this is a test!)
     // srand(time(NULL));
}

/*
 * Destructor for the player.
 */
Player::~Player() {
    delete board;
}

/*
 * Compute the next move given the opponent's last move. Your AI is
 * expected to keep track of the board on its own. If this is the first move,
 * or if the opponent passed on the last move, then opponentsMove will be NULL.
 *
 * msLeft represents the time your AI has left for the total game, in
 * milliseconds. doMove() must take no longer than msLeft, or your AI will
 * be disqualified! An msLeft value of -1 indicates no time limit.
 *
 * The move returned must be legal; if there are no valid moves for your side,
 * return NULL.
 */
Move *Player::doMove(Move *opponentsMove, int msLeft) {
    /* 
     * TODO: Implement how moves your AI should play here. You should first
     * process the opponent's opponents move before calculating your own move
     */
    // Update board with opponent's move:
    Side opponentsSide = (side == BLACK) ? WHITE : BLACK;
    board->doMove(opponentsMove, opponentsSide); 
    std::vector<Move*> moves;
    std::vector<int> scores;
    // Checks to see if there are legal moves
    if (board->hasMoves(side)) 
    {
        // Very basic first outline:
        // Go through all possible legal moves
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                // Check for legality
                Move *currentMove = new Move(i, j);
                if (board->checkMove(currentMove, side))
                {
                    // Calculate this move's score (based on location)
                    int score = board->scores[i][j];
                    // Store them (in a vector?)
                    moves.push_back(currentMove);
                    scores.push_back(score);
                    // pushing back by same amount, so indices should be same?
                }
            }
        }

        // Go through the possible scores and find maximum
        // Find a better way to do this?
        int max_index = 0;
        int max = scores[0];
        for (unsigned int i = 0; i < scores.size(); i++)
        {
           if (scores[i] > max)
           {
              max = scores[i];
              max_index = i;
           }
        }
        Move *chosenMove = moves[max_index];
        
        
        // ----CODE FOR RANDOM AI---
        // Pick one at random
        // int randMove = rand() % possible_moves.size();
        // Move *chosenMove = possible_moves[randMove];

        // Update board with chosen move and return
        board->doMove(chosenMove, side);
        return chosenMove;
    }
    // No legal moves - passes
    return NULL;
}
