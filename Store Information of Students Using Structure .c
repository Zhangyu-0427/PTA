#include <stdio.h>

struct stu
{
    char name[20];
    int roll;
    float score;
}STU[5];
int main()
{
    int i = 0;
    for(i = 0; i<5; i++)
    {
        scanf("%s %d %f",STU[i].name,&STU[i].roll,&STU[i].score);
    }
    for(i = 0; i<5; i++)
        printf("Roll number: %d\nName: %s\nMarks: %.1f\n",STU[i].roll,STU[i].name,STU[i].score);
    return 0;
}
