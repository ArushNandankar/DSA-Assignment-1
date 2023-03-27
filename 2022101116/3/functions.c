#include "functions.h"

void Insert(PtrNode Head, int num) {
    PtrNode NewNode = CreateNode (num);   
    NewNode -> NextNode = Head -> NextNode;
    Head -> NextNode = NewNode;
}

PtrNode Find( PtrNode Head, int num ) {
    PtrNode P = Head;
    while (P->NextNode != Head) {
        if (P->NextNode->Element == num) {
            P->NextNode = P->NextNode->NextNode;
            Insert (Head,num);
            return Head;
        }
        P = P->NextNode;
    }  
    return NULL;  
}

void Print( PtrNode Head) {
    
    if (Head == NULL)
    return;
    
    
    Node* Ptr = Head;
 
    if (Ptr->NextNode == NULL) {
        printf("\n");
        return;
    }
        
    
    while (Ptr->NextNode != Head) {
        printf("%d ",Ptr->NextNode->Element);
        Ptr = Ptr->NextNode;
    }       
    printf("\n");
}

List CreateList () {
    List L = CreateNode (0);
    L->NextNode = L;
    return L;
}

PtrNode CreateNode (int element) {
    PtrNode N = malloc (sizeof(Node));
    N -> Element = element;
    N -> NextNode = NULL;
    return N;
}
