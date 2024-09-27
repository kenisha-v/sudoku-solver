#include "sudoku.h"

int UNSOLVED = 81;
int SIZE_ROWS = 9;
int SIZE_COLUMNS = 9;


int main(){

    int** puzzle; 
    Square *** sudoku;

    puzzle = create_puzzle();
    sudoku = setUpPuzzle(puzzle);
    printpuzzle(sudoku);
 
    checkPuzzle(sudoku);
    printf("\n\n"); 
    printpuzzle(sudoku);


    return 0;   
}