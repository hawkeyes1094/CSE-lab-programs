//OS Lab week 7, Example 2

//By - Teja Juluru
//Created on - 11/9/19

//Example message queues program
//sender program
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include<errno.h>

#define MAX_TEXT 512

struct my_msg_st {
	long int my_msg_type;
	char some_text[MAX_TEXT];
};

int main(int argc, char const *argv[])
{
	int running = 1;
	struct my_msg_st some_data;
	int msgid;
	char buffer[BUFSIZ];

	msgid = msgget((key_t)1234,0666 | IPC_CREAT);
	if(msgid == -1) {
		fprintf(stderr,"msgget failed with error : %d\n",errno);
		exit(EXIT_FAILURE);
	}

	while(running) {
		printf("Enter some text : ");
		fgets(buffer,BUFSIZ,stdin);
		some_data.my_msg_type = 1;
		strcpy(some_data.some_text,buffer);
		if(msgsnd(msgid,(void*)&some_data,MAX_TEXT,0) == -1) {
			fprintf(stderr,"msgsnd failed\n");
			exit(EXIT_FAILURE);
		}
		if(strncmp(buffer,"end",3) == 0) {
			running = 0;
		}
	}
	exit(EXIT_SUCCESS);
	return 0;
}