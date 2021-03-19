#include<stdio.h>
#include<string.h>
struct process
{
	char pname[20];
	int at,bt,wt,tt,status;
}p[20],t;
struct done
{
	char name[20];
	int st,ct;
}d[20];
void main()
{
	int n,i,j,idle,num,k=0;
	float sumwt=0.0,sumtt=0.0,att,awt;
	printf("\n \t \t Enter the number of processes : ");
	scanf("%d",&n);
	for(k=0;k<n;k++)
	{
		printf("\nEnter the process name :");
		__fpurge(stdin);
		gets(p[k].pname);
		printf("Enter the arrival time : ");
		scanf("%d",&p[k].at);
		printf("Enter the burst time : ");
		scanf("%d",&p[k].bt);
		p[k].status=0;
	}
	for(i=0;i<n;i++) 		//sorting the processes according to arrival time
	{
		for(j=0;j<n-i-1;j++)
		{
			if(p[j].at>p[j+1].at)
			{
				t=p[j];
				p[j]=p[j+1];	
				p[j+1]=t;
			}
		}
	}
	idle=0;
	for(i=0,k=0,num=0;k<n;)
	{
		if(p[k].at<=i&&p[k].status==0)
		{
			if(idle==1)
			{
				d[num].ct=i;
				num++;
			}
			strcpy(d[num].name,p[k].pname);
			d[num].st=i;
			d[num].ct=i+p[k].bt;
			p[k].tt=d[num].ct-p[k].at;
			p[k].wt=p[k].tt-p[k].bt;
			i=d[num].ct;
			p[k].status=1;
			k++;
			num++;
			idle=0;
		}
		else if(idle==0)
		{
			strcpy(d[num].name,"idle");
			d[num].st=i;
			i++;
			idle=1;
		}
		else
		{
			i++;
		}
	}
	printf ( " | pname | arrival time\t | burst time\t | status\t | wait\t | turn") ;
	for ( i =0; i <n ; i ++)
	{
		printf ( "\n | %s \t | %d \t \t | %d \t \t | %d \t \t | %d \t | %d \n" , p[i].pname ,p[i].at , p[i].bt ,
		p[i].status,p[i].wt,p[i].tt );
	}
	printf("\n\n\nGantt chart\n");
	for(i=0;i<n;i++)
		printf("____________");
		printf("\n|");
	for(i=0;i<num;i++)
		printf("%s\t|",d[i].name);
		printf("\n");
	for(i=0;i<n;i++)
		printf("_____________");
		printf("\n");
	for(i=0;i<num;i++)
		printf("%d\t",d[i].st);
		printf("%d\t",d[num-1].ct);
		printf("\n");
	for(i=0;i<n;i++)
	{
		sumwt=sumwt+p[i].wt;
		sumtt=sumtt+p[i].tt;
	}
	awt=(float)(sumwt/n);
	att=(float)(sumtt/n);
	printf("\nAverage turnaround time = %f\n",att);
	printf("Average waiting time = %f\n",awt);	
}

