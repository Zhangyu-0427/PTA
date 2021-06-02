#include <stdio.h>

int main()
{
    char arr[80];
    char* p = arr;
    int cnt = 0, flag = 1;
    gets(arr);
    while(*p != '\0')
    {
        if(*p == ' ' && flag == 1)
        {
            cnt++;
            flag = 0;
        }
        else
        {
            if(*p == ' ')
                flag = 0;
            else
                flag = 1;
        }
        p++;
    }
    printf("%d",cnt+1);
    return 0;
}
