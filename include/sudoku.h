#ifndef SUDOKU_H
#define SUDOKU_H

#include <stdio.h>
#include <stdlib.h>


extern int UNSOLVED;

extern int SIZE_ROWS;
extern int SIZE_COLUMNS;
 
typedef struct Box{
    struct Box * next;
}   Box;

typedef struct Square{
    int number;
    int possible[9];
    int solvable;
    Box * box;
    int row;
    int column;
}   Square;


int ** create_puzzle();
void printpuzzle(Square ***   puzzle);
Square *** setUpPuzzle(int ** puzzle);
int solveSquare(Square * square); 

int updateSudoku(Square *** sudoku, int row, int column);

int checkPuzzle(Square ***  sudoku);

#endif