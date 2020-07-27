#include "score.h"
#include "board.h"
#include <iostream>
#include <list>
using namespace std;

score::score() {
    blackScore = 0;
    whiteScore = 0;
    size = 9;
    scoreChart.resize(size);
    // for (int i = 0; i < size; i++) {
    //     goBoard[i].resize(size);
    // }
    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            
            scoreChart[y].push_back(0);
        }
    }
}

void score::addScoreToColor(int color) {
    
    // if (color == 1) {
    //     blackScore = blackScore + 1;
    // } else if (color == 2) {
    //     whiteScore = whiteScore + 1;
    // }
}

void score::printScore() {
    cout << "Black score: " << blackScore << "   White score: " << whiteScore << "\n";
}

void score::calcScore(board gameBoard) {
    
     for (int y = 0; y < gameBoard.goBoard.size(); y++) {
        for (int x = 0; x < gameBoard.goBoard[y].size(); x++) {
            if (!gameBoard.goBoard[y][x]->checked && gameBoard.goBoard[y][x]->borw == 1) {
                list<board::Single*> queue;
                list<board::Single*> removedList;
   
                gameBoard.goBoard[y][x]->checked = true;
                queue.emplace_back(gameBoard.goBoard[y][x]);
 
                while (!queue.empty() ) {    
                    board::Single* s = queue.front();
                    removedList.emplace_back(s);
                    s->checked = true;
                    scoreChart[s->y][s->x] = 1;
                          
                    queue.pop_front();
                    if (s->y > 0) {

                        if ((gameBoard.goBoard[s->y-1][s->x]->borw == 1 ||  gameBoard.goBoard[s->y-1][s->x]->borw == 0 ) && gameBoard.goBoard[s->y-1][s->x]->checked != true) {
                            queue.emplace_back(gameBoard.goBoard[s->y-1][s->x]);
                        }
                    } 
                    if (s->x > 0) {
                        if ((gameBoard.goBoard[s->y][s->x-1]->borw == 1 || gameBoard.goBoard[s->y][s->x-1]->borw == 0) && gameBoard.goBoard[s->y][s->x-1]->checked != true) {
                            queue.emplace_back(gameBoard.goBoard[s->y][s->x-1]);
                        }
                    }
                    if (s->y < size - 1) {
             
                        if ((gameBoard.goBoard[s->y+1][s->x]->borw == 1 || gameBoard.goBoard[s->y+1][s->x]->borw == 0) && gameBoard.goBoard[s->y+1][s->x]->checked != true) {
                            queue.emplace_back(gameBoard.goBoard[s->y+1][s->x]);
                        }
                    } 
                    if (s->x < size - 1) {
                        if ((gameBoard.goBoard[s->y][s->x+1]->borw == 1 || gameBoard.goBoard[s->y][s->x+1]->borw == 0) && gameBoard.goBoard[s->y][s->x+1]->checked != true) {
                            queue.emplace_back(gameBoard.goBoard[s->y][s->x+1]);
                        }
                    } 
        

                 }
    

            } else if (!gameBoard.goBoard[y][x]->checked && gameBoard.goBoard[y][x]->borw == 2) {
                
                list<board::Single*> queue2;
                list<board::Single*> removedList;
   
                gameBoard.goBoard[y][x]->checked = true;
                queue2.emplace_back(gameBoard.goBoard[y][x]);
 
                while (!queue2.empty() ) {    
                    board::Single* s = queue2.front();
                    removedList.emplace_back(s);
                    s->checked = true;
                    scoreChart[s->y][s->x] = 2;
                          
                    queue2.pop_front();
                    if (s->y > 0) {

                        if ((gameBoard.goBoard[s->y-1][s->x]->borw == 2 ||  gameBoard.goBoard[s->y-1][s->x]->borw == 0 ) && gameBoard.goBoard[s->y-1][s->x]->checked != true) {
                            queue2.emplace_back(gameBoard.goBoard[s->y-1][s->x]);
                        }
                    } 
                    if (s->x > 0) {
                        if ((gameBoard.goBoard[s->y][s->x-1]->borw == 2 || gameBoard.goBoard[s->y][s->x-1]->borw == 0) && gameBoard.goBoard[s->y][s->x-1]->checked != true) {
                            queue2.emplace_back(gameBoard.goBoard[s->y][s->x-1]);
                        }
                    }
                    if (s->y < size - 1) {
             
                        if ((gameBoard.goBoard[s->y+1][s->x]->borw == 2 || gameBoard.goBoard[s->y+1][s->x]->borw == 0) && gameBoard.goBoard[s->y+1][s->x]->checked != true) {
                            queue2.emplace_back(gameBoard.goBoard[s->y+1][s->x]);
                        }
                    } 
                    if (s->x < size - 1) {
                        if ((gameBoard.goBoard[s->y][s->x+1]->borw == 2 || gameBoard.goBoard[s->y][s->x+1]->borw == 0) && gameBoard.goBoard[s->y][s->x+1]->checked != true) {
                            queue2.emplace_back(gameBoard.goBoard[s->y][s->x+1]);
                        }
                    } 
        

                 }
    

            
            }
            
        }
    }
    for (int y = 0; y < scoreChart.size(); y++) {
        for (int x = 0; x < scoreChart.size(); x++) {
            if (scoreChart[y][x] == 1) {
                blackScore = blackScore + 1;
            } else {
                whiteScore = whiteScore + 1;
            }
            
        }
    }
}