#include <stdio.h>

void findmax(int (*pArr)[4], int *pmax, int m, int n);

int main(void)
{
  int arr[3][4], *pa, max[3], i;
  pa = arr[0];
  for (i=0; i<12; i++)
  {
     scanf("%d", pa++);
  }

  findmax(arr,max,3,4);
  for (i=0; i<3; i++)
  {
     printf("line %d's max = %d\n", i, max[i]);
  }

  return 0;
}

void findmax(int (*pArr)[4], int *pmax, int m, int n)
{
   int i, j;

   for (i=0;  i<m;  i++, pmax++)
   {
       *pmax = *(*(pArr+i)+0);
       for (j=1; j<n; j++)
       {
           if(*(*(pArr+i)+j)>pmax)
           {
               *pmax = *(*(pArr+i)+j);
           }
       }
   }
}
