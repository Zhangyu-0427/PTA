#include <stdio.h>
#include <math.h>

int Wei(long int num);//计算位的函数
long int pow_10(int x);//由于pow函数的返回值为double类型 可能会破坏精度 最好自己写一个Pow_10函数

int main()
{
    long int num;//中间结果保持在2^31次方之内
    while(scanf("%ld",&num)!=EOF)
    {
        long int tmp[100000];
        long int count = 0,k = 0;//统计交换的次数与存放每次交换的中间变量
        while(1)
        {
            long int num_tmp = num,sum=0;
            int flag_h=1;//是回文数
            int Z_sort[32],ret_wei_num = Wei(num);
            //把 num 从个位开始存放
            for(int i = 0; i<ret_wei_num; i++)
            {
                Z_sort[i] = num_tmp%10;
                num_tmp /= 10;
                sum+=Z_sort[i]*pow_10(ret_wei_num-1-i);// num 的倒序数
            }
            /*判断是否是回文数*/
            for(int j = 0; j<ret_wei_num; j++)
            {
                if(Z_sort[j] != Z_sort[ret_wei_num-1-j])
                {
                    flag_h = 0;//不是回文数,需要交换
                    count++;
                    break;
                }
            }
            if(flag_h == 0)//不是回文数 sum 与 num 需相加
            {
                tmp[k] = num;
                k++;
                num += sum;//此时的 num 即为下一个需要判断的"伪"回文数
            }
            else//这个数即为回文数
            {
                tmp[k] = num;
                break;
            }
        }
        printf("%ld\n",count);
        for(int l = 0; l<=k; l++)
        {
            printf("%ld",tmp[l]);
            if(l != k)
                printf("--->");
        }
        printf("\n");
    }
    return 0;
}

long int pow_10(int x)
{
    long int ret=1;
    if(x == 0)
        return ret;
    else
    {
        for(int i = 0;i<x;i++)
        {
            ret *=10;
        }
        return ret;
    }
}

int Wei(long int num)
{
    int count = 0;//统计位
    while(num!=0)
    {
        num/=10;
        if(num)
        {
            count++;
        }
    }
    return count+1;
}
