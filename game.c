int ** newGame(int rows, int cols){
    printf("Generating board...");
    int game[++rows][++cols]; // game board 2D array created with 1 + given dimensions to account for walls
    // initialize board layout to be interpreted later by ____.
    // 0 is for an empty cell
    // 1 is for the apple
    // 2 is for a wall/barrier
    // -1 is for any cells part of the snake
    for (int i=0; i < rows; i++){
        for (int j=0; j<cols; j++){
            if (i == 0 || j == 0 || i == rows-1 || j == rows-1){game[i][j] = 2;} // set boundary cells to be walls
            else{game[i][j] = 0;} // set other cells to be empty
        }
    }

    // next, the initial positions of the 1st apple and snake have to be determined.
    // a random integer of range 0 to (rows-1)*(cols-1) will be used so that they do not
    // fall within a boundary
    int applePos = rand() % ((rows-1)*(cols-1));
    int snakePos = rand() % ((rows-1)*(cols-1));

    // compute the apple and snake positions
    applePos = posCalc(rows, cols, applePos);
    snakePos = posCalc(rows, cols, snakePos);
    // set the apple and snake positions finally
    **(game + applePos) = 1;
    **(game + snakePos) = -1;

    sleep(1);
    printf("OK.\n");
    return game[0][0];
}

/* Returns a random integer to be used as the seed in any calls of the srand
function. Important for the placement of the "apple" in the game.
INPUTS: one-an int, two-an int
OUTPUT: 1 if success, 0 if fail*/
int seedGen(int one, int two){
    printf("Generating seed..."); // cool message to seem cool
    int formula = (int) ((int) log(one))*((int) log(two)) / (one*two); // super complex dumb formula
    srand(formula); // set the seed for randomness
    printf("OK.\n");
    return 1; // successful seed setting
}

/* A helper function used to calculate position with respect to the boundaries
of the board. The value is added to an initial position of (1,1) and adjusted
so that when it hits a wall, it goes to the next row.
INPUTS: rows, cols, max (the value needed to be added)
OUTPUT: the refined position WR2 boundaries*/
int posCalc(int rows, int cols, int max){
    int i = 1, j = 1; // start the x and y values at the 2nd row, 2nd column
    for (int a=0; a<max; a++){ 
        if (j == cols-2){ // should j have reached the end of the allowed space, move to next row
            j = 1, i++;
            if (i == rows-2){
                i = 1;
            }
        }
        else{
            j++; // otherwise, just increment column value
        }
    }
    return i*cols+j;
}