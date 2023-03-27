#include <stdio.h>
#include <stdlib.h>

int* intersectionArray(int* arr1, int* arr2, int lenArr1, int lenArr2);
int countCharOccurrences(const char* str, int length, char ch);
char findFirstNonRepeatingChar(const char* str, int length);
char* findLongestCommonPrefix(char** str, int numStr, int maxLen);
int* maxMin(int* arr , int lenArr);
char* removeSubstring(char* str, int strLength, const char* substr, int substrLength);

void combine (int* arrleft, int lend, int* arrright, int rend, int* array);
void MergeSort (int n, int* array);
int max (int a, int b);
int min (int a, int b);

int intersection_arr_size;
int length_maxMin;
int substr_length;
