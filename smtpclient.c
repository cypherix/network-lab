/*
Program: SMTP: Client
Author: Priyanka Govind CV
*/

#include"sys/socket.h"
#include"netinet/in.h"
#include"stdio.h"
#include"string.h"
#include"stdlib.h"

int main()
{
	char buf[100];
	int k;
	int sock_desc;
	struct sockaddr_in client;
	memset(&client,0,sizeof(client));
	sock_desc=socket(AF_INET,SOCK_DGRAM,0);
	if(sock_desc==-1)
	{
		printf("\nError in socket creation");
		exit(1);
	}
	client.sin_family=AF_INET;
	client.sin_addr.s_addr=inet_addr("127.0.0.1");
	client.sin_port=3500;
	printf("\nMAIL TO : ");
	scanf("%s",buf);
	k=sendto(sock_desc,buf,sizeof(buf),0,(struct
	sockaddr*)&client,sizeof(client));
	if(k==-1)
	{
		printf("\nError in sending");
		exit(1);
	}
	strcpy(buf,"\0");
	printf("\nFROM : ");
	scanf("%s",buf);
	k=sendto(sock_desc,buf,sizeof(buf),0,(struct
	sockaddr*)&client,sizeof(client));
	if(k==-1)
	{
		printf("\nError in sending");
		exit(1);
	}
	strcpy(buf,"\0");
	printf("\nSUBJECT : ");
	scanf("%s",buf);
	k=sendto(sock_desc,buf,sizeof(buf),0,(struct
	sockaddr*)&client,sizeof(client));
	if(k==-1)
	{
		printf("\nError in sending");
		exit(1);
	}
	strcpy(buf,"\0");
	printf("\nMSG BODY : ");
	while(strcmp(buf,".")!=0)
	{
		strcpy(buf,"\0");
		scanf("%s",buf);
		k=sendto(sock_desc,buf,sizeof(buf),0,(struct
		sockaddr*)&client,sizeof(client));
		if(k==-1)
		{
			printf("\nError in sending");
			exit(1);
		} 
	}
	close(sock_desc);
	return 0;
}
