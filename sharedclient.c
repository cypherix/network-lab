/*
	Author : Arjun Muraleedharan
	Program : Client for shared memory
	Date : 23/01/2018
*/
#include<stdio.h>
#include<sys/shm.h>

void main()
{
	int id;
	char *shmaddr,buff[20]="4+3+2";		//Declaring variables to send

	id=shmget(1900,100,IPC_CREAT|0666);	//Creating the shared memory
	shmaddr=shmat(id,NULL,0);		//Getting the shared memory address

	sprintf(shmaddr,"%s",buff);		//Writing into shared memory

	shmdt(shmaddr);				//Detaching from shared memory
}
