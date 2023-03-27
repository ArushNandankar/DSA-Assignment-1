#include "functions.h"

int main () {
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++)
    {
        char OPER [6];
        scanf("%s", OPER);

        // Operation 1 Intersection Array
        if(OPER[4] == '1') {
            int n1,n2;
            scanf("%d %d",&n1,&n2);
            int arr1[n1];
            int arr2[n2];

            for (int i = 0; i < n1; i++)
                scanf("%d",&arr1[i]);

            for (int i = 0; i < n2; i++)
                scanf("%d",&arr2[i]);
            
            intersection_arr_size = 0;
            int* intersection_arr = intersectionArray(arr1,arr2,n1,n2);

            for (int i = 0; i < intersection_arr_size; i++)
                printf("%d ",intersection_arr[i]);           
            printf("\n");

            if (intersection_arr_size == 0)
                printf("-1");
            
        } // Done :)
        
        // Operation 2 Count Character Occurences
        else if (OPER[4] == '2') {
            int length;
            scanf("%d",&length);
            char str[length+1];
            scanf("%s",str);   
            char ch;
            scanf(" %c",&ch);
            int num = countCharOccurrences(str,length,ch);
            printf("%d\n",num);
               
        } // Done :)
        

        // Operation 3 First Non Reapeating character
        else if (OPER[4] == '3') {
            int length;
            scanf("%d",&length);
            char str[length+1];
            scanf("%s",str);   
            char ch = findFirstNonRepeatingChar(str,length);
            
            if (ch == '\0')
            printf("-1\n");
            else
            printf("%c\n",ch);
               
        } // Done :) 

        
        // Operation 4 Longest common prefix
        else if (OPER[4] == '4') {
            int n;
            scanf("%d",&n);

            char** strings = malloc (sizeof(char*)*n);
            int maxlengthpossible = 100;

            for (int i = 0; i < n; i++)
            {
                int m;
                scanf ("%d",&m);

                if (m < maxlengthpossible)
                maxlengthpossible = m;

                strings[i] = (char*) malloc(sizeof(char)*(m+1));
                scanf("%s",strings[i]);
            } 

            char* LongestCommonPrefix = findLongestCommonPrefix(strings,n,maxlengthpossible);
            
            if (LongestCommonPrefix[0] != '\0')
            printf("%s\n", LongestCommonPrefix);

            else
            printf("-1\n");
            
        } // Done :)
        
        // Operation 5 maxMin
        else if (OPER[4] == '5') {
            int n;
            scanf("%d",&n);
            int arr[n];

            for (int i = 0; i < n; i++)
                scanf("%d",&arr[i]);
            
            length_maxMin = 0;

            int * maxMinArr = maxMin(arr,n);

            if (length_maxMin != 0) {
                for (int i = 0; i < length_maxMin ; i++)
                    printf("%d ",maxMinArr[i]);
                printf("\n");
            }
            
            else 
                printf("-1\n");            
        } // Done :)


        // Operation 6 Remove substring
        else if (OPER[4] == '6') {
            int n,m;
            scanf("%d %d",&n,&m);
            char str[n];
            char substr[m];
            scanf("%s",str);
            scanf("%s",substr);

            char* removed_substr = removeSubstring (str,n,substr,m);

            if (substr_length == 0)
            printf("-1\n");
            
            else
            printf("%s\n",removed_substr);
            
        } // Done :)         
    }
}

