#include <stdio.h>
struct stu
{
    int ID;
    char name[20];
    float ret;
}S[100];
int main()
{
    int N = 0, loser_cnt = 0;
    int i = 0;
    float sum = 0, aver = 0;
    scanf("%d",&N);
    for(i = 0; i<N; i++)
    {
        scanf("%d %s %f",&S[i].ID,S[i].name,&S[i].ret);
        sum += S[i].ret;
        if(S[i].ret < 60)
            loser_cnt++;
    }
    aver = sum/N;
    printf("%.2f %.2f %d",sum,aver,loser_cnt);
    return 0;
}
