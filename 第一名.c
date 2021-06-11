#include <stdio.h>
typedef struct stu
{
    char name[20];
    int a;
    int b;
    int c;
}A;
int main()
{
    int i = 0, max = 0, index = 0;
    int arr[100];
    A STU[100];
    for(i = 0; i<2; i++)
    {
        scanf("%s %d %d %d",STU[i].name,&STU[i].a,&STU[i].b,&STU[i].c);
        arr[i] = STU[i].a + STU[i].b + STU[i].c;
    }

    for(i = 0; i<2; i++)
    {
        if(arr[i]>max)
        {
            index = i;
            max = arr[i];
        }
    }
    printf("%s",STU[index].name);
    return 0;
}
