#include "cell.h"

#include <stdio.h>
#include <string.h>

int compareCells(Cell *c1, Cell *c2) {
    return (c1->x == c2->x && c1->y == c2->y);
}