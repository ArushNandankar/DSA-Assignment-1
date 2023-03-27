#include "functions.h"

int main () {
    int T;
    scanf("%d",&T);

    List L = CreateList ();
    
    for (int i = 0; i < T; i++)
    {
        char OPER[6];
        scanf("%s",OPER);

        // Operation 1 Insert
        if (OPER[4] == '1') {
            int n;
            scanf("%d",&n);
            Insert(L,n);
        } // Done :)
        
        // Operation 2 Find
        else if (OPER[4] == '2') {
            int n;
            scanf("%d",&n);
            PtrNode P = Find(L,n);
            if (P != NULL)
            L = P;
        } // Done :)

        // Operation 3 Print
        else if (OPER[4] == '3') {
            Print(L);
        } // Done :)
    }
    
}

