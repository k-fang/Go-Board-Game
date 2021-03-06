#define CATCH_CONFIG_MAIN

#include <vector>
#include <iostream>
#include "catch.hpp"
#include "board.cpp"
#include "score.cpp"

using namespace std;

//class board;

// TEST_CASE ("board::empty board") {
//     board testBoard;

//     for (int y = 0; y < testBoard.size; y++) {
//         for (int x = 0; x < testBoard.size; x++) {
//             REQUIRE(testBoard.goBoard[y][x]->borw == 0);
//             REQUIRE(testBoard.goBoard[y][x]->x == x);
//             REQUIRE(testBoard.goBoard[y][x]->y == y);
//         }
//     }
// }

TEST_CASE ("board::place black") {
    board testBoard;
    testBoard.makeMove(1, 1, 1);
    REQUIRE(testBoard.goBoard[0][0]->borw == 1);

}

TEST_CASE ("board::place white") {
    board testBoard;
    testBoard.makeMove(1, 1, 2);
    REQUIRE(testBoard.goBoard[0][0]->borw == 2);

}

TEST_CASE ("board::place same spot") {
    board testBoard;
    testBoard.makeMove(1, 1, 1);
    try {
        testBoard.makeMove(1, 1, 2);
    } catch (exception& e) {
        REQUIRE(testBoard.goBoard[0][0]->borw == 1);
    }
    

}

TEST_CASE("board::surrounded illegal move single") {
    board testBoard;
    testBoard.makeMove(2, 1, 1);
    testBoard.makeMove(1, 2, 1);
    try {
        testBoard.makeMove(1, 1, 2);
    } catch (exception& e) {
        REQUIRE(testBoard.goBoard[0][0]->borw == 0);
    }
    testBoard.makeMove (1, 1, 1);
    REQUIRE(testBoard.goBoard[0][0]->borw == 1);
}

TEST_CASE ("board::surrounded illegal move multiple") {
    board testBoard;
    testBoard.makeMove(2, 1, 1);
    testBoard.makeMove(3, 1, 1);
    testBoard.makeMove(4, 1, 1);
    testBoard.makeMove(5, 2, 1);
    testBoard.makeMove(4, 3, 1);
    testBoard.makeMove(3, 3, 1);
    testBoard.makeMove(2, 3, 1);
    testBoard.makeMove(1, 2, 1);
    testBoard.makeMove(2, 2, 2);
    testBoard.makeMove(3, 2, 2);
    try {
        testBoard.makeMove(4, 2, 2);
    //    testBoard.printBoard();
        
    } catch (exception& e) {
        REQUIRE (testBoard.goBoard[1][3]->borw == 0);
    }
    //testBoard.printBoard();
    testBoard.makeMove(4, 2, 1);
    REQUIRE (testBoard.goBoard[1][3]->borw == 1);
    //testBoard.printBoard();
}

TEST_CASE ("board::captured stones from top edge case") {
    //cout << ("test 1");
    board testBoard;
    testBoard.makeMove(1, 9, 1);
    testBoard.makeMove(3, 9, 1);
    testBoard.makeMove(2, 9, 2);
    testBoard.makeMove(2, 8, 1);
    REQUIRE (testBoard.goBoard[8][1]->borw == 0);
    REQUIRE (testBoard.goBoard[8][0]->borw == 1);
    REQUIRE (testBoard.goBoard[8][2]->borw == 1);
    REQUIRE (testBoard.goBoard[7][1]->borw == 1);

}

TEST_CASE ("board::captured stones from top middle case") {
    board testBoard;
    testBoard.makeMove(2, 2, 2);
    testBoard.makeMove(1, 2, 1);
    testBoard.makeMove(2, 3, 1);
    testBoard.makeMove(3, 2, 1);
    testBoard.makeMove(2, 1, 1);
    REQUIRE (testBoard.goBoard[1][1]->borw == 0);
    REQUIRE (testBoard.goBoard[1][0]->borw == 1);
    REQUIRE (testBoard.goBoard[2][1]->borw == 1);
    REQUIRE (testBoard.goBoard[1][2]->borw == 1);
    REQUIRE (testBoard.goBoard[0][1]->borw == 1);

}

TEST_CASE ("board::captured stones from top middle case multiple") {
    board testBoard;
    testBoard.makeMove(2, 2, 2);
    testBoard.makeMove(1, 2, 2);
    testBoard.makeMove(2, 3, 2);
    testBoard.makeMove(3, 2, 2);
    testBoard.makeMove(2, 1, 2);
    testBoard.makeMove(3, 1, 1);
    testBoard.makeMove(4, 2, 1);
    testBoard.makeMove(3, 3, 1);
    testBoard.makeMove(2, 4, 1);
    testBoard.makeMove(1, 3, 1);
    testBoard.makeMove(1, 1, 1);
    REQUIRE (testBoard.goBoard[1][1]->borw == 0);
    REQUIRE (testBoard.goBoard[1][0]->borw == 0);
    REQUIRE (testBoard.goBoard[2][1]->borw == 0);
    REQUIRE (testBoard.goBoard[1][2]->borw == 0);
    REQUIRE (testBoard.goBoard[0][1]->borw == 0);
    //testBoard.printBoard();

}

TEST_CASE ("board::captured stones from left edge case") {
    //cout << ("test 1");
    board testBoard;
    testBoard.makeMove(9, 1, 1);
    testBoard.makeMove(9, 3, 1);
    testBoard.makeMove(9, 2, 2);
    testBoard.makeMove(8, 2, 1);
    REQUIRE (testBoard.goBoard[1][8]->borw == 0);
    REQUIRE (testBoard.goBoard[0][8]->borw == 1);
    REQUIRE (testBoard.goBoard[2][8]->borw == 1);
    REQUIRE (testBoard.goBoard[1][7]->borw == 1);

}

TEST_CASE ("board::captured stones from left middle case") {
    board testBoard;
    testBoard.makeMove(2, 2, 2);
    testBoard.makeMove(2, 1, 1);
    testBoard.makeMove(2, 3, 1);
    testBoard.makeMove(3, 2, 1);
    testBoard.makeMove(1, 2, 1);
    
    REQUIRE (testBoard.goBoard[1][1]->borw == 0);
    REQUIRE (testBoard.goBoard[1][0]->borw == 1);
    REQUIRE (testBoard.goBoard[2][1]->borw == 1);
    REQUIRE (testBoard.goBoard[1][2]->borw == 1);
    REQUIRE (testBoard.goBoard[0][1]->borw == 1);

}

TEST_CASE ("board::captured stones from left middle case multiple") {
    board testBoard;
    testBoard.makeMove(2, 2, 2);
    
    testBoard.makeMove(2, 3, 2);
    testBoard.makeMove(3, 2, 2);
    testBoard.makeMove(2, 1, 2);
    testBoard.makeMove(3, 1, 1);
    testBoard.makeMove(4, 2, 1);
    testBoard.makeMove(3, 3, 1);
    testBoard.makeMove(2, 4, 1);
    testBoard.makeMove(1, 3, 1);
    testBoard.makeMove(1, 1, 1);
    testBoard.makeMove(1, 2, 1);
    REQUIRE (testBoard.goBoard[1][1]->borw == 0);
    //REQUIRE (testBoard.goBoard[1][0]->borw == 0);
    REQUIRE (testBoard.goBoard[2][1]->borw == 0);
    REQUIRE (testBoard.goBoard[1][2]->borw == 0);
    REQUIRE (testBoard.goBoard[0][1]->borw == 0);
    //testBoard.printBoard();

}
TEST_CASE ("board::captured stones from right edge case") {
    //cout << ("test 1");
    board testBoard;
    testBoard.makeMove(1, 1, 1);
    testBoard.makeMove(1, 3, 1);
    testBoard.makeMove(1, 2, 2);
    testBoard.makeMove(2, 2, 1);
    REQUIRE (testBoard.goBoard[1][0]->borw == 0);
    REQUIRE (testBoard.goBoard[0][0]->borw == 1);
    REQUIRE (testBoard.goBoard[2][0]->borw == 1);
    REQUIRE (testBoard.goBoard[1][1]->borw == 1);

}

TEST_CASE ("board::captured stones from right middle case") {
    board testBoard;
    testBoard.makeMove(2, 2, 2);
    testBoard.makeMove(2, 1, 1);
    testBoard.makeMove(2, 3, 1);
    testBoard.makeMove(1, 2, 1);
    testBoard.makeMove(3, 2, 1);
    
    
    REQUIRE (testBoard.goBoard[1][1]->borw == 0);
    REQUIRE (testBoard.goBoard[1][0]->borw == 1);
    REQUIRE (testBoard.goBoard[2][1]->borw == 1);
    REQUIRE (testBoard.goBoard[1][2]->borw == 1);
    REQUIRE (testBoard.goBoard[0][1]->borw == 1);

}

TEST_CASE ("board::captured stones from right middle case multiple") {
    board testBoard;
    testBoard.makeMove(2, 2, 2);
    
    testBoard.makeMove(2, 3, 2);
    testBoard.makeMove(3, 2, 2);
    testBoard.makeMove(2, 1, 2);
    testBoard.makeMove(3, 1, 1);
    
    testBoard.makeMove(3, 3, 1);
    testBoard.makeMove(2, 4, 1);
    testBoard.makeMove(1, 3, 1);
    testBoard.makeMove(1, 1, 1);
    testBoard.makeMove(1, 2, 1);
    testBoard.makeMove(4, 2, 1);
    REQUIRE (testBoard.goBoard[1][1]->borw == 0);
    //REQUIRE (testBoard.goBoard[1][0]->borw == 0);
    REQUIRE (testBoard.goBoard[2][1]->borw == 0);
    REQUIRE (testBoard.goBoard[1][2]->borw == 0);
    REQUIRE (testBoard.goBoard[0][1]->borw == 0);
    //testBoard.printBoard();

}
TEST_CASE ("board::captured stones from bot edge case") {
    //cout << ("test 1");
    board testBoard;
    testBoard.makeMove(1, 9, 1);
    testBoard.makeMove(3, 9, 1);
    testBoard.makeMove(2, 9, 2);
    testBoard.makeMove(2, 8, 1);
    REQUIRE (testBoard.goBoard[8][1]->borw == 0);
    REQUIRE (testBoard.goBoard[8][0]->borw == 1);
    REQUIRE (testBoard.goBoard[8][2]->borw == 1);
    REQUIRE (testBoard.goBoard[7][1]->borw == 1);

}

TEST_CASE ("board::captured stones from bot middle case") {
    board testBoard;
    testBoard.makeMove(2, 2, 2);
    testBoard.makeMove(2, 1, 1);
    
    testBoard.makeMove(1, 2, 1);
    testBoard.makeMove(3, 2, 1);
    testBoard.makeMove(2, 3, 1);
    
    
    REQUIRE (testBoard.goBoard[1][1]->borw == 0);
    REQUIRE (testBoard.goBoard[1][0]->borw == 1);
    REQUIRE (testBoard.goBoard[2][1]->borw == 1);
    REQUIRE (testBoard.goBoard[1][2]->borw == 1);
    REQUIRE (testBoard.goBoard[0][1]->borw == 1);

}

TEST_CASE ("board::captured stones from bot middle case multiple") {
    board testBoard;
    testBoard.makeMove(2, 2, 2);
    
    testBoard.makeMove(2, 3, 2);
    testBoard.makeMove(3, 2, 2);
    testBoard.makeMove(2, 1, 2);
    testBoard.makeMove(3, 1, 1);
    
    testBoard.makeMove(3, 3, 1);
    
    testBoard.makeMove(1, 3, 1);
    testBoard.makeMove(1, 1, 1);
    testBoard.makeMove(1, 2, 1);
    testBoard.makeMove(4, 2, 1);
    testBoard.makeMove(2, 4, 1);
    REQUIRE (testBoard.goBoard[1][1]->borw == 0);
    //REQUIRE (testBoard.goBoard[1][0]->borw == 0);
    REQUIRE (testBoard.goBoard[2][1]->borw == 0);
    REQUIRE (testBoard.goBoard[1][2]->borw == 0);
    REQUIRE (testBoard.goBoard[0][1]->borw == 0);
    //testBoard.printBoard();

}

// TEST_CASE ("board::score test black") {
//     board testBoard;
//     testBoard.makeMove(2, 2, 2);
    
//     testBoard.makeMove(2, 3, 2);
//     testBoard.makeMove(3, 2, 2);
//     testBoard.makeMove(2, 1, 2);
//     testBoard.makeMove(3, 1, 1);
    
//     testBoard.makeMove(3, 3, 1);
    
//     testBoard.makeMove(1, 3, 1);
//     testBoard.makeMove(1, 1, 1);
//     testBoard.makeMove(1, 2, 1);
//     testBoard.makeMove(4, 2, 1);
//     testBoard.makeMove(2, 4, 1);
//     REQUIRE (testBoard.calculator.blackScore == 4);
// }

// TEST_CASE ("board::score test white") {
//     board testBoard;
//     testBoard.makeMove(2, 2, 1);
    
//     testBoard.makeMove(2, 3, 1);
//     testBoard.makeMove(3, 2, 1);
//     testBoard.makeMove(2, 1, 1);
//     testBoard.makeMove(3, 1, 2);
    
//     testBoard.makeMove(3, 3, 2);
    
//     testBoard.makeMove(1, 3, 2);
//     testBoard.makeMove(1, 1, 2);
//     testBoard.makeMove(1, 2, 2);
//     testBoard.makeMove(4, 2, 2);
//     testBoard.makeMove(2, 4, 2);
//     REQUIRE (testBoard.calculator.whiteScore == 4);
// }


TEST_CASE ("score::test basic") {
    board testBoard;
    score testScore;
    testBoard.makeMove (4, 1, 1);
    testBoard.makeMove (4, 2, 1);
    testBoard.makeMove (4, 3, 1);
    testBoard.makeMove (4, 4, 1);
    testBoard.makeMove (4, 5, 1);
    testBoard.makeMove (4, 6, 1);
    testBoard.makeMove (4, 7, 1);
    testBoard.makeMove (4, 8, 1);
    testBoard.makeMove (4, 9, 1);
    testBoard.makeMove (5, 1, 2);
    testBoard.makeMove (5, 2, 2);
    testBoard.makeMove (5, 3, 2);
    testBoard.makeMove (5, 4, 2);
    testBoard.makeMove (5, 5, 2);
    testBoard.makeMove (5, 6, 2);
    testBoard.makeMove (5, 7, 2);
    testBoard.makeMove (5, 8, 2);
    testBoard.makeMove (5, 9, 2);
    testScore.calcScore(testBoard);
    REQUIRE (testScore.whiteScore == 45);
    REQUIRE (testScore.blackScore == 36);
}

TEST_CASE ("score::test complex") {
    board testBoard;
    score testScore;
    testBoard.makeMove (6, 1, 1);
    testBoard.makeMove (6, 2, 1);
    testBoard.makeMove (6, 3, 1);
    testBoard.makeMove (6, 4, 1);
    testBoard.makeMove (6, 5, 1);
    testBoard.makeMove (6, 6, 1);
    testBoard.makeMove (6, 7, 1);
    testBoard.makeMove (5, 8, 1);
    testBoard.makeMove (5, 9, 1);
    testBoard.makeMove (2, 1, 1);
    testBoard.makeMove (2, 2, 1);
    testBoard.makeMove (1, 2, 1);
    testBoard.makeMove (2, 3, 1);
    testBoard.makeMove (2, 4, 1);
    testBoard.makeMove (1, 4, 1);
    testBoard.makeMove (5, 1, 2);
    testBoard.makeMove (5, 2, 2);
    testBoard.makeMove (5, 3, 2);
    testBoard.makeMove (5, 4, 2);
    testBoard.makeMove (5, 5, 2);
    testBoard.makeMove (5, 6, 2);
    testBoard.makeMove (5, 7, 2);
    testBoard.makeMove (4, 8, 2);
    testBoard.makeMove (4, 9, 2);
    
    testBoard.makeMove (3, 1, 2);
    testBoard.makeMove (3, 2, 2);
    testBoard.makeMove (3, 3, 2);
    testBoard.makeMove (3, 4, 2);
    testBoard.makeMove (1, 5, 2);
    testBoard.makeMove (2, 5, 2);

    testScore.calcScore(testBoard);
    REQUIRE (testScore.whiteScore == 35);
    REQUIRE (testScore.blackScore == 46);
}