//
// Created by flood on 10/16/2019.
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "flood_fill.h"

void loadPicture(char fName[], char *grid[], int *numRows, int *numCols) {
    (*numRows) = 0;
    FILE *fptr;
    fptr = fopen(fName, "r");

    if(fptr == NULL) {
        printf("wrong\n");
        exit(-1);
    }
    else {
        //printf("success\n");
        char buf[25];
        while(fgets(buf, sizeof(buf), fptr)) {
            char *s = (char *)malloc(strlen(buf));
            strcpy(s, buf);
            grid[(*numRows)] =  s;
            *numCols = (strlen(buf)) - 1;
            (*numRows)++;
        }
        //printf("numRows is %d\n", *numRows);
        //printf("numCols is %d\n", *numCols);
    }
}

void displayPicture(char *grid[], int numRows, int numCols) {
    int i;
    int j;
    for(i=0; i<(numRows); i++) {
        for(j=0; j<numCols; j++) {
            printf("%c", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("\n");
}
void floodFill(char *grid[], int numRows, int numCols, int row, int col, char color, char prevColor) {
    if(row==0 && col==0){                                           //top left corner
        if (grid[row][col + 1] == prevColor) {
            grid[row][col + 1] = color;
            floodFill(grid, numRows, numCols, row, col+1, color, prevColor);
        }
        if (grid[row + 1][col] == prevColor) {
            grid[row + 1][col] = color;
            floodFill(grid, numRows, numCols, row+1, col, color, prevColor);
        }
        if (grid[row + 1][col + 1] == prevColor) {
            grid[row + 1][col + 1] = color;
            floodFill(grid, numRows, numCols, row+1, col+1, color, prevColor);
        }
    }
    if(row==0 && col==(numCols-1)){                                 //top right corner
        if (grid[row][col - 1] == prevColor) {
            grid[row][col - 1] = color;
            floodFill(grid, numRows, numCols, row, col-1, color, prevColor);
        }
        if (grid[row + 1][col - 1] == prevColor) {
            grid[row + 1][col - 1] = color;
            floodFill(grid, numRows, numCols, row+1, col-1, color, prevColor);
        }
        if (grid[row + 1][col] == prevColor) {
            grid[row + 1][col] = color;
            floodFill(grid, numRows, numCols, row+1, col, color, prevColor);
        }
    }
    if(row==0 && (col != 0) && (col != (numCols -1))){                //top row (not including corners)
        if (grid[row][col - 1] == prevColor) {
            grid[row][col - 1] = color;
            floodFill(grid, numRows, numCols, row, col-1, color, prevColor);
        }
        if (grid[row + 1][col - 1] == prevColor) {
            grid[row + 1][col - 1] = color;
            floodFill(grid, numRows, numCols, row+1, col-1, color, prevColor);
        }
        if (grid[row + 1][col] == prevColor) {
            grid[row + 1][col] = color;
            floodFill(grid, numRows, numCols, row+1, col, color, prevColor);
        }
        if (grid[row + 1][col + 1] == prevColor) {
            grid[row + 1][col + 1] = color;
            floodFill(grid, numRows, numCols, row+1, col+1, color, prevColor);
        }
        if (grid[row][col + 1] == prevColor) {
            grid[row][col + 1] = color;
            floodFill(grid, numRows, numCols, row, col+1, color, prevColor);
        }
    }
    if(col==0 && row==(numRows-1)){                                 //bottom left corner
        if (grid[row - 1][col] == prevColor) {
            grid[row - 1][col] = color;
            floodFill(grid, numRows, numCols, row-1, col, color, prevColor);
        }
        if (grid[row - 1][col + 1] == prevColor) {
            grid[row - 1][col + 1] = color;
            floodFill(grid, numRows, numCols, row-1, col+1, color, prevColor);
        }
        if (grid[row][col + 1] == prevColor) {
            grid[row][col + 1] = color;
            floodFill(grid, numRows, numCols, row, col+1, color, prevColor);
        }
    }
    if(col==0 && (row != 0) && ( row!= (numRows-1))){                 //first column(not including corners)
        if (grid[row - 1][col] == prevColor) {
            grid[row - 1][col] = color;
            floodFill(grid, numRows, numCols, row-1, col, color, prevColor);
        }
        if (grid[row - 1][col + 1] == prevColor) {
            grid[row - 1][col + 1] = color;
            floodFill(grid, numRows, numCols, row-1, col+1, color, prevColor);
        }
        if (grid[row][col + 1] == prevColor) {
            grid[row][col + 1] = color;
            floodFill(grid, numRows, numCols, row, col+1, color, prevColor);
        }
        if (grid[row + 1][col + 1] == prevColor) {
            grid[row + 1][col + 1] = color;
            floodFill(grid, numRows, numCols, row+1, col+1, color, prevColor);
        }
        if (grid[row + 1][col] == prevColor) {
            grid[row + 1][col] = color;
            floodFill(grid, numRows, numCols, row+1, col, color, prevColor);
        }
    }
    if(row==(numRows-1) && (col==(numCols-1))){                         //bottom right corner
        if (grid[row - 1][col - 1] == prevColor) {
            grid[row - 1][col - 1] = color;
            floodFill(grid, numRows, numCols, row-1, col-1, color, prevColor);
        }
        if (grid[row - 1][col] == prevColor) {
            grid[row - 1][col] = color;
            floodFill(grid, numRows, numCols, row-1, col, color, prevColor);
        }
        if (grid[row][col - 1] == prevColor) {
            grid[row][col - 1] = color;
            floodFill(grid, numRows, numCols, row, col-1, color, prevColor);
        }
    }
    if(row==(numRows-1) && (col != (numCols-1)) && (col != 0)){           //bottom row(not including corners)
        if (grid[row - 1][col - 1] == prevColor) {
            grid[row - 1][col - 1] = color;
            floodFill(grid, numRows, numCols, row-1, col-1, color, prevColor);
        }
        if (grid[row - 1][col] == prevColor) {
            grid[row - 1][col] = color;
            floodFill(grid, numRows, numCols, row-1, col, color, prevColor);
        }
        if (grid[row - 1][col + 1] == prevColor) {
            grid[row - 1][col + 1] = color;
            floodFill(grid, numRows, numCols, row-1, col+1, color, prevColor);
        }
        if (grid[row][col - 1] == prevColor) {
            grid[row][col - 1] = color;
            floodFill(grid, numRows, numCols, row, col-1, color, prevColor);
        }
        if (grid[row][col + 1] == prevColor) {
            grid[row][col + 1] = color;
            floodFill(grid, numRows, numCols, row, col+1, color, prevColor);
        }
    }
    if(col==(numCols-1) && (row != 0) && (row != numRows-1)){             //last column(not including corners)
        if (grid[row - 1][col - 1] == prevColor) {
            grid[row - 1][col - 1] = color;
            floodFill(grid, numRows, numCols, row-1, col-1, color, prevColor);
        }
        if (grid[row - 1][col] == prevColor) {
            grid[row - 1][col] = color;
            floodFill(grid, numRows, numCols, row-1, col, color, prevColor);
        }
        if (grid[row][col - 1] == prevColor) {
            grid[row][col - 1] = color;
            floodFill(grid, numRows, numCols, row, col-1, color, prevColor);
        }
        if (grid[row + 1][col - 1] == prevColor) {
            grid[row + 1][col - 1] = color;
            floodFill(grid, numRows, numCols, row+1, col-1, color, prevColor);
        }
        if (grid[row + 1][col] == prevColor) {
            grid[row + 1][col] = color;
            floodFill(grid, numRows, numCols, row+1, col, color, prevColor);
        }
    }
    if((row>0) && (col>0) && (row<(numRows-1)) && (col<(numCols -1))) {       //all other cases in grid

        if (grid[row - 1][col - 1] == prevColor) {
            grid[row - 1][col - 1] = color;
            floodFill(grid, numRows, numCols, row-1, col-1, color, prevColor);
        }
        if (grid[row - 1][col] == prevColor) {
            grid[row - 1][col] = color;
            floodFill(grid, numRows, numCols, row-1, col, color, prevColor);
        }
        if (grid[row - 1][col + 1] == prevColor) {
            grid[row - 1][col + 1] = color;
            floodFill(grid, numRows, numCols, row-1, col+1, color, prevColor);
        }
        if (grid[row][col - 1] == prevColor) {
            grid[row][col - 1]= color;
            floodFill(grid, numRows, numCols, row, col-1, color, prevColor);
        }
        if (grid[row][col + 1] == prevColor) {
            grid[row][col + 1] = color;
            floodFill(grid, numRows, numCols, row, col+1, color, prevColor);
        }
        if (grid[row + 1][col - 1] == prevColor) {
            grid[row + 1][col - 1] = color;
            floodFill(grid, numRows, numCols, row+1, col-1, color, prevColor);
        }
        if (grid[row + 1][col] == prevColor) {
            grid[row + 1][col] = color;
            floodFill(grid, numRows, numCols, row+1, col, color, prevColor);
        }
        if (grid[row + 1][col + 1] == prevColor) {
            grid[row + 1][col + 1] = color;
            floodFill(grid, numRows, numCols, row+1, col+1, color, prevColor);
        }
    }

}