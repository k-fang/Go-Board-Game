#include "board.cpp"
#include <iostream>

#include <algorithm>
using namespace std;

int case_insensitive_match(string s1, string s2) {
   //convert s1 and s2 into lower case strings
   transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
   transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
   if(s1.compare(s2) == 0)
      return 1; //The strings are same
   return 0; //not matched
}

int main() {
    bool cont = true;
    int color = 1; //black has first move
    int x;
    int y;
    string pass; 
    bool onePass = false;
    board gameBoard; 
    
    while (cont) {
        gameBoard.printBoard();
        if (color == 1) {
            cout << "Black, ";
        } else {
            cout << "White, ";
        }
        cout << "would you like to pass(type yes or no) ";
        cin >> pass;
        if (case_insensitive_match(pass, "yes")) {
            if (onePass) {
                cont = false;
            } else {
                onePass = true;
            }
            if (color == 1) {
                color = 2;
            } else {
                color = 1;
            }
        } else if (case_insensitive_match(pass, "no")) {
            
            cout << "Enter the x coordinate of your move: " ;
            cin >> x;
        
            cout << "Enter the y coordinate of your move: ";
            cin >> y;
            try {
                //gameBoard.checkDead(x, y, color);

                gameBoard.makeMove(x, y, color);
                onePass = false;
                
                if (color == 1) {
                    color = 2;
                } else {
                    color = 1;
                }
                
                
            } catch (exception& e) {
                cout << "That move is not legal, try again. \n";
                
            }
        } else {
            cout << "That wasn't a valid option! \n";
        }
        

    }
}
