#include <stdio.h>
#include <string.h>

//候选人信息 1. 姓名 2. 投票数
typedef struct vote
{
    char name[10];
    int vote;
}candidate_infor;

//比较两个字符串 不区分大小写
int def_strcmp(char arr1[], char arr2[]);

//对选票结果进行排序
void Sore_cand_Co(candidate_infor arr[],int n);

int main()
{
    candidate_infor temp[10];
    char tmp[10], error[10][10];
    int n = 0, i = 0, j = 0, m = 0;
    int error_cnt = 0;

    scanf("%d",&n);
    for(i = 0; i<n; i++)
    {
        scanf("%s",temp[i].name);
        temp[i].vote = 0;
    }

    scanf("%d",&m);
    for(i = 0; i<m; i++)
    {
        scanf("%s",tmp);
        for(j = 0; j<n; j++)
        {
            if( def_strcmp(temp[j].name,tmp) == 1 )//两字符串相等（不区分大小写）
            {
                temp[j].vote++;
                break;
            }
        }
        if(j == n)
        {
            //error[error_cnt++] = tmp;
            strcpy(error[error_cnt++], tmp);
        }
    }
    Sore_cand_Co(temp,n);
    //输出
    for(i = 0; i<n; i++)
        printf("%s:%d\n",temp[i].name,temp[i].vote);
    if(error_cnt == 0)
        return 0;
    else
    {
        printf("\ninvalid vote:\n");
        for(i = 0; i<error_cnt; i++)
            printf("%s\n",error[i]);
    }
    return 0;
}
int def_strcmp(char arr1[], char arr2[])
{
    int i = 0;
    int ret_1 = strlen(arr1), ret_2 = strlen(arr2);
    if(ret_1 != ret_2)
        return 0;//姓名不同
    else
    {
        for(i = 0; i<ret_1; i++)
        {
            if(arr1[i] == arr2[i] || fabs(arr1[i]-arr2[i]) == 32)
                continue;
            else
                break;
        }
        if(i == ret_1)
            return 1;//姓名相同
        else
            return 0;//姓名不同
    }
}
void Sore_cand_Co(candidate_infor arr[],int n)
{
    int i = 0, j = 0;
    int max = 0;
    for(i = 0; i<n-1; i++)
    {
        max = i;
        for(j = i+1; j<n; j++)
        {
            if(arr[j].vote > arr[max].vote)
                max = j;
        }
        if(max != i)
        {
            candidate_infor tmp = arr[max];
            arr[max] = arr[i];
            arr[i] = tmp;
        }
    }
}
