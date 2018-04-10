/*
	Author : Arjun Muraleedharan
	Date : 16/1/18
	Program : IPC Using Single pipe
*/
#include<stdio.h>
#include<sys/types.h>
#include<string.h>

pid_t pid;
void main()
{
	int fd[2],p,i;
	char string1[20],string2[20];

	p=pipe(fd);					//Creating a pipe

	if(p==-1)					//Checking pipe error
		printf("An error occured while creating pipe");
	else 						//No pipe error
	{	
		printf("Enter a string:");
		gets(string1);

		pid=fork();				//Creating child

		if(pid==-1)				//Child error
			printf("Error occured while creating process");
		else if(pid==0)				//Inside child process
		{
			printf("\nInside Child:\n");
			read(fd[0],string2,sizeof(string2));	//Reading from pipe
			for(i=0;string2[i]!='\0';i++)	//Encodeing
			{
				if(string2[i]=='y')
					string2[i]='a';
				else if(string2[i]=='z')
					string2[i]='b';
				else
					string2[i]=string2[i]+2;
			}
			printf("The new string is %s\n",string2);
		}
		else 					//Inside Parent process
		{
			printf("\nInside Parent:\n");
			write(fd[1],string1,sizeof(string1));	//Writing into pipe
			printf("Actual String is:%s \n",string1);
		}
	}
}
	
