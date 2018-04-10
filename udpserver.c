#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>
#include <string.h>
#include<arpa/inet.h>

void main()
{
	struct sockaddr_in serv_addr,client_addr;
	char buffer[1024],msg[100];
	int sock,r,s,slen=sizeof(client_addr);

	strcpy(msg,"Received from server");	

	sock=socket(AF_INET, SOCK_DGRAM, 0);
	if(sock<0)
		printf("\nSocket Creation Error\n");

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = 7888;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	
	bind(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

	while(1)
	{
		printf("\nWaiting for data..\n");

		r=recvfrom(sock, buffer, sizeof(buffer), 0, (struct sockaddr *) &client_addr,&slen);
		if(r<0)
			printf("Receiving Error");
		else
			printf("\nData: %s\n" , buffer);

		s=sendto(sock , msg , sizeof(msg) , 0 , (struct sockaddr*) &client_addr, sizeof(client_addr));
		if(s<0)
			printf("Sending Error");
		else
			printf("Sent");
	}
}

