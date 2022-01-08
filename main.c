#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include <string.h>

/* TOKEN TYPES
    "PRINT","OSCOB","KOVICHKA","TEXT","ENTER","ZSCOB","ENDSTR",
    "INT","NAME_PEREMNOY","SCAN","PEREMENAYA_ARG","PLUS","NUMBER"
*/


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

struct TokenStartIndex
{
    int codepos;
    char text[50];
};
    
void TokenSort(struct TokenStartIndex *s_arr,int start,int end)
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
        TokenSort(s_arr,start,right);
        TokenSort(s_arr,left,end);
    }
}

/*==============================================================*
void SortInt(int *s_arr,int start,int end)                    
{
        if(start<end){
        int left=start;
        int right=end;
        int middle=s_arr[(start + end)/2];

        do {
            while(s_arr[left]<middle)
                left++;
            while(s_arr[right]>middle)
                right--;
            if(left<=right){
                int tmp=s_arr[left];
                s_arr[left]=s_arr[right];
                s_arr[right]=tmp;
                left++;
                right--;
            }

        }while(left < right);
        SortInt(s_arr,start,right);
        SortInt(s_arr,left,end);
    }
}
================================================================*
*/

void Lexer(char code[],struct TokenLexer Ltokens[1000])
{
    //сейчас я хочу добавить третий токен (у меня есть тока print и ( )
    char *PRINT="PRINT";
    char *Print="Print";
    struct TokenLexer tokens[1000];
    const int CodeTokenCount=3;
    int codepos[CodeTokenCount];
    int indexTokenLexer=0;
    const int LEN_TSI=1000;

    for(int i=0;i<CodeTokenCount;i++)
        codepos[i]=0;

    struct TokenStartIndex TSI[CodeTokenCount][LEN_TSI];


    for(int k=0;k<CodeTokenCount;k++)
        for(int i=0;i<LEN_TSI;i++)
            for(int j=0;j<50;j++)
                TSI[k][i].text[j]=' ';
    ///////////////////////////
    for(int k=0;k<CodeTokenCount;k++)
        for(int i=0;i<LEN_TSI;i++)
                TSI[k][i].codepos=0;

    char PrintText[5]={"Print"};
    char OSCOB[1]={'('};
    char BSCOB[1]={')'};
    int TokenCount[CodeTokenCount];

    for(int i=0;i<CodeTokenCount;i++)
        TokenCount[i]=0;

        BOOL breakcicl=TRUE;

        while(1)
        {


            for(int i=0;i<LEN_TSI;i++)
            {
                    //printf("-Debug-\n");
                    if(find(code,"Print",codepos[0])!=-1){ 
                        //printf("1\n");
                        TSI[0][i].codepos=find(code,"Print",codepos[0]);
                        //printf("2\n");
                        for(int p=0;p<strlen(Print);p++) 
                            TSI[0][i].text[p]=PrintText[p];
                        //printf("* IF PRINT *\n");
                        codepos[0]=find(code,"Print",codepos[0])+5+1;
                        TokenCount[0]++;
                    }
                    //printf("-Debug-\n");
                    if(find(code,"(",codepos[1])!=-1) 
                    {
                        TSI[1][i].codepos=find(code,"(",codepos[1])+1;
                        TSI[1][i].text[0]='(';
                        codepos[1]=find(code,"(",codepos[1])+1;
                        TokenCount[1]++;
                    }
                    if(find(code,")",codepos[2])!=-1)
                    {
                        TSI[2][i].codepos=find(code,")",codepos[2])+1;
                        TSI[2][i].text[0]=')';
                        codepos[2]=find(code,")",codepos[2])+1;
                        TokenCount[2]++;
                    }
                //printf("END - %d\n",i);
            }
            printf("\n\n\n");

            printf("================================\n");

            for(int i=0;i<CodeTokenCount;i++)
            {
                printf("\n");
                for(int k=0;k<CodeTokenCount;k++)
                {
                    for(int j=0;j<TokenCount[k];j++)
                    {
                        printf("NUMBER - %d",TSI[i][j].codepos);

                        printf(" ");

                        for(int h=0;h<strlen(TSI[i][j].text);h++)
                            printf("%c",TSI[i][j].text[h]);
                    }
                    printf("\n");
                }
            }

            printf("\n\n\n================================\n");
//********************************************************************

            struct TokenStartIndex Sort[CodeTokenCount][LEN_TSI];

            for(int i=0;i<CodeTokenCount;i++)
            {
                for(int j=0;j<LEN_TSI;j++){
                    Sort[i][j].codepos=0;
                    Sort[i][j].text[0]=' ';}
            }

/*
            for(int i=0;i<CodeTokenCount;i++){
                for(int j=0;j<TokenCount[i];j++){
                        Sort[i][j].codepos=TSI[i][j].codepos;

                        for(int k=0;k<50;k++){
                            Sort[i][j].text[k]=TSI[i][j].text[k]; 
                        }
                    // bag naverno tut no eto ne tochno
                    //убрать удваевание
                }
            }
*/
            //printf("%c",Sort[i][j].text[h]);

            for(int k=0;k<CodeTokenCount;k++)
            {
                for(int j=0;j<TokenCount[k];j++)
                {
                    Sort[k][j].codepos=TSI[k][j].codepos;  
                    for(int h=0;h<50;h++)
                        Sort[k][j].text[h]=TSI[k][j].text[h];
                }
            }

//*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*
           printf("TOKENS:\n\n\n");

            for(int k=0;k<CodeTokenCount;k++)
            {
                for(int j=0;j<TokenCount[k];j++)
                {
                    printf("%d ",Sort[k][j].codepos);  
                }
                printf("\n");
            }

            int LenTokenSymbols[CodeTokenCount];

            LenTokenSymbols[0]=5;
            LenTokenSymbols[1]=1;
            LenTokenSymbols[2]=1;

            printf("\n===Types Token Count: %d ===\n",CodeTokenCount);

/*
            printf("\n\ntext:\n\n");

            printf("\nprint Sort array text:\n\n");
*/

            printf("\n\n");

            for(int k=0;k<CodeTokenCount;k++)
            {
                for(int j=0;j<TokenCount[k];j++){
                    for(int h=0;h<LenTokenSymbols[k];h++)
                            printf("%c",Sort[k][j].text[h]);
                    printf(" ");
                }
                printf("\n");
            }

//=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=


            // sorting algorithm created and tested
            printf("\n\n\n");
//********************************************************************
            printf("================================\n");

/*
            for(int i=0;i<CodeTokenCount;i++)
            {
                printf("\n");
                for(int k=0;k<CodeTokenCount;k++)
                {
                    for(int j=0;j<TokenCount[k];j++)
                    {
                        printf("NUMBER - %d",TSI[i][j].codepos);

                        printf(" ");

                        for(int h=0;h<strlen(TSI[i][j].text);h++)
                            printf("%c",TSI[i][j].text[h]);
                    }
                    printf("\n");
                }
            }
*/

            printf("================================\n");


//\=====================================================================================================
//=\====================================================================================================
//==\===================================================================================================
//===\==================================================================================================
//====\=================================================================================================
//=====\================================================================================================
//======\===============================================================================================

//УЬРАТЬ ВВЫВОД НЕНУЖНЫХ ТЫСЯЧ СИМВОЛОВ!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


        for(int i=0;i<CodeTokenCount;i++)
        {
            for(int j=0;j<1000;j++)
            {
                
            }
        }



        //printf("%d\n",codepos);


        printf("TOKENS COUNT = %d\n",indexTokenLexer); 


        printf("\nToken Types,Token Counts:\n");

        printf("\n=-=PRINT=-=Print  %d  \n",TokenCount[0]);
        printf("\n=-=OSCOB=-=(  %d  \n",TokenCount[1]);
        printf("\n=-=BSCOB=-=)  %d  \n",TokenCount[2]);



//shutdown if there is an error
        if(GetKeyState(VK_ESCAPE)<=0)
            break;
//=============================


/*----------------------------------------   
        if(breakcicl==TRUE)
        {
            printf("\nEND\n");
            break;
        }
    }
------------------------------------------*/
        printf("\n\ngcc main.c -o floppa\n\n");
        break;
    }
}

//       gcc main.c -o floppa

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
    /*
        for(int i = 0;i<10000;i++)
        {
            if(code[i]=='\n')
                code[i]=' ';
        }
    */
    f=fopen("code.floppascript","r");
        while(!feof(f))
        {
            if(fgets(c,2000,f)!=0)
            {
                strcat(code,c);
            }
        }
    fclose(f);

    //


    printf("\n\n%s\n\n",code);

    int lencode=strlen(code);

    printf("\n----LENCODE = %d----\n",lencode);

    struct TokenLexer Tokens[1000];

    Lexer(code,Tokens);    
     
    system("pause");
}