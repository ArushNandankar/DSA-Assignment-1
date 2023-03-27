#include <stdio.h>
#include <stdlib.h>

struct ColNode {
    int column;
    int value;
    struct ColNode* NextNonZeroCol;
};

struct RowNode {
    int row;
    struct RowNode* NextNonZeroRow;
    struct ColNode* FirstNonZeroCol;
};

typedef struct ColNode ColNode;
typedef struct RowNode RowNode;
typedef ColNode* PtrToColNode;
typedef RowNode* PtrToRowNode;

PtrToColNode CreateColNode (int val, int col);
PtrToRowNode CreateRowNode (int row);

PtrToRowNode CreateRowList ();
