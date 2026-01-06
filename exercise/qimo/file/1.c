#include <stdio.h>

int main()
{
    int x;
    FILE *f1 = fopen("a.txt","r"),*f2 = fopen("b.txt","w");
    if(f1 == NULL || f2 == NULL){
        printf("wrong");
        return 0;
    }
    while((x = fgetc(f1)) != EOF)
    {
        fputc(x,f2);
    }
    return 0;
}