#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include <string.h>

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

        if(find(code,"(",codepos[1])!=-1)
        {
            char *osc="OSCOB";

            for(int i=0;i<strlen(osc);i++)
                tokens[indexTokenLexer].type[i]=osc[i];
            for(int i = 0;i<1;i++)
                tokens[indexTokenLexer].text[i]='(';

            printf("OSCOB ***%d***\n",codepos[1]);

            indexTokenLexer++;
            countTOKENTYPES[1]++;
            codepos[1]=find(code,"(",codepos[1])+1;
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

    printf("TOKEN COUNT PRINT = %d\n",countTOKENTYPES[0]);
    printf("TOKEN COUNT OSCOB = %d\n",countTOKENTYPES[1]);

    printf("\n");

    for(int i = 0;i<indexTokenLexer;i++)
        printf("%s ",tokens[i].text);

    printf("==================================\n");

    printf("\n");
 
    for(int i = 0;i<indexTokenLexer;i++)
        printf("%s ",tokens[i].type);   

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

    printf("\n\n");
     
    system("pause");
}
