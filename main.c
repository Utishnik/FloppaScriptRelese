#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main(void)
{
    FILE *f;
    char code[2000]={" "};
    char c[2000];
    f=fopen("code.floppascript","r");
        while(!feof(f))
        {
            if(fgets(c,2000,f)!=0)
            {
                strcat(code,c);
                
            }

        }
    fclose(f);

    //printf(c);


    printf("\n");
    system("pause");
}