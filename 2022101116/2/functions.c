#include "functions.h"

int* intersectionArray(int* arr1, int* arr2, int lenArr1, int lenArr2) {
    
    MergeSort(lenArr1,arr1);
    MergeSort(lenArr2,arr2);

    int temp_arr [max(lenArr1,lenArr2)];
     
    for (int i = 0; i < max(lenArr1,lenArr2); i++)
        temp_arr[i] = -1;
    

    int index = 0;
    int index1 = 0;
    int index2 = 0;

    while ((index1 < lenArr1) && (index2 < lenArr2)) {
        if (arr1[index1] == arr2[index2]) {
            temp_arr[index++] = arr1[index1];
            index1++;
            index2++;
        }

        else if (arr1[index1] > arr2[index2]) {
            index2++;
        }

        else if (arr1[index1] < arr2[index2]) {
            index1++;
        }
    }

    int* intersection_arr = malloc(index * sizeof(int));

    for (int i = 0; i < index; i++)
    {
        intersection_arr[i] = temp_arr[i];
    }

    intersection_arr_size = index;
    return intersection_arr;
    
}

int countCharOccurrences(const char* str, int length, char ch) {
    int count = 0;

    for (int i = 0; i < length; i++)
    {
        if (str[i] == ch)
        count++;
    }

    return count;
    
}

char findFirstNonRepeatingChar(const char* str, int length) {
    
    int freq [26];

    for (int i = 0; i < 26; i++)
        freq [i] = 0;
    
    
    for (int i = 0; i < length; i++)
        freq [str[i] - 97]++;

    for (int i = 0; i < length; i++)
    {
        if (freq[str[i] - 97] == 1)
        return str[i];
    }
    
    return '\0';
}

int* maxMin(int* arr , int lenArr) {
    int right_max[lenArr];
    int left_min[lenArr];
    int count = 0;

    for (int i = 0; i < lenArr ; i++)
    {
        if (i == 0)
        right_max[i] = arr[i];

        else if (arr[i] > right_max [i-1])
        right_max[i] = arr[i];

        else
        right_max[i] = right_max[i-1] ;
    }

    for (int i = lenArr-1 ; i > -1 ; i--)
    {
        if (i == lenArr - 1)
        left_min[i] = arr[i];

        else if (arr[i] < left_min[i+1])
        left_min[i] = arr[i];

        else
        left_min[i] = left_min [i+1];
    }

    for (int i = 0; i < lenArr ; i++)
    {
        if ((i == 0 || arr[i] > right_max[i-1])  && (i == lenArr -1 || arr[i] < left_min [i+1]))
        count++;
    }

    int* maxMinArr = malloc(sizeof(int)*count);
    int index = 0;

    for (int i = 0; i < lenArr ; i++)
    {
        if ((i == 0 || arr[i] > right_max[i-1])  && (i == lenArr -1 || arr[i] < left_min [i+1]))
        maxMinArr[index++] = i;
    }
    
    length_maxMin = count;
    return maxMinArr;    
}

char* removeSubstring(char* str, int strLength, const char* substr, int substrLength) {
    
    int num_deleted_chars = 0;

    for (int i = 0; i < strLength - substrLength + 1 ; i++)
    {
        int count = 0;
        for (int j = 0; j < substrLength; j++)
        {
            if (str[i+j] != substr [j])
            count++;
        }
        if (count == 0)
        {
            for (int j = 0; j < substrLength; j++)              
                str[i+j] = '\0';
            
            num_deleted_chars += substrLength;
        }
    }

    char* removed_substr = malloc(sizeof(char)*(strLength - num_deleted_chars + 1));
    int index = 0;

    for (int i = 0; i < strLength ; i++)
    {
        if (str[i] == '\0')
        continue;

        else
        removed_substr[index++] = str[i];
    }
    substr_length = index;
    removed_substr[index] = '\0';
    return removed_substr;
    
}

char* findLongestCommonPrefix(char** str, int numStr, int maxLen) {
    
    char temp [maxLen];

    for (int i = 0; i < maxLen; i++)
        temp[i] = '\0';

    int index = 0;    
    
    
    
    for (int i = 0; i < maxLen; i++)
    {
        int count = 0;
        for (int j = 1; j < numStr ; j++)
        {
            if (str[0][i] == str [j][i])
            count++;
        }

        if (count == (numStr - 1))
        temp[index++] = str[0][i];
        
        else
        break;
    }

    char* LongestCommonPrefix = malloc(sizeof(char)*(index + 1));

    for (int i = 0; i < index; i++)
    {
        LongestCommonPrefix[i] = temp[i];
    }
    
    LongestCommonPrefix[index] = '\0';
    return LongestCommonPrefix;
}

void combine (int* arrleft, int lend, int* arrright, int rend, int* array) {
    int r = 0;
    int l = 0;
    
    int n = lend + rend;
    
    for (int i = 0; i < n; i++)
    {
        if (l == lend)
        array [i] = arrright [r++];

        else if (r == rend)
        array [i] = arrleft [l++];

        else if (arrleft[l] < arrright [r])
        array [i] = arrleft [l++];

        else
        array [i] = arrright [r++];
    }
    
}

void MergeSort (int n, int* array) { 
    if(n == 1)
    return;
    
    int arrleft [n/2];
    for (int i = 0; i < n/2; i++)
    {
        arrleft [i] = array [i];
    }

    int arrright [n-n/2];
    for (int i = 0; i < n-n/2; i++)
    {
        arrright [i] = array[n/2+i];
    }

    MergeSort (n/2, arrleft);
    MergeSort (n-n/2, arrright);

    combine (arrleft, n/2, arrright, n-n/2, array);   
}

int max (int a, int b) {
    if (a > b)
    return a;

    else
    return b;
}

int min (int a, int b) {
    if (a > b)
    return b;

    else
    return a;
}

