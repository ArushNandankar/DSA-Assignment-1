#include "functions.h"


int main()
{
    char OPER[4];
    scanf("%s", OPER);

    if (OPER[0] == 'T') // Transpose
    {
        int N, M, K;
        scanf("%d %d %d", &N, &M, &K);
        int row_val[K];
        int col_val[K];
        int value[K];

        for (int i = 0; i < K; i++)       
            scanf("%d %d %d", &row_val[i], &col_val[i], &value[i]);
        
        printf("%d\n", K);

        double_merge_sort(K, row_val, col_val, value);

        for (int i = 0; i < K; i++)
        {
            printf("%d %d %d\n", col_val[i], row_val[i], value[i]);
        }
    }

    else if (OPER[0] == 'A') // Addition
    {
        int N, M, K1, K2;
        scanf("%d %d %d %d", &N, &M, &K1, &K2);
        int row_val1[K1];
        int col_val1[K1];
        int value1[K1];

        int row_val2[K2];
        int col_val2[K2];
        int value2[K2];

        int row_val3[K1 + K2];
        int col_val3[K1 + K2];
        int value3[K1 + K2];

        for (int i = 0; i < K1; i++)
            scanf("%d %d %d", &row_val1[i], &col_val1[i], &value1[i]);

        for (int i = 0; i < K2; i++)
            scanf("%d %d %d", &row_val2[i], &col_val2[i], &value2[i]);

        int index1 = 0;
        int index2 = 0;
        int count = 0;

        while (index1 != K1 || index2 != K2)
        {
            if (index1 == K1)
            {
                row_val3[count] = row_val2[index2];
                col_val3[count] = col_val2[index2];
                value3[count] = value2[index2];
                index2++;
                count++;
            }

            else if (index2 == K2)
            {
                row_val3[count] = row_val1[index1];
                col_val3[count] = col_val1[index1];
                value3[count] = value1[index1];
                index1++;
                count++;
            }

            else if (superCmp(row_val1, col_val1, value1, index1, row_val2, col_val2, value2, index2) == -1)
            {
                row_val3[count] = row_val2[index2];
                col_val3[count] = col_val2[index2];
                value3[count] = value2[index2];
                index2++;
                count++;
            }

            else if (superCmp(row_val1, col_val1, value1, index1, row_val2, col_val2, value2, index2) == 1)
            {
                row_val3[count] = row_val1[index1];
                col_val3[count] = col_val1[index1];
                value3[count] = value1[index1];
                index1++;
                count++;
            }

            else
            {
                if (value1[index1] + value2[index2] == 0)
                {
                    index1++;
                    index2++;
                }

                else
                {
                    row_val3[count] = row_val1[index1];
                    col_val3[count] = col_val1[index1];
                    value3[count] = value1[index1] + value2[index2];
                    index1++;
                    index2++;
                    count++;
                }
            }
        }

        printf("%d\n", count);
        for (int i = 0; i < count; i++)
            printf("%d %d %d\n", row_val3[i], col_val3[i], value3[i]);
    }

    else if (OPER[0] == 'M') // Multiplication
    {
        int N, M, L, K1, K2;
        scanf("%d %d %d %d %d", &N, &M, &L, &K1, &K2);

        int row_val1[K1];
        int col_val1[K1];
        int value1[K1];

        int col_val2[K2];
        int row_val2[K2];
        int value2[K2];

        int row_val3[K1 * K2];
        int col_val3[K1 * K2];
        int value3[K1 * K2];

        for (int i = 0; i < K1; i++)
            scanf("%d %d %d", &row_val1[i], &col_val1[i], &value1[i]);

        for (int i = 0; i < K2; i++)
            scanf("%d %d %d", &col_val2[i], &row_val2[i], &value2[i]);

        double_merge_sort(K2, row_val2, col_val2, value2);

        //multiply kaise karu?
        // :( 
        
        for (int i = 0; i < K1; i++)
        {
            
        }
        



    }
}
