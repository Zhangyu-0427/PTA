#include <stdio.h>
struct stu
{
    int ID;
    float Score;
};
//参数ps相当于结构体数组首元素地址 根据这个地址
//访问结构体成员 进而进行排序
void sort(struct stu *ps,int n)
{
    int i= 0, j = 0;
    int flag = 0;
    for(i = 0; i<n-1; i++)
    {
        flag = i;
        for(j = i+1; j<n; j++)
        {
            if(((ps+flag)->Score) < ((ps+j)->Score))
                flag = j;
        }
        //交换两个结构体的里所有成员的值
        //记住几行核心代码就好
        struct stu tmp;
        struct stu *p, *q;
        p = ps+flag;
        q = ps+i;
        tmp = *p;
        p = q;
        q = &tmp;
        *(ps+flag) = *p;
        *(ps+i)    = *q;
    }
}
int main()
{
    int N = 0;
    int i = 0;
    int rand[100];
    struct stu S[100];

    scanf("%d",&N);

    //信息录入
    for(i = 0; i<N; i++)
    {
        scanf("%d %f",&S[i].ID,&S[i].Score);
    }
    sort(S,N);//按成绩为基准 对结构体数组的元素进行排序

    for(i = 0; i<100; i++)
        rand[i] = i + 1;
    //题目就很操蛋 相同成绩情况下往下学生的排名还下降
    //根据这个操蛋的规则给排名数组赋初值

    //对排名数组进行 "去重"
    for(i = 0; i<N; i++)
    {
        if(S[i].Score > S[i+1].Score)
        {
            continue;
        }
        else
        {
            rand[i+1] = rand[i];
        }
    }
    //输出
    for(i = 0; i<N; i++)
    {
        printf("%d %d %.2f\n",rand[i],S[i].ID,S[i].Score);
    }
    return 0;
}
