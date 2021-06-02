//计算一组学生的总成绩、平均成绩和不及格人数(用结构指针变量作函数参数编程)。
#include<stdio.h>
struct stu{
    int num;
    char name[20];
    char sex;
    double score;
}s[5]={     {101,"Li ping"   , 'M',  45},
            {102,"Zhang ping", 'M',42.5},
            {103,"He fang"   , 'F',92.5},
            {104,"Cheng ling", 'F',  87},
            {105,"Wang ming" , 'M',  58}
        };
void ave(struct stu *ps){
     //补充你的代码
    int i = 0;
    float sum = 0, aver= 0, cnt_loser = 0;
    for(i = 0; i<5; i++)
    {
        sum += ps->score;
        if((ps->score) < 60)
            cnt_loser++;
        ps++;
    }
    aver = sum / 5;
    printf("%.2f %.2f %.0f",sum,aver,cnt_loser);
}
int main()
{
    ave(s);
}
//执行程序，输出：
//325.00 65.00 3
