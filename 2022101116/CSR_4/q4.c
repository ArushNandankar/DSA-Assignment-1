#include <stdio.h>
#include <stdlib.h>

void combine(int *left_row_val, int *left_col_val, int *left_value, int lend, int *right_row_val, int *right_col_val, int *right_value, int rend, int *row_val, int *col_val, int *value);
void merge_sort(int n, int *row_val, int *col_val, int *value);
int MAX(int a, int b);
int MIN(int a, int b);


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
        {
            scanf("%d %d %d", &row_val[i], &col_val[i], &value[i]);
        }
        printf("%d\n", K);

        merge_sort(K, row_val, col_val, value);

        for (int i = 0; i < K; i++)
        {
            printf("%d %d %d\n", col_val[i], row_val[i], value[i]);
        }
    }

    else if (OPER[0] == 'A') {

    }

    else if (OPER[0] == 'M') {

    }
}

void combine(int *left_row_val, int *left_col_val, int *left_value, int lend, int *right_row_val, int *right_col_val, int *right_value, int rend, int *row_val, int *col_val, int *value)
{
    int r = 0;
    int l = 0;
    int n = lend + rend;

    for (int i = 0; i < n; i++)
    {
        if (l == lend)
        {
            row_val[i] = right_row_val[r];
            col_val[i] = right_col_val[r];
            value[i] = right_value[r++];
        }
        else if (r == rend)
        {
            row_val[i] = left_row_val[l];
            col_val[i] = left_col_val[l];
            value[i] = left_value[l++];
        }
        else if (left_col_val[l] < right_col_val[r] || (left_col_val[l] == right_col_val[r] && left_row_val[l] < right_row_val[r]))
        {
            row_val[i] = left_row_val[l];
            col_val[i] = left_col_val[l];
            value[i] = left_value[l++];
        }
        else
        {
            row_val[i] = right_row_val[r];
            col_val[i] = right_col_val[r];
            value[i] = right_value[r++];
        }
    }
}

void merge_sort(int n, int *row_val, int *col_val, int *value)
{
    if (n == 1)
        return;

    int left_row_val[n / 2];
    int left_col_val[n / 2];
    int left_value[n / 2];
    for (int i = 0; i < n / 2; i++)
    {
        left_row_val[i] = row_val[i];
        left_col_val[i] = col_val[i];
        left_value[i] = value[i];
    }

    int right_row_val[n - n / 2];
    int right_col_val[n - n / 2];
    int right_value[n - n / 2];
    for (int i = 0; i < n - n / 2; i++)
    {

        right_row_val[i] = row_val[n / 2 + i];
        right_col_val[i] = col_val[n / 2 + i];
        right_value[i] = value[n / 2 + i];
    }

    merge_sort(n / 2, left_row_val, left_col_val, left_value);
    merge_sort(n - n / 2, right_row_val, right_col_val, right_value);
    combine(left_row_val, left_col_val, left_value, n / 2, right_row_val, right_col_val, right_value, n - n / 2, row_val, col_val, value);
}

int MAX(int a, int b)
{
    if (a > b)
        return a;

    else
        return b;
}

int MIN(int a, int b)
{
    if (a < b)
        return a;

    else
        return b;
}
