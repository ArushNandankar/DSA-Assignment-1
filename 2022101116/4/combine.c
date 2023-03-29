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


int main () {
    char OPER [4];
    scanf("%s",OPER);

    if (OPER[0] == 'T') {
        Start S = CreateRowList ();
        
        int N,M,K;

        scanf ("%d %d %d",&N,&M,&K);
        
        // int row_array [1000000] = {-1};
        // int col_array [1000000] = {-1};
        // int val_array [1000000] = {-1};
        
        int count = 0;

        for (int i = 0; i < K ; i++) 
        {
            int i,j,val;
            scanf("%d %d %d",&i,&j,&val);
            AddElement (i,j,val,S);
            count++;
        }

        printf("%d\n",count);


        for (int i = 0; i < K; i++)
        {
            for (int j = 0; j < N; j++)
            {
    
                if (FindElement(j,i,S) != 0) {
                    //int x = FindElement(j,i,S)->value;
                    printf ("%d %d %d\n",i,j,FindElement(j,i,S));
                }
                
                //printf ("%d ",x);
            }
            
        }
        //printf("\n");
        
    }

    else if (OPER[0] == 'A') {
        Start S1 = CreateRowList ();
        Start S2 = CreateRowList ();
        Start S3 = CreateRowList ();
        
        int N,M,K1,K2;

        scanf ("%d %d %d %d",&N,&M,&K1,&K2);
        

        for (int i = 0; i < K1 ; i++) 
        {
            int i,j,val;
            scanf("%d %d %d",&i,&j,&val);
            AddElement (i,j,val,S1);
        }

        for (int i = 0; i < K2 ; i++) 
        {
            int i,j,val;
            scanf("%d %d %d",&i,&j,&val);
            AddElement (i,j,val,S2);
        }

        int count = 0;

        for (int i = 0; i < N ; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if ((FindElement(i,j,S1) + FindElement (i,j,S2)) != 0) {
                    AddElement (i,j,(FindElement(i,j,S1) + FindElement (i,j,S2)),S3);
                    count++;
                }
            }
            
        }

        printf("%d\n",count);

        for (int i = 0; i < N ; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (FindElement(i,j,S3) != 0) {
                    printf("%d %d %d\n",i,j,FindElement(i,j,S3));
                }
            }
            
        }
        

    }

//     else if (OPER[0] == 'M') {
//         Start S1 = CreateRowList ();
//         Start S2 = CreateRowList ();
//         Start S3 = CreateRowList ();
        
//         int N,M,L,K1,K2;

//         scanf ("%d %d %d %d %d",&N,&M,&L,&K1,&K2);

//         for (int i = 0; i < K1 ; i++) 
//         {
//             int i,j,val;
//             scanf("%d %d %d",&i,&j,&val);
//             AddElement (i,j,val,S1);
//         }

//         for (int i = 0; i < K2 ; i++) 
//         {
//             int i,j,val;
//             scanf("%d %d %d",&i,&j,&val);
//             AddElement (i,j,val,S2);
//         }

//         for (int i = 0; i < N; i++)
//         {
//             for (int j = 0; j < M; j++)
//             {
//                 if (FindElement(i,j,S1)*)
//             }
            
//         }
        
//     }
}


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
