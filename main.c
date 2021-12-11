#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include <string.h>

char TokenTypes[13][25]={
    "PRINT","OSCOB","KOVICHKA","TEXT","ENTER","ZKOVICHKA","ZSCOB","ENDSTR",
    "INT","NAME_PEREMNOY","SCAN","PEREMENAYA_ARG","PLUS"
};

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

typedef struct 
{
    char text[80];
    char type[25];
    int pos;
}TokenLexer;

void Lexer(char code[],TokenLexer Ltokens[10000])
{
    int position=0;
    TokenLexer tokens[10000];

    while(1){
        if(position>=strlen(code))
            break;
        char token[30]={" "};
        int index=0;

        while(code[position]!=' ')
        {
            token[index]=code[position];
        }
        printf("\n%s\n",token);
        position++;
    }

    for(int i = 0;i<10000;i++)
        Ltokens[i]=tokens[i];
}


int main(void)
{
    
    char symbolDp[59]={" "};
    char s;

    for(int i=0;i<26;i++)
    {
        symbolDp[i]=65+i;
    }
    for(int i=0;i<26;i++)
    {
        symbolDp[i+25]=97+i;
    }

    symbolDp[51]='_';
    char cifri[10]={"0123456789"};
    int y=0;
    for(int i = 52;i<62;i++)
    {
        symbolDp[i]=cifri[y];
        y++;
    }

    ////////////////////////////////////////////////////
    printf("\n%s\n",symbolDp);
    ////////////////////////////////////////////////////

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

    for(int i = 0;i<lencode;i++)
        if(code[i]=='\n')
            code[i]=' ';

    printf("\n\n%s\n",code);


     
    system("pause");
}