#include <stdio.h>
#include <string.h>
#define N 5

void func(char **str);

int main(void)
{
    int i;
    char s[N][1024], *pStr[N];
    for (i=0; i<N; i++)
    {
        gets(s[i]);
        pStr[i] = s[i];
    }
    func(pStr);
    //输出排序后的结果
    for (i=0; i<N; i++)
         puts(pStr[i]);
    return 0;
}

void func(char **str)
{
    char *temp;
    int i,j,min;
    for(i=0;i<N-1;i++)
     {
        min=i;
        for(j=i+1;j<N;j++)
        if(strcmp(str[min],str[j])>0)
            min = j;
        if(min!=i)
         {
             temp = str[min];
             str[min] = str[i];
             str[i] = temp;
        }
    }
}
