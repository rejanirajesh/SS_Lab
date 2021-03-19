#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
void * reader(void *) ;  
void *writer (void *) ;  
sem_t wsem,mutex ;  
int readcount=0 ;  
main()  
{  
	int a=1,b=1;  
	system("clear");  
	sem_init(&wsem,0,1) ;  
	sem_init(&mutex,0,1) ;  
	pthread_t r,w,r1,w1 ;  
	pthread_create(&r,NULL,reader,(void *)a);  
	a++;  
	pthread_create(&w1,NULL,writer,(void *)b);  
	b++;  
	pthread_create(&r1,NULL,reader,(void *)a);  
	pthread_create(&w,NULL,writer,(void *)b);  
	pthread_join(r,NULL);  
	pthread_join(w1,NULL);  
	pthread_join(r1,NULL);  
	pthread_join(w,NULL) ;  
	printf("main terminated\n");  
}  
void * reader(void * arg)  
{  
	while(1)
	{
		int c=(int)arg ;  
		printf("\nReader %d is created\n",c);  
		sleep(1);  
		sem_wait(&mutex) ;  
		readcount++;  
		if(readcount==1)  
			sem_wait(&wsem);  
  			sem_post(&mutex) ;  
			/*Critcal Section */  
			printf("Reader %d is reading\n",c);  
			sleep(1) ;  
			printf("Reader%d finished reading",c);  
			/* critical section completed */  
			sem_wait(&mutex) ;  
			readcount-- ;  
		if(readcount==0)  
			sem_post(&wsem) ;  
			sem_post(&mutex) ;
	}  
 }  
void * writer(void * arg)  
{  
	while(1)
	{
		int c=(int)arg ;  
		printf("Writer %d is created\n",c);  
		sleep(1);  
		sem_wait(&wsem) ;  
		printf("Writer %d is writing\n",c) ;  
		sleep(1);  
		printf("Writer%d finished writing\n",c);  
		sem_post(&wsem) ; 
	} 
}
