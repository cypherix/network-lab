/*
	Author : Arjun Muraleedharan
	Program : Server using Shared Memmory
	Date : 23/01/2018
*/
#include<stdio.h>
#include<sys/shm.h>

void main()
{
	int id,i,sum;
	char *shmaddr,buff[20];			//Declaring variables to accept from shared memory

	id=shmget(1900,100,IPC_CREAT|0666);	//Create the shared memory
	shmaddr=shmat(id,NULL,0);		//Get the shared memory address

	sscanf(shmaddr,"%s",buff);		//Read from shared memory
	printf("\nData from Client is :%s\n",buff);

	sum=buff[0]-48;				//Calculate the expression
	for(i=1;buff[i]!='\0';i++)
	{		
		if(buff[i]=='+')
		{
			sum=sum+buff[i+1]-48;
		}
	}
	printf("\nSum:%d\n",sum);

	shmdt(shmaddr);				//Detaching from shared memory
}
