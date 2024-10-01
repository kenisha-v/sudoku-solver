#include "sudoku.h"

int UNSOLVED = 81;
int SIZE_ROWS = 9;
int SIZE_COLUMNS = 9;


int main(){

    int** puzzle; 
    Sudoku  * sudoku;
    int progress; 

    puzzle = create_puzzle();
    sudoku = setUpPuzzle(puzzle);
    printpuzzle(sudoku->squares);
 

    while(UNSOLVED > 0){
        progress = checkPuzzle(sudoku->squares, sudoku->boxes);

        if(progress == 0){
            printf("Failed to solve the puzzle!\n\n");
            break;
        }

    }



    printf("\n\n"); 
    printpuzzle(sudoku->squares);


    return 0;   
}