#include "board.h"
#include <iostream>
#include <list>
using namespace std;

//initializes a board of size dimensions
board::board() {
    size = 9;
    goBoard.resize(size);
    // for (int i = 0; i < size; i++) {
    //     goBoard[i].resize(size);
    // }
    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            Single * space = new Single(x, y);
            goBoard[y].push_back(space);
        }
    }
}

// places a piece on the board, black: color = 1, white: color = 2
void board::makeMove(int x, int y, int color) {
    checkDead(x, y , color);
    if (goBoard[y-1][x-1]->borw != 0) {
        throw myex;
    } else {
        goBoard[y-1][x-1]->borw = color;
        goBoard[y-1][x-1]->x = x-1;
        goBoard[y-1][x-1]->y = y-1;
    }
}

// calculates dead pieces and removes them 
void board::checkDead(int x, int y, int color) {
    list<Single*> queue;
    list<Single*> removedList;
    goBoard[y-1][x-1]->checked = true;
    queue.emplace_back(goBoard[y-1][x-1]);
    bool test; 

    while (!queue.empty() ) {
        //cout << " entered loop ";
        Single* s = queue.front();
        removedList.emplace_back(s);
        s->checked = true;
        
        if (s->y > 0) {
            

            if (goBoard[s->y-1][s->x]->borw == 0 && goBoard[s->y-1][s->x]->checked != true) {
               //cout << "break 1";

                break;
                
            }
        } 
        

        if (s->x > 0) {
            if (goBoard[s->y][s->x-1]->borw == 0 && goBoard[s->y][s->x-1]->checked != true) {
                //cout << "break 2";
                break;
            }
        }
        if (s->y < size) {
             if (goBoard[s->y+1][s->x]->borw == 0 && goBoard[s->y+1][s->x]->checked != true) {
                 //cout << "break 3";
                break;
            }
        } 
        if (s->x < size) {
             if (goBoard[s->y][s->x+1]->borw == 0 && goBoard[s->y][s->x+1]->checked != true) {
                 //cout << "break 4";
                break;
            }
        } 
        //cout << "didn't break";
        queue.pop_front();
        if (s->y > 0) {
            if (goBoard[s->y-1][s->x]->borw == color && goBoard[s->y-1][s->x]->checked != true) {
                queue.emplace_back(goBoard[s->y-1][s->x]);
            }
        } 
        if (s->x > 0) {
            if (goBoard[s->y][s->x-1]->borw == color && goBoard[s->y][s->x-1]->checked != true) {
                queue.emplace_back(goBoard[s->y][s->x-1]);
            }
        }
        if (s->y < size) {
            //cout << " inside if ";
            //cout << goBoard[s->y+1][s->x]->borw << color << goBoard[s->y+1][s->x]->checked;
             if (goBoard[s->y+1][s->x]->borw == color && goBoard[s->y+1][s->x]->checked != true) {
                 //cout << " twice";
                queue.emplace_back(goBoard[s->y+1][s->x]);
            }
        } 
        if (s->x < size) {
             if (goBoard[s->y][s->x+1]->borw == color && goBoard[s->y][s->x+1]->checked != true) {
                queue.emplace_back(goBoard[s->y][s->x+1]);
            }
        } 
        //cout << queue.size();

    }
    //cout << "removed list size: " << removedList.size();
    for (auto const& i : removedList) {
            //i->borw = 0;
            i->checked = false;
    }
    if (queue.empty()) {
        
        
        throw myex;
    }


}

// prints board
void board::printBoard() {
    int i = 1;
    cout << "   1   2   3   4   5   6   7   8   9 \n";
    for (int y = 0; y < size-1; y++) {
        cout << i << "  ";
        for (int x = 0; x < size - 1; x++) {
            if (goBoard[y][x]->borw == 0) {
                cout << " " << "---";
            } else if (goBoard[y][x]->borw == 1) {
                cout << "O" << "---";
            } else {
                cout << "X" << "---";
            }
            //cout << goBoard[y][x]->borw << "--";
        }
        if (goBoard[y][size-1]->borw == 0) {
                cout << " ";
            } else if (goBoard[y][size-1]->borw == 1) {
                cout << "O" ;
            } else {
                cout << "X" ;
        }
        //cout << goBoard[y][size-1]->borw;
        cout << "\n   ";
        for (int x = 0; x < size; x++) {
            cout <<"|   ";
        }
        cout << "\n";
        i++;
    }
    
    cout << i << "  "; 
    for (int x = 0; x < size - 1; x++) {
        if (goBoard[size-1][x]->borw == 0) {
                cout << " " << "---";
            } else if (goBoard[size-1][x]->borw == 1) {
                cout << "O" << "---";
            } else {
                cout << "X" << "---";
        }
        //cout << goBoard[size-1][x]->borw << "--";
    }
    if (goBoard[size-1][size-1]->borw == 0) {
                cout << " " ;
            } else if (goBoard[size-1][size-1]->borw == 1) {
                cout << "O" ;
            } else {
                cout << "X" ;
    }
    //cout << goBoard[size-1][ size -1] ->borw;
    cout << "\n";

}