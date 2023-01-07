#ifndef CELL_H
#define CELL_H

#include "list.h"

typedef struct {
    int x;
    int y;
} Cell;

int compareCells(Cell *c1, Cell *c2);

#endif