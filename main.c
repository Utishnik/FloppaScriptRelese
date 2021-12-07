#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include <string.h>

int find(char str[],char pstr[])
{
    int index=-1;
    int lenn=strlen(pstr);
    for(int i = 0;i<strlen(str);i++)
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


int main(void)
{

    char symbolDp[53]={" "};
    char s;

    for(int i=0;i<26;i++)
    {
        symbolDp[i]=65+i;
    }
    for(int i=0;i<26;i++)
    {
        symbolDp[i+25]=97+i;
    }

    symbolDp[52]='_';
    printf("\n%s\n",symbolDp);


    FILE *f;
    char c[200];
    int countlen=0;
    char code[10000];

    f=fopen("code.floppascript","r");
        while(!feof(f))
        {
            if(fgets(c,2000,f)!=0)
            {
                strcat(code,c);
            }
        }
    fclose(f);

    printf("\n\n%s\n\n",code);

    int lencode=strlen(code);

    int counts_string=0;

    for(int i = 0;i<lencode;i++)
    {
        if(code[i]==';')
            counts_string++;
    }

    char codestr[counts_string][200];

    printf("\ncstring %d \n",counts_string);
    int yy=0;
    for(int j = 0;j<counts_string;)
        for(int i = 0;i<200;)
        {
            if(code[yy]!='\n')
                codestr[j][i]=code[yy];
            else
            {
                j++;
            }
            yy++;
        }

    for(int i = 0;i<counts_string;i++)
    {
        for(int j = 0;j<200;j++)
            printf("%c",codestr[i][j]);
        printf("\n");
    }

     
    system("pause");
}