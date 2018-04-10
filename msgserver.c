/*
	Author : Arjun Muraleedharn
	Program : Server using Message Queue
	Date : 30/01/2018
*/
#include<stdio.h>
#include<sys/msg.h>

struct msgbuff						//Structure for message queue
{
	long msgtype;
	char msgs[400];
}s1;

void main()
{
	int mid,k,i,key;

	mid=msgget(1500,IPC_CREAT|0666);		//Creating the message queue
	
	k=msgrcv(mid,&s1,sizeof(s1),1,0);		//Receiving from message queue
	printf("\nMessage from client is %s\n",s1.msgs);
	x=strlen(s1.msgs);
	key=s1.msgs[x-1];
	s1.msgs[x-1]='\0';

	for(i=0;s1.msgs[i]!='\0';i++)			//Ecnoding the string
	{
		if(s1.msgs[i]==' ')
			continue;
		else
			s1.msgs[i]=s1.msgs[i]+key;
	}
	
	s1.msgtype=2;					//Setting message type
	k=msgsnd(mid,&s1,sizeof(s1),0);			//Sending the message to message queue
	if(k!=-1)					//Checking for errors
		printf("\nThe Encoded message was sent\n\n");
	else
		printf("Error Occured while sending encoded message");
}
