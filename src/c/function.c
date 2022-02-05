#include "../h/function.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int find(char str[],char pstr[],int start_index)
{
    int index=-1;
    int lenn=strlen(pstr);
    for(int i = start_index;i<strlen(str);i++)
    {
        for(int j = 0;j<strlen(pstr);j++)
        {
            if(lenn==0)
            {
                return index;
            }
            if(str[j+i]==pstr[j])
            {
                lenn--;
                index=i;
            }
            else
            {
                index=-1;
                lenn=strlen(pstr);
                break;
            }
        }
    }
    return index;
}
/*void TokenSort(struct TokenStartIndex *s_arr,int start,int end)
{
    if(start<end){
        int left=start;
        int right=end;
        int middle=s_arr[(start + end)/2].codepos;

        do {
            while(s_arr[left].codepos<middle)
                left++;
            while(s_arr[right].codepos>middle)
                right--;
            if(left<=right){
                int tmp=s_arr[left].codepos;
                s_arr[left].codepos=s_arr[right].codepos;
                s_arr[right].codepos=tmp;
                left++;
                right--;
            }

        }while(left < right);
    }
}
*/