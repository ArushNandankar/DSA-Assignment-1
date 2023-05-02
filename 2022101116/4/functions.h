#include <stdio.h>
#include <stdlib.h>

void combine(int *left_row_val, int *left_col_val, int *left_value, int lend, int *right_row_val, int *right_col_val, int *right_value, int rend, int *row_val, int *col_val, int *value);
void double_merge_sort(int n, int *row_val, int *col_val, int *value);
int MAX(int a, int b);
int MIN(int a, int b);
int superCmp(int *row_val1, int *col_val1, int *value1, int index1, int *row_val2, int *col_val2, int *value2, int index2);
