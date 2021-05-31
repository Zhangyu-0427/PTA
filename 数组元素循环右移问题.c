#include <stdio.h>

int main()
{
    int arr[100];
    int N = 0, M = 0, tmp, i = 0;

    scanf("%d %d",&N,&M);
    tmp = M%N;
    for(i = 0; i<N; i++)
        scanf("%d",&arr[i]);

    for(i = N-tmp; i<N; i++)
        printf("%d ",arr[i]);
    for(i = 0; i<N-tmp; i++)
    {
        if(i != N-tmp-1)
            printf("%d ",arr[i]);
        else
            printf("%d",arr[i]);
    }
    return 0;
}
