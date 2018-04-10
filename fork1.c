/*
	Program : Creating a new process using fork 
	Author : Arjun Muraleedharan
	Date : 09/01/2018
*/
#include<stdio.h>
#include<sys/types.h>
pid_t pid,pcid,cid;
void main()			
{
	printf("\n");
	pid=fork();
	if(pid==0)
	{	
		cid=getpid();
		pcid=getppid();
		printf("Child and child process id = %d and parent process id = %d\n",cid,pcid);
	}
	else if (pid>0)
	{	
		pcid=getpid();
		printf("Parent and parent process id = %d\n",pcid);
	}
	else
		printf("Error\n");
	printf("\n");
}
