#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char code[10000]={" "};
    char path[100]={" "};
    char c[2000]={" "};
    printf("please enter file code:\n");
    scanf("%s",path);
    
    //*******FILE OPEN***********
            FILE *f;

            f=fopen(path,"r");
                while(!feof(f))
                {
                    if(fgets(c,2000,f)!=0)
                    {
                        strcat(code,c);
                    }
                }
            fclose(f);

            if(!fopen(path,"r"))
            {
                printf("error open file!!!!\n");
                return 0;
            }
    //*******FILE OPEN END*******

    printf("please enter n number symbol:\n");
    int number=0;
    scanf("%d",&number);


    printf("please input 1 if you want to output n character otherwise 0 if you want to output a string from this character:\n");

    int vibor=0;

    scanf("%d",&vibor);

    if(vibor==1)
    {
        printf("%c",code[number]);
    }
    else
    {
        for(int i = number;i<strlen(code);i++)
            printf("%c",code[i]);
    }
}