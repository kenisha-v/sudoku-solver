#include "sudoku.h"

char POSSIBLE = 0x1FF;
int SIZE_ROWS = 9;
int SIZE_COLUMNS = 9;


int main(){

    int** puzzle; 
    Square *** sudoku;

    puzzle = create_puzzle();
    printpuzzle(puzzle);
    sudoku = setUpPuzzle(puzzle);

    return 0;   
}