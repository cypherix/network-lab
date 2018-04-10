#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void *Firstfn()
{
	int i;
	for(i=0;i<10;i++)
	{
		sleep(1);
		printf("\nHello ");
	}
}


void main()
{
	pthread_t tid[10];
	int i;	

	for(i=0;i<10;i++)
		pthread_create(&tid[i],NULL,Threadfn,NULL);

	for(i=0;i<10;i++)
		pthread_join(tid[i],NULL);
}
