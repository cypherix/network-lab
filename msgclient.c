/*
	Author : Arjun Muraleedharn
	Program : Client using Message Queue
	Date : 30/01/2018
*/
#include<stdio.h>
#include<sys/msg.h>

struct msgbuff					//Structure for message queue
{
	long msgtype;
	char msgs[400];
}s1,s2;

void main()
{
	int mid,k,key;

	printf("\nEnter the message:");
	gets(s1.msgs);
	s1.msgtype=1;				//Setting type for message
	printf("Enter key");
	scanf("%d",key);
	strcat(s1.msgs,key);

	mid=msgget(1500,IPC_CREAT|0666);	//Creating the message queue
	
	k=msgsnd(mid,&s1,sizeof(s1),0);		//Sending into message queue
	
	k=msgrcv(mid,&s2,sizeof(s2),2,0);	//Receiving the encoded string from message queue
	printf("\nMessage from client is %s\n",s2.msgs);

}
