#ifndef _BOARD_H_
#define _BOARD_H_

//#include <utility>
#include <vector>
//#include "single.h"
#include "score.h"
using namespace std; 


class board{
private:
   
    
    score calculator;
        
    
    

    
public:
    class Single{
    public:
        int x;
        int y;
        int borw; //0 is empty, 1 is black(O), 2 is white(X)
        bool checked;

        Single(int x, int y) {
            this->x = x;
            this->y = y;
            borw = 0;
            checked = false;
        }

    };
    class myexception: public exception {

    } myex;

    // builds a board size x size dimensions
    board(); 

    // places a piece on the board, black: color = 1, white: color = 2
    void makeMove(int x, int y, int color);

    // calculates dead pieces and removes them 
    void checkDead(int x, int y, int color);
        
    // prints board
    void printBoard();

    vector<vector<Single*>> goBoard;
    int size; 
};

#endif