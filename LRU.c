#include<stdio.h>
int main()
{
  int rs[50], flag[50], pf=0, n, f, i, j, count[50], next=1, min;
  printf("Enter length of Reference string ");
  scanf("%d", &n);
  printf("Enter Reference string\n ");
  for(i=0; i<n; i++)
  {
    scanf("%d", &rs[i]);
    flag[i]=0;
  }
  printf("Enter no of frames ");
  scanf("%d", &f);
  int m[f];
  for(i=0; i<f; i++)
  {
    m[i]=-1;
    count[i]=0;
  }
  for(i=0; i<n; i++)
  {
    for(j=0; j<f; j++)
    {
      if(m[j]==rs[i])
      {
        flag[i]=1;
        count[j]=next;
        next++;
      }
    }
    if(flag[i]==0)
    {
      if(i<f)
      {
        m[i]=rs[i];
        count[i]=next;
        next++;
      }
      else
      {
        min = 0;
        for (int j = 1; j < f; j++) {
          if(count[j]<count[min]){
            min = j;
          }
        }
        m[min] = rs[i];
        count[min]=next;
        next++;
      }
      pf++;
    }
    printf("\n");
    for(j=0;j<f;j++)
    {
      printf("%d\t",m[j] );
    }
  }
  printf("\nNo of Page Faults: %d\n", pf);

}
