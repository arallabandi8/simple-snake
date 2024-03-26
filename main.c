#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "game.h"

int main(){
    printf("\e[1;1H\e[2J"); // clear the area, make it seem more professional

    // important variable declarations
    int rows, cols;
    int cool = 0;
    char post[3], inputStr[20];

    // user prompts and info gathering
    printf("WELCOME TO SIMPLE SNAKE!!!\n");
    sleep(2); // for style :)
    printf("Please enter the grid size (rows columns): ");
    while(cool != 1){
        fgets(inputStr,10,stdin);
        if(sscanf(inputStr, "%d %d%2s", &rows, &cols, post) != 2){
            printf("Invalid input, try again.");
        }
        else{
            cool = 1;
        }
    }

    // prepare the board
    if (seedGen(rows, cols) == 0){
        printf("Error generating seed. Exiting...");
        return -1;
    }
    int ** game = newGame(rows, cols); // game board

    printf("Ready to play in 3...\n");
    sleep(1);
    printf("2...\n");
    sleep(1);
    printf("1...\n");
    sleep(1);

    return 0;
}