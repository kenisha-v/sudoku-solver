#include "sudoku.h"


Box ** createBoxes(){

    int x,y;
    
    Box ** boxes;
    boxes = malloc(sizeof(Box*)*9);
    
    for(x = 0; x<9; x++){
        boxes[x] =  malloc(sizeof(Box));
        boxes[x]->squares = malloc(sizeof(Square*)*9);
        boxes[x]->numbers = 0;
        boxes[x]->solvable = 9 ;

        for(y = 0; y<9; y++){
        boxes[x]->possible[y] = 0;
        }

    }


    return boxes;
}


int updateBoxes(Square *** sudoku, int row, int coloumn){
    int x;
    int number = sudoku[row][coloumn]->number;

    Box * box;
    box = sudoku[row][coloumn]->box;

    for(x = 0; x < 9; x++){
        if(box->squares[x]->possible[number - 1] == 0){
            box->squares[x]->solvable--;
            box->squares[x]->possible[number - 1] = 1;
        }
    }

}

int boxSingles(Square *** sudoku, Box ** boxes){
    int i, j, x;
    int count;
    int temp;

    for(i = 0; i<9; i++){ // loop for the boxes

        for(j = 0; j<9; j++){ // loop through the possible array

            count = 0;

            for(x = 0; x<9; x++){ // loop through the squares

                if(boxes[i]->squares[x]->number != 0){
                    continue;

                    if(boxes[i]->squares[x]->possible[j] == 0){
                        count++;
                        temp = x;
                    }
                    if(count == 2){
                        break;
                    }
                }

                if(count == 1){
                    boxes[i]->squares[x]->number = j;
                    UNSOLVED--;
                    boxes[i]->squares[temp]->solvable = 0; 

                    updateSudoku(sudoku, boxes[i]->squares[temp]->row, boxes[i]->squares[temp]->column);
                    return 1;
                }
            }
        } 

    }

    return 0;
}
