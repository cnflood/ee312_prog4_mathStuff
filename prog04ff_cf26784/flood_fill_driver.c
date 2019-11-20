//
// Created by flood on 10/16/2019.
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "flood_fill.h"
int main(int argc, char *argv[]) {
    int row;
    int col;
    //char fName[]= "grid.txt";
    char fName[strlen(argv[1])];
    strcpy(fName, argv[1]);
    const int MAX_ROWS = 25;
    char *picture[MAX_ROWS];
    int numRows;
    int numCols;
    char color;
    char prevColor;
    bool finished = false;
    while(!finished) {
        loadPicture(fName, picture, &numRows, &numCols);
        displayPicture(picture, numRows, numCols);
        printf("Enter row\n");
        scanf(" %d", &row);
        if (row < 25 && row>=0) {
            printf("Enter column\n");
            scanf(" %d", &col);
            prevColor = picture[row][col];
            printf("Enter color\n");
            scanf(" %c", &color);
            if (col < 25 && col >= 0) {
                floodFill(picture, numRows, numCols, row, col, color, prevColor);
                displayPicture(picture, numRows, numCols);
                int i;
                for(i=0; i<numRows;i++) {
                    free(picture[i]);
                }
            }
        }
        else if (row == -1 || col == -1){
            finished = true;
            int i;
            for(i=0; i<numRows;i++) {
                free(picture[i]);
            }
        }
        else {
            printf("Invalid Input, Try Again!\n");
            int i;
            for(i=0; i<numRows;i++) {
                free(picture[i]);
            }
        }
    }
}


