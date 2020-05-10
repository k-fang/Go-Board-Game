#define CATCH_CONFIG_MAIN

#include <vector>
#include <iostream>
#include "catch.hpp"
#include "board.cpp"

using namespace std;

//class board;

TEST_CASE ("board::empty board") {
    board testBoard;

    for (int y = 0; y < testBoard.size; y++) {
        for (int x = 0; x < testBoard.size; x++) {
            REQUIRE(testBoard.goBoard[y][x]->borw == 0);
            REQUIRE(testBoard.goBoard[y][x]->x == x);
            REQUIRE(testBoard.goBoard[y][x]->y == y);
        }
    }
}

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