//
// Created by flood on 10/16/2019.
//

#ifndef FLOOD_FILL_FLOOD_FILL_H
#define FLOOD_FILL_FLOOD_FILL_H

#endif //FLOOD_FILL_FLOOD_FILL_H
void loadPicture(char fName[], char *grid[], int *numRows, int *numCols);
void displayPicture(char *grid[], int numRows, int numCols);
void floodFill(char *grid[], int numRows, int numCols, int row, int col, char color, char prevColor);