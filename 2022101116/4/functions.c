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

Start CreateRowList () {
    Start S = CreateRowNode (-1);
    return S;
}

void AddElement (int row, int col, int val, Start S) {
    PtrToRowNode Ptr = S->NextNonZeroRow;
    if (Ptr == NULL) {
        S->NextNonZeroRow = CreateRowNode (row);
        S->NextNonZeroRow->FirstNonZeroCol = CreateColNode (val,col);
    }

    // if ((Ptr == NULL) && (S->row == -1)) {

    // }

    else if (Ptr->row == row) {
        PtrToColNode CnPtr = Ptr->FirstNonZeroCol;
        
        while (CnPtr->NextNonZeroCol != NULL) {
            CnPtr = CnPtr->NextNonZeroCol;
        }
        CnPtr->NextNonZeroCol = CreateColNode (val,col);
    }

    else if (Ptr->row < row) {
        AddElement (row,col,val,Ptr);
    }
}

// PtrToColNode FindElement (int row, int col, Start S) {
//     PtrToRowNode Ptr = S->NextNonZeroRow;

//     if (Ptr == NULL) {
//         return NULL;
//     }

//     if (Ptr->row == row) {
//         PtrToColNode CnPtr = Ptr->FirstNonZeroCol;
        
//         while (CnPtr != NULL) {
//             if (CnPtr->column == col) {
//                 return CnPtr;
//             }
//             else {
//                 CnPtr = CnPtr->NextNonZeroCol;
//             }
//         }

//         return NULL;
//     }

//     else {
//         return FindElement (row, col, Ptr);
//     }
// }

int FindElement (int row, int col, Start S) {
    PtrToRowNode Ptr = S->NextNonZeroRow;

    if (Ptr == NULL) {
        return 0;
    }

    if (Ptr->row == row) {
        PtrToColNode CnPtr = Ptr->FirstNonZeroCol;
        
        while (CnPtr != NULL) {
            if (CnPtr->column == col) {
                return CnPtr->value;
            }
            else {
                CnPtr = CnPtr->NextNonZeroCol;
            }
        }

        return 0;
    }

    else {
        return FindElement (row, col, Ptr);
    }
}

void combine(int arrleft[][2], int lend, int arrright[][2], int rend, int array[][2]) {
    int r = 0;
    int l = 0;
    int n = lend + rend;

    for (int i = 0; i < n; i++) {
        if (l == lend)
            array[i][0] = arrright[r][0], array[i][1] = arrright[r++][1];
        else if (r == rend)
            array[i][0] = arrleft[l][0], array[i][1] = arrleft[l++][1];
        else if (arrleft[l][0] < arrright[r][0])
            array[i][0] = arrleft[l][0], array[i][1] = arrleft[l++][1];
        else if (arrleft[l][0] > arrright[r][0])
            array[i][0] = arrright[r][0], array[i][1] = arrright[r++][1];
        else if (arrleft[l][1] < arrright[r][1])
            array[i][0] = arrleft[l][0], array[i][1] = arrleft[l++][1];
        else
            array[i][0] = arrright[r][0], array[i][1] = arrright[r++][1];
    }
}

void merge_sort(int n, int array[][2]) {
    if (n == 1)
        return;

    int arrleft[n / 2][2];
    for (int i = 0; i < n / 2; i++) {
        arrleft[i][0] = array[i][0];
        arrleft[i][1] = array[i][1];
    }

    int arrright[n - n / 2][2];
    for (int i = 0; i < n - n / 2; i++) {
        arrright[i][0] = array[n / 2 + i][0];
        arrright[i][1] = array[n / 2 + i][1];
    }

    merge_sort(n / 2, arrleft);
    merge_sort(n - n / 2, arrright);
    combine(arrleft, n / 2, arrright, n - n / 2, array);
}

int MAX (int a, int b) {
    if (a > b)
    return a;

    else
    return b;
}
int MIN (int a, int b) {
    if (a < b)
    return a;

    else
    return b;
}