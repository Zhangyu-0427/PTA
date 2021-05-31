//题目链接: https://pintia.cn/problem-sets/994805260223102976/problems/994805299301433344
//AC_date: 2021/5/31
#include <stdio.h>
int main()
{
    int A = 0, B = 0;
    long long sum = 0;
    int D, i = 0, j = 0;
    char arr[31] = {0};

    scanf("%d %d %d",&A,&B,&D);
    sum = A + B;
    if( D == 10 )
    {
        printf("%lld",sum);
    }
    else
    {
        if( sum == 0)
        {
            printf("0");
        }
        else
        {
            while(sum)
            {
                arr[i] = sum % D;
                sum /= D;
                i++;
            }
            for(j = i-1; j>=0; j--)
                printf("%d",arr[j]);
        }
    }
    return 0;
}
