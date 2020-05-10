#ifndef _SCORE_H_
#define _SCORE_H_

#include <vector>
#include "board.h"
using namespace std;

class Single; 

class score {
    public:

    // calculates score at the end of the game
    int calcScore (vector<vector<Single*>> gameBoard);


};

#endif