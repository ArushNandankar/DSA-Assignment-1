#include "functions.h"

void reverseString(char* str, int length) {
    char array [length];
    
    for (int i = 0; i < length; i++)
    {
        array [i] = str [i];
    }
    
    for (int i = 0; i < length/2; i++)
    {
        char temp = array [i];
        array [i] = array [length-i-1];
        array [length-i-1] = temp;
    }

    for (int i = 0; i < length; i++)
    {
        printf("%c", array[i]);
    }
    printf("\n");
}

char* compressString(char* str, int length) {
    
    char* arr = malloc (((2*length)+1) * sizeof(char));
    
    int index = 0;
    int count = 0;
    
    for (int i = 0; i < length; i++)
    {
        if (i == 0)
        {
            arr[index++] = str[i];
            count++;
        }

        else if (str[i] == str[i-1])
        {
            count++;
        }

        else 
        {

            if (count/10000 !=0)
            arr[index++] = '0' +  ((count/10000)%10);

            if (count/1000 !=0)
            arr[index++] = '0' +  ((count/1000)%10);

            if (count/100 !=0)
            arr[index++] = '0' +  ((count/100)%10);

            if (count/10 !=0)
            arr[index++] = '0' +  ((count/10)%10);

            
            arr[index++] = '0' +  ((count)%10);
        
            arr[index++] = str[i];
            count = 1;
        }
    }
    
    if (count/10000 !=0)
    arr[index++] = '0' +  ((count/10000)%10);

    if (count/1000 !=0)
    arr[index++] = '0' +  ((count/1000)%10);

    if (count/100 !=0)
    arr[index++] = '0' +  ((count/100)%10);

    if (count/10 !=0)
    arr[index++] = '0' +  ((count/10)%10);

            
    arr[index++] = '0' +  ((count)%10);
    

    return arr;
}

int* uniqueElements(int* arr, int length) {
   
    int* freq = calloc (10001,sizeof(int));
    int count = 0;

    for (int i = 0; i < length; i++)
    freq[arr[i]]++;

    for (int i = 0; i < 10001; i++)
    {
        if(freq[i] >= 1)
        count++;
    }
    
    
    int* unique_arr = malloc ((count) * sizeof(int));
    int index = 0;
    for (int i = 0; i < length; i++)
    {
        if(freq[arr[i]] >= 1) {
            unique_arr[index++] = arr[i];
            freq[arr[i]] = 0;
        }
        
    }
    length_unique_elements = count;
    free(freq);
    return unique_arr;
             
}

int** transpose(int** matrix, int NumRow, int NumCol)
{
    
    int** t_matrix = malloc(NumCol * sizeof(int*));

    for (int i = 0; i < NumCol ; i++)
    {
        t_matrix[i] = malloc(NumRow * sizeof(int));
    }
            
            
    for (int i = 0; i < NumCol; i++)
    {
        for (int j = 0; j < NumRow; j++)
        {
            t_matrix[i][j] = matrix[j][i];
        }
    }
    return t_matrix;
}
