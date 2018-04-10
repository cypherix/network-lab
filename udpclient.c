#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>
#include <string.h>
#include<arpa/inet.h>

void main()
{
	struct sockaddr_in serv_addr;
	char buffer[1024],msg[100];
	int sock,r,s,slen=sizeof(serv_addr);

	sock=socket(AF_INET, SOCK_DGRAM, 0);
	if(sock<0)
		printf("\nSocket Creation Error\n");

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = 7888;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	
	while(1)
	{
		printf("Enter message : ");
		scanf("%s",msg);

		s=sendto(sock, msg, sizeof(msg) , 0 , (struct sockaddr *) &serv_addr, slen);
		if(s<0)
			printf("Sending error");
		else
			printf("Sent");

		r=recvfrom(sock, buffer, sizeof(buffer), 0, (struct sockaddr *) &serv_addr , &slen);
		if(r<0)
			printf("Receiving Error");
		else
			printf("\n%s\n",buffer);

	}
}
