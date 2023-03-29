#include "functions.h"

int main () {
    char OPER [4];
    scanf("%s",OPER);

    if (OPER[0] == 'T') {
        Start S = CreateRowList ();
        
        int N,M,K;

        scanf ("%d %d %d",&N,&M,&K);
        
        int filled_indexes [K][2];
        
        int count = 0;

        for (int l = 0; l < K ; l++) 
        {
            int i,j,val;
            scanf("%d %d %d",&i,&j,&val);
            AddElement (i,j,val,S);
            filled_indexes[count][1] = i; //rows
            filled_indexes[count][0] = j; //columns
            count++;
        }

        printf("%d\n",count);

        merge_sort(count,filled_indexes);

        for (int i = 0; i < count; i++)
        {
            printf ("%d %d %d\n",filled_indexes[i][0],filled_indexes[i][1],FindElement(filled_indexes[i][1],filled_indexes[i][0],S));
        }
        
        
    } // Done :)

    else if (OPER[0] == 'A') {
        Start S1 = CreateRowList ();
        Start S2 = CreateRowList ();
        Start S3 = CreateRowList ();
        
        int N,M,K1,K2;

        scanf ("%d %d %d %d",&N,&M,&K1,&K2);
        

        int filled_indexes1 [K1][2];
        int filled_indexes2 [K2][2];
        

        for (int l = 0; l < K1 ; l++) 
        {
            int i,j,val;
            scanf("%d %d %d",&i,&j,&val);
            AddElement (i,j,val,S1);
            filled_indexes1[l][1] = i; //rows
            filled_indexes1[l][0] = j; //columns
        }

        for (int l = 0; l < K2 ; l++) 
        {
            int i,j,val;
            scanf("%d %d %d",&i,&j,&val);
            AddElement (i,j,val,S2);
            filled_indexes2[l][1] = i; //rows
            filled_indexes2[l][0] = j; //columns
            //count++;
        }


        int filled_indexes3 [K1+K2][2];

        // int count = 0;
        // for (int l = 0; l < K1 ; l++)
        // {
        //     int k = FindElement(filled_indexes1[l][1],filled_indexes1[l][0],S1)+FindElement(filled_indexes1[l][1],filled_indexes1[l][0],S2);

        //     if (k != 0) {
        //         AddElement (filled_indexes1[l][1],filled_indexes1[l][0],FindElement(filled_indexes1[l][1],filled_indexes1[l][0],S1)+FindElement(filled_indexes1[l][1],filled_indexes1[l][0],S2),S3);
        //         filled_indexes1[count][1] = fill
        //         count++;
        //     }           
        // }

        
        // for (int l = 0; l < K2 ; l++)
        // {
        //     if (FindElement(filled_indexes2[l][1],filled_indexes2[l][0],S1) == 0) {
        //         AddElement (filled_indexes2[l][1],filled_indexes2[l][0],FindElement(filled_indexes2[l][1],filled_indexes2[l][0],S2),S3);
        //         count++;
        //     }
        // }
        


        // printf("%d\n",count1+count2);
        // for (int l = 0; l < count1; l++)
        // {
        //     printf("%d %d %d",)
        // }
        

        
        

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
