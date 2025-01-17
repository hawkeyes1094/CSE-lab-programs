//Computer network lab week 1, Solved exercise

//by - Teja Juluru
//created on 25/07/19

//client code

#include<sys/types.h>
#include<sys/socket.h>
#include <stdio.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char const *argv[])
{
	int len,result,sockfd,n = 1;
	struct sockaddr_in address;
	char ch[256],buf[256];

	//Create a socket for the client
	sockfd = socket(AF_INET,SOCK_STREAM,0);

	//Name the socket as agreed with the server
	address.sin_family = AF_INET;
	//Forgot to change it here too. So dumb
	address.sin_addr.s_addr = inet_addr("127.0.0.1"); //MY PC IP addr
	address.sin_port = htons(10200);
	len = sizeof(address);

	//Connect your socket to the server's socket
	result = connect(sockfd,(struct sockaddr *)&address,len);
	if(result == -1) {
		perror("\nCLIENT ERROR");
		exit(1);
	}

	//You can now read and write via sockfd
	printf("Enter String \t");
	scanf("%[^\n]s",);
	printf("length of the message is : %d\n",strlen(buf));
	ch[strlen(ch)] = '\0';
	write(sockfd,ch,strlen(ch));
	printf("STRING SENT BACK FROM THE SERVER IS .....");
	while(n) {
		n = read(sockfd,buf,sizeof(buf));
		puts(buf);
	}
	return 0;
}
