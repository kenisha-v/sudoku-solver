#include "sudoku.h"


int main(){

    int** puzzle; 
    puzzle = create_puzzle();
    printpuzzle(puzzle);
    return 0;   
}