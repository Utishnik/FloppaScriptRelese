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
    
    char code[lenscount][100];


        int ii=0;

        f=fopen("code.floppascript","r");

        printf("\n");
    
         while(!feof(f))
        {
            if(fgets(c,2000,f)!=0)
            {
                for(int i = 0;i<strlen(c);i++)
                    code[ii][i]=c[i];
                ii++;
                printf(c);
            }
        }   

    

    fclose(f);

    printf("\n\n\n\n");

    printf("%d\n",lenscount);

    for(int i = 0;i<lenscount;i++)
        for(int j = 0;j<100;j++)
            printf("%c",code[i][j]);

    const int countcommand=1;

    char commands[countcommand][20];
    char comprint[20]={"Print"};

    lenscount++;

    for(int i = 0;i<20;i++)
        commands[0][i]=comprint[i];

    for(int i = 0;i<lenscount;i++)
    {
        if(find(code[i],";")==-1 )
        {
            printf("error ; str: %d",i+1);
        }
    }


    for(int i = 0;i<countcommand;i++)
    {
        if(i==0)
        {

        };
    }
    

    printf("\n");
    system("pause");
}