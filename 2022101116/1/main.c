#include "functions.h"

int main () {
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++)
    {
        char OPER [6];
        scanf("%s", OPER);

        // Operation 1 String Reverse
        if(OPER[4] == '1') {
            int length;
            scanf("%d", &length);
            char str[length];
            scanf("%s", str);
            reverseString(str, length);
        } // Done :)
        
        // Operation 2 String Compress
        else if (OPER[4] == '2') {
            int length;
            scanf("%d", &length);
            char str[length+1];
            scanf("%s", str);
            char* compressed = compressString(str,length);
            printf("%s\n",compressed);
        } // Done :)
        
        // Operation 3 Unique Elements
        else if (OPER[4] == '3') {
            int length;
            scanf("%d", &length);
            //int arr[length];
            int* arr = malloc(sizeof(int)*length);

            for (int i = 0; i < length; i++)
            scanf("%d",&arr[i]);
            
            length_unique_elements = 0;
            int* unique_arr = uniqueElements(arr,length);

            for (int i = 0; i < length_unique_elements; i++)
            printf("%d ",unique_arr[i]);

            printf("\n");

            free(unique_arr);
            free(arr);
        } // Done :)
       
       // Operation 4 Matrix Transpose       
        else if (OPER[4] == '4') {
            int nrows, ncols;
            
            scanf("%d %d", &nrows, &ncols);
            
            int* matrix[nrows];

            for (int i = 0; i < nrows; i++)
            {
                matrix[i] = malloc(ncols * sizeof(int));
            }
            
            
            for (int i = 0; i < nrows; i++)
            {
                for (int j = 0; j < ncols; j++)
                {
                    scanf("%d",&matrix[i][j]);
                }
            }
            

            int** t_matrix = malloc(sizeof(int)*nrows*ncols);
            t_matrix = transpose(matrix,nrows,ncols);

            for (int i = 0; i < ncols; i++)
            {
                for (int j = 0; j < nrows; j++)
                {
                    printf("%d ",t_matrix[i][j]);
                }
                printf("\n");
            }

            for (int j = 0; j < nrows; j++)
            {
                free(matrix[j]);
            }
            
            for (int i = 0; i < ncols ; i++)
            {
                free(t_matrix[i]);
            }
            
            
            free(t_matrix);            
        } // Done :)
    }
}

// Completed 
