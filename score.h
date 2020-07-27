#ifndef _SCORE_H_
#define _SCORE_H_

#include <vector>
#include "board.h"
using namespace std;

class Single; 

class score {
    public:
    int blackScore;
    int whiteScore;
    vector<vector<int>> scoreChart;
    int size; // make sure is the same size as in board.h

    // initializes score at 0
    score();

    // adds score to color (1 for black, 2 for white)
    void addScoreToColor(int color); 
    
    // prints current score for both colors
    void printScore();

    // calculates score at the end of the game
    void calcScore (board gameBoard);


};

#endif