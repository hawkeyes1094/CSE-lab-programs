//CN Lab week 1, Q3

//by - Teja Juluru
//created on 31/7/19

//Program where Server prints client IP and ephemeral port number
// and returns the message back in uppercase until "QUIT" is typed.
//Server side program
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include <ctype.h>
#include<arpa/inet.h>

#define PORTNO 15000
#define BUFFER_LEN 256

void TerminateSocket(int sockfd) {
  close(sockfd);
  exit(0);
}

int CreateServerSocket(char* ip_address) {
  struct sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = inet_addr(ip_address);
  server_addr.sin_port = PORTNO;

  int sockfd = socket(AF_INET,SOCK_STREAM,0);

  bind(sockfd,(struct sockaddr*)&server_addr,sizeof(server_addr));

  return sockfd;
}

void PerfromServerTask(int newsockfd,struct sockaddr_in client_addr) {
  char* buffer = (char*)malloc(BUFFER_LEN*sizeof(char));

  while(1) {

  //read from client and print
  int bytes_transmitted = recv(newsockfd,buffer,BUFFER_LEN*sizeof(char),0);
  printf("Message from client is : %s\n",buffer);
  if(!strcmp("QUIT",buffer)) {
    printf("Quitting...\n");
    TerminateSocket(newsockfd);
    exit(0);
  }

  printf("Length of message recieved is %ld\n",strlen(buffer));
  printf("Client IP : %s\n",inet_ntoa(client_addr.sin_addr));
  printf("Client port number is : %d\n",client_addr.sin_port);

  //changes mesage into uppercase
  int i = 0;
  while (buffer[i] != '\0') {
      if (buffer[i] >= 'a' && buffer[i] <= 'z') {
         buffer[i] = buffer[i] - 32;
      }
      i++;
   }

  //write the modified mesage back to client
  bytes_transmitted = send(newsockfd,buffer,BUFFER_LEN*sizeof(char),0);

  }

}


int main(int argc, char const *argv[]) {
  char ip_address [] = "127.0.0.1" ;

  int sockfd = CreateServerSocket(ip_address);

  struct sockaddr_in client_addr;
  int newsockfd,client_len;

  //while(1) {
    //listen for a connection
    listen(sockfd,5);
    printf("Server waiting\n");
    client_len = sizeof(client_addr);

    //accept a connection
    newsockfd = accept(sockfd,(struct sockaddr*)&client_addr,&client_len);

    PerfromServerTask(newsockfd,client_addr);
    printf("Exited PerfromServerTask\n");
  // }
  return 0;
}
