#include <stdio.h>
char a1[6] = "+--*/";
int fun(int x,int y,int type);
int main ()
{
    int a[4],i,j,k1,k2,temp2,l,temp1,h,k3;
    scanf("%d%d%d%d",&a[0],&a[1],&a[2],&a[3]);
    for(i = 0;i<4;i++)
    {
        for(j = 0;j<4;j++)
        {
            if(j == i){
                continue;
            }

            for(k1 = 0;k1<6;k1++)
            {
                temp1 = fun(a[i],a[j],k1);
                if(temp1 == 22500)
                {
                    continue;
                }
                for(l = 0;l<4;l++)
                {
                    if(l == i||l == j)
                    {
                        continue;
                    }
                    for(k2 = 0;k2<6;k2++)
                    {
                        temp2 = fun(temp1,a[l],k2);
                        if(temp2 == 22500)
                        {
                            continue;
                        }
                        for(h = 0;h==i||h==j||h==l;h++);
                        for(k3 =0;k3<6;k3++)
                        {
                            if(fun(temp2,a[h],k3) == 24)
                            {
                                goto print1;
                            }
                        }
                    }
                    
                }
            }
        }
    }//顺序运算

    for(i = 0;i<4;i++)//两两结合
    {
        for(j = 0;j<4;j++)
        {
            if(j == i){
                continue;
            }
            for(k1 = 0;k1<6;k1++)
            {
                temp1 = fun(a[i],a[j],k1);
                if(temp1 == 22500)
                {
                    continue;
                }
                for(l = 0;l<4;l++)
                {
                    if(l == i||l == j)
                    {
                        continue;
                    }
                    for(h = 0;h==i||h==j||h==l;h++);
                    for(k2 = 0;k2<6;k2++)
                    {
                        temp2 = fun(a[l],a[h],k2);
                        if(temp2 == 22500)
                        {
                            continue;
                        }
                        for(k3 =0;k3<6;k3++)
                        {
                            if(fun(temp1,temp2,k3) == 24)
                            {
                                goto print2;
                            }
                        }
                    }
                }
            }
        }
    }

    printf("-1\n");
    return 0;
    print1:
    if(k3 == 2 || k3 == 5)
    {
        printf("%d%c",a[h],a1[k3-1]);
    }
    printf("(");
    if(k2 == 2 || k2 == 5)
    {
        printf("%d%c",a[l],a1[k2-1]);
    }
    if(k1 == 2 || k1 == 5)
    {
        k1 -= 1;
        printf("(%d%c%d)",a[j],a1[k1],a[i]);
    }else{
        printf("(%d%c%d)",a[i],a1[k1],a[j]);
    }
    if(k2 != 2 && k2 != 5)
    {
        printf("%c%d",a1[k2],a[l]);
    }
    printf(")");
    if(k3 != 2 && k3 != 5)
    {
        printf("%c%d",a1[k3],a[h]);
    }
    printf("\n");
    return 0;

    print2:
    if(k3 == 2 || k3 == 5)
    {
        if(k2 == 2 || k2 == 5)
        {
            printf("(%d%c%d)",a[h],a1[k2-1],a[l]);
        }else{
            printf("(%d%c%d)",a[l],a1[k2],a[h]);
        }
        printf("%c",a1[k3-1]);
    }
    if(k1 == 2 || k1 == 5)
    {
        printf("(%d%c%d)",a[j],a1[k1-1],a[i]);
    }else{
        printf("(%d%c%d)",a[i],a1[k1],a[j]);
    }
    if(k3 != 2 && k3 != 5)
    {
        printf("%c",a1[k3]);
        if(k2 == 2 || k2 == 5)
        {
            printf("(%d%c%d)",a[h],a1[k2-1],a[l]);
        }else{
            printf("(%d%c%d)",a[l],a1[k2],a[h]);
        }
    }
    printf("\n");
    return 0;
    
}
int fun(int x,int y,int type)//0:+ 1:- 2:反- 3:* 4:/ 5:反/
{
    switch (type)
    {
        case 0:
        return x + y;
        case 1:
        return x - y;
        case 2:
        return y - x;
        case 3:
        return y * x;
        case 4:
        if(x!=0 && y%x == 0){
            return y / x;
        }else{
            return 22500;
        }
        case 5:
        if(y!=0 && x%y == 0){
            return x / y;
        }else{
            return 22500;
        }
    }

}