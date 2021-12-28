#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include <string.h>

char TokenTypes[13][25]={
    "PRINT","OSCOB","KOVICHKA","TEXT","ENTER","ZSCOB","ENDSTR",
    "INT","NAME_PEREMNOY","SCAN","PEREMENAYA_ARG","PLUS","NUMBER"
};


char TokenDefinition[9][25]={
    "Print","(","\"","\n",")",";",
    "int","Scan","+"
};

//you need to make a definition for the text of the name of the change, etc.

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

struct TokenLexer
{
    char text[80];
    char type[25];
};

void Lexer(char code[],struct TokenLexer Ltokens[1000])
{
    char *PRINT="PRINT";
    char *Print="Print";
    struct TokenLexer tokens[1000];
    int codepos=0;
    int indexTokenLexer=0;

    while(codepos<strlen(code))
    {
        BOOL breakcicl=TRUE;

        if(strlen(code)-codepos<=0)
        {
            printf("End code\n");
            break;
        }
        
        if(find(code,"Print",codepos)!=-1)
        {
            for(int i=0;i<strlen(PRINT);i++)
                tokens[indexTokenLexer].type[i]=PRINT[i];
            for(int i = 0;i<5;i++)
                tokens[indexTokenLexer].text[i]=Print[i];
            
            printf("***%d***\n",codepos);
            
            indexTokenLexer++;
            
            codepos=find(code,"Print",codepos)+5+1;
            breakcicl=FALSE;
        }

        //printf("%d\n",codepos);

        if(breakcicl==TRUE)
        {
            printf("\nEND\n");
            break;
        }
        printf("\n----CODEPOS INFORMATION= %d ----\n",codepos);
    }

    printf("TOKENS COUNT = %d\n",indexTokenLexer);

    printf("\nEND CODEPOS = %d\n",codepos);

    for(int i = 0;i<indexTokenLexer;i++)
        printf("\n\n%s\n\n",tokens[i].text);
    

    for(int i = 0;i<1000;i++)
        Ltokens[i]=tokens[i];
}


int main(void)
{
    
    char symbolDp[55]={" "};
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

    for(int i = 0;i<10000;i++)
    {
        if(code[i]=='\n')
            code[i]=' ';
    }
    //


    printf("\n\n%s\n\n",code);

    int lencode=strlen(code);

    printf("\n----LENCODE = %d----\n",lencode);

    struct TokenLexer Tokens[1000];

    Lexer(code,Tokens);    
     
    system("pause");
}
