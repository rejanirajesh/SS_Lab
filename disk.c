#include<stdio.h>
#include<stdlib.h>

int t,i,h,j=0,num1,num2,diff,hm,temp,n,pos;
int track[25],final[25],sort[25],ans[25],cans[25];

void fcfs()
	{
	final[0]=h;
	for(i=1;i<=t;i++)
		{
		final[i]=track[j];
		j++;
		}
	for(i=0;i<t;i++)
		{
		num1=final[i];
		num2=final[i+1];
		diff=abs(num2-num1);
		hm+=diff;
		}
	printf("\nFCFS\n");
	for(i=0;i<t+1;i++)
		printf("%d\t",final[i]);
	printf("\n\n");
	printf("Total head movement: %d\n",hm);
	}

void scan()
	{

	for(i=0;i<=t-1;i++)
		{
		for (j = 0; j <=t-i-1; j++)  
			{
    		if (final[j] > final[j+1])
    			{
    			temp=final[j];
    			final[j]=final[j+1];
    			final[j+1]=temp;
    			}  
			}
		}
	j=1;
	sort[0]=0;
	for(i=0;i<=t+1;i++)
		{
		sort[j]=final[i];
		j++;
		}
	sort[t+2]=199;
	n=t+2;
	for(i=0;i<=n;i++)
		{
		if(sort[i]==h)
			{
			pos=i;
			break;
			}
		}
	j=0;
	if(pos<=n/2)
		{
		for(i=pos;i>=0;i--)
			{
			ans[j]=sort[i];
			j++;
			}
		for(i=pos+1;i<n;i++)
			{
			ans[j]=sort[i];
			j++;
			}
		}
	else
		{
		for(i=pos;i<n;i++)
			{
			ans[j]=sort[i];
			j++;
			}
		for(i=pos-1;i>=0;i--)
			{
			ans[j]=sort[i];
			j++;
			}
		}
	
	hm=0;
	for(i=0;i<n-1;i++)
		{
		num1=ans[i];
		num2=ans[i+1];
		diff=abs(num2-num1);
		hm+=diff;
		}
	printf("\nSCAN\n");
	for(i=0;i<n;i++)
		printf("%d\t",ans[i]);
	printf("\n\n");
	printf("Total head movement: %d\n",hm);
	}

void cscan()
	{
	
	j=0;
	for(i=pos;i<=n;i++)
		{
		cans[j]=sort[i];
		j++;
		}
	for (i=0;i<pos;i++)
		{
		cans[j]=sort[i];
		j++;
		}
	hm=0;
	for(i=0;i<n;i++)
		{
		num1=cans[i];
		num2=cans[i+1];
		diff=abs(num2-num1);
		hm+=diff;
		}
	printf("\nC-SCAN\n");
	for(i=0;i<=n;i++)
		printf("%d\t",cans[i]);
	printf("\n\n");
	printf("Total head movement: %d\n",hm);

	}



int main()
    {
     int ch;
	printf("ENTER THE NO. OF TRACKS:");
	scanf("%d",&t);
	printf("ENTER EACH TRACK NO.S:\n ");
	for(i=0;i<t;i++)
		scanf("%d",&track[i]);
	printf("ENTER THE HEAD POSITION: ");
	scanf("%d",&h);
     do
     {
	printf("\n1.FCFS\n2.SCAN\n3.C-SCAN ");
	printf("\nEnter choice: ");
	scanf("%d",&ch);
	
      switch(ch)
      {
       case 1: fcfs();
               break;
       case 2: scan();
               break;
       case 3: cscan();
               break;
       default: break;
      }
     }while(ch<4);
    }

