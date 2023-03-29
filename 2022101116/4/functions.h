#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

// struct StartNode {
//     struct RowNode* FirstRowNodePtr;
// };

typedef struct ColNode ColNode;
typedef struct RowNode RowNode;
//typedef struct StartNode StartNode;
typedef struct RowNode* Start;
typedef ColNode* PtrToColNode;
typedef RowNode* PtrToRowNode;

PtrToColNode CreateColNode (int val, int col);
PtrToRowNode CreateRowNode (int row);

Start CreateRowList ();

void AddElement (int row, int col, int val, Start S);
int FindElement (int row, int col, Start S);

void combine(int arrleft[][2], int lend, int arrright[][2], int rend, int array[][2]);
void merge_sort(int n, int array[][2]);
int MAX (int a, int b);
int MIN (int a, int b);