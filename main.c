#include <stdlib.h>
#include <stdio.h>
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
                break;
            }
        }
    }
    return index;
}

void Print2(char str[])
{
    printf("%s",str);
}

int main(void)
{
    FILE *f;
    int lenscount=0;
    char c[2000];


    f=fopen("code.floppascript","r");
        while(!feof(f))
        {
            if(fgets(c,2000,f)!=0)
            {
                lenscount++;
            }
        }
    fclose(f);

    for(int i = 0;i<2000;i++)
        c[i]=' ';
    
    char code[3000]={" "};


        int ii=0;

        f=fopen("code.floppascript","r");

        printf("\n");
    
        while(!feof(f))
        {
            if(fgets(c,2000,f)!=0)
            {
                if(find(c,";")==-1)
                {
                    printf("idi nahyi!\n");
                    return -1;
                }
                strcat(code,c);
            }
        }   

    

    fclose(f);

    printf("\n\n\n\n");

    printf("%d\n",lenscount);

    //printf(code);

    const int countcommand=1;

    char commands[countcommand][20];
    char comprint[20]={"Print"};

    lenscount++;


    for(int i = 0;i<20;i++)
        commands[0][i]=comprint[i];

    int endstr=0;

    for(int i = 0;i<3000;i++)
    {
        if(code[i]==';')
            endstr++;
    }
    int ind=0;
    char codestr[endstr][200];

    for(int i = 0;i<endstr;i++)
        for(int j = 0;j<200;j++)
            codestr[i][j]=' ';

    int g=0;

    for(int j = 0;j<3000;j++)
    {
       if(code[j]!=';') 
           codestr[g][j]=code[j];
       else
       {
           codestr[g][j]=code[j];
           g++;
       }
    }


    printf("\n\n\n\n\n\n\n\n\n\n");


for(int j = 0;j<endstr;j++)
{
    for(int i = 0;i<countcommand;i++)
    {
        if(i==0)
        {
            int startprinti=0;
            int endprinti=0;
            int skobkiind[2]={};
            int kovichind[2]={};
            int onekovichind=0;
            if(find(codestr[j],commands[i])!=-1)
            {
                startprinti=find(codestr[j],commands[i]);
                endprinti=startprinti+(strlen(commands[i])-1);
            }
            if(find(codestr[j],"(")!=-1)
            {
                skobkiind[0]=find(codestr[j],"(");
            }

            if(find(codestr[j],")")!=-1)
            {
                skobkiind[1]=find(codestr[j],")");
            }

              if(find(codestr[j],"\"")!=-1)
            {
                kovichind[0]=find(codestr[j],"\"");
                
            }

            if(find(codestr[j],"\'")!=-1)
            {
                kovichind[1]=find(codestr[j],"\'");
            }
            for(int y = kovichind[0]+1;y<kovichind[1];y++)
                printf("%c",codestr[j][y]);
        };
    }
    printf("\n");
}       
    

    printf("\n");
    system("pause");
}