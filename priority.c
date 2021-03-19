#include<stdio.h>
#include<string.h>
struct process
{
	char pname[20];
	int at,bt,wt,tt,pt,status;
}p[20];
struct done
{
	char name[20];
	int st,ct;
}d[20];
void main()
{
	int n,i,j,idle,k,num,flag,found,ls;
	float sumwt=0.0,sumtt=0.0,t,w;
	printf("\n \t \t Enter the number of processes : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nEnter the process name : ");
		__fpurge(stdin);
		gets(p[i].pname);
		printf("Enter the arrival time : ");
		scanf("%d",&p[i].at);
		printf("Enter the burst time : ");
		scanf("%d",&p[i].bt);
		printf("Enter the priority : ");
		scanf("%d",&p[i].pt);
		p[i].status=0;
	}
	ls=0;
	idle=0;
	for(i=0;ls<n;)
	{
		flag=0;
		found=0;
		for(j=0;j<n;j++)
		{
			if(p[j].status==0 && p[j].at<= i && found==0)
			{
				k=j;
				flag++;
				found++;
			}
			else if(found>0 && p[j].status==0 && p[j].at<=i)
			{
				if(p[j].pt<p[k].pt)
				{
					k=j;
				}
				else if(p[j].pt==p[k].pt)
				{
					if(p[j].at<p[t].at)
					{
						k=j;
					}
				}
			}
		}	
		if(flag==0 && idle==0)
		{
			strcpy(d[num].name,"idle");
			d[num].st=i;idle=1;
			i++;
		}
		else if(flag>0)
		{
			if(idle==1)
			{
				d[num].ct=i;
				num++;
			}
			strcpy(d[num].name,p[k].pname);
			d[num].st=i;
			d[num].ct=i+p[k].bt;
			p[k].wt=d[num].st-p[k].at;
			p[k].tt=p[k].wt+p[k].bt;
			i=d[num].ct;
			num++;
			p[k].status=1;
			idle=0;
			ls++;
			k++;
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
	w=(float)(sumwt/n);
	t=(float)(sumtt/n);
	printf("\nAverage waiting time=%f\n",w);
	printf("\nAverage turnaround time=%f\n",t);
}

