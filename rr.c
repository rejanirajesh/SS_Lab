#include<stdlib.h>
#include<stdio.h>
#define SIZE 100
#include <string.h>
struct process{
	char pname[20];
	int at,bt,tt,wt,status,left,inqueue;
}p[20];
struct gantt{
	char name[20];
	int st,ct;
}d[20];
int front=-1,rear=-1;
int queue[SIZE];
void enqueue(int item)
{
	if(rear==-1)
	{
		front=rear=0;
		queue[rear]=item;
	}
	else if(rear==SIZE-1)
	{
		printf("Queue is full \n");
		return;
	}
	else
	{
		rear++;
		queue[rear]=item;
	}
}
int dequeue()
{
	int item;
	if(front==-1)
	{
		printf("Queue Empty\n");
		return 0;
	}
	else if(front==rear)
	{
		item=queue[front];
		front=rear=-1;
	}
	else
	{
		item=queue[front];
		front++;
	}
	return item;
}
int main()
{
	int i,n,j,idle,k,num,np,tq;
	float sumwt=0.0,sumtt=0.0,st,w,t;
	printf("\n Enter time quantum : ");
	scanf("%d",&tq);
	printf("\n ============================\n");
	printf("Enter the number of processes...");
	scanf("%d",&n);
        	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("\n Enter the process name :");
		scanf("%s",p[i].pname);
		printf("Enter the arrival time :");
		scanf("%d",&p[i].at);
		printf("Enter the burst time :");
		scanf("%d",&p[i].bt);
		p[i].status=0;
		p[i].inqueue = 0;
		p[i].left=p[i].bt;
	}
        	printf("============================\n\n");
	np=0;
	idle=0;
	num = 0;
	for(i=0;np<n;)
	{
		for(j=0;j<n;j++)
		{
			if(p[j].status != 2 && p[j].at<= i && p[j].inqueue!=1)
			{
				enqueue(j);
				p[j].inqueue = 1;
			}
		}
		if(front == -1 && idle==0)
		{
			strcpy(d[num].name,"idle");
			d[num].st=i;
			idle=1;i++;
		}
		else if(front > -1)
		{
			if(idle == 1)
			{
				d[num].ct=i;
				num++;
			}		
			k = dequeue();
			p[k].inqueue = 0;
			if(p[k].left <= tq)
			{
				strcpy(d[num].name,p[k].pname);
				d[num].st=i;
				d[num].ct=i+p[k].left;
				p[k].tt=d[num].ct-p[k].at;
				p[k].wt=p[k].tt-p[k].bt;
				i=d[num].ct;
				np++;
				num++;
				idle = 0;
				p[k].status=2;
			}
			else
			{
				strcpy(d[num].name,p[k].pname);
				d[num].st=i;
				d[num].ct=i+tq;
				i=i+tq;
				num++;
				p[k].status = 1;
				p[k].left= p[k].left -tq;
				idle=0;
				for(j=0;j<n;j++)
				{
					if(p[j].at <= i && p[j].status != 2 && p[j].inqueue != 1 && j!=k)
					{
						enqueue(j);
						p[j].inqueue = 1;
					}
				}	
				enqueue(k);
				p[k].inqueue = 1;
			}
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
		printf("____________________");
		printf("\n|");
	for(i=0;i<num;i++)
		printf("%s\t|",d[i].name);
		printf("\n");
	for(i=0;i<n;i++)
		printf("____________________");
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
	printf("\nAverage waiting time=%f ms\n",w);
	printf("\nAverage turnaround time=%f ms\n",t);
}
