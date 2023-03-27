#include "functions.h"

PtrToColNode CreateColNode (int val, int col) {
    PtrToColNode P = malloc (sizeof(ColNode));
    P->column = col;
    P->value = val;
    P->NextNonZeroCol = NULL;
    return P;
}

PtrToRowNode CreateRowNode (int row) {
    PtrToRowNode P = malloc (sizeof(RowNode));
    P->row = row;
    P->FirstNonZeroCol = NULL;
    P->NextNonZeroRow = NULL;
    return P;
}

PtrToRowNode CreateRowList () {
    PtrToRowNode P = CreateRowNode (-1);
    return P;
}
